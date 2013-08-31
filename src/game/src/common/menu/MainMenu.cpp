#include <content/ContentManager.h>
#include <video/Texture2D.h>

#include "ContentIds.h"
#include "GreeblesGame.h"
#include "menu/MainMenu.h"
#include "Messages.h"

using namespace SOAR;
using namespace Video;

MainMenu::MainMenu()
{
    // Initialize Menu Choices
    ADD_MM_MC(580, 0, 60, 30, MSG_INVALID, MSG_ZAP_CLICKED);
    ADD_MM_MC(390, 370, 240, 55, MSG_INVALID, MSG_STAIRWAYS_CLICKED);
    ADD_MM_MC(400, 430, 240, 50, MSG_INVALID, MSG_INVALID);
    ADD_MM_MC(64, 100, 280, 25, MSG_INVALID, MSG_PLAY_CLICKED);
    ADD_MM_MC(64, 134, 280, 25, MSG_INVALID, MSG_PLAY_CUSTOM_CLICKED);
    ADD_MM_MC(64, 168, 280, 25, MSG_INVALID, MSG_HOST_NETWORK_CLICKED);
    ADD_MM_MC(64, 202, 280, 25, MSG_INVALID, MSG_JOIN_NETWORK_CLICKED);
    ADD_MM_MC(64, 236, 280, 25, MSG_INVALID, MSG_SETUP_CLICKED);
    ADD_MM_MC(64, 270, 280, 25, MSG_INVALID, MSG_INSTRUCTIONS_CLICKED);
    ADD_MM_MC(64, 304, 280, 25, MSG_INVALID, MSG_DEMO_CLICKED);
    ADD_MM_MC(64, 338, 280, 25, MSG_INVALID, MSG_REGISTER_CLICKED);
    ADD_MM_MC(64, 372, 280, 25, MSG_INVALID, MSG_HIDE_CLICKED);
    ADD_MM_MC(64, 406, 280, 25, MSG_INVALID, MSG_QUIT_CLICKED);
}

MainMenu::~MainMenu()
{

}

void MainMenu::Render()
{
    CM.Handle<Texture2D>(CID_MENU_TITLE_IDLE)->Render(GreeblesGame::GAME_AREA_MIN_X,
                                                      GreeblesGame::GAME_AREA_MIN_Y);

    for (auto mc : menuChoices)
        mc->Render();
}
