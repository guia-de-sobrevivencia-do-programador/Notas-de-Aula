httpserver: server.c tpp.c
	gcc -o $@ -I. $^ -ggdb3 -Og -llttng-ust -ldl -lpthread

simulate_traffic: simulate_traffic.cpp
	g++ -o $@ $^ -g -lpthread

.PHONY: clean
clean:
	rm -f httpserver simulate_traffic
