#include <assert.h>
#include "Room.h"
#include "daveLib.h"
#include "Settings.h"

Room::Room (int roomID, const std::string& roomText, 
			const std::string& subjectPath, const std::string& backgroundPath,
			int choiceNo, const std::list <std::string>& choiceList)
	:
	roomID(roomID),
	roomText(roomText),
	roomSubject(LoadTexture(subjectPath.c_str())),
	roomBackground(LoadTexture(backgroundPath.c_str())),
	roomChoiceNo(choiceNo),
	choiceList(choiceList)
{
	assert(choiceNo > 0 && choiceNo < 4); // If assertio triggers : Number of room choices doesn't correspond (1-3 per room)
}
Room::Room()
	:
	roomID(0),
	roomText(),
	roomSubject(),
	roomBackground(),
	roomChoiceNo(0),
	choiceList()
{}

Room::~Room() noexcept
{}

Room::Room(Room&& other) noexcept
	:
	roomID(other.roomID),
	roomText(std::move(other.roomText)),
	roomSubject(std::move(other.roomSubject)),
	roomBackground(std::move(other.roomBackground)),
	roomChoiceNo(other.roomChoiceNo),
	choiceList(std::move(other.choiceList))
		
{}


void Room::drawRoom()
{
	// Background
	daveLib::DrawTexture(roomBackground, 
						settings::nullVec2, 
						DARKGRAY);
	// Window Frame
	daveLib::DrawRectangleLinesEx(settings::nullVec2, 
								settings::screenVec2, 
								settings::windowFrameThickness, 
								SHADE);

	// Textbox Base
	daveLib::DrawRectangleRounded(settings::textboxPos, 
								settings::textboxWidthHeight, 
								settings::textboxRoundness, 
								settings::textboxSegments, 
								HOLLOWBRICK);
	// Textbox Shadow
	daveLib::DrawRectangleRounded(settings::textFramePos, 
								settings::textFrameWidthHeight, 
								settings::textboxRoundness,
								settings::textboxSegments,
								DARKLIGHT);

	// Subject Shadow
	daveLib::DrawCircle(settings::ShadowsPos, 
						settings::shadowRadius, 
						SHADE);
	// Room Subject
	daveLib::DrawTexture(roomSubject, 
						settings::subjectPos, 
						RAYWHITE);


}

void Room::drawRoomText()
{
	std::string writeBuffer;
	int initialDrawPosY = settings::textPosY;
	for (std::string::iterator it = roomText.begin(); it!=roomText.end(); ++it)
	{
		writeBuffer.push_back(*it);
		if (*it == ' ')
		{
			if ( MeasureText(writeBuffer.c_str(), settings::fontSize) >= settings::writerDangerZone )
			{
				DrawText(writeBuffer.c_str(), 
							settings::textPosX, 
							initialDrawPosY, 
							settings::fontSize, 
							RAYWHITE);
				initialDrawPosY += 20;
				writeBuffer.clear();
			}
		}
	}
}



bool Room::operator < (const Room& rhs) const
{
	return (this->roomID < rhs.roomID);
}
bool Room::operator > (const Room& rhs) const
{
	return (this->roomID > rhs.roomID);
}
