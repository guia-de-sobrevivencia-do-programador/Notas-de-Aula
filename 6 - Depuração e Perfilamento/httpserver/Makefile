.PHONY: all clean
all: server simulate_traffic

clean:
	rm -f server simulate_traffic

server: main.c
	gcc -o $@ $^ -g -lpthread

simulate_traffic: simulate_traffic.cpp
	g++ -o $@ $^ -g -lpthread
