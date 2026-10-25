// ---------------- Inclusions --------------------------------------------------------------------
// Raylib
#include <raylib.h>

// Local
#include "../headers/board.hpp"
#include "../headers/globals.hpp"

// ---------------- Board Class -------------------------------------------------------------------
// Draw function - called during main drawing phase, see main.cpp
void Board::Draw() {
    // Window border
    DrawRectangleLinesEx(Rectangle{0.0f, 0.0f,
                        static_cast<float>(globals::currentState->screenWidth), 
                        static_cast<float>(globals::currentState->screenHeight)},
                        10, globals::colors[2]);

    // Grid border
    DrawRectangleLinesEx(Rectangle{static_cast<float>(boardLeft - 5),
                        static_cast<float>(boardTop - 5),
                        static_cast<float>(boardRight - boardLeft + 10),
                        static_cast<float>(boardBottom - boardTop + 10)},
                        5, globals::colors[2]);
}

// Getter functions
int Board::getCellSize() const{
    return cellSize;
}

int Board::getGridWidth() const{
    return gridWidth;
}

int Board::getGridHeight() const{
    return gridHeight;
}

int Board::getBoardLeft() const{
    return boardLeft;
}
int Board::getBoardTop() const{
    return boardTop;
}

// ------------------------------------------------------------------------------------------------