// ---------------- Inclusions --------------------------------------------------------------------
// Define once only
#pragma once

// Raylib
#include <raylib.h>

// Local
#include "globals.hpp"
#include "board.hpp"

// ---------------- Bullet Class ------------------------------------------------------------------
class Bullet {
public:
    // Constructors
    Bullet() = default; // Default-constructor, for empty bullets (for bullets array creation)
    Bullet(Vector2); // Constructor

    // Functions
    void Update();
    void Draw(Board);

    // Properties
    bool active = false;
    Vector2 position = Vector2{0, 0}; // Position holder

private:
    float speed = 60.0f;
};