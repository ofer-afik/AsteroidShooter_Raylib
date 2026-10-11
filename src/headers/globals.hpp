// ---------------- Inclusions --------------------------------------------------------------------
// Define once only
#pragma once

// ---------------- Constants Namespace -------------------------------------------------------------
namespace globals { // Basically used for all global game constants
    // Window globals
    const int screenWidth = 700;
    const int screenHeight = 1000;

    inline float dt = 0.1f; // Delta time (time since last frame)

    // Color globals
    const Color lightSpace = Color{28, 28, 74, 255};
    const Color darkSpace = Color{20, 20, 49, 255};
}

// ------------------------------------------------------------------------------------------------