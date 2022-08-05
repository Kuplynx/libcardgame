CC=gcc
CFLAGS=-std=c99 -shared -fPIC
LDFLAGS=-lncursesw

all: clean libcardgame.so test

clean:
	rm -f libcardgame.so

libcardgame.so:
	$(info Building libcardgame.so...)
	$(CC) $(CFLAGS) $(LDFLAGS) -o libcardgame.so libcardgame.c

test:
	$(info Testing linking...)
	$(CC) -I. -L. -Wl,-rpath=$(shell pwd) -o tests test.c -lcardgame -lncursesw
	$(info Testing funcionality...)
	./tests
	rm tests