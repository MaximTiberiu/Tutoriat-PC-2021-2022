all: build run

build: ex2.c
	gcc -Wall -Wextra -g ex2.c -o ex2

run: ex2
	./ex2

memcheck: ex2
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes --vgdb=full --error-exitcode=1 ./ex2