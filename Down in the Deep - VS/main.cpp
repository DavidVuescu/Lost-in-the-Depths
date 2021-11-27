#include <raylib.h>
#include "Game.h"
#include "Settings.h"


int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    Game game{ settings::gameWidth,
            settings::gameHeight,
            settings::targetFPS,
            "Down in the Deep PreAplha 1.6"};

    while (!game.shouldGameClose())
    {
        game.tick();
    }
    
    return 0;
}
