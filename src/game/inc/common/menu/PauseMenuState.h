#include <base/Telegram.h>

#include "menu/BaseMenuState.h"
#include "menu/PauseMenu.h"

using namespace SOAR;
using namespace Base;
using namespace State;

/**
 * This class is represents the main menu state of the game
 */
class PauseMenuState : public BaseMenuState
{
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
     * This method calls update on the PauseMenu
     * @param g Pointer to the object
     */
    virtual void Execute(GreeblesGame* g);

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

    /**
     * This method sets the MenuChoice texture CIDS for rendering
     * Hover and Pressed MCs
     */
    virtual void SetTextureCids();

};