# Source Files (`/src`)

This directory contains the C++ implementation (`.cpp`) files corresponding to the headers defined in the `/include` directory. 

## File Descriptions

* `ai.cpp` - Implements the core game loop, enemy spawning algorithms, and score tracking.
* `background.cpp` - Implements the drawing logic and scrolling animations for the background scenery (stars, moon, city buildings, and road).
* `bullet.cpp` - Implements the bullet rendering and movement updates.
* `colition.cpp` - Implements the hit-box logic, checking for overlap between bullets, enemies, and the player.
* `color.cpp` - Implements the HEX-to-RGB conversion logic used for all game styling.
* `controller.cpp` - Implements the main menu rendering, UI layout, and click detection logic.
* `enemy.cpp` - Implements enemy rendering, movement, and their automatic firing mechanics.
* `hero.cpp` - Implements the player's vehicle rendering, wheel rotation, jump physics, and bullet generation.
* `particles.cpp` - Implements the scaling and fading algorithms for explosion debris.
* `shapes.cpp` - Implements the raw OpenGL vertex plotting for geometric primitives.
* `soundcontroller.cpp` - Implementation file for future audio logic.
* `text.cpp` - Implements the font parsing using `glutBitmapCharacter` to display text in the game.
