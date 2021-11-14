all: build run

build: pointer.c
	gcc pointer.c -o pointer

run: pointer
	./pointer

memcheck: pointer
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1 ./pointer