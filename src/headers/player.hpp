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
    Player();
    void Update();
    void Draw(Board board);

private:
    Vector2 position;
};

// ------------------------------------------------------------------------------------------------