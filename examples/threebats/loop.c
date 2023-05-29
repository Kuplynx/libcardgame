/* Implements the loop */

#include "threebats.h"

bool threebats_loop(GAME *game) {
    threebats_print_hand(true, true, game->player_faceup);
    threebats_print_hand(true, false, game->player_hand);
    threebats_print_hand(false, true, game->dealer_faceup);
    threebats_gprint()

}