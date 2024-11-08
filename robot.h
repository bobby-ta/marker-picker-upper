#pragma once
#include "global.h"

typedef struct {
    Coord position;
    char direction;
    int markers_picked;
} Robot;

Robot initialiseRobot(Coord *marker);
int canMoveForward(Robot *robot);
void forward(Robot *robot);
void right(Robot *robot);
void left(Robot *robot);
int atMarker(Robot *robot, Coord *marker);
void pickUpMarker(Robot *robot, Coord *marker);
void dropMarker(Robot *robot, Coord *marker);
//int markerCount(Robot *robot);