#ifndef BASE_MENU_H
#define BASE_MENU_H

#include <vector>

#include <base/BaseEntity.h>

#include "menu/MenuChoice.h"

using namespace std;

/**
 * This class represents the basic idea of a menu.
 * It contains a vector of MenuChoices, and knows how to update them.
 * More specialize instances must intiialize the choices and render them.
 */
class BaseMenu : public BaseEntity
{
protected:

    /**
     * Vector of MenuChoices
     */
    vector<MenuChoice*>          menuChoices;

public:

    /**
     * Destructor
     */
    virtual ~BaseMenu();

    /**
     * Update method, updates each menu choice.
     */
    virtual void Update();

    /**
     * This method handles messages for this entity
     * @param  msg The message to handle
     * @return     Whether or not the message was handled
     */
    virtual bool HandleMessage(const Telegram& msg);

    /**
     * Render method, must be implemented by child classes
     */
    virtual void Render()=0;

};

#endif
