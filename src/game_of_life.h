#ifndef GAME_OF_LIFE_H_
#define GAME_OF_LIFE_H_

#include "config.def.h"

void initialize_grid(int grid[GRID_SIZE][GRID_SIZE]);
void randomize_grid(int grid[GRID_SIZE][GRID_SIZE]);
void display_grid(int grid[GRID_SIZE][GRID_SIZE]);
void update_grid(int grid[GRID_SIZE][GRID_SIZE]);
int count_neighbors(int grid[GRID_SIZE][GRID_SIZE], int x, int y);
int all_cells_dead(int grid[GRID_SIZE][GRID_SIZE]);

#endif  // GAME_OF_LIFE_H_
