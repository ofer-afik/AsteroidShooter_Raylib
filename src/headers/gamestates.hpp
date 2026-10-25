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

// ---------------- State Machine -----------------------------------------------------------------
// General game state class
class GameState {
public:
    // Abstract functions
    virtual void Draw() = 0;
    virtual void Update() = 0;

    // Window properties
    int screenWidth;
    int screenHeight;

    // Time
    double timeSinceStateBeginning;
};

// Title Screen
class TitleScreen : public GameState {
public:
    // Constructor + Deconstructor
    TitleScreen();
    ~TitleScreen();

    // Main functions
    void Draw() override;
    void Update() override;

    // Background assets
    Texture2D bg;
    Image image;
    bool bgLoaded = false;
};

// Menu class
class Menu : public GameState {
public:
    // Constructor + Deconstructor
    Menu();
    ~Menu();

    // Main functions
    void Draw() override;
    void Update() override;

    // Art assets
    Image srcImg;
    Texture2D heartImg;
};

// Game play class
class GamePlay : public GameState {
public:
    // Constructor + Deconstructor
    GamePlay();
    ~GamePlay();

    // Main functions
    void Draw() override;
    void Update() override;

    // Game mechanics objects
    std::vector<Enemy> enemies;
    Board board;
    Player player;
};

// Game over state class
class GameOver : public GameState {
public:
    // Constructor + Destructor
    GameOver();
    ~GameOver();

    // Main functions
    void Draw() override;
    void Update() override;

    // Background assets
    Image image;
    Texture2D bg;
    bool bgLoaded = false;
};

// ------------------------------------------------------------------------------------------------