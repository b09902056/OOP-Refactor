CC = g++
CFLAGS = -std=c++11 -Wall

all: main

main: main.o employee.o
	$(CC) $(CFLAGS) -o main main.o employee.o
main.o: main.cc
	$(CC) $(CFLAGS) -c -o main.o main.cc
employee.o: employee.cc
	$(CC) $(CFLAGS) -c -o employee.o employee.cc

clean:
	rm -f main main.o employee.o