#include <base/state/IState.h>
#include <base/Telegram.h>

#include "menu/PauseMenu.h"

using namespace SOAR;
using namespace Base;
using namespace State;

/**
 * This class is represents the main menu state of the game
 */
class PauseMenuState : public IState<GreeblesGame>
{
private:

    /**
     * The PauseMenu object
     */
    PauseMenu*               menu;

private:

    /**
     * Private constructor for singleton
     */
    PauseMenuState();

public:
    
    /**
     * Destructor
     */
    virtual ~PauseMenuState();

    /**
     * Singleton access method
     */
    static PauseMenuState& GetInstance();

    /**
     * This method creates a PauseMenu object
     * @param g Pointer to the object
     */
    virtual void Enter(GreeblesGame* g);

    /**
     * This method calls update on the PauseMenu
     * @param g Pointer to the object
     */
    virtual void Execute(GreeblesGame* g);

    /**
     * This method deletes the PauseMenu Object
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
     * This method calls the Render method of the PauseMenu
     * @param g Pointer to the  object
     */
    virtual void Render(GreeblesGame* g);

};