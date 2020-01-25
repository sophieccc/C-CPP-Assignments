.PHONY: all, clean

CPP = g++
CFLAGS = -ansi -pedantic -Wall -Werror -std=c++11 -DMAP -g

all: main statistics graph Lecture

Lecture: Lecture.cpp
	g++ -o Lecture Lecture.cpp $(CFLAGS)

statistics: statistics.cpp
	g++ -o statistics statistics.cpp $(CFLAGS)

graph: graph.cpp
	g++ -o statistics graph.cpp $(CFLAGS)

main: main.cpp Lecture.cpp graph.cpp statistics.cpp
	g++ -o main main.cpp statistics.cpp graph.cpp Lecture.cpp $(CFLAGS)

clean:
	rm -f $(OBJ) *.o