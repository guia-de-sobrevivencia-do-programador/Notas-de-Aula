#define LTTNG_UST_TRACEPOINT_DEFINE
#include "tp.h"

#include <stdlib.h>
#include <stdio.h>

int fib(int v)
{
	if (v <= 1)
		return 1;
	return fib(v-1)+fib(v-2);
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		printf("Usage: %s <itteration_n>\n", argv[0]);
		return 1;
	}

	int fib_n = atoi(argv[1]);
	printf("Fib %d: %d\n", fib_n, fib(fib_n));
}
