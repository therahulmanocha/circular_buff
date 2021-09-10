CC=g++
CFLAGS=-I.
DEPS = circbuff_api.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

make: test.o circbuff_api.o
	$(CC) -o runtest test.o circbuff_api.o

.PHONY: clean

clean:
	rm -f *.o runtest
