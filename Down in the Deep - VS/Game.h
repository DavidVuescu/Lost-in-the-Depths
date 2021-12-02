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

	States getState();
	void setState(States state);


	bool shouldGameClose() const;
	void tick();


private:
	States gameState;

	void state(); //Setting gamestate for game logic

	void update(); //Frame updating
	void render(); //Drawing
};

#endif
