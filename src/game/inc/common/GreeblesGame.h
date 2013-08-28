#ifndef GREEBLES_GAME_H
#define GREEBLES_GAME_H

#include <string>

#include <base/BaseEntity.h>
#include <base/state/StateMachineStack.h>
#include <base/Telegram.h>

#include "EntityIds.h"

using namespace std;

using namespace SOAR;
using namespace Base;
using namespace State;

#define GAME GreeblesGame::GetInstance()

class GreeblesGame : public BaseEntity
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

private:

    /**
     * running flag, shutdown must be controlled.
     */
    bool                running;

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
    virtual ~GreeblesGame();

    /**
     * Singleton Access Method
     */
    static GreeblesGame& GetInstance();

    /**
     * Run Method. This method initializes the game
     * and kicks off the main loops.
     */
    void Run();

    /**
     * Internal update method, updates all game FSMs,
     * timers, whatever.
     */
    virtual void Update();

    /**
     * Entities can send messages to the game itself
     * @param  msg The message to handle
     * @return     Whether or not the message was handled
     */
    virtual bool HandleMessage(const Telegram& msg);

    /**
     * Internal render method, sets all the rendering 
     * settings, then invokes render methods on all FSMs
     */
    void Render();

    /**
     * This method just flips the running flag to false.
     */
    void Quit();

    /**
     * This method hides the game window by minimizing it.
     */
    void Hide();

    /**
     * This method will launch the specified app, and reload
     * all pertinent settings afterwards if necessary.
     * @param  appName The name of the app. Must be one of
     *                 - setup
     *                 - custom
     *                 - join
     *                 - zap
     *                 - error
     * @param  appArgs A string containing any arguments to pass to the app
     * @return         True if the app launched, closed, and settings were
     *                 successfully reloaded.
     */
    bool LaunchApp(const char* appName, const char* appArgs="");

};

#endif
