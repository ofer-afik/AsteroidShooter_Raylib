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
    std::uniform_int_distribution<int> posDist(0, board.getGridWidth()  - 1);
    std::uniform_real_distribution<float> speedDist(5.0f, 0.5f * GetTime() + 5.0f); // Speed increases over time, but not too much

    // Other set up
    // Speed and position set up
    position.x = static_cast<float>(posDist(posGen));
    position.y = 0;

    speed = speedDist(speedGen);
}

// Update function
void Enemy::Update(Board board, Player& player) {
    // Update position
    position.y += globals::dt * speed;

    // Check collisions
    // Player collision
    if (static_cast<int>(player.position.x) == static_cast<int>(position.x)) {
        if (static_cast<int>(position.y) <= static_cast<int>(player.position.y) &&
            static_cast<int>(player.position.y) <= static_cast<int>(lastFramePos.y)) {
            player.alive = false;
        }
    }

    // Bullet collision
    for (Bullet& bullet : player.bullets) {
        if (static_cast<int>(bullet.position.x) == static_cast<int>(position.x) && bullet.active) {
            if (static_cast<int>(bullet.position.y) <= static_cast<int>(lastFramePos.y)) {
                alive = false;
                bullet.active = false;
            }
        }
    }

    // Boundary collision
    if (static_cast<int>(position.y) >= board.getGridHeight()) alive = false;
}

// Draw function
void Enemy::Draw(Board board) {
    DrawRectangle(static_cast<float>(static_cast<int>(position.x) * board.getCellSize() + board.getBoardLeft()),
                static_cast<float>(static_cast<int>(position.y) * board.getCellSize() + board.getBoardTop()),
                static_cast<float>(board.getCellSize()),
                static_cast<float>(board.getCellSize()),
                MAGENTA);
}