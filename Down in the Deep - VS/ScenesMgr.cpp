#include "ScenesMgr.h"

void Scenes::initRooms()
{
	roomIndex.emplace(2, Room(0, "Emanuel was Here", 
								"Assets/Subjects/BananaPeel.png", "Assets/Backgrounds/Dirt_Fullscreen.png", 1, 
								{ "1","2","3" },
								{ "Response1", "Response2","Response3" }));
	roomIndex.emplace(1, Room(1, "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Sed risus ultricies tristique nulla aliquet enim. At quis risus sed vulputate odio. Semper viverra nam libero justo laoreet sit amet. Ac turpis egestas sed tempus urna et pharetra pharetra massa. Mauris vitae ultricies leo integer. Aliquet nibh praesent tristique magna. Arcu dictum varius duis at consectetur lorem donec. Sapien pellentesque habitant morbi tristique senectus et. Adipiscing bibendum est ultricies integer quis auctor. Dolor sed viverra ipsum nunc aliquet bibendum enim facilisis. Eu scelerisque felis imperdiet proin fermentum leo vel orci. Tellus rutrum tellus pellentesque eu tincidunt. Urna cursus eget nunc scelerisque viverra mauris. Sit amet commodo nulla facilisi nullam vehicula. Mauris nunc congue nisi vitae suscipit. Habitasse platea dictumst quisque sagittis purus sit amet volutpat.", 
								"Assets/Subjects/BananaPeel.png", "Assets/Backgrounds/Dirt_Fullscreen.png", 3, 
								{ "Eat the Banana","Ignore the Banana","Talk to the Banana" },
								{"The banana was delicious, you feel replenished and ready to continue your journey, so you do",
								 "You decided ignorint the banana was the best course of action. You were wrong, while ignoring the banana, you slipped and cracked your skull",
								 "You tried talking to the banana. It was an interesting conversation by which you were heavily moved. Filled with newfound hope, you continue your journey"}));
}
