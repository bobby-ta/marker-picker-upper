#include "randomnum.h"
#include "global.h"

Coord generateMarker() {
    Coord marker = {};
    marker.x = randomNum(1, grid_width - 2);
    marker.y = randomNum(1, grid_height - 2);
    return marker;
}