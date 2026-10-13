// ---------------- Inclusions --------------------------------------------------------------------
// Raylib
#include <raylib.h>

// Local
#include "../headers/player.hpp"
#include "../headers/board.hpp"
#include "../headers/globals.hpp"

// ---------------- Player Class ------------------------------------------------------------------
// Constructor
Player::Player(Board board) {
    position = Vector2{static_cast<float>(board.getGridWidth()) / 2,
        static_cast<float>(board.getGridHeight() - 5)}; // Number of cells, not number of pixels
}

// Logic/collisions update function - called during main update phase, see main.cpp
void Player::Update(Board board) {
    // Movement
    Move(board);

    // Shooting
    if (IsKeyPressed(KEY_SPACE)) {
        Shoot();
    }

    // Bullets
    for (Bullet& bullet : bullets) bullet.Update();
}

// Draw function - called during main drawing phase, see main.cpp
void Player::Draw(Board board) {
    // Draw player
    DrawRectangle(static_cast<float>(static_cast<int>(position.x) * board.getCellSize() + board.getBoardLeft()),
                  static_cast<float>(static_cast<int>(position.y) * board.getCellSize() + board.getBoardTop()),
                  static_cast<float>(board.getCellSize()),
                  static_cast<float>(board.getCellSize()),
                  BLACK);
    
    // Draw bullets
    for (Bullet& bullet : bullets) bullet.Draw(board);
}
// Helper function, called every Player::Update()
void Player::Move(Board board) {
    if (IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_RIGHT)) {
        return;
    }

    bool precisionSpeed = !(IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT));

    if (IsKeyDown(KEY_LEFT)) {
        position.x -= globals::dt * playerSpeed * (precisionSpeed ? 1.0f : 0.5f);
    }

    if (IsKeyDown(KEY_RIGHT))  {
        position.x += globals::dt * playerSpeed * (precisionSpeed ? 1.0f : 0.5f);
    }

    if (position.x < 0.0) {
        position.x = static_cast<float>(board.getGridWidth() - 1);
    }

    if (position.x >= static_cast<float>(board.getGridWidth())) {
        position.x = 0.0;
    }
}

// Helper function, called every space is pressed
void Player::Shoot() {
    for (Bullet& bullet : bullets) {
        if (!bullet.active) {
            bullet.active = true;
            bullet.position = position;
            break;
        }
    }
}

// ------------------------------------------------------------------------------------------------