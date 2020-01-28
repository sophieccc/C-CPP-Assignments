.PHONY: all, clean

CPP = g++
CFLAGS = -ansi -pedantic -Wall -Werror -std=c++11 -DMAP -g

all: Analog Statistics Graph Lecture

Lecture: Lecture.cpp
	g++ -o Lecture Lecture.cpp $(CFLAGS)

Statistics: Statistics.cpp
	g++ -o Statistics Statistics.cpp $(CFLAGS)

Graph: Graph.cpp
	g++ -o Statistics Graph.cpp $(CFLAGS)

Analog: Analog.cpp Lecture.cpp Graph.cpp Statistics.cpp
	g++ -o Analog Analog.cpp Statistics.cpp Graph.cpp Lecture.cpp $(CFLAGS)

clean:
	rm -f $(OBJ) *.o