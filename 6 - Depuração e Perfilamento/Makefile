SRC_FILES=fib addvec httpserver

all:
	echo $(SRC_FILES) | xargs -n 1 -- make -C

clean:
	echo $(SRC_FILES) | tr ' ' '\n' | xargs -I ARG -- make -C ARG clean
