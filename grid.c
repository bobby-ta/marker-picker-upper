#include <stdlib.h>
#include "randomnum.h"
#include "global.h"
#include <stdio.h>

char **grid; // Pointer to a 2D array of characters
int grid_width;
int grid_height;

void initialiseGrid() {
    grid_width = randomNum(7, WIN_WIDTH / TILE_SIZE);  // Determine grid width
    grid_height = randomNum(7, WIN_HEIGHT / TILE_SIZE); // Determine grid height

    // Allocate memory for the grid
    grid = malloc(grid_height * sizeof(char*)); // Allocate memory for rows
    for (int i = 0; i < grid_height; i++) {
        grid[i] = malloc(grid_width * sizeof(char)); // Allocate memory for each row
    }
}

void updateGrid(Coord *marker) {
    for (int i = 0; i < grid_height; i++) {
        for (int j = 0; j < grid_width; j++) {
            if (i == 0 || i == grid_height - 1 || j == 0 || j == grid_width - 1) {
                grid[i][j] = 'w'; // 'w' for wall
            } else if (i == marker->y && j == marker->x) {
                grid[i][j] = 'm'; // 'm' for marker
            } else {
                grid[i][j] = 'e'; // 'e' for empty
            }
        }
    }
}

void freeGrid() {
    for (int i = 0; i < grid_height; i++) {
        free(grid[i]); // Free each row
    }
    free(grid); // Free the array of row pointers
}

