#ifndef GAME_H
#define GAME_H

#include <string>
#include "settings.h"
#include "SceneMgr.h"
#include "Player.h"

class Game
{
public:

	SceneMgr roomMgr;

	Player player;
	
	Game(int width, int height, int FPS, std::string title);
		Game(const Game& other) = delete;
		Game& operator = (const Game& other) = delete;
	~Game() noexcept;

	bool shouldGameClose() const;
	void tick();


private:

	void render();// Function used for drawing
	void update();// Function used for frame updating
};

#endif
