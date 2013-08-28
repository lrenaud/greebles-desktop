#include <base/MessageDispatcher.h>
#include <base/Telegram.h>
#include <content/ContentManager.h>
#include <input/Mouse.h>
#include <video/Texture2D.h>

#include "menu/MenuChoice.h"
#include "menu/PressedState.h"
#include "Messages.h"

using namespace SOAR;
using namespace Base;
using namespace Video;

PressedState::PressedState()
{

}

PressedState::~PressedState()
{

}

PressedState& PressedState::GetInstance()
{
    static PressedState instance;

    return instance;
}

void PressedState::Enter(MenuChoice* mc)
{

}

void PressedState::Execute(MenuChoice* mc)
{
    if (mc->WindowPosition().Contains(MOUSE.xPos, MOUSE.yPos) && !MOUSE.LMBIsDown())
        MD.DispatchMsg(mc->Id(), mc->Id(), MSG_MOUSE_LEFT_RELEASE);
    else if (!mc->WindowPosition().Contains(MOUSE.xPos, MOUSE.yPos))
        MD.DispatchMsg(mc->Id(), mc->Id(), MSG_MOUSE_EXIT);
}

void PressedState::Exit(MenuChoice* mc)
{

}

bool PressedState::OnMessage(MenuChoice* mc, const Telegram& msg)
{
    return false;
}

void PressedState::Render(MenuChoice* mc)
{
    CM.Handle<Texture2D>(mc->PressedCid())->Render(mc->WindowPosition().x,
                                                   mc->WindowPosition().y,
                                                   mc->TexturePosition());
}
