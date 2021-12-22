#pragma once
#include "Room.h"
#include "SceneMgr.h"

void SceneMgr::initRooms()
{
	roomIndex.emplace(1, Room(1, "The cave entrance looms before you. Way back this used to be a sprawling mine but now, over 40 years later it has just become a mess of abandoned shafts and rooms filled with all sorts of leftovers from back in the day. This is going to be a long adventure.\nAre you ready?",
		"Assets/Subjects/Cave_Entrance.png", "Assets/Backgrounds/Dirt_Fullscreen.png",
		{ "Go inside the mine" },
		{ "You muster up all your courage and run into the mine" },
		{ 2 }));
	roomIndex.emplace(2, Room(1, "In your misadventures, you find a banana on the floor. Right as you were about to pass it, its eyes open and it yells at you. Stunned, you are left looking at the banana.",
		"Assets/Subjects/BananaPeel.png", "Assets/Backgrounds/Dirt_Fullscreen.png", 
		{ "Eat the Banana","Ignore the Banana","Talk to the Banana" },
		{ "The banana was delicious, you feel replenished and ready to continue your journey, so you do",
		 "You decided ignoring the banana was the best course of action. You were wrong, while ignoring the banana, you slipped and cracked your skull",
		 "You tried talking to the banana. It was an interesting conversation by which you were heavily moved. Filled with newfound hope, you continue your journey" },
		{ 2,999,4 }));
	roomIndex.emplace(4, Room(1, "You see only darkness ahead of you, this is not good. Conveniently, there is a torch right beside you with a \"take me\" sign underneath it.\nWould you like to take the torch",
		"Assets/Subjects/Torch.png", "Assets/Backgrounds/Dirt_Fullscreen.png",
		{ "Take the torch", "Torches are overrated"},
		{ "You nibbed the torch. Right as you nibbed the torch you realised this is a prerelease demo and immediately got out of the cave with your newfound torch. You kept it as a token until the day you died\n\n...or at least until the dev releases the next update",
		"How dare you, torches are perfectly well rated... well anyway, you didn't see anything, so you tripped and fell and died, how unfortunate."},
		{ 888,999 }));

	roomIndex.emplace(888, Room(1, "I do not know how you managed to do it, but you did it, congratulations\nYou have won the game",
		"Assets/Subjects/winstate.png", "Assets/Backgrounds/Outside.png",
		{ "Awesome" },
		{ "Awesome indeed" },
		{ 888 }));
	roomIndex.emplace(999, Room(1, "You have died. Your face was forgotten from the surface and whatever was left of you ended up in the worst depths of the mine. What a horrible fate has befallen you",
		"Assets/Subjects/death.png", "Assets/Backgrounds/Depths.png",
		{ "Bummer" },
		{ "What a horrible fate has befallen you" },
		{ 999 }));
}

