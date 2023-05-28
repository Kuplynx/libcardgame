#include <string.h>

#include "threebats.h"

GAME init_threebats()
{
    GAME __game;
    __game.dealer_facedown = (HAND *)malloc(sizeof(HAND));
    __game.dealer_faceup = (HAND *)malloc(sizeof(HAND));
    __game.dealer_hand = get_hand(6);
    __game.player_facedown = (HAND *)malloc(sizeof(HAND));
    __game.player_faceup = (HAND *)malloc(sizeof(HAND));
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

void print_hand(const HAND *hand)
{
    if (hand != NULL)
    {
        int screenHeight, screenWidth;
        getmaxyx(stdscr, screenHeight, screenWidth);

        int startY = (screenHeight - hand->size) / 2;

        for (int i = 0; i < hand->size; i++)
        {
            int nameLength = strlen(hand->cards[i].name);
            int startX = (screenWidth - nameLength) / 2;

            mvprintw(startY + i, startX, "%s", hand->cards[i].name);
        }
    }
}

int main(void)
{
    GAME game = init_threebats();
    init_game("Three Bats");
    print_hand(game.player_hand);
    getch();
    destroy_game();
    delete_threebats(&game);
}