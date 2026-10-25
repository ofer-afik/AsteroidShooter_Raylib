// ---------------- Inclusions --------------------------------------------------------------------
// C++
#include <random>
#include <vector>
#include <string>

// Raylib
#include <raylib.h>

// Local
#include "../headers/globals.hpp"
#include "../headers/player.hpp"
#include "../headers/enemy.hpp"
#include "../headers/board.hpp"
#include "../headers/gamestates.hpp"

// ---------------- Title screen ------------------------------------------------------------------
// Constructor
TitleScreen::TitleScreen() {
    // Game window properties
    screenWidth = 1024;
    screenHeight = 512;
}

// Deconstructor
TitleScreen::~TitleScreen() {
    UnloadTexture(bg);
}

// Title screen update phase
void TitleScreen::Update() {
    // Load texture
    if (!bgLoaded) { // If bg null
        image = LoadImage("src/assets/pixelorama/images/titlescreen.png");
        bg = LoadTextureFromImage(image);
        UnloadImage(image);
        bgLoaded = true;
    }

    // Close title screen
    if (IsKeyPressed(KEY_ENTER)) {
        globals::currentState = std::make_unique<Menu>();
    }
}

// Title screen draw phase
void TitleScreen::Draw() {
    DrawTexture(bg, 0, 0, WHITE);
}

// ---------------- Gameplay class ----------------------------------------------------------------
// Constructor
GamePlay::GamePlay() {
    // Game window properties
    screenWidth = 750;
    screenHeight = 1024;

    SetWindowSize(screenWidth, screenHeight);

    // Time
    timeSinceStateBeginning = GetTime();
}

// Decontructor
GamePlay::~GamePlay() {

}

// Gameplay update phase
void GamePlay::Update() {
    // Set up enemy spawn engine
    std::random_device rd;
    std::mt19937 enemySpawnGen(rd());
    std::bernoulli_distribution enemySpawnDist(0.005);

    // Run enemy spawning
    for (int i = 0; i < static_cast<int>((GetTime() - timeSinceStateBeginning) / 5.0); i++) {
        if (enemySpawnDist(enemySpawnGen)) enemies.push_back(Enemy(board));
    }

    for (Enemy& enemy : enemies) enemy.Update(board, player);
    std::erase_if(enemies, [](Enemy& enemy) { return !enemy.alive; }); // Remove dead enemies

    // Update player
    player.Update(board);

    if (!player.alive) {
        globals::lives--;
        globals::currentState = std::make_unique<Menu>();
    }

    if (globals::enemiesPassed >= 100) {
        globals::currentState = std::make_unique<GameOver>();
    }
}

// Gameplay draw phase
void GamePlay::Draw() {
    ClearBackground(globals::colors[1]);

    // UI
    const std::string killedText = "Enemies killed: " + std::to_string(globals::enemiesKilled);
    const std::string escapedText = "Enemies escaped: " + std::to_string(globals::enemiesPassed);

    DrawText(escapedText.c_str(), 30, 20, 20, globals::colors[4]);
    DrawText(killedText.c_str(), 350, 20, 20, globals::colors[8]);

    // Game elements
    board.Draw();
    player.Draw(board);
    for (Enemy& enemy : enemies) enemy.Draw(board);
}

// ---------------- Menu class --------------------------------------------------------------------
// Constructor
Menu::Menu() {
    // Window properties
    screenWidth = 700;
    screenHeight = 1000;

    SetWindowSize(screenWidth, screenHeight);

    // Art assets
    srcImg = LoadImage("src/assets/pixelorama/images/heart.png");
    heartImg = LoadTextureFromImage(srcImg);
    UnloadImage(srcImg);
}

// Deconstructor
Menu::~Menu() {
    UnloadTexture(heartImg);
}

// Menu update phase
void Menu::Update() {
    // If out of lives, end game
    if (globals::lives <= 0) {
        globals::currentState = std::make_unique<GameOver>();
    }

    // Close menu
    if (IsKeyPressed(KEY_ENTER)) {
        globals::currentState = std::make_unique<GamePlay>();
    }
}

// Menu draw phase
void Menu::Draw() {
    ClearBackground(globals::colors[1]);

    // Lives
    for (int i = 0; i < globals::lives; i++) {
        DrawTexture(heartImg, 40 + 70 * i, 40, WHITE);
    }
    
    // Lore text
    DrawText("HQ COMMAND BROADCAST", 15, 200, 50, globals::colors[2]);
    DrawText("05 16 2076\n18:37:24", 150, 260, 30, globals::colors[3]);
    DrawText("    Pilots, you are humankind's last hope.\n"
             "You have each been assigned a post to defend.\n"
             "If just a single assigned pilot falls, we will fail.\n\n"
             "    We have lost nearly all pilots in Wars I\n"
             "and II. Thankfully, we have many ships in store. You\n"
             "have each been asigned five ships, to use when ejected\n"
             "of a destroyed ship. Use them well.\n\n"
             "    Should a single post allow just 100 ships to pass\n"
             "through the defensive line to earth, the collective\n"
             "chain explosion will be enough to destroy earth.\n\n"
             "    When no more enemy ships come, you will know that \n"
             "you have succeeded. But you may not live to see the\n"
             "the day.\n\n"
             "    But no matter what, remember, humanity depends on\n"
             "you.\n\n"
             "    DO NOT FAIL.",
             50, 350, 20, globals::colors[5]);
    
    // Instructions text
    DrawText("Use arrows << and >> to move, space to shoot.\nPress enter to launch first ship.", 75, 850, 20, globals::colors[4]);
}

// ---------------- Game over class ---------------------------------------------------------------
// Constructor
GameOver::GameOver() {
    // Game window properties
    screenWidth = 512;
    screenHeight = 512;

    SetWindowSize(screenWidth, screenHeight);
}

// Decontsructor
GameOver::~GameOver() {
    UnloadTexture(bg);
}

// Game over update phase
void GameOver::Update() {
    // Load texture
    if (!bgLoaded) { // If bg null
        image = LoadImage("src/assets/pixelorama/images/gameoverscreen.png");
        bg = LoadTextureFromImage(image);
        UnloadImage(image);
        bgLoaded = true;
    }
}

// Game over draw phase
void GameOver::Draw() {
    DrawTexture(bg, 0, 0, WHITE);
}

// ------------------------------------------------------------------------------------------------