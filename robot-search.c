#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "global.h"
#include "robot.h"
#include "marker.h"
#include "randomnum.h"
#include "grid.h"
#include "display.h"
#include <unistd.h>

// Function to initialise visited array
void initialiseVisited(bool ***visited) {
    *visited = malloc(grid_height * sizeof(bool*)); 
    for (int i = 0; i < grid_height; i++) {
        (*visited)[i] = malloc(grid_width * sizeof(bool));
        for (int j = 0; j < grid_width; j++) {
            (*visited)[i][j] = false;
        }
    }
}

void freeVisited(bool ***visited) {
    for (int i = 0; i < grid_height; i++) {
        free((*visited)[i]); // Free each row
    }
    free(*visited); // Free the array of pointers
}


// Directions for moving right, up, down, left
int row_num[] = {0, -1, 1, 0};
int col_num[] = {1, 0, 0, -1};

// Function to perform dfs
bool dfs(char **grid, bool **visited, Robot *robot) {
    if (grid[robot->position.y][robot->position.x] == 'm') {
        return true;
    }

    visited[robot->position.y][robot->position.x] = true;

    for (int i = 0; i < 4; i++) {
        Coord vector_to_next[] = {
            {0, -1},
            {1, 0},
            {0, 1},
            {-1, 0}
        };
        int direction_index = (robot->direction + i) % 4;
        int next_row = robot->position.y + vector_to_next[direction_index].y;
        int next_col = robot->position.x + vector_to_next[direction_index].x;

        if (!visited[next_row][next_col]) {
            while (robot->direction != direction_index) {
                right(robot);
                sleep(SLEEP_TIME / 4);
            };
            
            if (canMoveForward(robot)) {
                //robot->position.y = next_row;
                //robot->position.x = next_col;
                forward(robot);
                displayForeground(robot);
                sleep(SLEEP_TIME);

                if (dfs(grid, visited, robot)) {
                    return true; // Marker found in the recursive call
                } else {
                    while (robot->direction != (direction_index + 2) % 4) {
                        right(robot);
                        sleep(SLEEP_TIME / 4);
                    };
                    forward(robot);
                    //robot->position.y -= vector_to_next[direction_index].y;
                    //robot->position.x -= vector_to_next[direction_index].x;
                }
            }
        }
        displayForeground(robot);
        sleep(SLEEP_TIME);
    }

    return false;
}

bool search(Robot *robot) {
    bool **visited;
    initialiseVisited(&visited); 
    
    if (dfs(grid, visited, robot)) {
        freeVisited(&visited);
        return true;
    } else {
        printf("%s", "stuck???");
        freeVisited(&visited);
        return false;
    }
    
    return 0;
}
