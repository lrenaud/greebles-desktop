#include <base/state/IState.h>
#include <base/Telegram.h>

#include "menu/MainMenu.h"

using namespace SOAR;
using namespace Base;
using namespace State;

/**
 * This class is represents the main menu state of the game
 */
class MainMenuState : public IState<GreeblesGame>
{
private:

    /**
     * The MainMenu object
     */
    MainMenu*               menu;

private:

    /**
     * Private constructor for singleton
     */
    MainMenuState();

public:
    
    /**
     * Destructor
     */
    virtual ~MainMenuState();

    /**
     * Singleton access method
     */
    static MainMenuState& GetInstance();

    /**
     * This method creates a MainMenu object
     * @param g Pointer to the object
     */
    virtual void Enter(GreeblesGame* g);

    /**
     * This method calls update on the MainMenu
     * @param g Pointer to the object
     */
    virtual void Execute(GreeblesGame* g);

    /**
     * This method deletes the MainMenu Object
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
     * This method calls the Render method of the MainMenu
     * @param g Pointer to the  object
     */
    virtual void Render(GreeblesGame* g);

};