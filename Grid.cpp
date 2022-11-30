#include "Grid.h"
#include "Heap.h"
#include <unordered_set>

void Grid::SetupGrid()
{
    for (int x = 0; x < GRID_SIZE_X; x++)
    {
        for (int y = 0; y < GRID_SIZE_Y; y++)
        {
            gridArray[x][y].worldPosition.x = x * visualSpacing + x * gridArray[x][y].width - visualSpacing + offset;
            gridArray[x][y].worldPosition.y = y * visualSpacing + y * gridArray[x][y].height -visualSpacing + offset;
            gridArray[x][y].gridPosition.x = x;
            gridArray[x][y].gridPosition.y = y;
        }
    }
}

void Grid::DrawGrid()
{
    for (int x = 0; x < GRID_SIZE_X; ++x)
    {
        for (int y = 0; y < GRID_SIZE_Y; ++y)
        {
            gridArray[x][y].Draw();
        }
    }
}

void Grid::FindPath(GridCell* startCell, GridCell* targetCell, std::vector<Vector2Int> &path)
{
    Heap openSet;
    std::unordered_set<GridCell*> closedSet;
    openSet.Add(startCell);
  
    while (openSet.currentItemCount > 0)
    {
        GridCell* currentCell = openSet.RemoveFirst();
        closedSet.insert(currentCell);
        
        if (currentCell == targetCell) 
        {
            RetracePath(startCell, targetCell, path);
            return;
        }

        std::vector<GridCell*> neighbors;
        SetNeighbors(currentCell, neighbors);
       
        for (GridCell*& neighbour : neighbors)
        {
            if ( closedSet.find(neighbour) != closedSet.end())
            {
                continue;
            }
            const int newMovementCostToNeighbor = currentCell->gCost + GetDistance(currentCell, neighbour);
            if (newMovementCostToNeighbor < neighbour->gCost || !openSet.Contains(neighbour))
            {
                neighbour->gCost = newMovementCostToNeighbor;
                neighbour->hCost = GetDistance(neighbour, targetCell);
                neighbour->parent = currentCell;
                if (!openSet.Contains(neighbour))
                {
                    openSet.Add(neighbour);
                }
            }
        }
    }
}


void Grid::SetNeighbors(const GridCell* currentCell, std::vector<GridCell*> &neighbors)
{
    for (int x = -1; x <= 1; x++)
    {
        for (int y = -1; y <= 1; y++)
        {
            //excluding diagonal
            if (x == -1 && y ==-1 || x == -1 && y == 1 || x == 1 && y == -1 || x == 1 && y == 1 || x == 0 && y == 0)
            {
                continue;
            }

            const int checkX = currentCell->gridPosition.x + x;
            const int checkY = currentCell->gridPosition.y + y;
        
            if (checkX >= 0 && checkX < GRID_SIZE_X && checkY >= 0 && checkY < GRID_SIZE_Y)
            {
                if (gridArray[checkX][checkY].currentState != OBSTACLE)
                {
                    neighbors.push_back(&gridArray[checkX][checkY]);
                }
            }
        }
    }
}

int Grid::GetDistance(GridCell* cellA, GridCell* cellB)
{
    int distX = abs(cellA->gridPosition.x - cellB->gridPosition.x);
    int distY = abs(cellA->gridPosition.y - cellB->gridPosition.y);

    if (distX > distY)
    {
        return 10 * distY + 10 * (distX-distY);
    }
    return  10 * distX + 10 * (distY-distX);
}

void Grid::RetracePath(GridCell* startCell, GridCell* targetCell, std::vector<Vector2Int> &path)
{
    GridCell* currentCell = targetCell;
    
    while (currentCell != startCell)
    {
        path.push_back(currentCell->gridPosition);
        currentCell = currentCell->parent;
    }
    std::reverse(path.begin(), path.end());
}