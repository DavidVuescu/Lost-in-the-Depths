#include <time.h>
#include <raylib.h>
#include "Game.h"
#include "Settings.h"


int main(void)
{
    srand((unsigned int)time(NULL));

    // Initialization
    //--------------------------------------------------------------------------------------
    Game game{ settings::gameWidth,
            settings::gameHeight,
            settings::targetFPS,
            "Down in the Deep PreAplha 1.9"};

    while (!game.shouldGameClose())
    {
        game.tick();
    }
    
    return 0;
}
