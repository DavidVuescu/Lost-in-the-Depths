#ifndef ROOM_H
#define ROOM_H

#include <raylib.h>
#include <string>
#include <list>

class Room
{

	int roomID;
	std::string roomText;

	Texture2D roomSubject;
	Texture2D roomBackground;

	const int roomChoiceNo;
	std::list <std::string> choiceList;

public:
	Room(int roomID, const std::string& roomText,
		 const std::string& subjectPath, const std::string& backgroundPath,
		 const int choiceNo, const std::list <std::string>& choiceList);
	Room();
	Room(const Room& other) = delete;
	Room& operator = (const Room& other) = delete;
	Room(Room&& other) noexcept;
	~Room() noexcept;


	// Room Drawing Functions
	void drawRoom();// Master
	void drawRoomStory();// Textbox & Choices
	void drawRoomText();



	bool operator < (const Room& rhs) const;
	bool operator > (const Room& rhs) const;
};


#endif
