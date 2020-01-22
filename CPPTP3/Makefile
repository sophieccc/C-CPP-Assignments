.PHONY: all, clean

CPP = g++
CFLAGS = -ansi -pedantic -Wall -Werror -std=c++11 -DMAP -g

all: statistics statistics

statistics: statistics.cpp
	g++ -o statistics statistics.cpp $(CFLAGS)

main: main.cpp
	g++ -o main main.cpp statistics.cpp $(CFLAGS)

clean:
	rm -f $(OBJ) *.o