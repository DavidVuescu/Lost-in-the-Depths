#ifndef SETTINGS_H
#define SETTINGS_H

#include "Vec2.h"

namespace settings
{
	// Window Settings
	inline constexpr int gameWidth = 1280;
	inline constexpr int gameHeight = 720;
	inline constexpr int targetFPS = 60;


	// Background Settings & Vec2 Shortcuts
	inline constexpr Vec2<int> nullVec2 { 0,0 };
	inline constexpr Vec2<int> screenVec2 { 1280,720 };
	inline constexpr int windowFrameThickness = 4;


	// Textbox Settings
	inline constexpr Vec2<int> boxFramePos{ 30,30 };
	inline constexpr Vec2<int> boxFrameSize1{ 500,600 };
	inline constexpr Vec2<int> boxFrameSize2{ 500,540 };
	inline constexpr Vec2<int> boxFrameSize3{ 500,480 };

	inline constexpr Vec2<int> boxPos{ 35,35 };
	inline constexpr Vec2<int> boxSize1{ 490,590 };
	inline constexpr Vec2<int> boxSize2{ 490,530 };
	inline constexpr Vec2<int> boxSize3{ 490,470 };

	inline constexpr float boxRoundness = 0.1;
	inline constexpr int boxSegments = 100;
	

	// Choice Boxes Settings
	inline constexpr int choiceHeight = 50;
	inline constexpr int choicePadding = 10;
	inline constexpr float choiceRoundness = 0.5;


	// Room Subject Settings
	inline constexpr Vec2<int> shadowsPos { 900,250 };
	inline constexpr int shadowRadius = 200;
	inline constexpr Vec2<int> subjectPos { 700,30 };


	// Text Writer Settings
	inline constexpr int fontSize = 18;
	inline constexpr int writerDangerZone = 350;//Where the writer should stop and begin a newline
	inline constexpr int textPosX = 55;
	inline constexpr int textPosY = 70;
}

#endif
