CC = g++

CXXFLAGS= -std=c++11 -g -Wall

OBJECTS = node.o filesystem.o terminal.o
HEADERS := $(shell find . -path ./test -prune -o -name "*.hpp" -print)

main: main.o $(OBJECTS)
	$(CC) $(CXXFLAGS) -o $@ $^

$(OBJECTS): $(HEADERS)
