.PHONY: all clean
all: fib memleak

memleak: memleak.c
	gcc -o $@ $^

fib: obj/tp.o obj/fib.o
	gcc -o $@ $^ -llttng-ust -ldl

obj/:
	mkdir $@

obj/fib.o: fib.c tp.h obj/
	gcc -o $@ -c $<

obj/tp.o: tp.c tp.h obj/
	gcc -o $@ -c -I. $<

clean:
	rm -rf obj/ fib memleak
