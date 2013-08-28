#ifndef MENU_CHOICE_H
#define MENU_CHOICE_H

#include <base/BaseEntity.h>
#include <base/state/StateMachine.h>
#include <base/Telegram.h>
#include <math/Rectangle.h>

using namespace SOAR;
using namespace Util;
using namespace Base;
using namespace State;
using namespace Math;

/**
 * This class represents a choice on an in-game menu. It maintains
 * it's own internal state to know when to trigger sound effects,
 * game actions, or viual changes.
 */
class MenuChoice : public BaseEntity
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

    /**
     * Content IDs for the textures to use for hover and pressed choices
     */
    int                             hoverCid            = -1;
    int                             pressedCid          = -1;

public:

    /**
     * Constructor, takes a rectangle describing the position of the choice
     * in the texture, as well as Content Id's for the hover and pressed textures.
     */
    MenuChoice(const Rectangle<int>& texturePosition, int hoverCid, int pressedCid);

    /**
     * Destructor
     */
    ~MenuChoice();

    /**
     * This method just calls update on the state machine
     */
    virtual void Update();

    /**
     * This method handles messages that are sent to this MenuChoice
     * @param  msg The message that we're receiving
     * @return     Whether or not we handled the message
     */
    virtual bool HandleMessage(const Telegram& msg);

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
    const int HoverCid()const;
    const int PressedCid()const;

};

#endif

