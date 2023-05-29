#include <string.h>

#include "../../libcardgame.h"

#define PLAYER_TURN 0
#define DEALER_TURN 1

typedef struct
{
    HAND *dealer_facedown;
    HAND *dealer_faceup;
    HAND *dealer_hand;
    HAND *player_facedown;
    HAND *player_faceup;
    HAND *player_hand;

} GAME;

void threebats_gprint(bool player, bool bat, char *_msg, ...);

void threebats_print_hand(bool player, bool bat, HAND *hand);

bool threebats_loop(GAME *game);