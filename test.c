#include <libcardgame.h>

#include <stdlib.h>
#include <assert.h>
#include <ncurses.h>

int main(void)
{
    /* Test generating random cards and correct memory management */
    init_game("Three Bats!");
    HAND pfdc; 
    get_hand(&pfdc, 3);
    destroy_game();
    return 0;
}