// ---------------- Inclusions --------------------------------------------------------------------
// C++

// Raylib
#include <raylib.h>

// Local
#include "globals.hpp"
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
    Vector2 lastFramePos;
    bool alive = true;

private:
    float speed;
};