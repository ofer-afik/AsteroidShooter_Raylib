// ---------------- Inclusions --------------------------------------------------------------------
// Raylib
#include <raylib.h>

// Local
#include "../headers/player.hpp"
#include "../headers/board.hpp"

// ---------------- Player Class ------------------------------------------------------------------
// Constructor
Player::Player() {
    position = Vector2{0, 0}; // Number of cells, not number of pixels
}

// Logic/collisions update function - called during main update phase, see main.cpp
void Player::Update() {
    // Currently empty - TODO
}

// Draw function - called during main drawing phase, see main.cpp
void Player::Draw(Board board) {
    DrawRectangle(static_cast<float>(position.x * board.getCellSize() + board.getBoardLeft()),
                  static_cast<float>(position.y * board.getCellSize() + board.getBoardTop()),
                  static_cast<float>(board.getCellSize()),
                  static_cast<float>(board.getCellSize()),
                  BLACK);
}

// ------------------------------------------------------------------------------------------------