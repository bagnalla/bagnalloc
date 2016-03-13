CC = gcc
CPP = g++
OPTIONS = -Wall -O3
LDLIBS =

objects = malloc.o

test: test.c $(objects)
	$(CC) test.c $(objects) $(OPTIONS) $(LDLIBS)

cpp: cpptest.cc $(objects)
	$(CPP) cpptest.cc $(objects) $(OPTIONS)

thread: threads.cc $(objects)
	$(CPP) threads.cc $(objects) $(OPTIONS) -std=c++11 -fopenmp

%.o: %.c
	$(CC) $< -c $(OPTIONS) $(LDLIBS) -o $@

clean:
	rm -f *.o a.out
