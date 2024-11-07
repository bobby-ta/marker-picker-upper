#include <stdlib.h>
#include "randomnum.h"
#include "global.h"

void setGridSize(int *grid_width, int *grid_height) {
    *grid_width = randomNum(5, WIN_WIDTH / TILE_SIZE); //inc. walls
    *grid_height = randomNum(5, WIN_HEIGHT / TILE_SIZE);
}

void initialiseGrid(Coord *marker) {
    //2d array of strings = 3d array of characters
    char ***array = malloc(grid_height * sizeof(char**)); //each column is an array of pointers to pointers (rows) to strings

    for (int i = 0; i < grid_height; i++) {
        array[i] = malloc(grid_width * sizeof(char*)); //each row is an array of pointers to strings
        for (int j = 0; j < grid_width; j++) {
            array[i][j] = malloc(5 * sizeof(char)); //'empty'/'wall'/'obst' take up max 5 characters
        }
    }
}

void updateGrid() {

}