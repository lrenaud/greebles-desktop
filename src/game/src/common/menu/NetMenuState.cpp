#include <base/Telegram.h>
#include <base/MessageDispatcher.h>
#include <util/Log.h>

#include "EntityIds.h"
#include "Messages.h"
#include "GreeblesGame.h"
#include "Macros.h"
#include "menu/NetMenu.h"
#include "menu/NetMenuState.h"

using namespace SOAR;
using namespace Base;

NetMenuState::NetMenuState()
{

}

NetMenuState::~NetMenuState()
{
    
}

NetMenuState& NetMenuState::GetInstance()
{
    static NetMenuState instance;

    return instance;
}

void NetMenuState::Enter(GreeblesGame* g)
{
    menu = new NetMenu();
}

void NetMenuState::Execute(GreeblesGame* g)
{
    menu->Update();
}

void NetMenuState::Exit(GreeblesGame* g)
{
    SAFE_DELETE(menu);
}

bool NetMenuState::OnMessage(GreeblesGame* g, const Telegram& msg)
{
    switch (msg.message)
    {
        case MSG_CANCEL_CLICKED:
            MD.DispatchMsg(menu->Id(), GAME_ID, MSG_POP_STATE);
            return true;

        case MSG_PLAY_CLICKED:
            return true;
    }

    return false;
}

void NetMenuState::Render(GreeblesGame* g)
{
    menu->Render();
}
