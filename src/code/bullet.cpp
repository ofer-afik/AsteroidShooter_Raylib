// ---------------- Inclusions --------------------------------------------------------------------
// Raylib
#include <raylib.h>

// Local
#include "../headers/bullet.hpp"
#include "../headers/globals.hpp"

// ---------------- Bullet Class ------------------------------------------------------------------
Bullet::Bullet(Vector2 pos) {
    position = pos;
}

void Bullet::Update() {
    // Update position
    position.y -= speed * globals::dt;

    // Check boundaries
    active = static_cast<int>(position.y) < 0 ? active = false : active = true;
}

void Bullet::Draw(Board board) {
    if (active) {
        DrawRectangle(static_cast<float>(static_cast<int>(position.x) * board.getCellSize() + board.getBoardLeft()),
                    static_cast<float>(static_cast<int>(position.y) * board.getCellSize() + board.getBoardTop()),
                    static_cast<float>(board.getCellSize()),
                    static_cast<float>(board.getCellSize()),
                    WHITE);
    }
}