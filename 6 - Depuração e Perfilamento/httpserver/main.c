#define LTTNG_UST_TRACEPOINT_DEFINE
#include "tp.h"

#include <arpa/inet.h>
#include <memory.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

#define KB(x) (1024 * x)
#define MB(x) (1024 * 1024 * x)

struct http_request {
	char* method;
	char* uri;
	char* content;
};

static const char* response_header = "HTTP/1.1 %s\r\n"
                                     "Server: GSP-server\r\n"
                                     "Content-length: %d\r\n"
                                     "\r\n"
                                     "%s%n";

void sighand(int sigcode)
{
	printf("\r\x1b[JUser stopped the server\n");
	exit(0);
}

void send_404(int sock)
{
	static const char* response_content = "<html>\n"
	                                      "\t<header>\n"
	                                      "\t\t<title>GSP-server</title>\n"
	                                      "\t</header>\n"
	                                      "\t<body>\n"
	                                      "\t\t<h3>404 - Not found</h3>\n"
	                                      "\t</body>\n"
	                                      "</html>\n";

	char* buffer = (char*)calloc(1, MB(8));
	int buffer_len;
	snprintf(buffer, MB(8), response_header, "404 Not found",
	         strlen(response_content), response_content, &buffer_len);
	lttng_ust_tracepoint(httpservertp, network_send_start);
	send(sock, buffer, buffer_len, 0);
	lttng_ust_tracepoint(httpservertp, network_send_end, buffer_len);
	free(buffer);
}

void send_501(int sock)
{
	static const char* response_content = "<html>\n"
	                                      "\t<header>\n"
	                                      "\t\t<title>GSP-server</title>\n"
	                                      "\t</header>\n"
	                                      "\t<body>\n"
	                                      "\t\t<h3>501 - Not implemented</h3>\n"
	                                      "\t</body>\n"
	                                      "</html>\n";

	char* buffer = (char*)calloc(1, MB(8));
	int buffer_len;
	snprintf(buffer, MB(8), response_header, "501 Not implemented",
	         strlen(response_content), response_content, &buffer_len);
	lttng_ust_tracepoint(httpservertp, network_send_start);
	send(sock, buffer, buffer_len, 0);
	lttng_ust_tracepoint(httpservertp, network_send_end, buffer_len);
	free(buffer);
}

void get_file(int sock, const char* filepath)
{
	FILE* f = fopen(filepath, "rb");
	if (f == NULL) {
		send_404(sock);
		return;
	}

	fseek(f, 0, SEEK_END);
	long file_size = ftell(f);
	fseek(f, 0, SEEK_SET);

	char* file_content = (char*)calloc(1, file_size + 1);
	lttng_ust_tracepoint(httpservertp, file_read_start, filepath);
	fread(file_content, 1, file_size, f);
	lttng_ust_tracepoint(httpservertp, file_read_end, filepath, file_size);
	fclose(f);

	int response_size;
	char* buffer = (char*)calloc(1, strlen(response_header) + file_size + 128);
	sprintf(buffer, response_header, "200 Ok", file_size, file_content,
	        &response_size);
	free(file_content);

	lttng_ust_tracepoint(httpservertp, network_send_start);
	send(sock, buffer, response_size, 0);
	lttng_ust_tracepoint(httpservertp, network_send_end, response_size);

	free(buffer);
}

void put_file(int sock, const char* filepath, const char* content)
{
	static const char* response_body =
	    "<html>\n"
	    "\t<header>\n"
	    "\t\t<title>GSP-server</title>\n"
	    "\t</header>\n"
	    "\t<body>\n"
	    "\t\t<h3>File successfully saved to disk</h3>\n"
	    "\t</body>\n"
	    "</html>\n";

	FILE* f = fopen(filepath, "wb");
	if (f == NULL) {
		send_404(sock);
		return;
	}

	size_t content_len = strlen(content);
	lttng_ust_tracepoint(httpservertp, file_write_start, filepath);
	fwrite(content, 1, content_len, f);
	lttng_ust_tracepoint(httpservertp, file_write_end, filepath, content_len);

	int response_size;
	char* buffer = (char*)calloc(1, strlen(response_header) + 1024);
	sprintf(buffer, response_header, "200 Ok", strlen(response_body),
	        response_body, &response_size);
	lttng_ust_tracepoint(httpservertp, network_send_start);
	send(sock, buffer, response_size, 0);
	lttng_ust_tracepoint(httpservertp, network_send_end, response_size);
	free(buffer);

	fclose(f);
}

struct http_request parse_request(int sock)
{
	char* buffer = (char*)calloc(1, MB(8));
	lttng_ust_tracepoint(httpservertp, network_recv_start);
	int datalen = recv(sock, buffer, MB(8), 0);
	lttng_ust_tracepoint(httpservertp, network_recv_end, datalen);

	struct http_request request;
	request.method = (char*)calloc(1, 6);
	request.uri = (char*)calloc(1, 1024);
	request.content = buffer;

	sscanf(buffer, "%6s %1024s", request.method, request.uri);
	return request;
}

void free_request(struct http_request r)
{
	free(r.method);
	free(r.uri);
	free(r.content);
}

void* handle_client(void* sock_ptr)
{
	int sock = (long long)(sock_ptr);

	struct http_request request = parse_request(sock);
	printf("Got request:\n   Method: %s\n   URI: %s\n", request.method,
	       request.uri);

	char* filepath;
	if (request.uri[0] == '/') {
		filepath = (char*)calloc(1, strlen(request.uri) + 2);
		sprintf(filepath, ".%s", request.uri);
	}
	else {
		filepath = (char*)calloc(1, strlen(request.uri) + 3);
		sprintf(filepath, "./%s", request.uri);
	}

	if (strcmp(request.method, "GET") == 0) {
		get_file(sock, filepath);
	}
	else if (strcmp(request.method, "PUT") == 0) {
		put_file(sock, filepath, request.content);
	}
	else {
		send_501(sock);
	}

	free(filepath);
	free_request(request);

	close(sock);
	return NULL;
}

int main()
{
	int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	{
		int i = 1;
		setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &i, sizeof(i));
	}

	struct sockaddr_in hint;
	memset(&hint, 0, sizeof(hint));
	hint.sin_family = AF_INET;
	hint.sin_addr.s_addr = INADDR_ANY;
	hint.sin_port = htons(8080);
	if (bind(sock, (struct sockaddr*)(&hint), sizeof(hint)) == -1) {
		perror("bind");
		exit(1);
	}

	listen(sock, 16);

	signal(SIGINT, sighand);
	while (1) {
		long long client = accept(sock, NULL, NULL);
		if (client == -1) {
			perror("accept");
			continue;
		}

		pthread_t thread;
		pthread_create(&thread, NULL, handle_client, (void*)client);
		pthread_detach(thread);
	}
}
