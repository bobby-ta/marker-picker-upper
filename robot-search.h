#pragma once
#include <stdbool.h>
#include "robot.h"

// Function to initialise the visited array
void initialiseVisited(bool ***visited);

// Function to perform depth-first search (DFS)
bool dfs(char **grid, bool **visited, Robot *myrobot);

// Function to search for the marker using the robot
int search(Robot *robot);
