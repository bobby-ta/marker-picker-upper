#include <unistd.h>
#include "display.h"
#include "robot.h"
#include "marker.h"
#include "global.h"
#include "grid.h"

int main(void) {
    initialiseGrid();
    Coord marker = generateMarker();
    updateGrid(&marker);
    displayBackground(&marker);

    Robot robot = initialiseRobot(&marker);
    displayForeground(&robot);

    while (robot.direction != 'S') {
        right(&robot);
    }

    while (!atMarker(&robot, &marker)) {
        right(&robot);
        while (canMoveForward(&robot) && !atMarker(&robot, &marker)) {
            forward(&robot);
        }
    }

    freeGrid();
}