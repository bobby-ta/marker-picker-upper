#include "global.h"
#include "randomnum.h"
#include "robot.h"
#include "marker.h"

char directions[] = "NESW";

Robot initialiseRobot(Coord *marker) {
    Robot robot = {};
    do {
        robot.position.x = randomNum(1, grid_width - 2);
        robot.position.y = randomNum(1, grid_height - 2);
    } while (robot.position.x == marker->x && robot.position.y == marker->y);
    robot.direction = directions[randomNum(0, 3)];
    return robot;
}



