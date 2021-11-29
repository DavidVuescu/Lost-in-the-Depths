#ifndef ROOM_H
#define ROOM_H

#include <raylib.h>
#include <string>
#include <vector>

class Room
{

	int roomID;
	std::string roomText;

	Texture2D roomSubject;
	Texture2D roomBackground;

	int roomChoiceNo;
	int selectedChoice;
	std::vector <std::string> choiceList;
	std::vector <std::string> choiceResultList;


public:
	Room(int roomID, 
		 const std::string& roomText,
		 const std::string& subjectPath, 
		 const std::string& backgroundPath,
		 const int choiceNo, 
		 const std::vector <std::string>& choiceList,
		 const std::vector <std::string>& choiceResults);
	Room();
	Room(const Room& other) = delete;
	Room& operator = (const Room& other);
	Room(Room&& other) noexcept;
	~Room() noexcept;

	const int getRoomID();


	// Room Drawing Functions
	void drawRoom();// Master
	void drawRoomStory();// Textbox & Choices
	void roomTextWriter();



	bool operator < (const Room& rhs) const;
	bool operator > (const Room& rhs) const;
};


#endif
