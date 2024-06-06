This is my Maze Project with the following components;
maze_project/
|-- src/
|   |-- main.cpp
|   |-- raycasting.cpp
|   |-- sdl_utils.cpp
|-- include/
|   |-- raycasting.h
|   |-- sdl_utils.h
|-- assets/
|   |-- textures/
|-- maps/
|   |-- example_map.txt
|-- Makefile

The project will then be tested by 
make
./maze_project

Summary steps:
Orientation (Task 1): Modify renderScene to use different colors for north/south and east/west walls.
Rotation (Task 2): Add event handling in main.cpp to rotate the camera with keyboard input.
Movement (Task 3): Implement player movement with WASD keys.
Collision Handling (Task 4): Prevent the player from walking through walls.
Map Parsing (Task 5): Read the map from a file.
Draw the Map (Task 6): Display a mini-map.
Coding Style and Documentation (Task 7): Ensure code meets style guidelines and is well-documented.
Textures (Task 8): Apply textures to the walls.
Advanced Features (Tasks 9-14): Implement additional game features such as multi-directional movement, ground textures, weapons, enemies, and special effects.
