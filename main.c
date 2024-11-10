#include <unistd.h>
#include "display.h"
#include "robot.h"
#include "marker.h"
#include "global.h"
#include "grid.h"
#include "robot-search.h"
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
    srand(time(NULL));
    initialiseGrid();
    Coord marker = generateMarker();
    designGrid(&marker);
    Robot robot = initialiseRobot(&marker);
    //robot.position.x = 1; //for testing purposes
    //robot.position.y = 2; //for testing purposes
    displayAll(&robot, &marker);

    //Find marker
    if (search(&robot)) {
        pickUpMarker(&robot, &marker);

        //Drop marker at corner
        while (canMoveForward(&robot)) {
            forward(&robot);
        }
        dropMarker(&robot, &marker);
    }

    freeGrid();
}