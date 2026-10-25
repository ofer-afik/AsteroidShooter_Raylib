// ---------------- Inclusions --------------------------------------------------------------------
// C++
#include <algorithm>

// Raylib
#include <raylib.h>

// Local
#include "../headers/player.hpp"
#include "../headers/board.hpp"
#include "../headers/globals.hpp"
#include "../headers/embedded_assets.hpp"

// ---------------- Player Class ------------------------------------------------------------------
// Constructor
Player::Player() {
    // Position setup
    position = Vector2{320.0, 736.0}; // Number of pixels, not number of cells

    // Art setup
    srcImg = LoadEmbeddedImage("player.png");
    playerImg = LoadTextureFromImage(srcImg);
    UnloadImage(srcImg);
}

// Deconstructor
Player::~Player() {
    // Clear memory
    UnloadTexture(playerImg);
}

// Logic update function - called during main update phase, see main.cpp
void Player::Update(const Board& board) {
    // Movement
    Move(board);

    // Shooting
    if (IsKeyPressed(KEY_SPACE)) {
        Shoot();
    } 

    // Bullets
    for (Bullet& bullet : bullets) bullet.Update();
}

// Draw function - called during main drawing phase, see main.cpp
void Player::Draw(const Board& board) {
    // Draw player
    DrawTexture(playerImg, static_cast<int>(position.x) + board.getBoardLeft(), static_cast<int>(position.y) + board.getBoardTop(), WHITE);

    // Draw bullets
    for (Bullet& bullet : bullets) bullet.Draw(board);
}

// Helper function for moving, called every Player::Update()
void Player::Move(const Board& board) {
    const float dir = IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_RIGHT) ? 0.0f :
                      IsKeyDown(KEY_RIGHT) ? 1.0f :
                      IsKeyDown(KEY_LEFT) ? -1.0f : 0.0f;

    if (dir == 0.0f) {
        // Deceleration
        if (playerVel > 0.0f) {
            playerVel -= playerAccel;
            if (playerVel < 0.0f) playerVel = 0.0f;
        } else if (playerVel < 0.0f) {
            playerVel += playerAccel;
            if (playerVel > 0.0f) playerVel = 0.0f;
        }
    } else {
        // Acceleration
        playerVel += dir * playerAccel;
    }

    playerVel = std::clamp(playerVel, -playerMaxVel, playerMaxVel);
    position.x += playerVel * globals::dt;

    // Wrap around the player position if it goes out of bounds
    if (position.x <= -32.0) position.x = static_cast<float>((board.getGridWidth() - 1) * board.getCellSize());
    if (position.x >= static_cast<float>(board.getGridWidth() * board.getCellSize())) position.x = 0.0;
}

// Helper function for setting up bullets, called every space is pressed
void Player::Shoot() {
    for (Bullet& bullet : bullets) {
        if (!bullet.active) {
            bullet.active = true;
            bullet.position = position;
            break;
        }
    }
}

// ------------------------------------------------------------------------------------------------