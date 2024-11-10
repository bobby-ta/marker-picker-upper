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
int rowNum[] = {0, -1, 1, 0};
int colNum[] = {1, 0, 0, -1};

// Function to perform dfs
bool dfs(char **grid, bool **visited, Robot *robot) {
    printf("Current cell: %d %d \n", robot->position.y, robot->position.x);
    // If we find the marker, return true
    if (grid[robot->position.y][robot->position.x] == 'm') {
        sleep(1000);
        return true;
    }

    // Mark the current cell as visited
    visited[robot->position.y][robot->position.x] = true;

    // Explore all 4 possible directions
    for (int i = 0; i < 4; i++) {
        int newRow = robot->position.y + rowNum[i];
        int newCol = robot->position.x + colNum[i];
        
        // Check if the new position is within bounds and not visited
        if (newRow >= 0 && newRow < grid_height && newCol >= 0 && newCol < grid_width &&
            (grid[newRow][newCol] == 'e' || grid[newRow][newCol] == 'm') && 
            !visited[newRow][newCol]) {
            robot->position.y = newRow;
            robot->position.x = newCol;
            displayForeground(robot);
            sleep(SLEEP_TIME);

            if (dfs(grid, visited, robot)) {
                return true; // Marker found in the recursive call
            }
        }
        printf("Came back to: %d %d \n", robot->position.y, robot->position.x);
        displayForeground(robot);
        sleep(SLEEP_TIME);
    }

    return false; // Marker not found in this path
}

bool search(Robot *robot) {
    bool **visited;
    initialiseVisited(&visited); 
    
    // Start dfs from the top-left corner (0, 0)
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
