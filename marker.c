#include "randomnum.h"
#include "global.h"

Coord generateMarker() {
    Coord marker = {};
    int which_edge = randomNum(0, 3); //0 = north, 1 = east, etc.
    int x, y;
    switch (which_edge) 
    {
    case 0:
        x = randomNum(1, grid_width - 2);
        y = 1;
        break;
    case 1:
        x = grid_width - 2;
        y = randomNum(1, grid_height - 2);
        break;
    case 2:
        x = randomNum(1, grid_width - 2);
        y = grid_height - 2;
        break;
    case 3:
        x = 1;
        y = randomNum(1, grid_height - 2);
        break;
    default:
        break;
    }
    marker.x = x;
    marker.y = y;
    return marker;
}