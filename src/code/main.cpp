// ---------------- Inclusions --------------------------------------------------------------------
// C++ Standard
#include <iostream>

// Raylib
#include <raylib.h>

// Local
#include "../headers/player.hpp"
#include "../headers/board.hpp"
#include "../headers/globals.hpp"

// ---------------- Main Function -----------------------------------------------------------------
int main(void)
{
// ---------------- Initialization ----------------------------------------------------------------
    Board board; // Game-wide board (grid, background, UI...) object
    Player player = Player(board); // Game-wide player object

    InitWindow(globals::screenWidth, globals::screenHeight, "Arcade Asteroid Shooter"); // Initialize window

    SetTargetFPS(60); // Set game to run at 60 frames-per-second


// ---------------- Main game loop ----------------------------------------------------------------
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        globals::dt = GetFrameTime();
        std::cout << std::endl << globals::dt;
        player.Update(board);

        // Draw
        BeginDrawing();
            board.Draw();
            player.Draw(board);
        EndDrawing();

    }

// ---------------- De-Initialization -------------------------------------------------------------

// ---------------- Close and finish --------------------------------------------------------------
    CloseWindow();        // Close window
    return 0;
}

// ------------------------------------------------------------------------------------------------