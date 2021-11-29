#include <assert.h>
#include "Room.h"
#include "daveLib.h"
#include "Settings.h"

Room::Room (int roomID, const std::string& roomText, 
			const std::string& subjectPath, const std::string& backgroundPath,
			const int choiceNo, const std::list <std::string>& choiceList)
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

	// Textbox & Choices
	drawRoomStory();
	
	// Subject Shadow
	daveLib::DrawCircle(settings::shadowsPos, 
						settings::shadowRadius, 
						SHADE);
	// Room Subject
	daveLib::DrawTexture(roomSubject, 
						settings::subjectPos, 
						RAYWHITE);


}

void Room::drawRoomStory()
{
	Vec2<int> boxSize{};
	Vec2<int> boxFrameSize{};

	switch (roomChoiceNo) // Textbox becomes smaller for each choice
	{
	case 1: {boxSize = settings::boxSize1; boxFrameSize = settings::boxFrameSize1; break; };
	case 2: {boxSize = settings::boxSize2; boxFrameSize = settings::boxFrameSize2; break; };
	case 3: {boxSize = settings::boxSize3; boxFrameSize = settings::boxFrameSize3; break; };
	}
	// Textbox Frame
	daveLib::DrawRectangleRounded(settings::boxFramePos,
								boxFrameSize,
								settings::boxRoundness,
								settings::boxSegments,
								HOLLOWBRICK);
	// Textbox
	daveLib::DrawRectangleRounded(settings::boxPos,
								boxSize,
								settings::boxRoundness,
								settings::boxSegments,
								DARKLIGHT);
	// Choices
	int choiceX = settings::boxFramePos.GetX();
	int choiceY = settings::boxFramePos.GetY() + settings::choicePadding*2 + boxSize.GetY();
	for (int i = 0; i < roomChoiceNo; ++i)
	{
		daveLib::DrawRectangleRounded({ choiceX, choiceY },
										{ boxFrameSize.GetX(), settings::choiceHeight },
										settings::choiceRoundness,
										settings::boxSegments,
										HOLLOWBRICK);
		choiceY = choiceY + settings::choicePadding + settings::choiceHeight;
	}

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
	// Leftover Text in Buffer
	DrawText(writeBuffer.c_str(),
		settings::textPosX,
		initialDrawPosY,
		settings::fontSize,
		RAYWHITE);
}



bool Room::operator < (const Room& rhs) const
{
	return (this->roomID < rhs.roomID);
}
bool Room::operator > (const Room& rhs) const
{
	return (this->roomID > rhs.roomID);
}
