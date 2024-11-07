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
    while (canMoveForward(&robot)) {
        forward(&robot);
        displayForeground(&robot);
        sleep(100);
    }

    freeGrid();
}