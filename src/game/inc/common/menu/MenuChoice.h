#ifndef MENU_CHOICE_H
#define MENU_CHOICE_H

#include <math/Rectangle.h>
#include <util/state/StateMachine.h>

using namespace SOAR;
using namespace Util;
using namespace State;
using namespace Math;

/**
 * This class represents a choice on an in-game menu. It maintains
 * it's own internal state to know when to trigger sound effects,
 * game actions, or viual changes.
 */
class MenuChoice
{
private:

    /**
     * This menu's absolute location (WINDOW COORDINATES)
     */
    Rectangle<int>                  windowPosition      = {0, 0, 0, 0};

    /**
     * This menu choice's aboslute location in texture coordinates
     */
    Rectangle<int>                  texturePosition     = {0, 0, 0, 0};

    /**
     * This menu choice's state machine (for internal state)
     */
    StateMachine<MenuChoice>*       stateMachine        = nullptr;

public:

    /**
     * Constructor
     */
    MenuChoice(const Rectangle<int>& texturePosition);

    /**
     * Destructor
     */
    ~MenuChoice();

    /**
     * This method just calls update on the state machine
     */
    void Update();

    /**
     * This just calls Render on the current state. If a menu choice is in the
     * idle state, it does nothing, but if it's in any other state, it draws the
     * appropriate overlay.
     */
    void Render();

    /**
     * Accessors
     */
    const Rectangle<int>& WindowPosition();
    const Rectangle<int>& TexturePosition();

};

#endif

