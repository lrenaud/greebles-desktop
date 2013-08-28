#include <base/MessageDispatcher.h>
#include <content/ContentManager.h>
#include <input/Mouse.h>
#include <video/Texture.h>
#include <video/Texture2D.h>

#include "ContentIds.h"
#include "GreeblesGame.h"
#include "menu/HoverState.h"
#include "menu/IdleState.h"
#include "menu/MenuChoice.h"
#include "Messages.h"

using namespace SOAR;
using namespace Base;
using namespace State;
using namespace Video;

IdleState::IdleState()
{

}

IdleState::~IdleState()
{

}

IdleState& IdleState::GetInstance()
{
    static IdleState instance;

    return instance;
}

void IdleState::Enter(MenuChoice* mc)
{
    
}

void IdleState::Execute(MenuChoice* mc)
{
    if (mc->WindowPosition().Contains(MOUSE.xPos, MOUSE.yPos))
        MD.DispatchMsg(mc->Id(), mc->Id(), MOUSE_ENTER);
}

void IdleState::Exit(MenuChoice* mc)
{
    
}

bool IdleState::OnMessage(MenuChoice* mc, const Telegram& msg)
{
    return false;
}

void IdleState::Render(MenuChoice* mc)
{
    
}

