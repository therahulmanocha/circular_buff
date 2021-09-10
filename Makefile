CC=g++
CFLAGS=-I.
DEPS = circbuff_api.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

make: test.o circbuff_api.o
	$(CC) -o test test.o circbuff_api.o
