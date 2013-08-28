#include <base/state/StateMachine.h>
#include <base/Telegram.h>
#include <math/Rectangle.h>
#include <util/Log.h>

#include "GreeblesGame.h"
#include "Macros.h"
#include "menu/MenuChoice.h"
#include "menu/IdleState.h"
#include "menu/HoverState.h"
#include "menu/PressedState.h"
#include "Messages.h"

using namespace SOAR;
using namespace Math;

MenuChoice::MenuChoice(const Rectangle<int>& texturePosition, int hoverCid, int pressedCid)
{
    this->texturePosition = texturePosition;
    
    this->windowPosition = texturePosition;
    this->windowPosition.x += GreeblesGame::GAME_AREA_MIN_X;
    this->windowPosition.y += GreeblesGame::GAME_AREA_MIN_Y;

    this->hoverCid = hoverCid;
    this->pressedCid = pressedCid;

    stateMachine = new StateMachine<MenuChoice>(this);
    stateMachine->SetGlobalState(nullptr);
    stateMachine->SetCurrentState(&IdleState::GetInstance());
}

MenuChoice::~MenuChoice()
{
    SAFE_DELETE(stateMachine);
}

void MenuChoice::Update()
{
    stateMachine->Update();
}

bool MenuChoice::HandleMessage(const Telegram& msg)
{
    if (stateMachine->HandleMessage(msg))
        return true;

    if (msg.message == MOUSE_ENTER)
        stateMachine->ChangeState(&HoverState::GetInstance());
    else if (msg.message == MOUSE_EXIT)
        stateMachine->ChangeState(&IdleState::GetInstance());
    else if (msg.message == MOUSE_LEFT_CLICK)
        stateMachine->ChangeState(&PressedState::GetInstance());
    else if (msg.message == MOUSE_LEFT_RELEASE)
        stateMachine->ChangeState(&HoverState::GetInstance());
    else
        return false;

    return true;
}

void MenuChoice::Render()
{
    stateMachine->Render();
}

const Rectangle<int>& MenuChoice::WindowPosition()
{
    return windowPosition;
}

const Rectangle<int>& MenuChoice::TexturePosition()
{
    return texturePosition;
}

const int MenuChoice::HoverCid()const
{
    return hoverCid;
}

const int MenuChoice::PressedCid()const
{
    return pressedCid;
}
