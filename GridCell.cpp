#include "GridCell.h"
#include "Collision.h"
#include "Engine.h"

void GridCell::Draw()
{
    switch (currentState)
    {
    case WALKABLE:
        SDL_SetRenderDrawColor(render,50, 150, 110, 255);
        break;
    case OBSTACLE:
        SDL_SetRenderDrawColor(render,100, 0, 100, 255);
        width = 50;
        height = 50;
        break;
    case FRUIT:
        SDL_SetRenderDrawColor(render,200, 0, 0, 255);
        width = 20;
        height = 20;
        break;
    }
    
    const AABB box = AABB::MakeFromPositionSize(worldPosition.x,worldPosition.y,width,height);
    DrawBox(box);
}
