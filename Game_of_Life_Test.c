#include <assert.h>
#include <stdio.h>
#include "Game_of_Life.h"

int g_grid[ROW_NUM][COLUMN_NUM];
int test_expected_grid[ROW_NUM][COLUMN_NUM];

static void test_no_live_cell(void)
{
    memset(g_grid, 0, sizeof(g_grid));
    memset(test_expected_grid, 0, sizeof(test_expected_grid));

    create_generation();
    assert(memcmp(g_grid, test_expected_grid, sizeof(g_grid)) == 0);
}

static void test_one_live_cell(void)
{
    memset(g_grid, 0, sizeof(g_grid));
    g_grid[1][1] = 1;
    memset(test_expected_grid, 0, sizeof(test_expected_grid));

    create_generation();
    assert(memcmp(g_grid, test_expected_grid, sizeof(g_grid)) == 0);
}

static void test_three_live_cell_in_middle_row(void)
{
    memset(g_grid, 0, sizeof(g_grid));
    g_grid[1][1] = 1;
    g_grid[1][2] = 1;
    g_grid[1][3] = 1;
    memset(test_expected_grid, 0, sizeof(test_expected_grid));
    test_expected_grid[0][2] = 1;
    test_expected_grid[1][2] = 1;
    test_expected_grid[2][2] = 1;
    
    create_generation();
    assert(memcmp(g_grid, test_expected_grid, sizeof(g_grid)) == 0);
}

static void test_three_live_cell_in_first_row(void)
{
    memset(g_grid, 0, sizeof(g_grid));
    g_grid[0][1] = 1;
    g_grid[0][2] = 1;
    g_grid[0][3] = 1;
    memset(test_expected_grid, 0, sizeof(test_expected_grid));
    test_expected_grid[0][2] = 1;
    test_expected_grid[1][2] = 1;
    
    create_generation();
    assert(memcmp(g_grid, test_expected_grid, sizeof(g_grid)) == 0);
}

static void test_three_live_cell_in_last_row(void)
{
    memset(g_grid, 0, sizeof(g_grid));
    g_grid[ROW_NUM - 1][1] = 1;
    g_grid[ROW_NUM - 1][2] = 1;
    g_grid[ROW_NUM - 1][3] = 1;
    memset(test_expected_grid, 0, sizeof(test_expected_grid));
    test_expected_grid[ROW_NUM - 1][2] = 1;
    test_expected_grid[ROW_NUM - 2][2] = 1;
    
    create_generation();
    assert(memcmp(g_grid, test_expected_grid, sizeof(g_grid)) == 0);
}

static void test_three_live_cell_in_first_column(void)
{
    memset(g_grid, 0, sizeof(g_grid));
    g_grid[1][0] = 1;
    g_grid[2][0] = 1;
    g_grid[3][0] = 1;
    memset(test_expected_grid, 0, sizeof(test_expected_grid));
    test_expected_grid[2][0] = 1;
    test_expected_grid[2][1] = 1;
    
    create_generation();
    assert(memcmp(g_grid, test_expected_grid, sizeof(g_grid)) == 0);
}

static void test_three_live_cell_in_last_column(void)
{
    memset(g_grid, 0, sizeof(g_grid));
    g_grid[1][COLUMN_NUM - 1] = 1;
    g_grid[2][COLUMN_NUM - 1] = 1;
    g_grid[3][COLUMN_NUM - 1] = 1;
    memset(test_expected_grid, 0, sizeof(test_expected_grid));
    test_expected_grid[2][COLUMN_NUM - 1] = 1;
    test_expected_grid[2][COLUMN_NUM - 2] = 1;
    
    create_generation();
    assert(memcmp(g_grid, test_expected_grid, sizeof(g_grid)) == 0);
}

static void test_three_live_cell_in_upper_left_corner(void)
{
    memset(g_grid, 0, sizeof(g_grid));
    g_grid[0][0] = 1;
    g_grid[0][1] = 1;
    g_grid[1][0] = 1;
    memset(test_expected_grid, 0, sizeof(test_expected_grid));
    test_expected_grid[0][0] = 1;
    test_expected_grid[0][1] = 1;
    test_expected_grid[1][0] = 1;
    test_expected_grid[1][1] = 1;
    
    create_generation();
    assert(memcmp(g_grid, test_expected_grid, sizeof(g_grid)) == 0);
}

static void test_nine_live_cell_in_corner(void)
{
    memset(g_grid, 0, sizeof(g_grid));
    g_grid[0][0] = 1;
    g_grid[0][1] = 1;
    g_grid[0][2] = 1;
    g_grid[1][0] = 1;
    g_grid[1][1] = 1;
    g_grid[1][2] = 1;
    g_grid[2][0] = 1;
    g_grid[2][1] = 1;
    g_grid[2][2] = 1;
    memset(test_expected_grid, 0, sizeof(test_expected_grid));
    test_expected_grid[0][0] = 1;
    test_expected_grid[0][2] = 1;
    test_expected_grid[2][0] = 1;
    test_expected_grid[2][2] = 1;
    test_expected_grid[1][3] = 1;
    test_expected_grid[3][1] = 1;
    
    create_generation();
    assert(memcmp(g_grid, test_expected_grid, sizeof(g_grid)) == 0);
}

int main(void)
{
    test_no_live_cell();
    test_one_live_cell();
    test_three_live_cell_in_middle_row();
    test_three_live_cell_in_first_row();
    test_three_live_cell_in_last_row();
    test_three_live_cell_in_first_column();
    test_three_live_cell_in_last_column();
    test_three_live_cell_in_upper_left_corner();
    test_nine_live_cell_in_corner();
    puts("All tests passed");
}
