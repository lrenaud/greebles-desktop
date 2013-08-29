#include <base/Telegram.h>

#include "GreeblesGame.h"
#include "Macros.h"
#include "menu/ThanksMenu.h"
#include "menu/ThanksMenuState.h"

using namespace SOAR;
using namespace Base;

ThanksMenuState::ThanksMenuState()
{
    menu = new ThanksMenu();
}

ThanksMenuState::~ThanksMenuState()
{
    SAFE_DELETE(menu);
}

ThanksMenuState& ThanksMenuState::GetInstance()
{
    static ThanksMenuState instance;

    return instance;
}

void ThanksMenuState::Enter(GreeblesGame* g)
{
    
}

void ThanksMenuState::Execute(GreeblesGame* g)
{
    menu->Update();
}

void ThanksMenuState::Exit(GreeblesGame* g)
{
    
}

bool ThanksMenuState::OnMessage(GreeblesGame* g, const Telegram& msg)
{
    switch (msg.message)
    {
        case MSG_DONE_CLICKED:
            g->stateStack->PopState();
            return true;
    }

    return false;
}

void ThanksMenuState::Render(GreeblesGame* g)
{
    menu->Render();
}
