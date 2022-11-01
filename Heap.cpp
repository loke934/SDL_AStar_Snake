#include "Heap.h"

void Heap::Add(GridCell* item)
{
    item->heapIndex = currentItemCount;
    items[currentItemCount] = item;
    SortUp(item);
    currentItemCount++;
}

GridCell* Heap::RemoveFirst()
{
    GridCell* firstItem = items[0];
    currentItemCount--;
    items[0] = items[currentItemCount];
    items[0]->heapIndex = 0;
    SortDown(items[0]);
    return firstItem;
}

void Heap::SortUp(GridCell* item)
{
    int parentIndex = (item->heapIndex-1)/2;

    while (true)
    {
        GridCell* parentItem = items[parentIndex];
        if (Compare(item,parentItem) > 0)
        {
            Swap(item,parentItem);
        }
        else
        {
            break;
        }
        parentIndex = (item->heapIndex-1)/2;
    }

}

void Heap::SortDown(GridCell* item)
{
    while (true)
    {
        int childIndexLeft = item->heapIndex * 2 + 1;
        int childIndexRight = item->heapIndex * 2 + 2;
        int swapIndex = 0;
        //set the index to be swapped to the child with the lowest f-cost
        if (childIndexLeft < currentItemCount)
        {
            swapIndex = childIndexLeft;
            
            if (childIndexRight < currentItemCount)
            {
                if (Compare(items[childIndexLeft],items[childIndexRight]) < 0)
                {
                    swapIndex = childIndexRight;
                }
            }
            if (Compare(item, items[swapIndex]) < 0)
            {
                Swap(item,items[swapIndex]);
            }
            else
            {
                return;
            }
        }
        else
        {
            return;
        }
    }
}

void Heap::Swap(GridCell* a, GridCell* b)
{
    items[a->heapIndex] = b;
    items[b->heapIndex] = a;
    int temp = a->heapIndex;
    a->heapIndex = b->heapIndex;
    b->heapIndex = temp;
}

int Heap::Compare(const GridCell* a, const GridCell* b)
{
    //Higher prioritization (lowest f-cost) will return 1, lowe -1, h-cost as tiebreaker
    int compare;
    if (a->FCost() < b->FCost())
    {
        compare = 1;
    }
    else if (a->FCost() == b->FCost())
    {
        if (a->hCost < b->hCost)
        {
            compare = 1;
        }
        else
        {
            compare = -1;
        }
    }
    else
    {
        compare = -1;
    }
    
    return compare;
}

bool Heap::Contains(GridCell* item)
{
    if (items[item->heapIndex] == item)
    {
        return true;
    }
    return false;
}

void Heap::UpdateItem(GridCell* item)
{
    SortUp(item);
}
