// ---------------- Inclusions --------------------------------------------------------------------
// Define once only
#pragma once

// ---------------- Board Class ------------------------------------------------------------------
class Board {
public:
    // Constructor
    Board() = default;

    // Draw function
    void Draw();

    // Getter functions
    int getCellSize() const;
    int getGridWidth() const;
    int getGridHeight() const;
    int getBoardLeft() const;
    int getBoardTop() const;

private:
    // Grid sizes
    const int cellSize  = 32; // Both height and width of a cell
    const int gridWidth = 20; // Cell number, not pixel number
    const int gridHeight = 26; // Same

    // Grid offsets
    const int boardLeft = 50; // Offset from left
    const int boardTop = 150; // Offset from top
    const int boardRight = boardLeft + gridWidth * cellSize; // Offset from right
    const int boardBottom = boardTop + gridHeight * cellSize; // Offset from bottom
};

// ------------------------------------------------------------------------------------------------