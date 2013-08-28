#include <base/Telegram.h>

#include "GreeblesGame.h"
#include "Macros.h"
#include "menu/MainMenu.h"
#include "menu/MainMenuState.h"

using namespace SOAR;
using namespace Base;

MainMenuState::MainMenuState()
{

}

MainMenuState::~MainMenuState()
{

}

MainMenuState& MainMenuState::GetInstance()
{
    static MainMenuState instance;

    return instance;
}

void MainMenuState::Enter(GreeblesGame* g)
{
    menu = new MainMenu();
}

void MainMenuState::Execute(GreeblesGame* g)
{
    menu->Update();
}

void MainMenuState::Exit(GreeblesGame* g)
{
    SAFE_DELETE(menu);
}

bool MainMenuState::OnMessage(GreeblesGame* g, const Telegram& msg)
{
    switch (msg.message)
    {
        case MSG_PLAY_CLICKED:
            return true;

        case MSG_PLAY_CUSTOM_CLICKED:
            return true;

        case MSG_HOST_NETWORK_CLICKED:
            return true;

        case MSG_JOIN_NETWORK_CLICKED:
            return true;

        case MSG_SETUP_CLICKED:
            g->LaunchApp("setup");
            return true;

        case MSG_INSTRUCTIONS_CLICKED:
            return true;

        case MSG_DEMO_CLICKED:
            return true;

        case MSG_REGISTER_CLICKED:
            return true;

        case MSG_HIDE_CLICKED:
            g->Hide();
            return true;

        case MSG_QUIT_CLICKED:
            g->Quit();
            return true;

        case MSG_ZAP_CLICKED:
            g->LaunchApp("zap");
            return true;

        case MSG_STAIRWAYS_CLICKED:
            return true;
    }

    return false;
}

void MainMenuState::Render(GreeblesGame* g)
{
    menu->Render();
}
