# Death by Race

A 2D arcade survival shooter developed in C++ using OpenGL. It features a custom engine delivering smooth 60 FPS gameplay alongside a beautifully animated scrolling night city background. Players dodge obstacles and defeat enemies using intense shooting mechanics. The code showcases OOP principles with classes for AI, physics and rendering.

## Requirements

To build and run this project, you will need the following tools installed on your Windows machine:
1. **Code::Blocks IDE**: Used as the primary development environment for the project.
2. **MinGW Compiler**: Specifically the MSYS2 UCRT64 toolchain (or a compatible GCC setup).
3. **FreeGLUT & OpenGL**: The graphics library used for window management, rendering, and input handling.

## Setup and Installation

1. **Clone the Repository**
   ```bash
   git clone https://github.com/BharathGDevadiga/Death-by-Race.git
   ```

2. **Open the Project**
   * Launch **Code::Blocks**.
   * Go to `File` -> `Open` and select the `Graphics Project.cbp` file located in the cloned project directory.

3. **Configure the Compiler (If necessary)**
   * Ensure your Code::Blocks is using the correct MinGW toolchain by going to `Settings` -> `Compiler` -> `Toolchain executables`.
   * Make sure the Linker settings include the required libraries: `-lfreeglut -lopengl32 -lglu32 -lwinmm -lgdi32`. (These are already configured in the `.cbp` file, so it should work automatically if your MSYS2 path matches).

4. **Build and Run**
   * Press **`F9`** (or click `Build and run` in the top toolbar) to compile and launch the game.

## Controls
* **S** - Shoot
* **Arrow Keys** - Move your vehicle (Up, Down, Left, Right)
* **P / R** - Pause / Resume the game
* **Q** - Quit the game
