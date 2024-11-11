#include <unistd.h>
#include "display.h"
#include "robot.h"
#include "marker.h"
#include "global.h"
#include "grid.h"
#include "search.h"
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    srand(time(NULL));

    setGridSize();

    int marker_count = rand() % (grid_width / 3) + 2;
    Coord *markers = createMarkers(marker_count);
    
    initialiseGrid(markers, marker_count);

    Robot robot = initialiseRobot();
    grid[robot.position.y][robot.position.x] = 'h';
    displayBackground();
    sleep(200);
    
    //Find marker
    search(&robot, &markers, marker_count);
    
    freeMarkers(markers);
    freeGrid();
}