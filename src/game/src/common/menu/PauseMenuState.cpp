#include <base/Telegram.h>

#include "ContentIds.h"
#include "GreeblesGame.h"
#include "Macros.h"
#include "menu/MenuChoice.h"
#include "menu/PauseMenu.h"
#include "menu/PauseMenuState.h"

using namespace SOAR;
using namespace Base;

PauseMenuState::PauseMenuState()
{
    menu = new PauseMenu();
}

PauseMenuState::~PauseMenuState()
{
    SAFE_DELETE(menu);
}

PauseMenuState& PauseMenuState::GetInstance()
{
    static PauseMenuState instance;

    return instance;
}

void PauseMenuState::Execute(GreeblesGame* g)
{
    menu->Update();
}

bool PauseMenuState::OnMessage(GreeblesGame* g, const Telegram& msg)
{
    switch (msg.message)
    {
        case MSG_INSTRUCTIONS_CLICKED:
            return true;

        case MSG_KILL_GAME_CLICKED:
            return true;

        case MSG_SETUP_CLICKED:
            g->LaunchApp("setup");
            return true;

        case MSG_HIDE_CLICKED:
            g->Hide();
            return true;

        case MSG_RESUME_GAME_CLICKED:
            g->stateStack->PopState();
            return true;
    }

    return false;
}

void PauseMenuState::Render(GreeblesGame* g)
{
    menu->Render();
}

void PauseMenuState::SetTextureCids()
{
    MenuChoice::hoverCid = CID_MENU_PAUSE_HOVER;
    MenuChoice::pressedCid = CID_MENU_PAUSE_PRESSED;
}
