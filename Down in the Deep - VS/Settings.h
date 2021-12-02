#ifndef SETTINGS_H
#define SETTINGS_H

#include <stdlib.h>
#include <raylib.h>
#include "Vec2.h"

// Types
enum States
{
	Cutscene, //Player sprite hidden, can skip (TBD)
	Adventure, //Player sprite active, can move up and down to choose
	Paused //Game waits for player input
};

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
	// Frame
	inline constexpr Vec2<int> boxFramePos{ 30,30 };
	inline constexpr Vec2<int> boxFrameSize1{ 500,600 };
	inline constexpr Vec2<int> boxFrameSize2{ 500,540 };
	inline constexpr Vec2<int> boxFrameSize3{ 500,480 };
	// Box
	inline constexpr Vec2<int> boxPos{ 35,35 };
	inline constexpr Vec2<int> boxSize1{ 490,590 };
	inline constexpr Vec2<int> boxSize2{ 490,530 };
	inline constexpr Vec2<int> boxSize3{ 490,470 };
	// Other Params
	inline constexpr float boxRoundness = 0.1;
	inline constexpr int boxSegments = 100;
	
	// Choice Settings
	// Boxes
	inline constexpr int choiceHeight = 50;
	inline constexpr int choicePadding = 10;
	inline constexpr float choiceRoundness = 0.5;
	inline constexpr Vec2<int> /*dynamic*/choicePos1{ boxFramePos.GetX(),boxFramePos.GetY() + choicePadding * 2 + boxSize1.GetY() };
	inline constexpr Vec2<int> /*dynamic*/choicePos2{ boxFramePos.GetX(),boxFramePos.GetY() + choicePadding * 2 + boxSize2.GetY() };
	inline constexpr Vec2<int> /*dynamic*/choicePos3{ boxFramePos.GetX(),boxFramePos.GetY() + choicePadding * 2 + boxSize3.GetY() };
	inline constexpr Vec2<int> /*dynamic*/choiceHighlightSize{ boxSize3.GetX(),choiceHeight - 10 };
	// Text
	inline constexpr Vec2<int> /*dynamic*/choiceDisplacement{ choiceHeight / 2 * 3,choiceHeight / 3 };


	// Room Subject Settings
	inline constexpr Vec2<int> shadowsPos { 900,250 };
	inline constexpr int shadowRadius = 200;
	inline constexpr Vec2<int> subjectPos { 700,30 };


	// Text Writer Settings
	inline constexpr int fontSize = 18;
	inline constexpr int writerDangerZone = 350;//Where the writer should stop and begin a newline
	inline constexpr int textPosX = 55;
	inline constexpr int textPosY = 70;


	// Player Render
	inline constexpr Rectangle shirtCoords1{ 0,0,16,16 };
	inline constexpr Rectangle shirtCoords2{ 16,0,16,16 };
	inline constexpr int /*dynamic*/playerPadding_Room = choiceHeight / 3;


	// Gameplay Settings
	inline constexpr int firstRoom = 3;
}

#endif
