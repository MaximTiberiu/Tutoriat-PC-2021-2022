all: build memcheck

build: matrice.c
	gcc -Wall -Wextra matrice.c -o vematricector

run: matrice
	./matrice

memcheck: matrice
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1 ./matrice