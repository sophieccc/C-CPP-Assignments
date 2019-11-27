.PHONY: all, clean

CC = gcc
CFLAGS = -ansi -pedantic –Wall –std=c++11

Trajet.o	:	Trajet.cpp
	$(CC) $(CFLAGS) -c Trajet.cpp

TrajetSimple.o: Trajet.cpp TrajetSimple.cpp 
	$(CC) $(CFLAGS) -c Trajet.cpp TrajetSimple.cpp 

TrajetComplexe.o: Trajet.cpp TrajetComplexe.cpp
	$(CC) $(CFLAGS) -c Trajet.cpp TrajetComplexe.cpp

Trajet	: Trajet.o
	$(CC) $(CFLAGS) -o Trajet.o

TrajetSimple: TrajetSimple.o Trajet.o
	$(CC) $(CFLAGS) -o Trajet.o TrajetSimple.o

TrajetComplexe: TrajetComplexe.o Trajet.o
	$(CC) $(CFLAGS) -o Trajet.o TrajetComplexe.o

clean:
	rm -f $(PROGS) *.o