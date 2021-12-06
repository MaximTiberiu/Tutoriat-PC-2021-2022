all: build run

build: matrice.c
	gcc matrice.c -o matrice

run: matrice
	./matrice

memcheck: matrice
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1 ./matrice
