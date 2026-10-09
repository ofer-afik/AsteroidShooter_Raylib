// ---------------- Inclusions --------------------------------------------------------------------
// Define once only
#pragma once

// ---------------- Board Class ------------------------------------------------------------------
class Board {
public:
    Board();
    void Draw();
    int getCellSize();
    int getGridWidth();
    int getGridHeight();
    int getBoardLeft();
    int getBoardTop();

private:
    int cellSize;
    int gridWidth;
    int gridHeight;

    int boardLeft;
    int boardTop;
    int boardRight;
    int boardBottom;
};

// ------------------------------------------------------------------------------------------------