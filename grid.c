#include <stdlib.h>
#include "randomnum.h"
#include "global.h"
#include <stdio.h>

int grid_width;
int grid_height;
char ***grid;

void initialiseGrid() {
    grid_width = randomNum(7, WIN_WIDTH / TILE_SIZE); //inc. walls
    grid_height = randomNum(7, WIN_HEIGHT / TILE_SIZE);

    grid = malloc(grid_height * sizeof(char**)); //each column is an array of pointers to pointers (rows) to strings

    for (int i = 0; i < grid_height; i++) {
        grid[i] = malloc(grid_width * sizeof(char*)); //each row is an array of pointers to strings
        for (int j = 0; j < grid_width; j++) {
            grid[i][j] = malloc(7 * sizeof(char)); //'empty'/'wall'/'obst'/'marker' take up max 6 characters, + \0
        }
    }
}

void updateGrid(Coord *marker) {
    for (int i = 0; i < grid_height; i++) {
        for (int j = 0; j < grid_width; j++) {
            if (i == 0 || i == grid_height - 1 || j == 0 || j == grid_width - 1) {
                snprintf(grid[i][j], 5, "wall");
            } else if (i == marker->y && j == marker->x){
                snprintf(grid[i][j], 7, "marker");
            } //ADD OBSTACLES LATER
            else {
                snprintf(grid[i][j], 6, "empty");
            }
            //printf("%s", grid[i][j]);
        }
        //printf("%c", '\n');
    }
}

void freeGrid() {
    for (int i = 0; i < grid_height; i++) {
        for (int j = 0; j < grid_width; j++) {
            free(grid[i][j]);
        }
        free(grid[i]);
    }
    free(grid);
}