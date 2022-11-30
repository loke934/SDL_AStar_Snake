#pragma once

struct AABB
{
    static AABB MakeFromPositionSize(float X, float Y, float With, float Height);

    float xMin;
    float xMax;
    float yMin;
    float yMax;
};

void DrawBox(const AABB& box);