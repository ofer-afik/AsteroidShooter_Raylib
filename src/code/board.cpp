// ---------------- Inclusions --------------------------------------------------------------------
// Raylib
#include <raylib.h>

// Local
#include "../headers/board.hpp"
#include "../headers/globals.hpp"

// ---------------- Board Class -------------------------------------------------------------------
// Draw function - called during main drawing phase, see main.cpp
void Board::Draw() {
    ClearBackground(globals::lightSpace);

    // Window border
    DrawRectangleLinesEx(Rectangle{0.0f, 0.0f,
                        static_cast<float>(globals::screenWidth), 
                        static_cast<float>(globals::screenHeight)},
                        10, globals::darkSpace);

    // Grid border
    DrawRectangleLinesEx(Rectangle{static_cast<float>(boardLeft - 5),
                        static_cast<float>(boardTop - 5),
                        static_cast<float>(boardRight - boardLeft + 10),
                        static_cast<float>(boardBottom - boardTop + 10)},
                        5, globals::darkSpace);

    // Vertical lines
    for (int i = 1; i < gridWidth; i++) {
        DrawLineEx(Vector2{static_cast<float>(boardLeft + i * cellSize), static_cast<float>(boardTop)},
                   Vector2{static_cast<float>(boardLeft + i * cellSize),static_cast<float>(boardBottom)},
                   1.5f, globals::darkSpace);
    };

    // Horizontal lines
    for (int i = 1; i < gridHeight; i++) {
        DrawLineEx(Vector2{static_cast<float>(boardLeft), static_cast<float>(boardTop + i * cellSize)},
                   Vector2{static_cast<float>(boardRight), static_cast<float>(boardTop + i * cellSize)},
                   1.5f, globals::darkSpace);
    };
}

// Getter functions

int Board::getCellSize() {
    return cellSize;
}

int Board::getGridWidth() {
    return gridWidth;
}

int Board::getGridHeight() {
    return gridHeight;
}

int Board::getBoardLeft() {
    return boardLeft;
}
int Board::getBoardTop() {
    return boardTop;
}

// ------------------------------------------------------------------------------------------------