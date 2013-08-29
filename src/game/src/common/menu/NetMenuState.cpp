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
    menu = new NetMenu();
}

NetMenuState::~NetMenuState()
{
    SAFE_DELETE(menu);   
}

NetMenuState& NetMenuState::GetInstance()
{
    static NetMenuState instance;

    return instance;
}

void NetMenuState::Enter(GreeblesGame* g)
{
    
}

void NetMenuState::Execute(GreeblesGame* g)
{
    menu->Update();
}

void NetMenuState::Exit(GreeblesGame* g)
{
    
}

bool NetMenuState::OnMessage(GreeblesGame* g, const Telegram& msg)
{
    switch (msg.message)
    {
        case MSG_CANCEL_CLICKED:
            g->stateStack->PopState();
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
