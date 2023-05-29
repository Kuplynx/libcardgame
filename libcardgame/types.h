#ifndef TYPES
#define TYPES

typedef enum
{
    SPADE,
    HEART,
    DIAMOND,
    CLUB
} card_type;

typedef enum
{
    ACE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
} card_value;

typedef struct
{
    char *repr;
    char *name;
    card_type house;
    card_value value;
} CARD;

typedef enum
{
    PLAYER_SIDE = 0,
    DEALER_SIDE = 1,
    DECK_SIDE = 2
} card_position;

typedef struct
{
    CARD *cards;
    int size;
} HAND;

#endif