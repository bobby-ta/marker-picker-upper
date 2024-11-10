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

void updateGrid(Coord *marker) {
    for (int i = 0; i < grid_height; i++) {
        for (int j = 0; j < grid_width; j++) {
            if (i == 0 || i == grid_height - 1 || j == 0 || j == grid_width - 1) {
                grid[i][j] = 'w'; //wall
            } else if (i == marker->y && j == marker->x) {
                grid[i][j] = 'm'; //marker
            } else {
                grid[i][j] = 'e'; //empty
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

