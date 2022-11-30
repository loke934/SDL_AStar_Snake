#pragma once
#include <vector>
#include "GridCell.h"

#define GRID_SIZE_X 15
#define GRID_SIZE_Y 15
#define GRID_SIZE (GRID_SIZE_X * GRID_SIZE_Y)

class Grid
{
public:
    GridCell gridArray[GRID_SIZE_X][GRID_SIZE_Y];

    float offset = 25.f;
    float visualSpacing = 2.f;
    
    void SetupGrid();
    void DrawGrid();
    void FindPath(GridCell* startCell, GridCell* targetCell, std::vector<Vector2Int> &path);
    void SetNeighbors(const GridCell* currentCell, std::vector<GridCell*> &neighbors);
    int GetDistance(GridCell* cellA, GridCell* cellB);
    void RetracePath(GridCell* startCell, GridCell* targetCell, std::vector<Vector2Int> &path);
};



