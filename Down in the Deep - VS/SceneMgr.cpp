#include "SceneMgr.h"
#include "daveLib.h"
#include "Settings.h"

SceneMgr::SceneMgr()
	:
	currentScene(),
	currentChoice(1)
{}
SceneMgr::~SceneMgr()
{}


int SceneMgr::getSceneType()
{
	return currentScene.getRoomID();
}
int SceneMgr::getSceneChoiceNo()
{
	return currentScene.getChoiceNo();
}
void SceneMgr::setCurrentRoom(int newRoom)
{
	currentScene = roomIndex[newRoom];
}
void SceneMgr::nextRoom()
{
	int index = currentChoice - 1; //******FIX from 1-3 to 0-2 for peace of mind
	setCurrentRoom(currentScene.fetchNextRoom(index));
}


void SceneMgr::printCurrentScene()
{
	currentScene.drawRoom();
}


void SceneMgr::highlightChoice(int highlighted, int totalChoices, Player player)
{
	switch (totalChoices)
	{
	case 1:
	{
		daveLib::DrawRectangleRounded(settings::choicePos1 + 5,
			settings::choiceHighlightSize,
			settings::choiceRoundness,
			settings::boxSegments,
			DARKLIGHT);
		player.movePlayer(settings::choicePos3 + settings::playerPadding_Room);

		break;
	}
	case 2:
	{
		switch (highlighted)
		{
		case 1:
		{
			daveLib::DrawRectangleRounded(settings::choicePos2 + 5,
				settings::choiceHighlightSize,
				settings::choiceRoundness,
				settings::boxSegments,
				DARKLIGHT);
			player.movePlayer(settings::choicePos2 + settings::playerPadding_Room);
			break;
		}
		case 2:
		{
			daveLib::DrawRectangleRounded(settings::choicePos1 + 5,
				settings::choiceHighlightSize,
				settings::choiceRoundness,
				settings::boxSegments,
				DARKLIGHT);
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
		case 1:
		{
			daveLib::DrawRectangleRounded(settings::choicePos3 + 5,
				settings::choiceHighlightSize,
				settings::choiceRoundness,
				settings::boxSegments,
				DARKLIGHT);
			player.movePlayer(settings::choicePos1 + settings::playerPadding_Room);
			break;
		}
		case 2:
		{
			daveLib::DrawRectangleRounded(settings::choicePos2 + 5,
				settings::choiceHighlightSize,
				settings::choiceRoundness,
				settings::boxSegments,
				DARKLIGHT);
			player.movePlayer(settings::choicePos2 + settings::playerPadding_Room);
			break;
		}
		case 3:
		{
			daveLib::DrawRectangleRounded(settings::choicePos1 + 5,
				settings::choiceHighlightSize,
				settings::choiceRoundness,
				settings::boxSegments,
				DARKLIGHT);
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
		if (currentChoice > totalChoices)
		{
			currentChoice = 1;
		}
		/*DEBUG*/printf("--------- USR INPUT: user pressed DOWN key\n");
		/*DEBUG*/printf("--------- USR INPUT: current choice is: %d\n", currentChoice);
	}
	else if (IsKeyPressed(KEY_UP))
	{
		--currentChoice;
		if (currentChoice < 1)
		{
			currentChoice = totalChoices;
		}
		/*DEBUG*/printf("--------- USR INPUT: user pressed UP key\n");
		/*DEBUG*/printf("--------- USR INPUT: current choice is: %d\n", currentChoice);
	}

	if (IsKeyPressed(KEY_ENTER))
	{
		currentScene.setRoomFinishState(true);
		return 1;
	}
	if (IsKeyPressed(KEY_SPACE))
	{
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

