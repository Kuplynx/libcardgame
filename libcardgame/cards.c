/* All card related functions */

#include "libcardgame.h"

/* Internal */
CARD *_get_random_card(void)
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

HAND *get_hand(int num_cards)
{
    HAND *__hand = (HAND *)malloc(sizeof(HAND));
    if (__hand == NULL)
        return NULL;
    __hand->size = num_cards;

    CARD *__cards = (CARD *)malloc(num_cards * sizeof(CARD));
    if (__cards == NULL)
    {
        free(__hand);
        return NULL;
    }

    for (int i = 0; i < num_cards; i++)
    {
        __cards[i] = *_get_random_card();
    }
    __hand->cards = __cards;
    return __hand;
}

/* Will likely never be used */
void remove_card(HAND *hand, int index)
{
        for (int i = index; i < hand->size - 1; i++)
        {
                hand->cards[i] = hand->cards[i + 1];
        }
        hand->size--;
}