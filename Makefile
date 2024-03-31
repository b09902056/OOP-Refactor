CC = g++
CFLAGS = -std=c++11 -Wall

all: main

main: main.o employeeList.o
	$(CC) $(CFLAGS) -o main main.o employeeList.o
main.o: main.cc
	$(CC) $(CFLAGS) -c -o main.o main.cc
employeeList.o: employeeList.cc
	$(CC) $(CFLAGS) -c -o employeeList.o employeeList.cc

clean:
	rm -f main main.o employeeList.o