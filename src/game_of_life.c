#include <stdlib.h>
#include <raylib.h>
#include "config.def.h"

void randomize_grid(int grid[GRID_SIZE][GRID_SIZE])
{
	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE; ++j) {
			grid[i][j] = rand() % 2;
		}
	}
}

void display_grid(int grid[GRID_SIZE][GRID_SIZE])
{
	int cellWidth = SCREEN_WIDTH / GRID_SIZE;
	int cellHeight = SCREEN_HEIGHT / GRID_SIZE;

	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE; ++j) {
			if (grid[i][j] == 1) {
				DrawRectangle(j * cellWidth, i * cellHeight, cellWidth, cellHeight, BLACK);
			} else {
				DrawRectangleLines(j * cellWidth, i * cellHeight, cellWidth, cellHeight, DARKGRAY);
			}
		}
	}
}

int count_neighbors(int grid[GRID_SIZE][GRID_SIZE], int x, int y)
{
	int count = 0;
	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {
			if (i == 0 && j == 0) continue;
			int nx = x + i;
			int ny = y + j;
			if (nx >= 0 && nx < GRID_SIZE && ny >= 0 && ny < GRID_SIZE) {
				count += grid[nx][ny];
			}
		}
	}
	return count;
}

void update_grid(int grid[GRID_SIZE][GRID_SIZE])
{
	int new_grid[GRID_SIZE][GRID_SIZE];
	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE; ++j) {
			int neighbors = count_neighbors(grid, i, j);
			if (grid[i][j] == 1) {
				new_grid[i][j] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
			} else {
				new_grid[i][j] = (neighbors == 3) ? 1 : 0;
			}
		}
	}

	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE; ++j) {
			grid[i][j] = new_grid[i][j];
		}
	}
}

int all_cells_dead(int grid[GRID_SIZE][GRID_SIZE])
{
	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE; ++j) {
			if (grid[i][j] == 1) {
				return 0;
			}
		}
	}
	return 1;
}
