CC=gcc
CFLAGS=-std=c99
LDFLAGS=-lncursesw

# In most cases building libcardgame directly into the binary makes more sense
internal:
	$(CC) $(CFLAGS) ../../libcardgame/libcardgame.c ../../libcardgame/cards.c ../../libcardgame/helpers.c ../../libcardgame/cardset.c ./threebats.c ./cards.c ./loop.c ./dealer.c -o threebats $(LDFLAGS)