#pragma once
#include <stdbool.h>
#include "robot.h"

void initialiseVisited(bool ***visited);
void freeVisited(bool ***visited);
bool dfs(char **grid, bool **visited, Robot *myrobot, char target);
bool search(Robot *robot, Coord **markers, int marker_count);
