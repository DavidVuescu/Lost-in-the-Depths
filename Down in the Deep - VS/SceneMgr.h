#pragma once
#include <map>
#include "Room.h"
#include "Player.h"

class SceneMgr
{
	std::map <int, Room> roomIndex;

public:
	Room currentScene;

	int currentChoice;


	SceneMgr();
	SceneMgr(const SceneMgr& other) = delete;
	SceneMgr& operator = (const SceneMgr& other) = delete;
	~SceneMgr() noexcept;


	int getSceneType();
	int getSceneChoiceNo();
	void setCurrentRoom(int newRoom);

	void printCurrentScene();
	void initRooms();

	void highlightChoice(int highlighted, int totalChoices, Player player);
	int getPlayerInput_Adventure();
};
