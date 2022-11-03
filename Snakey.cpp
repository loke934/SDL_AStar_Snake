#include "Snakey.h"
#include "Game.h"

void Snakey::GrowSnake(Vector2 worldPos, Vector2Int gridPos)
{
    grid->gridArray[gridPos.x][gridPos.y].currentState = OBSTACLE;
    body.push_back({});
    Node& last = body.back();
    last.worldPosition = worldPos;
    last.gridPosition = gridPos;
    
    if (count <= 0) 
    {
        head = &last;
    }
    else
    {
        last.previousNode = tail;
        tail->nextNode = &last;
    }
    tail = &last;
    count++;
}

void Snakey::MoveSnake(Vector2 nextPosition, Vector2Int gridPos)
{
    if (count <= 0)
    {
        return;
    }
    
    tail->DrawPreviousTail();
    grid->gridArray[tail->gridPosition.x][tail->gridPosition.y].currentState = WALKABLE;

    Node* currentNode = tail;
    while (currentNode != nullptr)
    {
        if (currentNode == head)
        {
            currentNode->worldPosition = nextPosition;
            currentNode->gridPosition = gridPos;            
        }
        else
        {
            currentNode->worldPosition = currentNode->previousNode->worldPosition;
            currentNode->gridPosition = currentNode->previousNode->gridPosition;
        }
        grid->gridArray[currentNode->gridPosition.x][currentNode->gridPosition.y].currentState = OBSTACLE;
        currentNode = currentNode->previousNode;
    }
    DrawSnake();
}

void Snakey::DrawSnake()
{
    for (Node item : body)
    {
        item.DrawBody();
    }
}