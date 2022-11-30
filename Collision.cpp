#include "Collision.h"
#include <SDL/SDL_rect.h>
#include <SDL/SDL_render.h>
#include "Engine.h"

AABB AABB::MakeFromPositionSize(float X, float Y, float With, float Height)
{
    AABB box;
    box.xMin = X - (With * 0.5f);
    box.xMax = X + (With * 0.5f);
    box.yMin = Y - (Height * 0.5f);
    box.yMax = Y + (Height * 0.5f);
    return box;
}

void DrawBox(const AABB& box)
{
    SDL_FRect rect = {box.xMin, box.yMin, (box.xMax -box.xMin), (box.yMax - box.yMin)};
    SDL_RenderFillRectF(render, &rect);
}



