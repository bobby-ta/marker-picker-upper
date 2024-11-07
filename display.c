#include <stdlib.h>
#include <time.h>
#include "graphics.h"
#include "global.h"
#include "robot.h"
#include <stdio.h>
#include <string.h>

static int left_corner_x;
static int left_corner_y;

void displayBackground(Coord *marker) {
    setWindowSize(WIN_WIDTH, WIN_HEIGHT);
    background();

    left_corner_x = (WIN_WIDTH - grid_width * TILE_SIZE) / 2;
    left_corner_y = (WIN_HEIGHT - grid_height * TILE_SIZE) / 2;

    for (int i = 0; i < grid_height; i++) {
        for (int j = 0; j < grid_width; j++) {
            if (strcmp(grid[i][j], "wall") == 0) {
                setRGBColour(203, 65, 84);
                fillRect(left_corner_x + TILE_SIZE * j, left_corner_y + TILE_SIZE * i, TILE_SIZE, TILE_SIZE);
            } else if (strcmp(grid[i][j], "marker") == 0){
                setRGBColour(10, 218, 100);
                fillRect(left_corner_x + TILE_SIZE * j, left_corner_y + TILE_SIZE * i, TILE_SIZE, TILE_SIZE);
            } else {
                setRGBColour(0, 0, 0);
                drawRect(left_corner_x + TILE_SIZE * j, left_corner_y + TILE_SIZE * i, TILE_SIZE, TILE_SIZE);
            }
        }
    }
}

void displayForeground(Robot *robot) {
    foreground();
    clear();
    char robotimg[24];

    switch (robot->direction) {
    case 'N':
        snprintf(robotimg, sizeof(robotimg), "./resources/robot-n.png");
        break;
    case 'E':
        snprintf(robotimg, sizeof(robotimg), "./resources/robot-e.png");
        break;
    case 'S':
        snprintf(robotimg, sizeof(robotimg), "./resources/robot-s.png");
        break;
    case 'W':
        snprintf(robotimg, sizeof(robotimg), "./resources/robot-w.png");
        break;
    };

    displayImage(robotimg, left_corner_x + 1 + (TILE_SIZE * robot->position.x), left_corner_y + 1 + (TILE_SIZE * robot->position.y));
}