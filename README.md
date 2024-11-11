# COMP0002 C Coursework

## Description
The program generates a randomly-sized arena with a random number of randomly-placed obstacles and markers inside it. The robot navigates to each marker (green) using depth-first search, before returning to the home tile (blue, where it started). It avoids the obstacles (black) and walls (red).

### Steps
1. Setup
   a. Set grid dimensions
   b. Generate dynamic array of markers (as Coordinate structs)
   c. Generate dynamic arena array with character elements
      1. ```'w'``` for wall<br>
      2. ```'o'``` for obstacle<br>
      3. ```'m'``` for marker<br>
      4. ```'e'``` for empty<br>
   d. Create robot struct - contains position (Coordinate struct), direction (enum) and number of markers picked (integer)
2. Search
   a. Program iterates through markers, searching for them sequentially 
      1. Recursive depth-first search is used
      2. Pointer to robot struct is passed into search and movement to change robot's position/direction as search happens
      2. Dynamic array ```visited[grid_height][grid_width]``` stores booleans for whether each square has been visited, to avoid redundant searches
   b. Once the markers have been collected, the same depth-first search is applied to navigate back to the home tile
3. Display
   a. The display refreshes every time the robot moves or a marker is picked up/placed

## Instructions
1. Copy files ```graphics.c```, ```graphics.h``` and ```drawapp-4.0.jar``` into the main directory
2. Navigate to the main directory in the terminal
3. Type ```gcc *.c``` into the terminal and press Enter
4. Type ```./a.out | java -jar drawapp-4.0.jar``` into the terminal and press Enter
5. Have fun! I spent a whole eternity on this so hope it works :)
   a. SLEEP_TIME can be changed in global.h for longer pauses (or shorter!)
