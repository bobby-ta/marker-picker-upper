#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "global.h"
#include "robot.h"
#include "grid.h"
#include "display.h"
#include "search.h"

void search(Robot *robot, Coord **markers, int marker_count) {
    bool **visited;
    initialiseVisited(&visited);
    while (marker_count > 0) {
         
        if (dfs(grid, visited, robot, 'm')) {
            pickUpMarker(robot, markers, &marker_count);
        } else {
            //Clear map and try dfs again if failed
            freeVisited(&visited);
            initialiseVisited(&visited);
            dfs(grid, visited, robot, 'm');
            freeVisited(&visited);
            initialiseVisited(&visited);
            break;
        }
        
    }
    freeVisited(&visited);
    initialiseVisited(&visited); 
    dfs(grid, visited, robot, 'h');
    freeVisited(&visited);
}

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
        free((*visited)[i]);
    }
    free(*visited);
    *visited = NULL;
}

//DFS as explained by ChatGPT
bool dfs(char **grid, bool **visited, Robot *robot, char target) {
    if (grid[robot->position.y][robot->position.x] == target) {
        return true;
    } else if (grid[robot->position.y][robot->position.x] == 'm') { //In case looking for home tile but stumble on a marker
        robot->markers_picked ++;
        grid[robot->position.y][robot->position.x] = 'e';
        displayAll(robot);
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
                forward(robot);
                if (dfs(grid, visited, robot, target)) {
                    return true;
                } else {
                    while (robot->direction != (direction_index + 2) % 4) {
                        right(robot);
                        sleep(SLEEP_TIME / 4);
                    };
                    forward(robot);
                    right(robot);
                    right(robot);
                }
            }
        }
        displayForeground(robot);
        sleep(SLEEP_TIME);
    }

    return false;
}
