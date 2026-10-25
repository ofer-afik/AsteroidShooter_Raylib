// ---------------- Inclusions --------------------------------------------------------------------
// C++ Standard
#include <iostream>
#include <vector>
#include <random>
#include <memory>
#include <string>
#include <typeinfo>

// Raylib
#include <raylib.h>

// Local
#include "../headers/player.hpp"
#include "../headers/board.hpp"
#include "../headers/globals.hpp"
#include "../headers/enemy.hpp"
#include "../headers/gamestates.hpp"

// ---------------- Pre-Function Set up -----------------------------------------------------------
// Initialize state pointer
std::unique_ptr<GameState> globals::currentState = std::make_unique<TitleScreen>();


// ---------------- Main Function -----------------------------------------------------------------
int main() {
    // Initialize window
    InitWindow(globals::currentState->screenWidth, globals::currentState->screenHeight, globals::windowTitle.c_str());
    SetTargetFPS(120);

    // Load bullet art
    Bullet::srcImg = LoadImage("src/assets/pixelorama/images/bullet.png");
    Bullet::bulletImg = LoadTextureFromImage(Bullet::srcImg);
    UnloadImage(Bullet::srcImg);

    // Load enemy art
    Enemy::srcImg = LoadImage("src/assets/pixelorama/images/enemy.png");
    Enemy::enemyImg = LoadTextureFromImage(Enemy::srcImg);
    UnloadImage(Enemy::srcImg);

    // Main game loop
    while (!WindowShouldClose()) {
        // Update delta time
        globals::dt = GetFrameTime();

        // Update game
        globals::currentState->Update();

        // Draw game
        BeginDrawing();
            globals::currentState->Draw();
        EndDrawing();
    }


    CloseWindow();
    return 0;
}

// ------------------------------------------------------------------------------------------------