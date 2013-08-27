#ifndef GLOBAL_GAME_STATE_H
#define GLOBAL_GAME_STATE_H

#include <util/state/IState.h>

#include "GreeblesGame.h"

using namespace SOAR;
using namespace Util;
using namespace State;

class GlobalGameState : public IState<GreeblesGame>
{
private:

    /**
     * Constructor
     */
    GlobalGameState();

public:
    
    /**
     * Destructor
     */
    virtual ~GlobalGameState();

    /**
     * Singleton access method
     */
    static GlobalGameState& GetInstance();

    /**
     * This method prepares everything for the game. It takes care of loading
     * content, and initializing game systems
     * @param g Pointer to the game object
     */
    virtual void Enter(GreeblesGame* g);

    /**
     * This method takes care of everything that needs to be done in the game
     * every cycle, regardless of state.
     * @param g Pointer to the game object
     */
    virtual void Execute(GreeblesGame* g);

    /**
     * This method takes care of releasing everything once the game has ended.
     * @param g Pointer to the game object
     */
    virtual void Exit(GreeblesGame* g);

    /**
     * This method takes care of rendering things for this state
     * @param g Pointer to the game object
     */
    virtual void Render(GreeblesGame* g);

};

#endif
