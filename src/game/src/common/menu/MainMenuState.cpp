#include <base/Telegram.h>
#include <util/Log.h>

#include "ContentIds.h"
#include "GreeblesGame.h"
#include "Macros.h"
#include "menu/InstructionsMenuState.h"
#include "menu/MainMenu.h"
#include "menu/MainMenuState.h"
#include "menu/MenuChoice.h"
#include "menu/NetMenuState.h"
#include "menu/ThanksMenuState.h"

using namespace SOAR;
using namespace Base;

MainMenuState::MainMenuState()
{
    menu = new MainMenu();
}

MainMenuState::~MainMenuState()
{
    SAFE_DELETE(menu);
}

MainMenuState& MainMenuState::GetInstance()
{
    static MainMenuState instance;

    return instance;
}

void MainMenuState::Execute(GreeblesGame* g)
{
    menu->Update();
}

bool MainMenuState::OnMessage(GreeblesGame* g, const Telegram& msg)
{
    switch (msg.message)
    {
        case MSG_PLAY_CLICKED:
            // Start local game
            return true;

        case MSG_PLAY_CUSTOM_CLICKED:
            g->LaunchApp("custom", "-l4 -h2");
            return true;

        case MSG_HOST_NETWORK_CLICKED:
            g->LaunchApp("custom", "-l4 -h2 -n");
            g->stateStack->PushState(&NetMenuState::GetInstance());
            return true;

        case MSG_JOIN_NETWORK_CLICKED:
            g->LaunchApp("join", "-l4 -h2");
            g->stateStack->PushState(&NetMenuState::GetInstance());
            return true;

        case MSG_SETUP_CLICKED:
            g->LaunchApp("setup");
            return true;

        case MSG_INSTRUCTIONS_CLICKED:
            g->stateStack->PushState(&InstructionsMenuState::GetInstance());
            return true;

        case MSG_DEMO_CLICKED:
            // Start Game with all AI players
            return true;

        case MSG_REGISTER_CLICKED:
            g->stateStack->PushState(&ThanksMenuState::GetInstance());
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
            // Launch internet browser, to go to website.
            return true;
    }

    return false;
}

void MainMenuState::Render(GreeblesGame* g)
{    
    menu->Render();
}

void MainMenuState::SetTextureCids()
{
    MenuChoice::hoverCid = CID_MENU_TITLE_HOVER;
    MenuChoice::pressedCid = CID_MENU_TITLE_PRESSED;
}
