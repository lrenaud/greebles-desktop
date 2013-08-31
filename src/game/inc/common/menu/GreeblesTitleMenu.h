#ifndef GREEBLES_TITLE_MENU_H
#define GREEBLES_TITLE_MENU_H

#include "menu/BaseMenu.h"

// Shorthand for adding menu choices
#define ADD_GT_MC(x, y, w, h, hover, clicked) menuChoices.push_back(new MenuChoice{ {x, y, w, h}, hover, clicked })

class GreeblesTitleMenu : public BaseMenu
{
public:
    
    /**
     * Constructor
     */
    GreeblesTitleMenu();

    /**
     * Destructor
     */
    ~GreeblesTitleMenu();

    /**
     * This method takes care of drawing the idle texture
     * for the main menu. Individual MenuChoices draw the 
     * hover and pressed stages.
     */
    virtual void Render()=0;

};

#endif
