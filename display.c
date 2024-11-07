#include <stdlib.h>
#include <time.h>
#include "graphics.h"
#include "global.h"
#include <stdio.h>

void displayBackground(Coord *marker) {
    setWindowSize(WIN_WIDTH, WIN_HEIGHT);
    background();

    int left_corner_x = (WIN_WIDTH - grid_width * TILE_SIZE) / 2;
    int left_corner_y = (WIN_HEIGHT - grid_height * TILE_SIZE) / 2;

    for (int i = 0; i < grid_height; i++) {
        for (int j = 0; j < grid_width; j++) {
            if (i == 0 || i == grid_height - 1 || j == 0 || j == grid_width - 1) {
                setRGBColour(203, 65, 84);
                fillRect(left_corner_x + TILE_SIZE * j, left_corner_y + TILE_SIZE * i, TILE_SIZE, TILE_SIZE);
            } else if (i == marker->y && j == marker->x){
                setRGBColour(10, 218, 100);
                fillRect(left_corner_x + TILE_SIZE * j, left_corner_y + TILE_SIZE * i, TILE_SIZE, TILE_SIZE);
            } else {
                setRGBColour(0, 0, 0);
                drawRect(left_corner_x + TILE_SIZE * j, left_corner_y + TILE_SIZE * i, TILE_SIZE, TILE_SIZE);
            }
        }
    }
}

void displayForeground(void) {

}