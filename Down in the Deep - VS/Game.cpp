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
	roomMap.initRooms();
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
}
void Game::render() // Function used for drawing
{
	roomMap.roomIndex[1].drawRoom();
}
