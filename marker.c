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
    // Simply remove the marker from the grid
    grid[robot_pos.y][robot_pos.x] = 'e';  // Mark the position as empty

    // Loop through the markers and find the one to remove
    for (int i = 0; i < *total_markers; i++) {
        if ((*markers)[i].x == robot_pos.x && (*markers)[i].y == robot_pos.y) {
            // Shift the remaining markers left to fill the gap
            for (int j = i; j < *total_markers - 1; j++) {
                (*markers)[j] = (*markers)[j + 1];
            }

            // Decrease the total number of markers
            (*total_markers)--;

            // Exit the loop once the marker is removed
            break;
        }
    }
}


void freeMarkers(Coord *markers) {
    free(markers);
}