CFLAGS= -Wall -pedantic -std=c11

all: q_test1

%.o: %.c %.h
		gcc $(CFLAGS) -c $<

q_test1: queue.o q_test1.o
		gcc $(CFLAGS) queue.o q_test1.o -o $@

clean:
		rm -f *.o q_test1
