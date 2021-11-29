#include <assert.h>
#include "Room.h"
#include "daveLib.h"
#include "Settings.h"

Room::Room (int roomID, 
			const std::string& roomText, 
			const std::string& subjectPath, 
			const std::string& backgroundPath,
			const int choiceNo, 
			const std::vector <std::string>& choiceList,
			const std::vector <std::string>& choiceResults)
	:
	roomID(roomID),
	roomText(roomText),
	roomSubject(LoadTexture(subjectPath.c_str())),
	roomBackground(LoadTexture(backgroundPath.c_str())),
	roomChoiceNo(choiceNo),
	choiceList(choiceList),
	choiceResultList(choiceResults)
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
	choiceList(),
	choiceResultList()
{}

Room& Room::operator = (const Room& other) 
{
	roomID = other.roomID;
	roomText = other.roomText;
	roomSubject = other.roomSubject;
	roomBackground = other.roomBackground;
	roomChoiceNo = other.roomChoiceNo;
	choiceList = other.choiceList;
	choiceResultList = other.choiceList;
	return *this;
}

Room::~Room() noexcept
{}

Room::Room(Room&& other) noexcept
	:
	roomID(other.roomID),
	roomText(std::move(other.roomText)),
	roomSubject(std::move(other.roomSubject)),
	roomBackground(std::move(other.roomBackground)),
	roomChoiceNo(other.roomChoiceNo),
	choiceList(std::move(other.choiceList)),
	choiceResultList(std::move(other.choiceResultList))
		
{}

const int Room::getRoomID()
{
	return roomID;
}

int Room::getChoiceNo()
{
	return roomChoiceNo;
}


// Draw Room Functions: Background, Window Frame, Subject, Subject Shadow
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

	// Subject Shadow
	daveLib::DrawCircle(settings::shadowsPos, 
						settings::shadowRadius, 
						SHADE);
	// Room Subject
	daveLib::DrawTexture(roomSubject, 
						settings::subjectPos, 
						RAYWHITE);
}

// Draw Room Functions: Textbox & Choices 
void Room::drawRoomStory()
{
	Vec2<int> boxSize{};
	Vec2<int> boxFrameSize{};
	Vec2<int> choicePos{};

	switch (roomChoiceNo) // Assigning box sizing dependant on number of choices
	{
	case 1: {boxSize = settings::boxSize1; boxFrameSize = settings::boxFrameSize1; choicePos = settings::choicePos1; break; };
	case 2: {boxSize = settings::boxSize2; boxFrameSize = settings::boxFrameSize2; choicePos = settings::choicePos2; break; };
	case 3: {boxSize = settings::boxSize3; boxFrameSize = settings::boxFrameSize3; choicePos = settings::choicePos3; break; };
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
	for (int i = 0; i < roomChoiceNo; ++i)
	{
		// Choices
		daveLib::DrawRectangleRounded(choicePos,
									{ boxFrameSize.GetX(), settings::choiceHeight },
									settings::choiceRoundness,
									settings::boxSegments,
									HOLLOWBRICK);

		// Choice Text
		Vec2<int> choiceTextCoords = choicePos + settings::choiceDisplacement;

		DrawText(choiceList[i].c_str(), 
				choiceTextCoords.GetX(),
				choiceTextCoords.GetY(),
				settings::fontSize, 
				RAYWHITE);

		choicePos += {0, settings::choicePadding + settings::choiceHeight};//Moving drawing to next choice position
	}

}

// Draw Room Functions: Text
void Room::roomTextWriter()
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
