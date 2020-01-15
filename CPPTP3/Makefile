.PHONY: all, clean

CC = g++
CFLAGS = -Wall -Werror

LIBS += -lpthread

SRCS = $(wildcard *.c)
PROGS = $(SRCS:.c=.o)

all: $(PROGS)	

(PROGS): $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<	
	
clean:
	rm -f $(PROGS) *.o