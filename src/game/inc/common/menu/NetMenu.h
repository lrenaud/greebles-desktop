#ifndef NET_MENU_H
#define NET_MENU_H

#include "menu/BaseMenu.h"

// Shorthand for adding menu choices
#define ADD_NET_MC(x, y, w, h, hover, clicked) menuChoices.push_back(new MenuChoice{ {x, y, w, h}, hover, clicked, CID_MENU_NET_HOVER, CID_MENU_NET_PRESSED })

class NetMenu : public BaseMenu
{
public:
    
    /**
     * Constructor
     */
    NetMenu();

    /**
     * Destructor
     */
    ~NetMenu();

    /**
     * This method takes care of drawing the idle texture
     * for the main menu. Individual MenuChoices draw the 
     * hover and pressed stages.
     */
    virtual void Render();

};

#endif
