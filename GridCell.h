#pragma once

enum GRIDCELL_STATE
{
    WALKABLE,
    OBSTACLE,
    FRUIT
};

struct Vector2
{
    Vector2()
    {
        x = 0;
        y = 0;
    }
    float x;
    float y;
};

struct Vector2Int
{
    Vector2Int()
    {
        x = 0;
        y = 0;
    }
    int x;
    int y;
};

class GridCell
{
public:
    //Grid
    Vector2 worldPosition;
    GRIDCELL_STATE currentState = WALKABLE;

    //Pathfinding
    Vector2Int gridPosition;
    int gCost = 0;
    int hCost = 0;
    GridCell* parent = nullptr;
    int FCost() const
    {
        return gCost + hCost;
    }
    int heapIndex;

    //Render 
    float width = 50.f;
    float height = 50.f;
    void Draw();
};
