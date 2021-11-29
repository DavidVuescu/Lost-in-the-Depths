#include <assert.h>
#include <raylib.h>
#include "Game.h"
#include "Room.h"
#include "Settings.h"

Game::Game(int width, int height, int FPS, std::string title)
{
	assert(!GetWindowHandle()); // If assertion triggers : Game window already open

	SetTargetFPS(FPS);
	InitWindow(width, height, title.c_str());
	roomMgr.initRooms();
	roomMgr.setCurrentRoom(settings::firstRoom);
	player.setSprite("Assets/Player/playerSprite.png");
}

Game::~Game() noexcept
{
	assert(GetWindowHandle()); // If assertion triggers : Game window already closed
	CloseWindow();
}


bool Game::shouldGameClose() const
{
	return WindowShouldClose();
}

void Game::tick()
{
	BeginDrawing();
	update();
	render();
	EndDrawing();
}

void Game::update() // Function used for frame updating
{
	ClearBackground(BLACK);

	switch (roomMgr.getSceneType())
	{
	case 0: 
	{ 
		player.setState(Cutscene); 
		player.hidePlayer();
		break; 
	}
	case 1: 
	{ 
		player.setState(Adventure); 
		if (roomMgr.getPlayerInput_Adventure()) printf("--------- ROOMMGR: option has been selected\n");
		break; 
	}
	}

}

void Game::render() // Function used for drawing
{
	roomMgr.printCurrentScene();
	roomMgr.highlightChoice(roomMgr.currentChoice, roomMgr.getSceneChoiceNo(), std::move(player));
	// TODO player.renderPlayer();
}
