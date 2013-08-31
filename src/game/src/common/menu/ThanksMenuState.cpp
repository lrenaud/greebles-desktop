#include <base/Telegram.h>

#include "ContentIds.h"
#include "GreeblesGame.h"
#include "Macros.h"
#include "menu/MenuChoice.h"
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

void ThanksMenuState::Execute(GreeblesGame* g)
{
    menu->Update();
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

void ThanksMenuState::SetTextureCids()
{
    MenuChoice::hoverCid = CID_MENU_THANKS_HOVER;
    MenuChoice::pressedCid = CID_MENU_THANKS_PRESSED;
}
