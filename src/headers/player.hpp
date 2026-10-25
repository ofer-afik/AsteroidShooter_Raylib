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
    // Constructor + Deconstructor
    Player();
    ~Player();

    // Functions
    void Update(const Board&);
    void Draw(const Board&);

    // Properties
    float playerAccel = 40.0f;
    float playerMaxVel = 700.f;
    float playerVel  = 0.f;
    // double timeMoveBegan;
    Vector2 position;
    bool alive = true;

    // Bullets
    std::array<Bullet, 100> bullets;

private:
    // Helper functions
    void Move(const Board&);
    void Shoot();

    // Image assets
    Image srcImg;
    Texture2D playerImg;
};

// ------------------------------------------------------------------------------------------------