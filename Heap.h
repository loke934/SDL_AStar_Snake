#pragma once
#include "Grid.h"

class GridCell;

class Heap
{
public:
    GridCell* items [GRID_SIZE];
    int currentItemCount = 0;

    void Add(GridCell* item);
    GridCell* RemoveFirst();
    void SortUp(GridCell* item);
    void SortDown(GridCell* item);
    void Swap(GridCell* a, GridCell* b);
    int Compare(const GridCell* a, const GridCell* b);
    bool Contains(GridCell* item);
    void UpdateItem(GridCell* item);
};
