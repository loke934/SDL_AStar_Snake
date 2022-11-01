#pragma once
#include <memory>

#include "Grid.h"
#include "Snakey.h"

extern Grid* grid;

enum GAME_STATE
{
    MOVE,
    FIND_PATH,
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

    GAME_STATE currentState = DEFAULT_STATE;
    
    //A*
    std::vector<Vector2Int> path;
    Vector2Int fruitPos;
    Vector2Int snakePos;
    int length;
    int index = 0;

    Snakey* snake;
    float time = 1.f;
    
    void SetupGame();
    void SpawnSnake();
    void SpawnFruit();
    void UpdateGame();
    void DoMovement();
    void SetMovementPath();
    Vector2Int GetRandomGridPosition();

    void EndGame();

    //Clean up func when I close the application delete the nodes
    //return, move and copy keep it stack allocated more optimized
    // std::vector<Node> nodeBuffer;
    // std::vector<Node*> unusedNodes;
};


