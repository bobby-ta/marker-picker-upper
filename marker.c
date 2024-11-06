#include "randomnum.h"
#include "global.h"

Coord generateMarker(int grid_width, int grid_height) {
    Coord marker = {};
    int which_edge = randomNum(0, 3); //0 = north, 1 = east, etc.
    int x, y;
    switch (which_edge)
    {
    case 0:
        x = randomNum(1, grid_width - 1);
        y = 1;
        break;
    case 1:
        x = grid_width - 1;
        y = randomNum(1, grid_height - 1);
        break;
    case 2:
        x = randomNum(1, grid_width - 1);
        y = grid_height - 1;
        break;
    case 3:
        x = 1;
        y = randomNum(1, grid_height - 1);
        break;
    default:
        break;
    }
    marker.x = x;
    marker.y = y;
    return marker;
}