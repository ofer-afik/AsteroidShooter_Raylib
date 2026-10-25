// ---------------- Inclusions --------------------------------------------------------------------
// Define once only
#pragma once

// C++
#include <raylib.h>
#include <string>
#include <memory>
#include <random>
#include <vector>

// Local
#include "board.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "gamestates.hpp"

// ---------------- Constants Namespace -------------------------------------------------------------
namespace globals { // Basically used for all global game constants
    // Delta time
    inline float dt = 0.1f; // Delta time (time since last frame)

    // Scores
    inline int enemiesKilled;
    inline int enemiesPassed;
    inline int lives = 5;

    // Window title
    const std::string windowTitle = "Asteroid Shooter";

    // Color globals
    inline Color colors[] = {
        Color{  19,  38,  12, 255 },
        Color{  15,  21,  38, 255 },
        Color{  37,   0,  19, 255 },
        Color{  71,  21,  93, 255 },
        Color{  81,  68, 138, 255 },
        Color{  83, 116, 206, 255 },
        Color{  79, 176, 189, 255 },
        Color{  64, 128,  41, 255 },
        Color{ 120, 241,  76, 255 },
        Color{ 226, 243, 126, 255 },
        Color{ 255, 238, 231, 255 }
    };

    // States
    extern std::unique_ptr<GameState> currentState;
};

// ------------------------------------------------------------------------------------------------