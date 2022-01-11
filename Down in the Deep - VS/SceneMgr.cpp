#include <assert.h>
#include <iostream>

#include "SceneMgr.h"
#include "daveLib.h"
#include "Settings.h"

#include "json/json.h"
#include "json/forwards.h"

SceneMgr::SceneMgr()
	:
	roomFile("Data/rooms.json"),
	currentScene(),
	currentChoice(0)
{
	assert(roomFile.is_open()); // If assertion triggers : Program could not find rooms.json
	reader.parse(roomFile, roomJson);
}
SceneMgr::~SceneMgr()
{
	roomFile.close();
}


int SceneMgr::getSceneType()
{
	return currentScene.getRoomID();
}
int SceneMgr::getSceneChoiceNo()
{
	return currentScene.getChoiceNo();
}
int SceneMgr::getRoomAdress(int newRoom)
{
	reader.parse(roomFile, roomJson);
	int idx = 1;
	int i=1;
	int adress = roomJson[i]["Adress"].asInt();
	while (adress != newRoom)
	{
		i++; idx++;
		adress = roomJson[i]["Adress"].asInt();
		if (idx == 1000) break;
	}
	return idx;
}
void SceneMgr::setCurrentRoom(int newRoom)
{
	int adress = getRoomAdress(newRoom);
	assert(adress != 1000); // If assertion triggers : Program could not find room adress
	/*DEBUG*/printf("--------- ROOMMGR: accessing room adress: %d\n", adress);

	int type = roomJson[adress]["Type"].asInt();
	std::string blurb = roomJson[adress]["Blurb"].asString();
	std::string subject = roomJson[adress]["Subject"].asString();
	std::string background = roomJson[adress]["Background"].asString();

	std::vector<std::string> choiceVector;
	for (int i = 0; i < roomJson[adress]["Choices"].size(); ++i) { choiceVector.push_back(roomJson[adress]["Choices"][i].asString()); }
	std::vector<std::string> repercussionVector;
	for (int i = 0; i < roomJson[adress]["Repercussions"].size(); ++i) { repercussionVector.push_back(roomJson[adress]["Repercussions"][i].asString()); }
	std::vector<unsigned int> pointersVector;
	for (int i = 0; i < roomJson[adress]["Pointers"].size(); ++i) { pointersVector.push_back(roomJson[adress]["Pointers"][i].asInt()); }

	Room room(type, blurb, subject, background,
		choiceVector, repercussionVector, pointersVector);
	currentScene = room;
}
void SceneMgr::nextRoom()
{
	setCurrentRoom(currentScene.fetchNextRoom(currentChoice));
	currentChoice = 0;
	/*DEBUG*/printf("--------- ROOMMGR: room changed successfully\n");
}


void SceneMgr::printCurrentScene()
{
	currentScene.drawRoom(currentChoice);
}

void SceneMgr::initFirstRoom()
{
	/*DEBUG*/printf("--------- ROOMMGR: Accessing room adress %d\n",roomJson[0]["Adress"].asInt());
	int type = roomJson[0]["Type"].asInt();
	std::string blurb = roomJson[0]["Blurb"].asString();
	std::string subject = roomJson[0]["Subject"].asString();
	std::string background = roomJson[0]["Background"].asString();

	std::vector<std::string> choiceVector;
	for (int i = 0; i < roomJson[0]["Choices"].size(); ++i) { choiceVector.push_back(roomJson[0]["Choices"][i].asString()); }
	std::vector<std::string> repercussionVector;
	for (int i = 0; i < roomJson[0]["Repercussions"].size(); ++i) { repercussionVector.push_back(roomJson[0]["Repercussions"][i].asString()); }
	std::vector<unsigned int> pointersVector;
	for (int i = 0; i < roomJson[0]["Pointers"].size(); ++i) { pointersVector.push_back(roomJson[0]["Pointers"][i].asInt()); }

	Room room(type, blurb, subject, background, 
				choiceVector, repercussionVector, pointersVector);
	currentScene = room;
}

