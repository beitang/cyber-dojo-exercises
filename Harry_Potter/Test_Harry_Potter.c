#include <assert.h>
#include <stdio.h>
#include "Harry_Potter.h"

static void test_buy_one_book(void)
{
    assert(get_min_money(1, 0, 0, 0, 0) == 8);
}

static void test_buy_two_different_books(void)
{
    assert(get_min_money(1, 1, 0, 0, 0) == (float)(8 * 2 * 0.95));
}

int main(void)
{
    test_buy_one_book();
    test_buy_two_different_books();
    puts("All tests passed");
}
