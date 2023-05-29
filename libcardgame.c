#include "libcardgame.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>
#include <ncurses.h>
#include <locale.h>
#include <sys/random.h>

CARD _cards[52] = {
    {.name = "Ace of Spades",
     .repr = "A♠",
     .house = SPADE,
     .value = ACE},
    {.name = "Two of Spades",
     .repr = "2♠",
     .house = SPADE,
     .value = TWO},
    {.name = "Three of Spades",
     .repr = "3♠",
     .house = SPADE,
     .value = THREE},
    {.name = "Four of Spades",
     .repr = "4♠",
     .house = SPADE,
     .value = FOUR},
    {.name = "Five of Spades",
     .repr = "5♠",
     .house = SPADE,
     .value = FIVE},
    {.name = "Six of Spades",
     .repr = "6♠",
     .house = SPADE,
     .value = SIX},
    {.name = "Seven of Spades",
     .repr = "7♠",
     .house = SPADE,
     .value = SEVEN},
    {.name = "Eight of Spades",
     .repr = "♠8",
     .house = SPADE,
     .value = EIGHT},
    {.name = "Nine of Spades",
     .repr = "9♠",
     .house = SPADE,
     .value = NINE},
    {.name = "Ten of Spades",
     .repr = "10♠",
     .house = SPADE,
     .value = TEN},
    {.name = "Jack of Spades",
     .repr = "J♠",
     .house = SPADE,
     .value = JACK},
    {.name = "Queen of Spades",
     .repr = "Q♠",
     .house = SPADE,
     .value = QUEEN},
    {.name = "King of Spades",
     .repr = "K♠",
     .house = SPADE,
     .value = KING},
    {.name = "Ace of Hearts",
     .repr = "A♥",
     .house = HEART,
     .value = ACE},
    {.name = "Two of Hearts",
     .repr = "2♥",
     .house = HEART,
     .value = TWO},
    {.name = "Three of Hearts",
     .repr = "3♥",
     .house = HEART,
     .value = THREE},
    {.name = "Four of Hearts",
     .repr = "4♥",
     .house = HEART,
     .value = FOUR},
    {.name = "Five of Hearts",
     .repr = "5♥",
     .house = HEART,
     .value = FIVE},
    {.name = "Six of Hearts",
     .repr = "6♥",
     .house = HEART,
     .value = SIX},
    {.name = "Seven of Hearts",
     .repr = "7♥",
     .house = HEART,
     .value = SEVEN},
    {.name = "Eight of Hearts",
     .repr = "8♥",
     .house = HEART,
     .value = EIGHT},
    {.name = "Nine of Hearts",
     .repr = "9♥",
     .house = HEART,
     .value = NINE},
    {.name = "Ten of Hearts",
     .repr = "10♥",
     .house = HEART,
     .value = TEN},
    {.name = "Jack of Hearts",
     .repr = "J♥",
     .house = HEART,
     .value = JACK},
    {.name = "Queen of Hearts",
     .repr = "Q♥",
     .house = HEART,
     .value = QUEEN},
    {.name = "King of Hearts",
     .repr = "K♥",
     .house = HEART,
     .value = KING},
    {.name = "Ace of Diamonds",
     .repr = "A♦",
     .house = DIAMOND,
     .value = ACE},
    {.name = "Two of Diamonds",
     .repr = "2♦",
     .house = DIAMOND,
     .value = TWO},
    {.name = "Three of Diamonds",
     .repr = "3♦",
     .house = DIAMOND,
     .value = THREE},
    {.name = "Four of Diamonds",
     .repr = "4♦",
     .house = DIAMOND,
     .value = FOUR},
    {.name = "Five of Diamonds",
     .repr = "5♦",
     .house = DIAMOND,
     .value = FIVE},
    {.name = "Six of Diamonds",
     .repr = "6♦",
     .house = DIAMOND,
     .value = SIX},
    {.name = "Seven of Diamonds",
     .repr = "7♦",
     .house = DIAMOND,
     .value = SEVEN},
    {.name = "Eight of Diamonds",
     .repr = "8♦",
     .house = DIAMOND,
     .value = EIGHT},
    {.name = "Nine of Diamonds",
     .repr = "9♦",
     .house = DIAMOND,
     .value = NINE},
    {.name = "Ten of Diamonds",
     .repr = "10♦",
     .house = DIAMOND,
     .value = TEN},
    {.name = "Jack of Diamonds",
     .repr = "J♦",
     .house = DIAMOND,
     .value = JACK},
    {.name = "Queen of Diamonds",
     .repr = "Q♦",
     .house = DIAMOND,
     .value = QUEEN},
    {.name = "King of Diamonds",
     .repr = "K♦",
     .house = DIAMOND,
     .value = KING},
    {.name = "Ace of Clubs",
     .repr = "A♣",
     .house = CLUB,
     .value = ACE},
    {.name = "Two of Clubs",
     .repr = "2♣",
     .house = CLUB,
     .value = TWO},
    {.name = "Three of Clubs",
     .repr = "3♣",
     .house = CLUB,
     .value = THREE},
    {.name = "Four of Clubs",
     .repr = "4♣",
     .house = CLUB,
     .value = FOUR},
    {.name = "Five of Clubs",
     .repr = "5♣",
     .house = CLUB,
     .value = FIVE},
    {.name = "Six of Clubs",
     .repr = "6♣",
     .house = CLUB,
     .value = SIX},
    {.name = "Seven of Clubs",
     .repr = "7♣",
     .house = CLUB,
     .value = SEVEN},
    {.name = "Eight of Clubs",
     .repr = "8♣",
     .house = CLUB,
     .value = EIGHT},
    {.name = "Nine of Clubs",
     .repr = "9♣",
     .house = CLUB,
     .value = NINE},
    {.name = "Ten of Clubs",
     .repr = "10♣",
     .house = CLUB,
     .value = TEN},
    {.name = "Jack of Clubs",
     .repr = "J♣",
     .house = CLUB,
     .value = JACK},
    {.name = "Queen of Clubs",
     .repr = "Q♣",
     .house = CLUB,
     .value = QUEEN},
    {.name = "King of Clubs",
     .repr = "K♣",
     .house = CLUB,
     .value = KING}};

