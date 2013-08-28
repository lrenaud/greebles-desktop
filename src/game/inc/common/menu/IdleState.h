#ifndef IDLE_STATE_H
#define IDLE_STATE_H

#include <base/state/IState.h>
#include <base/Telegram.h>

#include "menu/MenuChoice.h"

using namespace SOAR;
using namespace Base;
using namespace State;

/**
 * This class is represents the idle state for a menu choice
 */
class IdleState : public IState<MenuChoice>
{
private:

    /**
     * Private constructor for singleton
     */
    IdleState();

public:
    
    /**
     * Destructor
     */
    virtual ~IdleState();

    /**
     * Singleton access method
     */
    static IdleState& GetInstance();

    /**
     * This method prepares everything for the menu choice.
     * @param mc Pointer to the menu choice object
     */
    virtual void Enter(MenuChoice* mc);

    /**
     * This will poll the mouse state and update the menu choice state 
     * appropriately. 
     * @param mc Pointer to the menu choice object
     */
    virtual void Execute(MenuChoice* mc);

    /**
     * This method takes care of releasing everything once the menu choice has ended.
     * @param mc Pointer to the menu choice object
     */
    virtual void Exit(MenuChoice* mc);

    /**
     * This method provides the state a place to handle messages
     */
    virtual bool OnMessage(MenuChoice* mc, const Telegram& msg);

    /**
     * This method takes care of rendering things for this state
     * @param mc Pointer to the menu choice object
     */
    virtual void Render(MenuChoice* mc);

};

#endif
