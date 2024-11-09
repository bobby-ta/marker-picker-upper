# Brainstorming

## Display
- Grid and obstacles in background
- Robot and markers in foreground

## Grid
- 2D array using pointers
- Each array element holds either empty, wall or obstacle

## Markers
- Global coord (struct)
### int atMarker()
- Compare robot location to marker location
### void pickUpMarker()
- Set marker coord to {-1, -1} -> won't be drawn on the grid
- Redraw background layer


## Robot
- Struct - coords, direction
### void forward(coord, direction)
- Switch statement to add/subtract to x/y
### void left()
- direction -= 90
### void right()
- direction += 90
### int canMoveForward(coord, direction)
- Switch statement (basically same logic as forward())

Stage 4: Complex Navigation

    Breadth-First Search (BFS) or Depth-First Search (DFS): Use these algorithms to explore the arena and find the shortest path to the marker. This is especially useful when the marker is not next to a wall.
    A Search Algorithm*: Implement A* for more efficient pathfinding, especially in complex arenas with obstacles. A* uses heuristics to find the shortest path to the target.

Stage 5: Handling Obstacles and Multiple Markers

    Pathfinding with Obstacles: Modify your pathfinding algorithm (like A* or BFS) to account for obstacles. Ensure the robot can navigate around them.
    Marker Collection Logic: Implement logic for the robot to collect multiple markers. This may involve maintaining a list of markers and iterating through them.

Stage 6: Home Tile and Return Logic

    Home Tile Identification: Designate a specific tile as the home tile. You can randomly select a tile or choose a fixed position.
    Return Pathfinding: After collecting all markers, use your pathfinding algorithm to navigate back to the home tile.

Stage 7: Random-Shaped Arena with Multiple Markers

    Random Arena Generation: Create an algorithm to generate a random-sized and shaped arena. This could involve:
        Polygon Generation: Use algorithms to create random polygons that define the arena shape.
        Tile Placement: Ensure that tiles are placed within the defined shape and that there are accessible paths.
    Marker Accessibility Check: Implement a function to ensure that markers are placed in accessible locations. This could involve:
        Flood Fill Algorithm: Use a flood fill or similar algorithm to check if a marker is reachable from the robot's starting position.
    Enhanced Pathfinding: Use the previously mentioned pathfinding algorithms to navigate the robot through the arena, ensuring it can collect all markers and return to the home tile.

Summary of Algorithms

    Grid Drawing: Basic loops for drawing the arena and tiles.
    Wall-Following: Simple logic for navigating along walls.
    Random Generation: Random number generation for arena size and marker placement.
    Pathfinding: BFS, DFS, or A* for navigating to markers and returning to the home tile.
    Flood Fill: To check marker accessibility.
    Polygon Generation: For creating random-shaped arenas.
