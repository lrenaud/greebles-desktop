#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "menu/BaseMenu.h"

// Shorthand for adding menu choices
#define ADD_MC(x, y, w, h, hover, clicked) menuChoices.push_back(new MenuChoice{ {x, y, w, h}, hover, clicked, CID_MENU_TITLE_HOVER, CID_MENU_TITLE_PRESSED })

class MainMenu : public BaseMenu
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
