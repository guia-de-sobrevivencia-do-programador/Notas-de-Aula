#define LTTNG_UST_TRACEPOINT_DEFINE
#include "tp.h"

#include <stdio.h>

int fib(int v)
{
	if (v <= 1)
		return 1;
	return fib(v-1)+fib(v-2);
}

int main()
{
	printf("Fib 40: %d\n", fib(40));
}
