#include "Game.h"
#include "Engine.h"
#include <iostream>

Grid* grid;

void Game::SetupGame()
{
    grid->SetupGrid();
    grid->DrawGrid();
    SpawnSnake();
    SpawnFruit();
    
    grid->FindPath(&grid->gridArray[snakePos.x][snakePos.y], &grid->gridArray[fruitPos.x][fruitPos.y], path);
    if (path.empty())
    {
        std::cout << "No path was found!"  << std::endl;
        return;
    }
    //Debug: draw the found path
    // for (size_t i = 0; i < path.size()-1; i++)
    // {
    //     grid->gridArray[path[i].x][path[i].y].currentState = OBSTACLE;
    //     grid->gridArray[path[i].x][path[i].y].Draw();
    // }
  
    length = (int)path.size();
    currentState = MOVE;
}

void Game::SpawnSnake()
{
    Node* node = new Node();
    Vector2Int random = GetRandomGridPosition();
    snakePos = random;
    Vector2 worldPosition = grid->gridArray[random.x][random.y].worldPosition;
    snake->GrowSnake(node,worldPosition, random);
    snake->DrawSnake();
}

void Game::SpawnFruit()
{
    Vector2Int random = GetRandomGridPosition();
    fruitPos = random;
    grid->gridArray[random.x][random.y].currentState = FRUIT;
    grid->gridArray[random.x][random.y].Draw();
}

void Game::UpdateGame()
{
    switch (currentState)
    {
    case MOVE:
        DoMovement();
        break;
            
    case FIND_PATH:
        SetMovementPath();       
        break;
        
    case DEFAULT_STATE:
        break;
    }
}

void Game::DoMovement()
{
    if (time <= 0.f)
    {
        if (index < length)
        {
            Vector2Int nextGridCell = path[index];
            Vector2  nextPosition = grid->gridArray[nextGridCell.x][nextGridCell.y].worldPosition;
            snake->MoveSnake(nextPosition, nextGridCell);
            index++;
            time = 0.5f;
        }
        else
        {
            currentState = FIND_PATH;
        }
    }
    time-= deltaTime;
}

void Game::SetMovementPath()
{
    if (index >= length)
    {
        snakePos = fruitPos;
        SpawnFruit();
        path.clear();
            
        grid->FindPath(&grid->gridArray[snakePos.x][snakePos.y], &grid->gridArray[fruitPos.x][fruitPos.y], path);
        if (path.empty())
        {
            std::cout << "Error: Path empty!" << std::endl;
            return;
        }
            
        Node* node = new Node();
        snake->GrowSnake(node, snake->tail->worldPosition,snake->tail->gridPosition);
        snake->DrawSnake();
            
        length = path.size();
        index = 0;
        currentState = MOVE;
    }
}

Vector2Int Game::GetRandomGridPosition()
{
    Vector2Int randomVector;
    randomVector.x = rand() % GRID_SIZE_X - 1;
    randomVector.y = rand() % GRID_SIZE_Y - 1;
    if (grid->gridArray[randomVector.x][randomVector.y].currentState != WALKABLE)
    {
        randomVector = GetRandomGridPosition();
    }
    return randomVector;
}

void Game::EndGame()
{
    delete snake;
    delete grid;
}
