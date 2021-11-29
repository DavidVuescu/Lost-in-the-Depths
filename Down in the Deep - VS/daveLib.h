#pragma once

#include <raylib.h>
#include "Vec2.h"

#define SHADE		CLITERAL(Color){ 0, 0, 0, 100 }
#define HOLLOWBRICK	CLITERAL(Color){ 63,68, 70, 70 }
#define DARKLIGHT	CLITERAL(Color){ 23, 18, 19, 60 }

namespace daveLib
{
	void DrawRectangle(Vec2<int> pos, Vec2<int> widthHeight, Color color);
	void DrawRectangleLinesEx(Vec2<int> pos, Vec2<int> widthHeight, float lineThick, Color color);
	void DrawRectangleRounded(Vec2<int> pos, Vec2<int> widthHeight, float roundness, int segments, Color color);
	void DrawCircle(Vec2<int> centerPos, float radius, Color color);

	void DrawTexture(Texture2D texture, Vec2<int> pos, Color tint);
}
