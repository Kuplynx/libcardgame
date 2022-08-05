#include <libcardgame.h>

#include <stdlib.h>
#include <assert.h>
#include <ncurses.h>

int main(void) {
    /* Test generating random cards and correct memory management */
    init_game();
    HAND hand;
    get_hand(&hand, 5);
    gprint(PLAYER_SIDE, hand.cards[0].name);
    destroy_game();
    return 0;
}