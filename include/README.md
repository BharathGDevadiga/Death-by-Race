# Header Files (`/include`)

This directory contains all the C++ header (`.h`) files for the project. These files define the structure of the classes and their member functions, establishing a clear Object-Oriented Programming (OOP) architecture.

## File Descriptions

* `ai.h` - Defines the `AI` class which manages the core game loop, spawning enemies, keeping score, and handling the current game state.
* `background.h` - Defines the `Background` class, which handles the parallax scrolling night city, stars, and moon graphics.
* `bullet.h` - Defines the `Bullet` class for player and enemy projectiles, tracking their position and speed.
* `colition.h` - Contains the collision detection utility functions for resolving bullet hits and vehicle crashes.
* `color.h` - Defines a utility class for parsing HEX color codes into OpenGL-compatible RGB values.
* `controller.h` - Defines the `Controller` class, handling the main menu UI, buttons, and state transitions.
* `enemy.h` - Defines the `Enemy` class representing enemy vehicles and their behaviors.
* `hero.h` - Defines the `Hero` class, controlling the player's vehicle, jumping mechanics, and weapon firing.
* `particles.h` - Defines the `Particles` class for explosion effects and debris animations.
* `shapes.h` - A utility class containing primitive OpenGL drawing functions (rectangles, octagons).
* `soundcontroller.h` - Scaffolded class for managing game audio and sound effects.
* `text.h` - A utility class for rendering bitmap text onto the OpenGL viewport.
