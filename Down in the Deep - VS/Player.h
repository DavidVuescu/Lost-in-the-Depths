#pragma once

#include <string>
#include <raylib.h>
#include "Vec2.h"

class Player
{
	States playerState;
	Texture2D playerSprite;
	Vec2<int> playerCoords;

	const int playerShirtColor;

public:
	Player();
	Player(const Player& other) = delete;
	Player& operator = (const Player& other) = delete;
	~Player() noexcept;

	States getState(); 
	void setState(States state);

	void setSprite(const std::string& spritePath);

	void renderPlayer();
	void movePlayer();
};

