#include <assert.h>
#include "daveLib.h"


void daveLib::DrawRectangle(Vec2<int> pos, Vec2<int> widthHeight, Color color)
{
    assert (pos.GetX() >= 0 && pos.GetY() >= 0 &&
            pos.GetX() < GetScreenWidth() && pos.GetY() < GetScreenHeight()); // If assertion triggers : Function is trying to draw outside the screen space
    
    DrawRectangle(pos.GetX(), pos.GetY(), widthHeight.GetX(), widthHeight.GetY(), color);
}

void daveLib::DrawRectangleLinesEx(Vec2<int> pos, Vec2<int> widthHeight, float lineThick, Color color)
{
    assert (pos.GetX() >= 0 && pos.GetY() >= 0 &&
            pos.GetX() < GetScreenWidth() && pos.GetY() < GetScreenHeight()); // If assertion triggers : Function is trying to draw outside the screen space
    assert(lineThick > 0); // If assertion triggers : Line thickness negative
    
    DrawRectangleLinesEx({ (float)pos.GetX(), (float)pos.GetY(), (float)widthHeight.GetX(), (float)widthHeight.GetY() }, lineThick, color);
}

void daveLib::DrawRectangleRounded(Vec2<int> pos, Vec2<int> widthHeight, float roundness, int segments, Color color)
{
    assert (pos.GetX() >= 0 && pos.GetY() >= 0 &&
            pos.GetX() < GetScreenWidth() && pos.GetY() < GetScreenHeight()); // If assertion triggers : Function is trying to draw outside the screen space
    
    DrawRectangleRounded({ (float)pos.GetX(),(float)pos.GetY(),(float)widthHeight.GetX(),(float)widthHeight.GetY() }, 
                            roundness, segments, color);
}


void daveLib::DrawCircle(Vec2<int> centerPos, float radius, Color color)
{
    assert (centerPos.GetX() >= 0 && centerPos.GetY() >= 0 &&
            centerPos.GetX() < GetScreenWidth() && centerPos.GetY() < GetScreenHeight()); // If assertion triggers : Function is trying to draw outside the screen space
    
    DrawCircle(centerPos.GetX(), centerPos.GetY(), radius, color);
}

void daveLib::DrawTexture(Texture2D texture, Vec2<int> pos, Color tint)
{
    assert (pos.GetX() >= 0 && pos.GetY() >= 0 &&
            pos.GetX() < GetScreenWidth() && pos.GetY() < GetScreenHeight()); // If assertion triggers : Function is trying to draw outside the screen space

    DrawTexture(texture, pos.GetX(), pos.GetY(), tint);
}

void daveLib::DrawTextureRec(Texture2D texture, Rectangle source, Vec2<int> pos, Color tint)
{
    DrawTextureRec(texture, source, Vector2{(float)pos.GetX(), (float)pos.GetY()}, tint);
}
