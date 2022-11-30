#pragma once
#include <memory>
#include "Node.h"

class Snakey
{
public:
    Snakey()
    {
        head = nullptr;
        tail = nullptr;
        count = 0;
        body.reserve(GRID_SIZE);
    }
    std::vector<Node> body;
    Node* head;
    Node* tail;
    int count;
    
    void GrowSnake(Vector2 worldPos, Vector2Int gridPos);
    void MoveSnake(Vector2 nextPosition, Vector2Int gridPos);
    void DrawSnake();
};