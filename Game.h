#pragma once
#include <memory>
#include "Grid.h"
#include "Snakey.h"

extern std::unique_ptr<Grid> grid;

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
        grid = std::make_unique<Grid>();
        snake = std::make_unique<Snakey>();
    }

    GAME_STATE currentState = DEFAULT_STATE;
    
    //Pathfinding
    std::vector<Vector2Int> path;
    Vector2Int fruitPos;
    Vector2Int snakePos;
    int length = 0;
    int index = 0;

    std::unique_ptr<Snakey> snake;
    float time = 1.f;
    float timer = 0.3f;
    
    void SetupGame();
    void SpawnSnake();
    void SpawnFruit();
    bool UpdateGame();
    void DoMovement();
    void SetMovementPath();
    static Vector2Int GetRandomGridPosition();
};