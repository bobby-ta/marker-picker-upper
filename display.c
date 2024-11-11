#include <stdlib.h>
#include <time.h>
#include "graphics.h"
#include "global.h"
#include "robot.h"
#include <stdio.h>
#include <string.h>
#include "display.h"

static int left_corner_x;
static int left_corner_y;

void displayAll(Robot *robot) {
    displayBackground();
    displayForeground(robot);
}

void displayBackground() {
    setWindowSize(WIN_WIDTH, WIN_HEIGHT);
    background();
    clear();

    left_corner_x = (WIN_WIDTH - grid_width * TILE_SIZE) / 2;
    left_corner_y = (WIN_HEIGHT - grid_height * TILE_SIZE) / 2;

    for (int i = 0; i < grid_height; i++) {
        for (int j = 0; j < grid_width; j++) {
            if (grid[i][j] == 'w') {
                setRGBColour(203, 65, 84);
                fillRect(left_corner_x + TILE_SIZE * j, left_corner_y + TILE_SIZE * i, TILE_SIZE, TILE_SIZE);
            } else if (grid[i][j] == 'm') {
                setRGBColour(10, 218, 100);
                fillRect(left_corner_x + TILE_SIZE * j, left_corner_y + TILE_SIZE * i, TILE_SIZE, TILE_SIZE);
            } else if (grid[i][j] == 'o') {
                setRGBColour(0, 0, 0);
                fillRect(left_corner_x + TILE_SIZE * j, left_corner_y + TILE_SIZE * i, TILE_SIZE, TILE_SIZE);
            } else if (grid[i][j] == 'h') {
                setRGBColour(41, 166, 201);
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
    case NORTH:
        snprintf(robotimg, sizeof(robotimg), "./resources/robot-n.png");
        break;
    case EAST:
        snprintf(robotimg, sizeof(robotimg), "./resources/robot-e.png");
        break;
    case SOUTH:
        snprintf(robotimg, sizeof(robotimg), "./resources/robot-s.png");
        break;
    case WEST:
        snprintf(robotimg, sizeof(robotimg), "./resources/robot-w.png");
        break;
    };

    displayImage(robotimg, left_corner_x + 1 + (TILE_SIZE * robot->position.x), left_corner_y + 1 + (TILE_SIZE * robot->position.y));
}

