#pragma once
#include "global.h"

Coord generateMarker(); 
Coord* createMarkers(int marker_count);
void removeMarker(Coord **markers, int *marker_count, Coord robot_pos);
void freeMarkers(Coord *markers);