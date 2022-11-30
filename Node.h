#pragma once
#include "Grid.h"

class Node
{
public:
    Node* previousNode = nullptr;
    Node* nextNode = nullptr;
    Vector2 worldPosition;
    Vector2Int gridPosition;
    
    //Draw
    float width = 50.f;
    float height = 50.f;
    void DrawBody();
    void DrawPreviousTail();
};
