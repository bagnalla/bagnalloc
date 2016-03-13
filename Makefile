CC = gcc
CPP = g++
OPTIONS = -Wall -O3
LDLIBS =

objects = malloc_mmap.o

test: test.c $(objects)
	$(CC) test.c $(objects) $(OPTIONS) $(LDLIBS)

time: test_time.c $(objects)
	$(CC) test_time.c $(objects) $(OPTIONS) $(LDLIBS)

cpp: cpptest.cc $(objects)
	$(CPP) cpptest.cc $(objects) $(OPTIONS)

thread: threads.cc $(objects)
	$(CPP) threads.cc $(objects) $(OPTIONS) -std=c++11 -fopenmp

threadtime: threads_time.cc $(objects)
	$(CPP) threads_time.cc $(objects) $(OPTIONS) -std=c++11 -fopenmp

%.o: %.c
	$(CC) $< -c $(OPTIONS) $(LDLIBS) -o $@

clean:
	rm -f *.o a.out
