#pragma once
#include "Node.h"

class Snakey
{
public:
    Snakey()
    {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    ~Snakey()
    {
        for (Node* node : body)
        {
            delete node;
        }
        body.clear();
    }
    std::vector<Node*> body;
    
    Node* head;
    Node* tail;
    int count;
    
    void GrowSnake(Vector2 worldPos, Vector2Int gridPos);
    void MoveSnake(Vector2 nextPosition, Vector2Int gridPos);
    void DrawSnake();
};