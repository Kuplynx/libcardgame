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