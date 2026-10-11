// ---------------- Inclusions --------------------------------------------------------------------
// Define once only
#pragma once

// Raylib
#include <raylib.h>

// Local
#include "board.hpp"


// ---------------- Player Class ------------------------------------------------------------------
class Player {
public:
    Player(Board board);

    void Update(Board board);
    void Draw(Board board);

    float playerSpeed = 20.0;

private:
    Vector2 position;
    void Move(Board board);
    void Shoot(Board board);
};

// ------------------------------------------------------------------------------------------------