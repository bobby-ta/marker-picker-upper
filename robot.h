#pragma once
#include "global.h"

typedef struct {
    Coord position;
    char direction;
} Robot;

Robot initialiseRobot(Coord *marker);
int canMoveForward(Robot *robot);
void forward(Robot *robot);