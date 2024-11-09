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
    Robot robot = initialiseRobot(&marker);
    displayAll(&robot, &marker);

    //Find marker
    while (!atMarker(&robot, &marker)) {
        right(&robot);
        while (canMoveForward(&robot) && !atMarker(&robot, &marker)) {
            forward(&robot);
        }
    }
    pickUpMarker(&robot, &marker);

    //Drop marker at corner
    while (canMoveForward(&robot)) {
        forward(&robot);
    }
    dropMarker(&robot, &marker);

    freeGrid();
}