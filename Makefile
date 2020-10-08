CFLAGS= -Wall -pedantic -std=c11

all: test_apply test_put test_concat test_remove test_close test_get test_search

%.o: %.c %.h
		gcc $(CFLAGS) -c $<

test_apply: queue.o test_apply.o
		gcc $(CFLAGS) queue.o test_apply.o -o $@

test_get: queue.o test_get.o
		gcc $(CFLAGS) queue.o test_get.o -o $@

test_remove: queue.o test_remove.o
		gcc $(CFLAGS) queue.o test_remove.o -o $@

test_close: queue.o test_close.o
		gcc $(CFLAGS) queue.o test_close.o -o $@

test_put:	queue.o test_put.o
			gcc $(CFLAGS) queue.o test_put.o -o $@

test_concat: queue.o test_concat.o
			gcc $(CFLAGS) queue.o test_concat.o -o $@

test_search: queue.o test_search.o
			gcc $(CFLAGS) queue.o test_search.o -o $@

clean:
		rm -f *.o test_apply test_remove test_put test_concat test_close test_get test_search
