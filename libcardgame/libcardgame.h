#ifndef LIBCARDGAME_H
#define LIBCARDGAME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <stdarg.h>
#include <ncurses.h>

#include "types.h"
#include "cardset.h"


/* Card related functions */

HAND *get_hand(int num_cards);

void delete_hand(HAND *hand);

void remove_card(HAND *hand, int index);

/* Initialize and destroy game */

void init_game(char *msg);

void destroy_game(void);

/* Game and UI functions */

void *gprint(card_position side, char *_msg, ...);

/* Internal Functions*/

int random_int(void);


#endif