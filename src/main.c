#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <getopt.h>
#include "raylib.h"
#include "game_of_life.h"
#include "config.def.h"

typedef struct {
	float speed;
} args_t;

void process_input(int argc, char **argv, args_t *config);

int main(int argc, char **argv)
{
	args_t config = { .speed = DEFAULT_SPEED };
	process_input(argc, argv, &config);

	int grid[GRID_SIZE][GRID_SIZE];
	int steps;

	srand(time(NULL));
	randomize_grid(grid);

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "LifeSim: Conway's Game of Life");

	SetTargetFPS((int)(config.speed * 3.6));

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);

		display_grid(grid);

		if (all_cells_dead(grid)) {
			break;
		}

		update_grid(grid);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}

void print_usage()
{
	fprintf(stderr, "Usage: lifesim [-s <speed>] \n");
	fputs("  --speed, -s  The speed of the simulation of Conway's Game of Life (1x, 2.5x, ...)\n", stderr);
	exit(EXIT_FAILURE);
}

void process_input(int argc, char *argv[], args_t *config)
{
	int opt;
	static struct option long_options[] = {
		{"speed", required_argument, 0, 's'},
		{0, 0, 0, 0}
	};

	while ((opt = getopt_long(argc, argv, "s:h", long_options, NULL)) != -1) {
		switch (opt) {
			case 's':
				config->speed = atof(optarg);
				if (config->speed <= 0) {
					fprintf(stderr, "Invalid speed: speed must be a positive number.\n");
					exit(EXIT_FAILURE);
				}
				break;
			case 'h':
				print_usage();
			default:
				print_usage();
		}
	}

	if (optind < argc) {
		print_usage();
	}
}
