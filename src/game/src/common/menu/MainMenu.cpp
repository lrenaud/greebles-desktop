#include <content/ContentManager.h>
#include <video/Texture2D.h>

#include "ContentIds.h"
#include "GreeblesGame.h"
#include "menu/MainMenu.h"

using namespace SOAR;
using namespace Video;

MainMenu::MainMenu()
{
    // Initialize Menu Choices
    ADD_MC(25, 0, 385, 70);
    ADD_MC(580, 0, 60, 30);
    ADD_MC(400, 370, 240, 110);
    ADD_MC(70, 100, 275, 25);
    ADD_MC(70, 134, 275, 25);
    ADD_MC(70, 168, 275, 25);
    ADD_MC(70, 202, 275, 25);
    ADD_MC(70, 236, 275, 25);
    ADD_MC(70, 270, 275, 25);
    ADD_MC(70, 304, 275, 25);
    ADD_MC(70, 338, 275, 25);
    ADD_MC(70, 372, 275, 25);
    ADD_MC(70, 406, 275, 25);
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