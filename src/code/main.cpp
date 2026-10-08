#include <raylib.h>
#include "../headers/player.hpp"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 650;
    const int screenHeight = 950;

    const int cellSize = 10;

    const Player player = Player();



    InitWindow(screenWidth, screenHeight, "Arcade Asteroid Shooter"); // Initialize window

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(Color{28, 28, 74, 255});
            DrawRectangleLinesEx(Rectangle{0, 0, screenWidth, screenHeight}, 5, Color{14, 14, 37, 255});
            DrawRectangleLinesEx(Rectangle{50, 150, screenWidth - 100, screenHeight - 200}, 5, Color{14, 14, 37, 255});
            

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window
    //--------------------------------------------------------------------------------------

    return 0;
}