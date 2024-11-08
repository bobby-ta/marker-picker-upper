#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "global.h"
#include "randomnum.h"
#include "robot.h"
#include "marker.h"
#include "display.h"

char directions[] = "NESW";

Robot initialiseRobot(Coord *marker) {
    Robot robot = {};
    robot.markers_picked = 0;
    do {
        robot.position.x = randomNum(1, 5);
        robot.position.y = randomNum(1, grid_height - 2);
    } while (robot.position.x == marker->x || robot.position.y == marker->y);
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
    sleep(SLEEP_TIME);
    displayForeground(robot);
}

void left(Robot *robot) {
    switch (robot->direction)
    {
        case 'N':
            robot->direction = 'W';
            break;
        case 'E':
            robot->direction = 'N';
            break;
        case 'S':
            robot->direction = 'E';
            break;
        case 'W':
            robot->direction = 'S';
            break;
    }
    sleep(SLEEP_TIME);
    displayForeground(robot);
}

void right(Robot *robot)
{
    switch (robot->direction)
    {
    case 'N':
        robot->direction = 'E';
        break;
    case 'E':
        robot->direction = 'S';
        break;
    case 'S':
        robot->direction = 'W';
        break;
    case 'W':
        robot->direction = 'N';
        break;
    }
    sleep(SLEEP_TIME);
    displayForeground(robot);
}

int atMarker(Robot *robot, Coord *marker) {
    return (robot->position.x == marker->x) && (robot->position.y == marker->y);
}