#include "display.h"
#include "marker.h"
#include "global.h"
#include <stdio.h>

int win_width = 1000;
int win_height = 800;

int main(void) {
    int grid_width;
    int grid_height;
    initialiseGrid(&grid_width, &grid_height);
    Coord marker = generateMarker(grid_width, grid_height);
    displayBackground(grid_width, grid_height, 50, &marker);
    printf("Marker: %d %d", marker.x, marker.y);
}