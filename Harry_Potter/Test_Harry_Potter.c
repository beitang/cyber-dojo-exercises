#include <assert.h>
#include <stdio.h>
#include "Harry_Potter.h"

static void test_buy_one_book(void)
{
    assert(get_min_money(1, 0, 0, 0, 0) == MONEY_FOR_ONE_BOOK);
}

static void test_buy_two_different_books(void)
{
    assert(get_min_money(1, 1, 0, 0, 0) == (float)(MONEY_FOR_ONE_BOOK * 2 * DISCOUNT_FOR_TWO));
}

static void test_buy_three_different_books(void)
{
    assert(get_min_money(1, 1, 1, 0, 0) == (float)(MONEY_FOR_ONE_BOOK * 3 * DISCOUNT_FOR_THREE));
}

static void test_buy_four_different_books(void)
{
    assert(get_min_money(1, 1, 1, 1, 0) == (float)(MONEY_FOR_ONE_BOOK * 4 * DISCOUNT_FOR_FOUR));
}

static void test_buy_five_different_books(void)
{
    assert(get_min_money(1, 1, 1, 1, 1) == (float)(MONEY_FOR_ONE_BOOK * 5 * DISCOUNT_FOR_FIVE));
}

static void test_buy_three_books(void)
{
    assert(get_min_money(2, 1, 0, 0, 0) == (float)(MONEY_FOR_ONE_BOOK * 2 * DISCOUNT_FOR_TWO + MONEY_FOR_ONE_BOOK));
}

static void test_buy_example_books_in_order(void)
{
    assert(get_min_money(2, 2, 2, 1, 1) == (float)(51.599998));
}

static void test_buy_example_books_not_in_order(void)
{
    assert(get_min_money(2, 1, 2, 1, 2) == (float)(51.599998));
}

int main(void)
{
    init_min_money_array();
    test_buy_one_book();
    test_buy_two_different_books();
    test_buy_three_different_books();
    test_buy_four_different_books();
    test_buy_five_different_books();
    test_buy_three_books();
    test_buy_example_books_in_order();
    test_buy_example_books_not_in_order();
    puts("All tests passed");
}
