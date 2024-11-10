#pragma once
#include "global.h"
#include <stdbool.h>

typedef enum {
    NORTH,
    EAST,
    SOUTH,
    WEST,
    DIRECTION_COUNT
} Direction;

typedef struct {
    Coord position;
    Direction direction;
    int markers_picked;
} Robot;


Robot initialiseRobot(Coord *marker);
bool canMoveForward(Robot *robot);
void forward(Robot *robot);
void right(Robot *robot, Direction currentdir);
void left(Robot *robot, Direction currentdir);
int atMarker(Robot *robot, Coord *marker);
void pickUpMarker(Robot *robot, Coord *marker);
void dropMarker(Robot *robot, Coord *marker);
//int markerCount(Robot *robot);