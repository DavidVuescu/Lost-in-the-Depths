#include <assert.h>
#include <raylib.h>
#include "Game.h"
#include "Settings.h"

Game::Game(int width, int height, int FPS, std::string title)
{
	assert(!GetWindowHandle()); // If assertio triggers : Game window already open

	SetTargetFPS(FPS);
	InitWindow(width, height, title.c_str());

}

Game::~Game() noexcept
{
	assert(GetWindowHandle()); // If assertio triggers : Game window already closed
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
	ClearBackground(RAYWHITE);

	DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
}

