#include "libcardgame.h"

#include <locale.h>
#include <sys/random.h>

void init_game(char *msg)
{
        setlocale(LC_ALL, "");
        srand(time(NULL));
        initscr();
        raw();
        keypad(stdscr, TRUE);
        start_color();
        init_pair(1, COLOR_MAGENTA, COLOR_WHITE);
        gprint(DECK_SIDE, msg);
        getch();
        clear();
}

void destroy_game(void)
{
        clear();
        int row, col;
        getmaxyx(stdscr, row, col);
        char *str = "Press any key to exit...";
        mvprintw(row / 2, (col - strlen(str)) / 2, str);
        refresh();
        getch();
        endwin();
}

void delete_hand(HAND *hand)
{
        if (hand != NULL)
        {
                free(hand->cards);
                free(hand);
        }
}

/* Generic print function provided, most games will need their own
   Format insecurity not much of an issue and needed for functionality*/
void *gprint(card_position side, char *_msg, ...)
{
        char *msg;
        va_list args;
        va_start(args, _msg);
        vasprintf(&msg, _msg, args);
        va_end(args);
        int row, col;
        getmaxyx(stdscr, row, col);
        switch (side)
        {
        case PLAYER_SIDE:
        {
                mvprintw(row - 1, (col - strlen(msg)) / 2, msg);
                break;
        }
        case DEALER_SIDE:
        {
                mvprintw(0, (col - strlen(msg)) / 2, msg);
                break;
        }
        case DECK_SIDE:
        {
                mvprintw(row / 2, (col - strlen(msg)) / 2, msg);
                break;
        }
        }
        getch();
}

void *card_choice(HAND *hand, HAND *result, int num_cards)
{
        attron(COLOR_PAIR(1));
        getch();
        attroff(COLOR_PAIR(1));
}
