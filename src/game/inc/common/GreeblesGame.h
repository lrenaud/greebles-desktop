#ifndef GREEBLES_GAME_H
#define GREEBLES_GAME_H

#include <string>

#include <util/state/StateMachineStack.h>

using namespace std;

using namespace SOAR;
using namespace Util;
using namespace State;

class GreeblesGame
{
public:

    /**
     * Constants
     */
    const static int    GAME_WINDOW_ID          = 1;

    const static int    WINDOW_WIDTH            = 800;
    const static int    WINDOW_HEIGHT           = 600;

    const static int    GAME_AREA_MIN_X         = 80;
    const static int    GAME_AREA_MIN_Y         = 60;

    const static int    GAME_AREA_MAX_X         = 720;
    const static int    GAME_AREA_MAX_Y         = 540;

public:

    /**
     * Most data members of the game will be public so that other game 
     * systems can access them as needed
     */
    
    /**
     * The Game's State Machine
     */
    StateMachineStack<GreeblesGame>*     stateStack     = nullptr;

private:  

    /**
     * Private Constructor for Singleton 
     */
    GreeblesGame();

public:

    /**
     * Destructor
     */
    ~GreeblesGame();

    /**
     * Singleton Access Method
     */
    static GreeblesGame& GetInstance();

    /**
     * Run Method. This method initializes the game
     * and kicks off the main loops.
     */
    void Run();

private:

    /**
     * Internal update method, updates all game FSMs,
     * timers, whatever.
     */
    void update();

    /**
     * Internal render method, sets all the rendering 
     * settings, then invokes render methods on all FSMs
     */
    void render();

};

#endif
