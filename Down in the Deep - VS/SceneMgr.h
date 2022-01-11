#pragma once
#include <fstream>
#include "Room.h"
#include "Player.h"

class SceneMgr
{
	std::ifstream roomFile;
	Json::Value roomJson;
	Json::Reader reader;

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
	void nextRoom();

	void printCurrentScene();
	int getRoomAdress(int newRoom);
	void initFirstRoom();

	void highlightChoice(int highlighted, int totalChoices, Player player);

	//Player Input
	int getPlayerInput_Adventure();
	int getPlayerInput_Paused();
};
