#include <stdio.h>
#include "Game_of_Life.h"

extern int g_grid[ROW_NUM][COLUMN_NUM];

int g_parent_grid[ROW_NUM + 2][COLUMN_NUM + 2];

int neighour_num_to_state_mapping[2][9] = {{0, 0, 0, 1, 0, 0, 0, 0, 0}, 
                                           {0, 0, 1, 1, 0, 0, 0, 0, 0}};

int get_live_neighbor_num(int r, int c);

void update_cell(int r, int c);

void copy_grid_to_large_parent_grid(void);

int get_live_neighbor_num(int r, int c)
{
    return (g_parent_grid[r][c] + g_parent_grid[r][c + 1] + g_parent_grid[r][c + 2]
           + g_parent_grid[r + 1][c] + g_parent_grid[r + 1][c + 2]
           + g_parent_grid[r + 2][c] + g_parent_grid[r + 2][c + 1] + g_parent_grid[r + 2][c + 2]);
}

void update_cell(int r, int c)
{
    int neighbor_sum = 0;

    neighbor_sum = get_live_neighbor_num(r, c);

    g_grid[r][c] = neighour_num_to_state_mapping[g_grid[r][c]][neighbor_sum];

    return;
}

void copy_grid_to_large_parent_grid(void)
{
    int r = 0;
    int c = 0;
    
    memset(g_parent_grid, 0, sizeof(g_parent_grid));
    for(; r < ROW_NUM; r++)
    {
        for(c = 0; c < COLUMN_NUM; c++)
        {
            g_parent_grid[r + 1][c + 1] = g_grid[r][c];
        }
    }

    return;
}

void create_generation(void)
{
    int r = 0;
    int c = 0;

    copy_grid_to_large_parent_grid();

    for(r = 0; r < ROW_NUM; r++)
    {
        for(c = 0; c < COLUMN_NUM; c++)
        {
            update_cell(r, c);
        }
    }

    return;
}
