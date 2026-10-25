// ---------------- Inclusions --------------------------------------------------------------------
#pragma once

// C++

// Raylib
#include <raylib.h>

// Local
#include "board.hpp"
#include "player.hpp"

// ---------------- Enemy Class -------------------------------------------------------------------
class Enemy {
public:
    // Constructor
    Enemy(Board);

    // Functions
    void Update(Board, Player&);
    void Draw(Board);

    // Properties
    Vector2 position;
    bool alive = true;

    // Art assets
    static Image srcImg;
    static Texture2D enemyImg;

private:
    float enemySpeed;
};