# FJ Tria (@fjstria)
# WordleSolver/Makefile

CC = clang

CFLAGS = -Wall -Wpedantic -Werror -Wextra -g -O0


all: Solver

Solver: Search.o Solver.o
	$(CC) Search.o Solver.o -o Solver

Search.o: Search.c
	$(CC) $(CFLAGS) -c Search.c

Solver.o: Solver.c
	$(CC) $(CFLAGS) -c Solver.c

clean:
	rm -f Search.o Solver.o Solver

format:
	clang-format -i -style=file *.[ch]
