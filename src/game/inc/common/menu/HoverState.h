#ifndef HOVER_STATE_H
#define HOVER_STATE_H

#include <base/state/IState.h>
#include <base/Telegram.h>

#include "menu/MenuChoice.h"

using namespace SOAR;
using namespace Base;
using namespace State;

/**
 * This class is represents the hover state for a menu choice
 */
class HoverState : public IState<MenuChoice>
{
private:

    /**
     * Private constructor for singleton
     */
    HoverState();

public:
    
    /**
     * Destructor
     */
    virtual ~HoverState();

    /**
     * Singleton access method
     */
    static HoverState& GetInstance();

    /**
     * This method prepares this state
     * @param mc Pointer to the object
     */
    virtual void Enter(MenuChoice* mc);

    /**
     * This method checks for mouse clicks
     * @param mc Pointer to the object
     */
    virtual void Execute(MenuChoice* mc);

    /**
     * This method cleans up after this state
     * @param mc Pointer to the object
     */
    virtual void Exit(MenuChoice* mc);

    /**
     * This method handles messages sent to this state
     * @param mc Pointer to the object
     * @param msg         The message object received
     * @return      Whether or not the message was handled
     */
    virtual bool OnMessage(MenuChoice* mc, const Telegram& msg);

    /**
     * This method takes care of rendering things for this state
     * @param mc Pointer to the  object
     */
    virtual void Render(MenuChoice* mc);

};

#endif

