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
    Player(Board);

    void Update(Board);
    void Draw(Board);

    float playerSpeed = 20.0f;

private:
    Vector2 position;
    void Move(Board);
    void Shoot();
    std::array<Bullet, 100> bullets;
};

// ------------------------------------------------------------------------------------------------