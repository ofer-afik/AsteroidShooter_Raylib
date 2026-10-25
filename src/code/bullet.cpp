// ---------------- Inclusions --------------------------------------------------------------------
// Raylib
#include <raylib.h>

// Local
#include "../headers/bullet.hpp"
#include "../headers/globals.hpp"

// ---------------- Bullet Class ------------------------------------------------------------------
// Art setup
Image Bullet::srcImg = {};
Texture2D Bullet::bulletImg = {};

void Bullet::Update() {
    // Update position
    position.y -= bulletSpeed * globals::dt;

    // Check boundaries
    if (static_cast<int>(position.y) < 0) active = false;
}

void Bullet::Draw(Board board) {
    if (active) {
        DrawTexture(bulletImg, static_cast<int>(position.x) + board.getBoardLeft(), static_cast<int>(position.y) + board.getBoardTop(), WHITE);
    }
}