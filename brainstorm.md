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
