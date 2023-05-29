#include "threebats.h"

GAME threebats_init()
{
    GAME __game;
    __game.dealer_facedown = get_hand(3);
    __game.dealer_faceup = get_hand(3);
    __game.dealer_hand = get_hand(6);
    __game.player_facedown = get_hand(3);
    __game.player_faceup = get_hand(3);
    __game.player_hand = get_hand(6);
    return __game;
}

void delete_threebats(GAME *game)
{
    delete_hand(game->dealer_facedown);
    delete_hand(game->dealer_faceup);
    delete_hand(game->dealer_hand);
    delete_hand(game->player_facedown);
    delete_hand(game->player_faceup);
    delete_hand(game->player_hand);
}

int main(void)
{
    GAME game = threebats_init();
    init_game("Three Bats");
    bool result = threebats_loop(&game);

    getch();
    destroy_game();
    delete_threebats(&game);
}