// ---------------- Inclusions --------------------------------------------------------------------
// C++ Standard
#include <iostream>
#include <vector>
#include <random>

// Raylib
#include <raylib.h>

// Local
#include "../headers/player.hpp"
#include "../headers/board.hpp"
#include "../headers/globals.hpp"
#include "../headers/enemy.hpp"

// ---------------- Main Function -----------------------------------------------------------------
int main()
{
// ---------------- Initialization ----------------------------------------------------------------
    // Game config
    Board board; // Game-wide board (grid, background, UI...) object
    Player player = Player(board); // Game-wide player object
    std::vector<Enemy> enemies;

    // Enemy spawning engine
    std::random_device rd;
    std::mt19937 enemySpawnGen(rd());
    std::bernoulli_distribution enemySpawnDist(0.005);

    // Window config
    InitWindow(globals::screenWidth, globals::screenHeight, "Arcade Asteroid Shooter"); // Initialize window
    SetTargetFPS(120); // Set game to run at 60 frames-per-second


// ---------------- Main game loop ----------------------------------------------------------------
    while (!WindowShouldClose() && player.alive)    // Detect window close button or ESC key
    {
        // Update
        globals::dt = GetFrameTime(); // Update delta time variable

        player.Update(board);

        // Enemy spawning and updating
        for (int i = 0; i < static_cast<int>(GetTime() / 5.0); i++) {
            if (enemySpawnDist(enemySpawnGen)) enemies.push_back(Enemy(board));
        }

        for (Enemy& enemy : enemies) enemy.Update(board, player);
        std::erase_if(enemies, [](Enemy& enemy) { return !enemy.alive; }); // Remove dead enemies

        // Draw
        BeginDrawing();
            board.Draw();
            player.Draw(board);
            for (Enemy& enemy : enemies) enemy.Draw(board);
        EndDrawing();

        // Set properties for next frame logic
        for (Enemy& enemy : enemies) enemy.lastFramePos = enemy.position;
}

// ---------------- De-Initialization -------------------------------------------------------------

// ---------------- Close and finish --------------------------------------------------------------
    CloseWindow();        // Close window
    return 0;
}

// ------------------------------------------------------------------------------------------------