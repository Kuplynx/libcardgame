#include <string.h>
#include "../../libcardgame/libcardgame.h"

#define PLAYER_TURN 0
#define DEALER_TURN 1

typedef struct
{
    /* Yes I know this is a ridiculous amount of HANDs, eventually it will just be {PLAYER *player, DEALER *dealer, DECK *deck) */
    HAND *dealer_facedown;
    HAND *dealer_faceup;
    HAND *dealer_hand;
    HAND *player_facedown;
    HAND *player_faceup;
    HAND *player_hand;
    HAND *deck_storage;
    HAND *deck_faceup;

} GAME;

void threebats_gprint(bool player, bool bat, bool msg, char *_msg, ...);

void threebats_print_hand(bool player, bool bat, HAND *hand);

bool threebats_loop(GAME *game);