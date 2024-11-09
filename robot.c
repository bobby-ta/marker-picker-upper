#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "global.h"
#include "randomnum.h"
#include "robot.h"
#include "marker.h"
#include "display.h"
#include "grid.h"

Robot initialiseRobot(Coord *marker) {
    Robot robot = {};
    robot.markers_picked = 0;
    do {
        robot.position.x = randomNum(1, 5);
        robot.position.y = randomNum(1, grid_height - 2);
    } while (robot.position.x == marker->x || robot.position.y == marker->y);
    robot.direction = (Direction)randomNum(0, 3);
    return robot;
}

int canMoveForward(Robot *robot) {
    char tile_in_front;
    switch (robot->direction) {
        case NORTH:
            tile_in_front = grid[robot->position.y - 1][robot->position.x];
            break;
        case EAST:
            tile_in_front = grid[robot->position.y][robot->position.x + 1];
            break;
        case SOUTH:
            tile_in_front = grid[robot->position.y + 1][robot->position.x];
            break;
        case WEST:
            tile_in_front = grid[robot->position.y][robot->position.x - 1];
            break;
    }
    return (tile_in_front != 'w' && tile_in_front != 'o');
}

void forward(Robot *robot) {
    switch (robot->direction) {
        case NORTH:
            robot->position.y -= 1;
            break;
        case EAST:
            robot->position.x += 1;
            break;
        case SOUTH:
            robot->position.y += 1;
            break;
        case WEST:
            robot->position.x -= 1;
            break;
    }
    sleep(SLEEP_TIME);
    displayForeground(robot);
}

void left(Robot *robot) {
    switch (robot->direction) {
        case NORTH:
            robot->direction = WEST;
            break;
        case EAST:
            robot->direction = NORTH;
            break;
        case SOUTH:
            robot->direction = EAST;
            break;
        case WEST:
            robot->direction = SOUTH;
            break;
    }
    sleep(SLEEP_TIME);
    displayForeground(robot);
}

void right(Robot *robot) {
    switch (robot->direction) {
        case NORTH:
            robot->direction = EAST;
            break;
        case EAST:
            robot->direction = SOUTH;
            break;
        case SOUTH:
            robot->direction = WEST;
            break;
        case WEST:
            robot->direction = NORTH;
            break;
    }
    sleep(SLEEP_TIME);
    displayForeground(robot);
}


int atMarker(Robot *robot, Coord *marker) {
    return (robot->position.x == marker->x) && (robot->position.y == marker->y);
}

void pickUpMarker(Robot *robot, Coord *marker) {
    robot->markers_picked += 1;
    marker->x = -1;
    marker->y = -1;
    updateGrid(marker);
    displayAll(robot, marker);
}

void dropMarker(Robot *robot, Coord *marker) {
    robot->markers_picked -= 1;
    marker->x = robot->position.x;
    marker->y = robot->position.y;
    updateGrid(marker);
    displayAll(robot, marker);
}