#pragma once
#include "Node.h"

class Snakey
{
public:
    std::vector<Node*> body;

    Node* head = nullptr;
    Node* tail = nullptr;
    int count = 0;
    
    void GrowSnake(Node* node, Vector2 worldPos, Vector2Int gridPos);
    void MoveSnake(Vector2 nextPosition, Vector2Int gridPos);
    void DrawSnake();
};



