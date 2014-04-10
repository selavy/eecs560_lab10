CC = g++
CFLAGS = --std=c++11 -Wall -Werror

OBJS = DisjointSet.o main.o
EXEC = lab10

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)
DisjointSet.o: DisjointSet.hpp DisjointSet.cpp
	$(CC) $(CFLAGS) -c DisjointSet.cpp
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
.PHONY: clean
clean:
	rm -rf $(OBJS) $(EXEC)