void SceneMgr::highlightChoice(int highlighted, int totalChoices, Player player)
{
	Color boxColor = DARKLIGHT;
	if (currentScene.getRoomFinishState()) boxColor = MONSOON;

	switch (totalChoices)
	{
	case 1:
	{
		daveLib::DrawRectangleRounded(settings::choicePos1 + 5,
			settings::choiceHighlightSize,
			settings::choiceRoundness,
			settings::boxSegments,
			boxColor);
		player.movePlayer(settings::choicePos3 + settings::playerPadding_Room);

		break;
	}
	case 2:
	{
		switch (highlighted)
		{
		case 0:
		{
			daveLib::DrawRectangleRounded(settings::choicePos2 + 5,
				settings::choiceHighlightSize,
				settings::choiceRoundness,
				settings::boxSegments,
				boxColor);
			player.movePlayer(settings::choicePos2 + settings::playerPadding_Room);
			break;
		}
		case 1:
		{
			daveLib::DrawRectangleRounded(settings::choicePos1 + 5,
				settings::choiceHighlightSize,
				settings::choiceRoundness,
				settings::boxSegments,
				boxColor);
			player.movePlayer(settings::choicePos3 + settings::playerPadding_Room);
			break;
		}
		}
		break;
	}
	case 3:
	{
		switch (highlighted)
		{
		case 0:
		{
			daveLib::DrawRectangleRounded(settings::choicePos3 + 5,
				settings::choiceHighlightSize,
				settings::choiceRoundness,
				settings::boxSegments,
				boxColor);
			player.movePlayer(settings::choicePos1 + settings::playerPadding_Room);
			break;
		}
		case 1:
		{
			daveLib::DrawRectangleRounded(settings::choicePos2 + 5,
				settings::choiceHighlightSize,
				settings::choiceRoundness,
				settings::boxSegments,
				boxColor);
			player.movePlayer(settings::choicePos2 + settings::playerPadding_Room);
			break;
		}
		case 2:
		{
			daveLib::DrawRectangleRounded(settings::choicePos1 + 5,
				settings::choiceHighlightSize,
				settings::choiceRoundness,
				settings::boxSegments,
				boxColor);
			player.movePlayer(settings::choicePos3 + settings::playerPadding_Room);
			break;
		}
		}
		break;
	}
	}
}
int SceneMgr::getPlayerInput_Adventure()
{
	const int totalChoices = currentScene.getChoiceNo();

	if (IsKeyPressed(KEY_DOWN))
	{
		++currentChoice;
		if (currentChoice > totalChoices - 1)
		{
			currentChoice = 0;
		}
		/*DEBUG*/printf("--------- USR INPUT: user pressed DOWN key\n");
		/*DEBUG*/printf("--------- USR INPUT: current choice is: %d\n", currentChoice+1);
	}
	else if (IsKeyPressed(KEY_UP))
	{
		--currentChoice;
		if (currentChoice < 0)
		{
			currentChoice = totalChoices - 1;
		}
		/*DEBUG*/printf("--------- USR INPUT: user pressed UP key\n");
		/*DEBUG*/printf("--------- USR INPUT: current choice is: %d\n", currentChoice+1);
	}

	if (IsKeyPressed(KEY_ENTER))
	{
		/*DEBUG*/printf("--------- USR INPUT: user pressed ENTER key\n");
		currentScene.setRoomFinishState(true);
		return 1;
	}
	if (IsKeyPressed(KEY_SPACE))
	{
		/*DEBUG*/printf("--------- USR INPUT: user pressed SPACE key\n");
		currentScene.setRoomFinishState(true);
		return 1;
	}

	return 0;
}
int SceneMgr::getPlayerInput_Paused()
{
	if (IsKeyPressed(KEY_ENTER)) return 1;
	if (IsKeyPressed(KEY_SPACE)) return 1;
	return 0;
}

