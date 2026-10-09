// ---------------- Inclusions --------------------------------------------------------------------
// Raylib
#include <raylib.h>

// Local
#include "../headers/player.hpp"
#include "../headers/board.hpp"

// ---------------- Player Class ------------------------------------------------------------------
// Constructor
Player::Player(Board board) {
    position = Vector2{static_cast<float>(board.getGridWidth()) / 2, static_cast<float>(board.getGridHeight() - 5)}; // Number of cells, not number of pixels
}

// Logic/collisions update function - called during main update phase, see main.cpp
void Player::Update(Board board) {
    Move(board);
}

// Draw function - called during main drawing phase, see main.cpp
void Player::Draw(Board board) {
    DrawRectangle(static_cast<float>(position.x * board.getCellSize() + board.getBoardLeft()),
                  static_cast<float>(position.y * board.getCellSize() + board.getBoardTop()),
                  static_cast<float>(board.getCellSize()),
                  static_cast<float>(board.getCellSize()),
                  BLACK);
}
// A helper function
void Player::Move(Board board) {
    if (IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_RIGHT)) {
        return;
    }

    if (IsKeyDown(KEY_LEFT)) {
        position.x -= 1.0;
    }

    if (IsKeyDown(KEY_RIGHT)) {
        position.x += 1.0;
    }

    if (position.x < 0.0) {
        position.x = 0.0;
    }

    if (position.x >= static_cast<float>(board.getGridWidth())) {
        position.x = static_cast<float>(board.getGridWidth() - 1);
    }
}


// ------------------------------------------------------------------------------------------------