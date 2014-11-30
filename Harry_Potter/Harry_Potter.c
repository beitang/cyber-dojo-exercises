#include <stdio.h>
#include "Harry_Potter.h"

#define MAX_BOOK 10
float min_money[MAX_BOOK][MAX_BOOK][MAX_BOOK][MAX_BOOK][MAX_BOOK] = {0};

float min(float n1, float n2)
{
   return n1 < n2? n1 : n2;
}

void init_min_money_array(void)
{
    int i, j, k, l, m;

    for (i = 0; i < MAX_BOOK; i++)
        for (j = 0; j <= i; j++)
            for (k = 0; k <= j; k++)
                for (l = 0; l <= k; l++)
                    for (m = 0; m <= l; m++)
                        min_money[i][j][k][l][m] = -1;

    min_money[0][0][0][0][0] = 0;
    min_money[1][0][0][0][0] = MONEY_FOR_ONE_BOOK;
    min_money[1][1][0][0][0] = MONEY_FOR_ONE_BOOK * 2 * DISCOUNT_FOR_TWO;
    min_money[1][1][1][0][0] = MONEY_FOR_ONE_BOOK * 3 * DISCOUNT_FOR_THREE;
    min_money[1][1][1][1][0] = MONEY_FOR_ONE_BOOK * 4 * DISCOUNT_FOR_FOUR;
    min_money[1][1][1][1][1] = MONEY_FOR_ONE_BOOK * 5 * DISCOUNT_FOR_FIVE;
}

float get_min_money(int num_book1, int num_book2, int num_book3, int num_book4, int num_book5)
{
    float ret_min_money;
    float f1 = 65535, f2 = 65535, f3 = 65535, f4 = 65535, f5 = 65535;

    printf("call now\n");
    if (min_money[num_book1][num_book2][num_book3][num_book4][num_book5] != -1)
    {
        ret_min_money =  min_money[num_book1][num_book2][num_book3][num_book4][num_book5];
    }
    else
    {
        if (num_book1 > 1) 
        {
            f1 = get_min_money(num_book1 - 1, num_book2, num_book3, num_book4, num_book5) + MONEY_FOR_ONE_BOOK;
            if (num_book2 > 1)
            {
                f2 = get_min_money(num_book1 - 1, num_book2 - 1, num_book3, num_book4, num_book5) + MONEY_FOR_ONE_BOOK * 2 * DISCOUNT_FOR_TWO;
                if (num_book3 > 1)
                {
                    f3 = get_min_money(num_book1 - 1, num_book2 - 1, num_book3 - 1, num_book4, num_book5) + MONEY_FOR_ONE_BOOK * 3 * DISCOUNT_FOR_THREE;
                    if (num_book4 > 1)
                    {
                        f4 = get_min_money(num_book1 - 1, num_book2 - 1, num_book3 - 1, num_book4 - 1, num_book5) + MONEY_FOR_ONE_BOOK * 4 * DISCOUNT_FOR_FOUR;
                        if (num_book5 > 1)
                        {
                            f5 = get_min_money(num_book1 - 1, num_book2 - 1, num_book3 - 1, num_book4 - 1, num_book5 - 1) + MONEY_FOR_ONE_BOOK * 5 * DISCOUNT_FOR_FIVE;
                        }
                    }
                }
            }
        }
        printf("f1 = %f, f2 = %f, f3 = %f, f4 = %f, f5 = %f\n", f1, f2, f3, f4, f5);
        ret_min_money = min(min(min(f1, f2), min(f3, f4)), f5);
    }

    printf("%d, %d, %d, %d, %d, %f\n", num_book1, num_book2, num_book2, num_book4, num_book5, ret_min_money);
    min_money[num_book1][num_book2][num_book3][num_book4][num_book5] = ret_min_money;

    return ret_min_money;
}
