// ---------------- Inclusions --------------------------------------------------------------------
// Raylib
#include <raylib.h>

// Local
#include "../headers/player.hpp"
#include "../headers/board.hpp"
#include "../headers/constants.hpp"

// ---------------- Main Function -----------------------------------------------------------------
int main(void)
{
// ---------------- Initialization ----------------------------------------------------------------
    Board board; // Game-wide board (grid, background, UI...) object
    Player player = Player(board); // Game-wide player object

    InitWindow(constants::screenWidth, constants::screenHeight, "Arcade Asteroid Shooter"); // Initialize window

    SetTargetFPS(60); // Set game to run at 60 frames-per-second


// ---------------- Main game loop ----------------------------------------------------------------
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
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