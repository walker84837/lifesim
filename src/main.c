#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <ncurses.h>
#include <stdlib.h>
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
	int ch;

	srand(time(NULL));
	randomize_grid(grid);

	initscr();
	cbreak();
	noecho();
	curs_set(FALSE);
	nodelay(stdscr, TRUE);

	for (steps = 0;; ++steps) {
		clear();
		display_grid(grid);
		refresh();

		if ((ch = getch()) == 'q') {
			break;
		}

		if (all_cells_dead(grid)) {
			break;
		}

		update_grid(grid);
		usleep((int)(1000000 / config.speed));
	}

	endwin();
	return 0;
}

void process_input(int argc, char *argv[], args_t *config)
{
	if (argc == 1) {
		goto help;
	}

	int opt;
	static struct option long_options[] = {
		{"speed", required_argument, 0, 's'},
		// {"some_other_option", required_argument, 0, 'o'},
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
				goto help;
				break;
			default:
				goto help;
		}
	}

help:
	fprintf(stderr, "Usage: %s [-s <speed>] \n", argv[0]);
	fputs("  --speed, -s  The speed of the simulation of Conway's Game of Life (1x, 2.5x, ...)\n", stderr);
	exit(EXIT_FAILURE);
}