/* Internal */
int random_int(void)
{
        static int max = 52;
        if (max == 0)
        {
                printf("Error: Ran out of cards!\n");
                exit(1);
        }
        int result = random() % max;
        max--;
        return result;
}

/* Internal */
CARD *get_random_card(void)
{
        static CARD cards[52];
        static int cc = 52;
        static bool initialized = false;
        if (!initialized)
        {
                memcpy(&cards, _cards, sizeof(_cards));
                initialized = true;
        }
        int index = random_int();
        CARD card = cards[index];
        CARD end = cards[cc - 1];
        cards[index] = end;
        CARD new_cards[cc];
        for (int i = 0; i < cc - 1; i++)
        {
                new_cards[i] = cards[i];
        }
        memcpy(&cards, &new_cards, sizeof(new_cards));
        cc--;
        CARD *ptr = &card;
        return ptr;
}

void *init_game(char *msg)
{
        setlocale(LC_ALL, "");
        srand(time(NULL) * 2 * 32 / 1.3134568734985);
        initscr();
        keypad(stdscr, TRUE);
        start_color();
        init_pair(1, COLOR_MAGENTA, COLOR_WHITE);
        gprint(DECK_SIDE, msg);
        getch();
        clear();
}

void *destroy_game(void)
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

HAND *get_hand(int num_cards)
{
        HAND *__hand = malloc(sizeof(HAND));
        if (__hand == NULL)
                return NULL;
        __hand->size = num_cards;

        CARD *__cards = malloc(num_cards * sizeof(CARD));
        if (__cards == NULL)
        {
                free(__hand);
                return NULL;
        }

        for (int i = 0; i < num_cards; i++)
        {
                __cards[i] = *get_random_card();
        }
        __hand->cards = __cards;
        return __hand;
}

void delete_hand(HAND *hand)
{
        if (hand != NULL)
        {
                free(hand->cards);
                free(hand);
        }
}

void *remove_card(HAND *hand, int index)
{
        for (int i = index; i < hand->size - 1; i++)
        {
                hand->cards[i] = hand->cards[i + 1];
        }
        hand->size--;
}

void *gprint(card_position side, char *_msg, ...)
{
        char *msg = "Unknown error occured!";
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
