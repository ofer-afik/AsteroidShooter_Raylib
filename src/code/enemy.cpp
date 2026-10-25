// ---------------- Inclusions --------------------------------------------------------------------
// C++
#include <random>

// Raylib
#include <raylib.h>

// Local
#include "../headers/enemy.hpp"
#include "../headers/globals.hpp"

// ---------------- Enemy Class -------------------------------------------------------------------
// Constructor
Enemy::Enemy(Board board) {
    // Random engines set up
    // Random devices
    std::random_device posRD;
    std::random_device speedRD;

    // Random engines
    std::mt19937 posGen(posRD());
    std::mt19937 speedGen(speedRD());

    // Distribution
    std::uniform_int_distribution<int> posDist(0, (board.getGridWidth() - 1) * board.getCellSize());
    std::uniform_real_distribution<float> speedDist(160.0f, 10.0f * (GetTime() - globals::currentState->timeSinceStateBeginning) + 32.0f); // Speed increases over time, but not too much

    // Other set up
    // Speed and position set up
    position.x = static_cast<float>(posDist(posGen));
    position.y = 0;

    enemySpeed = speedDist(speedGen);
}

// Art setup
Image Enemy::srcImg = {};
Texture2D Enemy::enemyImg = {};

// Update function + all game collisions
void Enemy::Update(Board board, Player& player) {
    // Update position
    position.y += globals::dt * enemySpeed;

    // Check collisions
    // Player collision
    if (CheckCollisionRecs(
        // Player rec
        Rectangle{player.position.x + static_cast<float>(board.getBoardLeft()), // pos x
                  player.position.y + static_cast<float>(board.getBoardTop()), // pos y
                  static_cast<float>(board.getCellSize()), // - - - - - - - width
                  static_cast<float>(board.getCellSize())}, // - - - - - - height
        // Enemy rec
        Rectangle{position.x + static_cast<float>(board.getBoardLeft()), // pos x
                  position.y + static_cast<float>(board.getBoardTop()), // pos y
                  static_cast<float>(board.getCellSize()), // - - - - - - - width
                  static_cast<float>(board.getCellSize())})) // - - - - - - height
    {
        player.alive = false;
    }

    // Bullet collision
    for (Bullet& bullet : player.bullets) {
        if (bullet.active && CheckCollisionRecs(
            // Bullet rec
            Rectangle{bullet.position.x + static_cast<float>(board.getBoardLeft() + 11.0), // pos x
                    bullet.position.y + static_cast<float>(board.getBoardTop()), // pos y
                    10.0, // - - - - - - - - - - - - - - - - - - - - - - - - - - - - width
                    static_cast<float>(board.getCellSize())}, // - - - - - - - - - height
            // Enemy rec
            Rectangle{position.x + static_cast<float>(board.getBoardLeft()), // pos x
                    position.y + static_cast<float>(board.getBoardTop()), // pos y
                    static_cast<float>(board.getCellSize()), // - - - - - - width
                    static_cast<float>(board.getCellSize())}))// - - - - - - height
        {
            bullet.active = false;
            alive = false;
            globals::enemiesKilled++;
        }
    }

    // Boundary collision
    if (static_cast<int>(position.y) >= (board.getGridHeight() - 1) * board.getCellSize()) {
        alive = false;
        globals::enemiesPassed++;
    }
}

// Draw function
void Enemy::Draw(Board board) {
    DrawTexture(enemyImg,
                static_cast<int>(position.x) + board.getBoardLeft(),
                static_cast<int>(position.y) + board.getBoardTop(),
                WHITE);
}

// ------------------------------------------------------------------------------------------------