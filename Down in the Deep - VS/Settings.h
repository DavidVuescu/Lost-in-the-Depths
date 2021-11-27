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
	inline constexpr Vec2<int> textboxPos { 30,30 };
	inline constexpr Vec2<int> textboxWidthHeight{ 500,660 };
	inline constexpr float textboxRoundness = 0.2;
	inline constexpr int textboxSegments = 100;

	inline constexpr Vec2<int> textFramePos { 35,35 };
	inline constexpr Vec2<int> textFrameWidthHeight { 490,650 };
	

	// Room Subject Settings
	inline constexpr Vec2<int> ShadowsPos { 900,250 };
	inline constexpr int shadowRadius = 200;
	inline constexpr Vec2<int> subjectPos { 700,30 };


}

#endif
