// ---------------- Inclusions --------------------------------------------------------------------
// Raylib
#include <raylib.h>

// Local
#include "../headers/board.hpp"
#include "../headers/constants.hpp"

// ---------------- Board Class -------------------------------------------------------------------
// Constructor
Board::Board() {
    // Grid (*note: that aren't defined as constants)
    cellSize = 20; // Both height and width of a cell
    gridWidth = 30; // Cell number, not pixel number
    gridHeight = 40; // Same

    // Offsets (screen edge to grid)
    boardLeft = 50;
    boardTop = 150;
    boardRight = boardLeft + gridWidth * cellSize;
    boardBottom = boardTop + gridHeight * cellSize;
}

// Draw function - called during main drawing phase, see main.cpp
void Board::Draw() {
    ClearBackground(constants::lightSpace);

    // Window border
    DrawRectangleLinesEx(Rectangle{0.0f, 0.0f,
                        static_cast<float>(constants::screenWidth), 
                        static_cast<float>(constants::screenHeight)},
                        10, constants::darkSpace);

    // Grid border
    DrawRectangleLinesEx(Rectangle{static_cast<float>(boardLeft - 5),
                        static_cast<float>(boardTop - 5),
                        static_cast<float>(boardRight - boardLeft + 10),
                        static_cast<float>(boardBottom - boardTop + 10)},
                        5, constants::darkSpace);

    // Vertical lines
    for (int i = 1; i < gridWidth; i++) {
        DrawLineEx(Vector2{static_cast<float>(boardLeft + i * cellSize), static_cast<float>(boardTop)},
                   Vector2{static_cast<float>(boardLeft + i * cellSize),static_cast<float>(boardBottom)},
                   1.5f, constants::darkSpace);
    };

    // Horizontal lines
    for (int i = 1; i < gridHeight; i++) {
        DrawLineEx(Vector2{static_cast<float>(boardLeft), static_cast<float>(boardTop + i * cellSize)},
                   Vector2{static_cast<float>(boardRight), static_cast<float>(boardTop + i * cellSize)},
                   1.5f, constants::darkSpace);
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