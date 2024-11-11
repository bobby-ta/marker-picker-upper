#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "robot.h"
#include "marker.h"
#include "display.h"
#include "grid.h"

Robot initialiseRobot() {
    Robot robot = {};
    robot.markers_picked = 0;
    do {
        robot.position.x = rand() % (grid_width - 2) + 1;
        robot.position.y = rand() % (grid_height - 2) + 1;
    } while (grid[robot.position.y][robot.position.x] != 'e');
    robot.direction = (Direction)(rand() % 4);
    return robot;
}

bool canMoveForward(Robot *robot) {
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
    robot->direction = (robot->direction - 1) % 4;
    sleep(SLEEP_TIME);
    displayForeground(robot);
}

void right(Robot *robot) {
    robot->direction = (robot->direction + 1) % 4;
    sleep(SLEEP_TIME);
    displayForeground(robot);
}

void pickUpMarker(Robot *robot, Coord **markers, int *marker_count) {
    robot->markers_picked ++;
    removeMarker(markers, marker_count, robot->position);
    displayAll(robot);
}

void dropMarker(Robot *robot, Coord *marker) {
    robot->markers_picked -= 1;
    marker->x = robot->position.x;
    marker->y = robot->position.y;
    grid[robot->position.y][robot->position.x] = 'm';
    displayAll(robot);
}