LASTNAME = Lesslie

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

.PHONY: tar
tar: clean
	mkdir $(LASTNAME)_lab10
	cp *.cpp *.hpp Makefile LICENSE README.md *.out $(LASTNAME)_lab10
	tar -czvf $(LASTNAME)_lab10.tar.gz $(LASTNAME)_lab10
	rm -rf $(LASTNAME)_lab10