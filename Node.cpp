#include "Node.h"
#include "Shapes.h"
#include <SDL/SDL_render.h>
#include "Engine.h"

void Node::DrawBody()
{
    SDL_SetRenderDrawColor(render,100, 0, 100, 255);
    width = 51;
    height = 51;
    const AABB box = AABB::MakeFromPositionSize(worldPosition.x,worldPosition.y,width,height);
    DrawBox(box);
}

void Node::DrawPreviousTail()
{
    SDL_SetRenderDrawColor(render,20, 0, 0, 255);
    width = 52;
    height = 52;
    const AABB background = AABB::MakeFromPositionSize(worldPosition.x,worldPosition.y,width,height);
    DrawBox(background);
    
    SDL_SetRenderDrawColor(render,50, 150, 110, 255);
    width = 50;
    height = 50;
    const AABB box = AABB::MakeFromPositionSize(worldPosition.x,worldPosition.y,width,height);
    DrawBox(box);
}


