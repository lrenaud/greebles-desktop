#include <base/state/IState.h>
#include <base/Telegram.h>

#include "menu/ThanksMenu.h"

using namespace SOAR;
using namespace Base;
using namespace State;

/**
 * This class is represents the main menu state of the game
 */
class ThanksMenuState : public IState<GreeblesGame>
{
private:

    /**
     * The ThanksMenu object
     */
    ThanksMenu*               menu;

private:

    /**
     * Private constructor for singleton
     */
    ThanksMenuState();

public:
    
    /**
     * Destructor
     */
    virtual ~ThanksMenuState();

    /**
     * Singleton access method
     */
    static ThanksMenuState& GetInstance();

    /**
     * This method creates a ThanksMenu object
     * @param g Pointer to the object
     */
    virtual void Enter(GreeblesGame* g);

    /**
     * This method calls update on the ThanksMenu
     * @param g Pointer to the object
     */
    virtual void Execute(GreeblesGame* g);

    /**
     * This method deletes the ThanksMenu Object
     * @param g Pointer to the object
     */
    virtual void Exit(GreeblesGame* g);

    /**
     * This method handles messages sent to this state
     * @param g Pointer to the object
     * @param msg         The message object received
     * @return      Whether or not the message was handled
     */
    virtual bool OnMessage(GreeblesGame* g, const Telegram& msg);

    /**
     * This method calls the Render method of the ThanksMenu
     * @param g Pointer to the  object
     */
    virtual void Render(GreeblesGame* g);

};