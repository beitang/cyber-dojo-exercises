#include <stdio.h>
#include "Harry_Potter.h"

#define MAX_BOOK 10
float min_money[MAX_BOOK][MAX_BOOK][MAX_BOOK][MAX_BOOK][MAX_BOOK];

float get_min_money(int num_book1, int num_book2, int num_book3, int num_book4, int num_book5)
{
    if (num_book1 + num_book2 == 1)
        return 8;
    if (num_book1 + num_book2 == 2)
        return 8 * 2 * 0.95;
}
