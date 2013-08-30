#include <base/Telegram.h>

#include "menu/BaseMenuState.h"
#include "menu/NetMenu.h"

using namespace SOAR;
using namespace Base;
using namespace State;

/**
 * This class is represents the main menu state of the game
 */
class NetMenuState : public BaseMenuState
{
private:

    /**
     * Private constructor for singleton
     */
    NetMenuState();

public:
    
    /**
     * Destructor
     */
    virtual ~NetMenuState();

    /**
     * Singleton access method
     */
    static NetMenuState& GetInstance();

    /**
     * This method creates a NetMenu object
     * @param g Pointer to the object
     */
    virtual void Enter(GreeblesGame* g);

    /**
     * This method calls update on the NetMenu
     * @param g Pointer to the object
     */
    virtual void Execute(GreeblesGame* g);

    /**
     * This method deletes the NetMenu Object
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
     * This method calls the Render method of the NetMenu
     * @param g Pointer to the  object
     */
    virtual void Render(GreeblesGame* g);

};