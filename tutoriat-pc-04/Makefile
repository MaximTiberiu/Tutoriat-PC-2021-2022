all: build run

build: vector.c
	gcc vector.c -o vector

run: vector
	./vector

memcheck: vector
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1 ./vector
