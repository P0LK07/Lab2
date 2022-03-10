CC=gcc
CF=-c -Wall

all: vector

list: list.o input.o main.o
	$(CC) list.o input.o main.o -o lab2

vector: vector.o input.o main.o
	$(CC) vector.o input.o main.o -o lab2

vector.o: vector.c
	$(CC) $(CF) vector.c

list.o: list.c
	$(CC) $(CF) list.c

input.o: input.c
	$(CC) $(CF) input.c

main.o: main.c
	$(CC) $(CF) main.c

