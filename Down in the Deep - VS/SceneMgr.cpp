#include "SceneMgr.h"
#include "daveLib.h"
#include "Settings.h"

SceneMgr::SceneMgr()
	:
	currentScene(),
	currentChoice(0)
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
	setCurrentRoom(currentScene.fetchNextRoom(currentChoice));
	currentChoice = 0;
	/*DEBUG*/printf("--------- ROOMMGR: room changed successfully\n");
}


void SceneMgr::printCurrentScene()
{
	currentScene.drawRoom(currentChoice);
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

