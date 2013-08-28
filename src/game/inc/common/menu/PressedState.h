#ifndef PRESSED_STATE_H
#define PRESSED_STATE_H

#include <base/state/IState.h>
#include <base/Telegram.h>

using namespace SOAR;
using namespace Base;
using namespace State;

/**
 * This class is represents the pressed state of a menu choice
 */
class PressedState : public IState<MenuChoice>
{
private:

    /**
     * Private constructor for singleton
     */
    PressedState();

public:
    
    /**
     * Destructor
     */
    virtual ~PressedState();

    /**
     * Singleton access method
     */
    static PressedState& GetInstance();

    /**
     * This method prepares this state
     * @param mc Pointer to the object
     */
    virtual void Enter(MenuChoice* mc);

    /**
     * This method checks to see if the mouse is still over this choice,
     * and if it was released
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

