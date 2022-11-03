#pragma once
#include <memory>

#include "Grid.h"
#include "Snakey.h"

extern Grid* grid;

enum GAME_STATE
{
    MOVE,
    FIND_PATH,
    GAME_OVER,
    DEFAULT_STATE
};

class Game
{
public:
    Game()
    {
        grid = new Grid();
        snake = new Snakey();
    }
    ~Game()
    {
        delete snake;
        delete grid;
    }

    GAME_STATE currentState = DEFAULT_STATE;
    
    //A*
    std::vector<Vector2Int> path;
    Vector2Int fruitPos;
    Vector2Int snakePos;
    int length = 0;
    int index = 0;

    Snakey* snake;
    float time = 1.f;
    float timer = 0.3f;
    
    void SetupGame();
    void SpawnSnake();
    void SpawnFruit();
    bool UpdateGame();
    void DoMovement();
    void SetMovementPath();
    Vector2Int GetRandomGridPosition();

};


