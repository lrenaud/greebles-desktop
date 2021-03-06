#include <base/EntityManager.h>
#include <base/MessageDispatcher.h>
#include <base/state/StateMachine.h>
#include <base/Telegram.h>
#include <math/Rectangle.h>
#include <util/Log.h>

#include "EntityIds.h"
#include "GreeblesGame.h"
#include "Macros.h"
#include "menu/HoverState.h"
#include "menu/IdleState.h"
#include "menu/MenuChoice.h"
#include "menu/PressedState.h"
#include "Messages.h"

using namespace SOAR;
using namespace Math;

int MenuChoice::hoverCid = -1;
int MenuChoice::pressedCid = -1;

MenuChoice::MenuChoice(const Rectangle<int>& texturePosition, int hoverMsg, int clickedMsg)
{
    this->texturePosition = texturePosition;
    
    this->windowPosition = texturePosition;
    this->windowPosition.x += GreeblesGame::GAME_AREA_MIN_X;
    this->windowPosition.y += GreeblesGame::GAME_AREA_MIN_Y;

    this->hoverMsg = hoverMsg;
    this->clickedMsg = clickedMsg;

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

    if (msg.message == MSG_MOUSE_ENTER)
    {
        stateMachine->ChangeState(&HoverState::GetInstance());
        MD.DispatchMsg(Id(), GAME_ID, hoverMsg);
    }
    else if (msg.message == MSG_MOUSE_EXIT)
        stateMachine->ChangeState(&IdleState::GetInstance());
    else if (msg.message == MSG_MOUSE_LEFT_CLICK)
        stateMachine->ChangeState(&PressedState::GetInstance());
    else if (msg.message == MSG_MOUSE_LEFT_RELEASE)
    {
        stateMachine->ChangeState(&HoverState::GetInstance());
        MD.DispatchMsg(Id(), GAME_ID, clickedMsg);
    }
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
