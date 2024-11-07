#include "global.h"
#include "randomnum.h"
#include "robot.h"
#include "marker.h"
#include <string.h>
#include <unistd.h>

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

int canMoveForward(Robot *robot) {
    char *tile_in_front;
    switch (robot->direction)
    {
        case 'N':
            tile_in_front = grid[(robot->position.y)-1][robot->position.x];
            break;
        case 'E':
            tile_in_front = grid[robot->position.y][(robot->position.x)+1];
            break;
        case 'S':
            tile_in_front = grid[(robot->position.y)+1][robot->position.x];
            break;
        case 'W':
            tile_in_front = grid[robot->position.y][(robot->position.x)-1];
            break;
    }
    return (strcmp(tile_in_front, "wall") != 0 && strcmp(tile_in_front, "obstacle") != 0);
}

void forward(Robot *robot) {
    switch (robot->direction)
    {
        case 'N':
            robot->position.y -= 1;
            break;
        case 'E':
            robot->position.x += 1;
            break;
        case 'S':
            robot->position.y += 1;
            break;
        case 'W':
            robot->position.x -= 1;
            break;
    }
}


