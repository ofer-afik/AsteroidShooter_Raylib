// ---------------- Inclusions --------------------------------------------------------------------
// Define once only
#pragma once

// Raylib
#include <raylib.h>

// Local
#include "board.hpp"

// ---------------- Bullet Class ------------------------------------------------------------------
class Bullet {
public:
    // Constructors
    Bullet() = default;

    // Functions
    void Update();
    void Draw(Board);

    // Properties
    bool active = false;
    Vector2 position = Vector2{0, 0}; // Position holder

    // Art assets
    static Image srcImg;
    static Texture2D bulletImg;

private:
    // Speed
    float bulletSpeed = 2000.0f;
};