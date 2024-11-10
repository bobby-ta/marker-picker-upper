#include <stdlib.h>
#include "randomnum.h"
#include "global.h"
#include <stdio.h>

char **grid;
int grid_width;
int grid_height;

void initialiseGrid() {
    grid_width = randomNum(7, WIN_WIDTH / TILE_SIZE); 
    grid_height = randomNum(7, WIN_HEIGHT / TILE_SIZE); 

    grid = malloc(grid_height * sizeof(char*)); 
    for (int i = 0; i < grid_height; i++) {
        grid[i] = malloc(grid_width * sizeof(char));
    }
}

void designGrid(Coord *marker) {
    for (int i = 0; i < grid_height; i++) {
        for (int j = 0; j < grid_width; j++) {
            if (i == 0 || i == grid_height - 1 || j == 0 || j == grid_width - 1) {
                grid[i][j] = 'w'; //wall
            } else if (i == marker->y && j == marker->x) {
                grid[i][j] = 'm'; //marker
            } else {
                if ((rand() % 100) < 20) {
                    grid[i][j] = 'o'; //obstacle
                } else {
                    grid[i][j] = 'e'; //empty
                }
            }
        }
    }
}

void updateMarker(Coord *marker) {
    for (int i = 0; i < grid_height; i++) {
        for (int j = 0; j < grid_width; j++) {
            if (i == marker->y && j == marker->x) {
                grid[i][j] = 'm'; //if marker has been dropped then display
            } else if (grid[i][j] != 'o' && grid[i][j] != 'w') {
                grid[i][j] = 'e'; //if marker has been picked then don't display
            }
        }
    }
}

void freeGrid() {
    for (int i = 0; i < grid_height; i++) {
        free(grid[i]);
    }
    free(grid);
}

