#pragma once
#include <map>
#include "Room.h"

class Scenes
{
public:

	std::map <int, Room> roomIndex;
	Room currentRoom;

	void initRooms();
};
