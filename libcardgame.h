#ifndef LIBCARDGAME_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>

typedef enum {
    SPADE,
    HEART,
    DIAMOND,
    CLUB
} card_type;

typedef enum {
    ACE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
} card_value;

typedef struct {
    char *repr;
    char *name;
    card_type house;
    card_value value;
} CARD;

typedef enum {
    PLAYER_SIDE = 0,
    DEALER_SIDE = 1,
    DECK_SIDE = 2
} card_position;

typedef struct {
    CARD *cards;
    int size;
} HAND;


/* Card related functions */

void *get_hand(HAND* hand, int num_cards);

void *remove_card(HAND* hand, int index);

void *card_choice(HAND *hand, HAND *result, int num_cards, int cur_choice);

/* Initialize and destroy game and all related components */

void *init_game(char* msg);

void *destroy_game(void);

/* Game and UI functions */

void *gprint(card_position side, char* _msg, ...);


#endif // !LIBCARDGAME