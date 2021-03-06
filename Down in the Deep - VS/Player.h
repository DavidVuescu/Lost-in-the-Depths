#pragma once

#include <string>
#include <raylib.h>
#include "Settings.h"
#include "Vec2.h"

class Player
{
	States playerState;
	Texture2D playerSprite;
	Vec2<int> playerCoords;

	const int playerShirtColor;

public:
	Player();
	Player(const Player& other);
	Player& operator = (const Player& other);
	~Player() noexcept;

	void setSprite(const std::string& spritePath);

	void renderPlayer();
	void hidePlayer();
	void movePlayer(Vec2<int> pos);
};

