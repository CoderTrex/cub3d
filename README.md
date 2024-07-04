# Cub3d

## Introduction

Cub3d is a project at 42 school designed to introduce students to the basics of raycasting. The goal is to create a simple 3D game engine using 2D raycasting to render a maze-like world from a first-person perspective. This project aims to enhance your understanding of graphics programming and game development fundamentals.

## Features

- 2D raycasting engine to render a 3D perspective.
- Player movement and rotation.
- Textured walls.
- Simple sprite rendering.
- Basic keyboard controls for movement and interaction.

## Requirements

- C programming language
- MinilibX (a simple X-Window programming API)
- Make

## Installation

1. **Clone the repository:**

    ```sh
    git clone https://github.com/Tyranno-Rex/cub3d
    ```

2. **Navigate to the project directory:**

    ```sh
    cd cub3d
    ```

3. **Compile the project:**

    ```sh
    make
    ```

## Usage

1. **Run the executable:**

    ```sh
    ./cub3d [path_to_map_file.cub]
    ```

2. **Controls:**
    - `W`: Move forward
    - `S`: Move backward
    - `A`: Strafe left
    - `D`: Strafe right
    - `Left Arrow`: Rotate left
    - `Right Arrow`: Rotate right
    - `ESC`: Exit the game

## Map File Format

The map file (`.cub` file) should define the layout of the game world. Below is an example of a simple map file format:

```
R 640 480            // Resolution: width and height
NO ./textures/north.xpm  // Path to the texture for the north wall
SO ./textures/south.xpm  // Path to the texture for the south wall
WE ./textures/west.xpm   // Path to the texture for the west wall
EA ./textures/east.xpm   // Path to the texture for the east wall
S ./textures/sprite.xpm  // Path to the sprite texture

F 220,100,0         // Floor color (R,G,B)
C 225,30,0          // Ceiling color (R,G,B)

111111
100001
102001
100001
111111
```

- `1`: Wall
- `0`: Empty space
- `2`: Sprite

## Project Structure

cub3d.h
libft.h
struct.h

```
cub3d/
├── includes/
│   ├── cub3d.h          // Header file for project-wide definitions
│   ├── libft.h          // Header file for the Libft library
│   ├── struct.h         // Header file for project structures
├── libft/              // Libft library source files
├── maps/                // Directory for map files
├── mlx/                // MinilibX library files
├── src/
|   ├── mlx/             // MinilibX source files
│       ├── exit_game.c       // Functions for closing the window
│       ├── init_game.c       // Functions for initializing the game
│       ├── key_hook.c        // Functions for handling keyboard input
│       ├── mlx_utils.c       // Utility functions for MinilibX
│       ├── move_player.c     // Functions for player movement
│       ├── raycast.c         // Functions for raycasting
│       ├── render.c          // Functions for rendering the game
│   ├── parsing/         // Source files for parsing the map file
│       ├── check_map.c       // Functions for validating the map
│       ├── color.c           // Functions for parsing colors
│       ├── map.c             // Functions for handling the map
│       ├── map_utils.c       // Utility functions for the map
│       ├── parsing.c         // Functions for parsing the map file
│       ├── parsing_utils.c   // Utility functions for parsing
│       ├── utils.c           // Utility functions for the project
│       ├── utils2.c          // More utility functions
│   ├── main.c           // Entry point of the program
├── textures/            // Directory for texture files
├── Makefile             // Build script
└── README.md            // Project documentation
```

## References

- [MinilibX documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [Raycasting tutorial](https://lodev.org/cgtutor/raycasting.html)
- [Raycasting tutorial (in korean)](https://github.com/365kim/raycasting_tutorial)


## summary
- [notion](https://uttermost-meteoroid-5fa.notion.site/4-3-cub3d-2230f85a8b784862a7057a517850e56a)

## License

This project is licensed under the MIT License. See the LICENSE file for more details.