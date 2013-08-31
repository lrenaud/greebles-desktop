#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "menu/GreeblesTitleMenu.h"

// Shorthand for adding menu choices
#define ADD_MM_MC(x, y, w, h, hover, clicked) menuChoices.push_back(new MenuChoice{ {x, y, w, h}, hover, clicked })

class MainMenu : public GreeblesTitleMenu
{
public:
    
    /**
     * Constructor
     */
    MainMenu();

    /**
     * Destructor
     */
    ~MainMenu();

    /**
     * This method takes care of drawing the idle texture
     * for the main menu. Individual MenuChoices draw the 
     * hover and pressed stages.
     */
    virtual void Render();

};

#endif
