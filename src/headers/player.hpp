// ---------------- Inclusions --------------------------------------------------------------------
// Define once only
#pragma once

// C++
#include <array>

// Raylib
#include <raylib.h>

// Local
#include "board.hpp"
#include "bullet.hpp"


// ---------------- Player Class ------------------------------------------------------------------
class Player {
public:
    // Constructor
    Player(Board);

    // Functions
    void Update(Board);
    void Draw(Board);

    // Properties
    float playerSpeed = 20.0f;
    Vector2 position;
    bool alive = true;

    // Bullets
    std::array<Bullet, 100> bullets;



private:
    void Move(Board);
    void Shoot();
    double lastMoveTime = 0.0; // Time of last movement, for movement speed control
    bool heldMovement = false; // If the player is holding down a movement key, for movement speed control
};

// ------------------------------------------------------------------------------------------------