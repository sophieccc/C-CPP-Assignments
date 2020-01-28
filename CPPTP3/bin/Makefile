.PHONY: all, clean

CPP = g++
CFLAGS = -ansi -pedantic -Wall -Werror -std=c++11 -DMAP -g

all: main Statistics Graph Lecture

Lecture: Lecture.cpp
	g++ -o Lecture Lecture.cpp $(CFLAGS)

Statistics: Statistics.cpp
	g++ -o Statistics Statistics.cpp $(CFLAGS)

Graph: Graph.cpp
	g++ -o Statistics Graph.cpp $(CFLAGS)

main: main.cpp Lecture.cpp Graph.cpp Statistics.cpp
	g++ -o main main.cpp Statistics.cpp Graph.cpp Lecture.cpp $(CFLAGS)

clean:
	rm -f $(OBJ) *.o