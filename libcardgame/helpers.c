#include "libcardgame.h"

/* Not sure if this is flexible enough yet */
int random_int(void)
{
        static int max = CARD_COUNT;
        if (max == 0)
        {
                printf("Error: Ran out of cards!\n");
                exit(1);
        }
        int result = rand() % max;
        max--;
        return result;
}
