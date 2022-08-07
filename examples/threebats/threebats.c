#include "../../libcardgame.h"

int main(void) 
{
    init_game("Three Bats!");
    HAND pfdc;
    get_hand(&pfdc, 3);
    HAND dfdc;
    get_hand(&dfdc, 3);
    HAND ph;
    get_hand(&ph, 6);
    HAND dh;
    get_hand(&dh, 6);
    gprint(PLAYER_SIDE, "%s, %s, %s, %s, %s, %s", 
    ph.cards[0].name, 
    ph.cards[1].name,
    ph.cards[2].name,
    ph.cards[3].name,
    ph.cards[4].name,
    ph.cards[5].name);
    HAND pfuc;
    card_choice(&ph, &pfuc, 3, 2);
    getch();
    destroy_game();
}   