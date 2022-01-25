#include <arpa/inet.h>
#include <fstream>
#include <iostream>
#include <random>
#include <signal.h>
#include <sstream>
#include <stdio.h>
#include <string>
#include <sys/socket.h>
#include <thread>
#include <unistd.h>
#include <vector>

static bool is_running = true;

static const std::string request_get = "GET /in_data HTTP/1.1\r\n"
                                       "\r\n";

static const std::string request_put = "PUT /out_data HTTP/1.1\r\n"
                                       "\r\n";

static const std::string request_501 = "POST /main.c HTTP/1.1\r\n"
                                       "Content-length: 24\r\n"
                                       "\r\n"
                                       "name=banana&hello=world!";

static const std::string request_404 = "GET /asdf HTTP/1.1\r\n"
                                       "\r\n";

std::random_device rd;
std::uniform_int_distribution<int> dist(0, 3);

void handle_signal(int sigcode)
{
	is_running = false;
	std::cout << "\r\x1b[JStopping threads" << std::endl;
}

void make_requests()
{
	static sockaddr_in host;
	host.sin_port = htons(8080);
	host.sin_family = AF_INET;

	inet_aton("127.0.0.1", &host.sin_addr);

	while (is_running) {
		int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (connect(sock, reinterpret_cast<sockaddr*>(&host), sizeof(host)) ==
		    -1) {
			perror("connect");
			return;
		}

		std::cout << "Making a request" << std::endl;

		int choice = dist(rd);
		std::string request;
		switch (choice) {
			case 0:
				std::cout << "Sending a GET request" << std::endl;
				request = request_get;
				break;
			case 1: {
				std::cout << "Sending a PUT request" << std::endl;
				std::ifstream data("./data");
				std::string content((std::istreambuf_iterator<char>(data)),
				                    (std::istreambuf_iterator<char>()));
				data.close();
				request = request_put + content;
			} break;
			case 2:
				std::cout << "Sending an ERROR 404 request" << std::endl;
				request = request_404;
				break;
			case 3:
				std::cout << "Sending an ERROR 501 request" << std::endl;
				request = request_501;
				break;
		}
		send(sock, request.data(), request.size(), 0);

		std::array<char, 1024> buffer;
		while (read(sock, buffer.data(), buffer.size()) > 0)
			;
		close(sock);
	}
}

int main()
{
	std::vector<std::thread> threads(4);

	for (auto& thread : threads)
		thread = std::thread(make_requests);

	signal(SIGINT, handle_signal);
	for (auto& thread : threads)
		thread.join();
}
