#include <assert.h>
#include <raylib.h>
#include "Game.h"
#include "Room.h"
#include "InitRooms.h"

Game::Game(int width, int height, int FPS, std::string title)
	:
	gameState(Cutscene)
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

States Game::getState()
{
	return gameState;
}
void Game::setState(States state)
{
	gameState = state;
}


bool Game::shouldGameClose() const
{
	return WindowShouldClose();
}

void Game::tick()
{
	BeginDrawing();
	state();
	update();
	render();
	EndDrawing();
}

//Setting gamestate for game logic
void Game::state()
{
	if (getState() == Cutscene)
	{
		switch (roomMgr.getSceneType())
		{
		case 1: {setState(Adventure); break; }
		case 2: {setState(Paused); break; }
		}
	}
}

//Frame updating
void Game::update() 
{
	ClearBackground(BLACK);

	switch (getState())
	{
	case Cutscene: 
	{ 
		player.hidePlayer();
		break; 
	}
	case Adventure: 
	{ 
		if (roomMgr.getPlayerInput_Adventure())
		{
			/*DEBUG*/printf("--------- ROOMMGR: option has been selected\n");
			setState(Paused);
			roomMgr.currentScene.setRoomFinishState(true);
		}
		break; 
	}
	case Paused:
	{
		if (roomMgr.getPlayerInput_Paused())
		{
			/*DEBUG*/printf("--------- USR INPUT: player exited paused state\n");
			setState(Cutscene);
			roomMgr.nextRoom();
		}
	}
	}

}

//Screen Drawing
void Game::render() 
{
	roomMgr.printCurrentScene();
	roomMgr.highlightChoice(roomMgr.currentChoice, roomMgr.getSceneChoiceNo(), std::move(player));
	// TODO player.renderPlayer();
}
