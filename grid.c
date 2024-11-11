#include <stdlib.h>
#include "global.h"
#include <stdio.h>

char **grid;
int grid_width;
int grid_height;

void setGridSize() {
    grid_width = (rand() % 9) + 7;
    grid_height = (rand() % 9) + 7; 
}

void initialiseGrid(Coord *markers, int marker_count) {
    grid = malloc(grid_height * sizeof(char*)); 
    for (int i = 0; i < grid_height; i++) {
        grid[i] = malloc(grid_width * sizeof(char));
    }

    for (int i = 0; i < grid_height; i++) {
        for (int j = 0; j < grid_width; j++) {
            if (i == 0 || i == grid_height - 1 || j == 0 || j == grid_width - 1) {
                grid[i][j] = 'w'; //wall
            } else {
                if ((rand() % 100) < 20) {
                    grid[i][j] = 'o'; //obstacle
                } else {
                    grid[i][j] = 'e'; //empty
                }
            }
        }
    }
    //Inefficient but avoids overwriting markers
    for (int i = 0; i < marker_count; i++) {
        grid[markers[i].y][markers[i].x] = 'm'; //marker
    }
}

void freeGrid() {
    for (int i = 0; i < grid_height; i++) {
        free(grid[i]);
    }
    free(grid);
}

