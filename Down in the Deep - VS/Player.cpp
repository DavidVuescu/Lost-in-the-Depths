#include <assert.h>
#include "daveLib.h"
#include "Settings.h"
#include "Player.h"
#include "Game.h"


Player::Player()
	:
	playerState(Cutscene),
	playerSprite(),
	playerCoords({ 20,20 }),
	playerShirtColor((rand() % 100 + 1) % 2)
{
	/*DEBUG*/printf("--------- PLAYER : Shirt colour is : %d\n", playerShirtColor);
}
Player::Player(const Player& other)
	:
	playerState(other.playerState),
	playerSprite(other.playerSprite),
	playerCoords(other.playerCoords),
	playerShirtColor(other.playerShirtColor)
{}

Player::~Player()
{}

States Player::getState()
{
	return playerState;
}

void Player::setState(States state)
{
	playerState = state;
}

void Player::setSprite(const std::string& spritePath)
{
	playerSprite = LoadTexture(spritePath.c_str());
}


void Player::renderPlayer()
{
	switch (playerShirtColor)
	{
	case 0:
	{
		//Green Shirt
		daveLib::DrawTextureRec(playerSprite,
								settings::shirtCoords1,
								playerCoords,
								WHITE);
		break;
	}
	case 1:
	{
		//Orange Shirt
		daveLib::DrawTextureRec(playerSprite,
								settings::shirtCoords2,
								playerCoords,
								WHITE);
		break;
	}
	}
	
}
void Player::hidePlayer() { playerCoords = { -100,-100 }; }
void Player::movePlayer(Vec2<int> pos) 
{ 
	playerCoords = { pos.GetX(),pos.GetY() };
}

