#pragma once
#include "global.h"
#include <stdbool.h>

typedef enum {
    NORTH,
    EAST,
    SOUTH,
    WEST
} Direction;

typedef struct {
    Coord position;
    Direction direction;
    int markers_picked;
} Robot;


Robot initialiseRobot();
bool canMoveForward(Robot *robot);
void forward(Robot *robot);
void right(Robot *robot);
void left(Robot *robot);
void pickUpMarker(Robot *robot, Coord **markers, int *marker_count);
void dropMarker(Robot *robot, Coord *marker);
