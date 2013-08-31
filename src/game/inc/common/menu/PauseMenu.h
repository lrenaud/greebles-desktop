#ifndef PAUSE_MENU_H
#define PAUSE_MENU_H

#include "menu/BaseMenu.h"

// Shorthand for adding menu choices
#define ADD_PM_MC(x, y, w, h, hover, clicked) menuChoices.push_back(new MenuChoice{ {x, y, w, h}, hover, clicked })

class PauseMenu : public BaseMenu
{
public:
    
    /**
     * Constructor
     */
    PauseMenu();

    /**
     * Destructor
     */
    virtual ~PauseMenu();

    /**
     * This method takes care of drawing the idle texture
     * for the main menu. Individual MenuChoices draw the 
     * hover and pressed stages.
     */
    virtual void Render();

};

#endif
