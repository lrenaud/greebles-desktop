#include <base/Telegram.h>

#include "GreeblesGame.h"
#include "Macros.h"
#include "menu/PauseMenu.h"
#include "menu/PauseMenuState.h"

using namespace SOAR;
using namespace Base;

PauseMenuState::PauseMenuState()
{

}

PauseMenuState::~PauseMenuState()
{

}

PauseMenuState& PauseMenuState::GetInstance()
{
    static PauseMenuState instance;

    return instance;
}

void PauseMenuState::Enter(GreeblesGame* g)
{
    menu = new PauseMenu();
}

void PauseMenuState::Execute(GreeblesGame* g)
{
    menu->Update();
}

void PauseMenuState::Exit(GreeblesGame* g)
{
    SAFE_DELETE(menu);
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
