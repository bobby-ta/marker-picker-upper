#include <stdlib.h>
#include <time.h>
#include "graphics.h"
#include "randomnum.h"

void displayBackground(void) {
    background();

    int win_width = 1000;
    int win_height = 800;
    setWindowSize(win_width, win_height);

    int tile_size = 50;
    int grid_width = randomNum(5, win_width / tile_size); //inc. walls
    int grid_height = randomNum(5, win_height / tile_size);
    int left_corner_x = (win_width - grid_width * tile_size) / 2;
    int left_corner_y = (win_height - grid_height * tile_size) / 2;

    for (int i = 0; i < grid_height; i++) {
        for (int j = 0; j < grid_width; j++) {
            if (i == 0 || i == grid_height - 1 || j == 0 || j == grid_width - 1) {
                setRGBColour(203, 65, 84);
                fillRect(left_corner_x + tile_size * j, left_corner_y + tile_size * i, tile_size, tile_size);
            } else {
                setRGBColour(0, 0, 0);
                drawRect(left_corner_x + tile_size * j, left_corner_y + tile_size * i, tile_size, tile_size);
            }
        }
    }
}

void displayForeground(void) {

}