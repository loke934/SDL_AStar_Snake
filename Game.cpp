#include "Game.h"
#include "Engine.h"
#include <iostream>

std::unique_ptr<Grid> grid;

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
    grid->gridArray[fruitPos.x][fruitPos.y].Draw();
    length = (int)path.size();
    currentState = MOVE;

    //Debug: draw the found path
    // for (size_t i = 0; i < path.size()-1; i++)
    // {
    //     grid->gridArray[path[i].x][path[i].y].currentState = OBSTACLE;
    //     grid->gridArray[path[i].x][path[i].y].Draw();
    // }
}

void Game::SpawnSnake()
{
    Vector2Int random = GetRandomGridPosition();
    snakePos = random;
    Vector2 worldPosition = grid->gridArray[random.x][random.y].worldPosition;
    snake->GrowSnake(worldPosition, random);
    snake->DrawSnake();
}

void Game::SpawnFruit()
{
    Vector2Int random = GetRandomGridPosition();
    fruitPos = random;
    grid->gridArray[random.x][random.y].currentState = FRUIT;
}

bool Game::UpdateGame()
{
    switch (currentState)
    {
    case MOVE:
        DoMovement();
        break;
            
    case FIND_PATH:
        SetMovementPath();       
        break;
        
    case GAME_OVER:
        return true;
        
    case DEFAULT_STATE:
        break;
    }

    return false;
}

void Game::DoMovement()
{
    if (time <= 0.f)
    {
        if (index < length)
        {
            const Vector2Int nextGridCell = path[index];
            const Vector2  nextPosition = grid->gridArray[nextGridCell.x][nextGridCell.y].worldPosition;
            snake->MoveSnake(nextPosition, nextGridCell);
            index++;
            time = timer;
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
        path.clear();
            
        for (size_t i = 0; i < 999; i++)
        {
            SpawnFruit();
            grid->FindPath(&grid->gridArray[snakePos.x][snakePos.y], &grid->gridArray[fruitPos.x][fruitPos.y], path);
            if (!path.empty())
            {
                grid->gridArray[fruitPos.x][fruitPos.y].Draw();
                break;
            }
            if (i == 998 && path.empty())
            {
                currentState = GAME_OVER;
                return;
            }
        }
        
        snake->GrowSnake(snake->tail->worldPosition,snake->tail->gridPosition);
        snake->DrawSnake();
            
        length = (int)path.size();
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

