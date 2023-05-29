/* Implements logic behind the bats/rats */

#include "threebats.h"

void threebats_gprint(bool player, bool bat, bool msg, char *_msg, ...)
{
    va_list args;
    va_start(args, _msg);
    int row, col;
    getmaxyx(stdscr, row, col);

    if (player)
    {
        row = bat ? row - 2 : row - 3;
        row = msg ? row - 1 : row;
        if (bat)
            row -= 2;
        if (msg)
            row -= 1;
        else
            row -= 3;
        mvprintw(row, (col - strlen(_msg)) / 2, _msg, args);
    }
    else
    {
        row = bat ? 1 : 2;
        mvprintw(row, (col - strlen(_msg)) / 2, _msg, args);
    }
    va_end(args);
}

void threebats_print_hand(bool player, bool bat, HAND *hand)
{
    int totalLength = 0;

    for (int i = 0; i < hand->size; i++)
    {
        totalLength += strlen(hand->cards[i].repr) + 1;
    }

    char *string = (char *)malloc((totalLength + 1) * sizeof(char));

    int index = 0;
    for (int i = 0; i < hand->size; i++)
    {
        char *repr = hand->cards[i].repr;
        int reprLength = strlen(repr);
        strncpy(string + index, repr, reprLength);
        index += reprLength;
        string[index] = ' ';
        index++;
    }
    string[totalLength - 1] = '\0';

    threebats_gprint(player, bat, false, string);
}