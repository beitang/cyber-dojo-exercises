#ifndef HARRY_POTTER_INCLUDED
#define HARRY_POTTER_INCLUDED

#include <string.h>

#define MONEY_FOR_ONE_BOOK 8
#define DISCOUNT_FOR_TWO 0.95
#define DISCOUNT_FOR_THREE 0.90
#define DISCOUNT_FOR_FOUR 0.80
#define DISCOUNT_FOR_FIVE 0.75

void init_min_money_array(void);
float get_min_money(int num_book1, int num_book2, int num_book3, int num_book4, int num_book5);

#endif
