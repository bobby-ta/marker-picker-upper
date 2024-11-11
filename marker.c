#include "global.h"
#include <stdlib.h>
#include <stdio.h>

Coord generateMarker() {
    Coord marker = {};
    marker.x = rand() % (grid_width - 2) + 1;
    marker.y = rand() % (grid_height - 2) + 1;
    return marker;
}

Coord* createMarkers(int marker_count) {
    Coord* markers = (Coord*)malloc(marker_count * sizeof(Coord));
    for (int i = 0; i < marker_count; i++) {
        markers[i] = generateMarker(); 
    }
    return markers;
}

void removeMarker(Coord **markers, int *total_markers, Coord robot_pos) {
    grid[robot_pos.y][robot_pos.x] = 'e';

    for (int i = 0; i < *total_markers; i++) {
        if ((*markers)[i].x == robot_pos.x && (*markers)[i].y == robot_pos.y) {
            for (int j = i; j < *total_markers - 1; j++) {
                (*markers)[j] = (*markers)[j + 1];
            }
            
            (*total_markers)--;
            break;
        }
    }
}


void freeMarkers(Coord *markers) {
    free(markers);
}