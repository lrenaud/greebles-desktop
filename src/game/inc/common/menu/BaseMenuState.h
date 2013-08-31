#ifndef HOVER_STATE_H
#define HOVER_STATE_H

#include <base/state/IStackableState.h>
#include <base/Telegram.h>

#include "GreeblesGame.h"
#include "menu/BaseMenu.h"

using namespace SOAR;
using namespace Base;
using namespace State;

/**
 * This class is represents the hover state for a menu choice
 */
class BaseMenuState : public IStackableState<GreeblesGame>
{
protected:

    /**
     * Every menu state creates a menu instance
     */
    BaseMenu*               menu;

protected:

    /**
     * Private constructor for singleton
     */
    BaseMenuState(){}

public:
    
    /**
     * Destructor
     */
    virtual ~BaseMenuState(){}

    /**
     * This method prepares this state
     * @param g Pointer to the object
     */
    virtual void Enter(GreeblesGame* g);

    /**
     * This method checks for mouse clicks
     * @param g Pointer to the object
     */
    virtual void Execute(GreeblesGame* g)=0;

    /**
     * This method cleans up after this state
     * @param g Pointer to the object
     */
    virtual void Exit(GreeblesGame* g);

    /**
     * This method handles messages sent to this state
     * @param g Pointer to the object
     * @param msg         The message object received
     * @return      Whether or not the message was handled
     */
    virtual bool OnMessage(GreeblesGame* g, const Telegram& msg)=0;

    /**
     * This method takes care of rendering things for this state
     * @param g Pointer to the  object
     */
    virtual void Render(GreeblesGame* g)=0;

    /**
     * This method is called when this state is pushed deeper onto the stateStack
     * @param g Pointer to the game object
     */
    virtual void Pause(GreeblesGame* g);

    /**
     * This method is called when this state rises to the top of the stack
     * @param g Pointer to the game object
     */
    virtual void Resume(GreeblesGame* g);

    /**
     * This method is called by Resume, it should set the current content Ids for the 
     * menu choice hover/pressed CIDs for the current menu.
     */
    virtual void SetTextureCids()=0;

};

#endif

