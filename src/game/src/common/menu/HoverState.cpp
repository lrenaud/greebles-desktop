#include <base/MessageDispatcher.h>
#include <base/Telegram.h>
#include <content/ContentManager.h>
#include <input/Mouse.h>
#include <video/Texture2D.h>

#include "menu/HoverState.h"
#include "Messages.h"

using namespace SOAR;
using namespace Base;
using namespace Video;

HoverState::HoverState()
{

}

HoverState::~HoverState()
{

}

HoverState& HoverState::GetInstance()
{
    static HoverState instance;

    return instance;
}

void HoverState::Enter(MenuChoice* mc)
{

}

void HoverState::Execute(MenuChoice* mc)
{
    if (mc->WindowPosition().Contains(MOUSE.xPos, MOUSE.yPos) && MOUSE.LMBIsDown())
        MD.DispatchMsg(mc->Id(), mc->Id(), MOUSE_LEFT_CLICK);
    else if (!mc->WindowPosition().Contains(MOUSE.xPos, MOUSE.yPos))
        MD.DispatchMsg(mc->Id(), mc->Id(), MOUSE_EXIT);
}

void HoverState::Exit(MenuChoice* mc)
{

}

bool HoverState::OnMessage(MenuChoice* mc, const Telegram& msg)
{
    return false;
}

void HoverState::Render(MenuChoice* mc)
{
    CM.Handle<Texture2D>(mc->HoverCid())->Render(mc->WindowPosition().x,
                                                 mc->WindowPosition().y,
                                                 mc->TexturePosition());
}
