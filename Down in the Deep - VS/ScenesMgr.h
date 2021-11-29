#pragma once
#include <map>
#include "Room.h"
#include "Player.h"

class Scenes
{
	std::map <int, Room> roomIndex;

public:
	Room currentScene;

	int currentChoice;


	Scenes();
	Scenes(const Scenes& other) = delete;
	Scenes& operator = (const Scenes& other) = delete;
	~Scenes() noexcept;


	int getSceneType();
	int getSceneChoiceNo();
	void setCurrentRoom(int newRoom);

	void printCurrentScene();
	void initRooms();

	void highlightChoice(int highlighted, int totalChoices, Player player);
	int getPlayerInput_Adventure();
};
