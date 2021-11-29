#include <assert.h>
#include <raylib.h>
#include "Game.h"
#include "Room.h"
#include "Settings.h"

Game::Game(int width, int height, int FPS, std::string title)
	:
	currentRoom(settings::firstRoom)
{
	assert(!GetWindowHandle()); // If assertion triggers : Game window already open

	SetTargetFPS(FPS);
	InitWindow(width, height, title.c_str());
	roomMgr.initRooms();
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

	switch (roomMgr.roomIndex[currentRoom].getRoomID())
	{
	case 0: { player.setState(Cutscene); break; }
	case 1: { player.setState(Adventure); break; }
	}

	player.movePlayer();
}
void Game::render() // Function used for drawing
{
	roomMgr.roomIndex[currentRoom].drawRoom();
	player.renderPlayer();
}
