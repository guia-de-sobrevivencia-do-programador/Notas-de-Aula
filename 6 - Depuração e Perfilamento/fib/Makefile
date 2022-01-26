fib: fib.c tpp.c
	gcc -o $@ -I. $^ -Og -ggdb3 -llttng-ust -ldl

.PHONY: clean
clean:
	rm -f fib
