#ifndef INSTRUCTIONS_MENU_H
#define INSTRUCTIONS_MENU_H

#include "menu/BaseMenu.h"

// Shorthand for adding menu choices
#define ADD_MI_MC(x, y, w, h, hover, clicked) menuChoices.push_back(new MenuChoice{ {x, y, w, h}, hover, clicked })

class MoreInstructionsMenu : public BaseMenu
{
public:
    
    /**
     * Constructor
     */
    MoreInstructionsMenu();

    /**
     * Destructor
     */
    ~MoreInstructionsMenu();

    /**
     * This method takes care of drawing the idle texture
     * for the main menu. Individual MenuChoices draw the 
     * hover and pressed stages.
     */
    virtual void Render();

};

#endif
