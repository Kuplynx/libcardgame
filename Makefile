CC=gcc
CFLAGS=-std=c99 -shared -fPIC
LDFLAGS=-lncursesw

all: clean libcardgame.so

clean:
	rm -f libcardgame.so

# Optional building as shared object
libcardgame.so:
	$(info Building libcardgame.so...)
	$(CC) $(CFLAGS)  -o libcardgame.so ./libcardgame/libcardgame.c $(LDFLAGS)