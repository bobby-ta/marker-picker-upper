#pragma once

#define WIN_WIDTH 1000
#define WIN_HEIGHT 800
#define TILE_SIZE 50
extern int grid_width;
extern int grid_height;
extern char ***grid;

typedef struct {
    int x; 
    int y;
} Coord;