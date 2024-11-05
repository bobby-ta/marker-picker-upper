#include "graphics.h"

int displayGrid(void) {
    int tile_size = 50;
    int grid_width = 10;
    int grid_height = 10;

    setWindowSize(500, 500);

    for (int i = 0; i < grid_height; i++) {
        for (int j = 0; j < grid_width; j++) {
            if (i == 0 || i == grid_height - 1 || j == 0 || j == grid_width - 1) {
                setRGBColour(203, 65, 84);
                fillRect(tile_size * j, tile_size * i, tile_size, tile_size);
            } else {
                setRGBColour(0, 0, 0);
                drawRect(tile_size * j, tile_size * i, tile_size, tile_size);
            }
        }
    }

    return 0;
}