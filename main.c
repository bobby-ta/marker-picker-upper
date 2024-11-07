#include "display.h"
#include "marker.h"
#include "global.h"
#include "grid.h"
#include <stdio.h>

int main(void) {
    initialiseGrid();
    Coord marker = generateMarker();
    updateGrid(&marker);
    displayBackground(&marker);




    freeGrid();
}