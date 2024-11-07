#include "display.h"
#include "marker.h"
#include "global.h"
#include "grid.h"
#include <stdio.h>

int grid_width;
int grid_height;

int main(void) {
    setGridSize(&grid_width, &grid_height);
    Coord marker = generateMarker();
    displayBackground(&marker);
}