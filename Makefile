CC = gcc
CPP = g++
OPTIONS = -Wall -pthread
LDLIBS =

objects = malloc.o

all: test.c $(objects)
	$(CC) test.c $(objects) $(OPTIONS) $(LDLIBS)

cpp: cpptest.cc $(objects)
	$(CPP) cpptest.cc $(objects) $(OPTIONS)

%.o: %.c
	$(CC) $< -c $(OPTIONS) $(LDLIBS) -o $@

clean:
	rm -f *.o a.out
