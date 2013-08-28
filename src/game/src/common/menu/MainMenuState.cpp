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
    return false;
}

void MainMenuState::Render(GreeblesGame* g)
{
    menu->Render();
}
