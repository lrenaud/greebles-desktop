#include <content/ContentManager.h>
#include <video/Texture2D.h>

#include "ContentIds.h"
#include "GreeblesGame.h"
#include "menu/PauseMenu.h"
#include "Messages.h"

using namespace SOAR;
using namespace Video;

PauseMenu::PauseMenu()
{
    // Initialize Menu Choices
    ADD_PM_MC(25, 219, 129, 96, MSG_INVALID, MSG_INSTRUCTIONS_CLICKED);
    ADD_PM_MC(26, 362, 129, 96, MSG_INVALID, MSG_KILL_GAME_CLICKED);
    ADD_PM_MC(250, 363, 129, 96, MSG_INVALID, MSG_SETUP_CLICKED);
    ADD_PM_MC(490, 363, 129, 96, MSG_INVALID, MSG_RESUME_GAME_CLICKED);
    ADD_PM_MC(489, 218, 129, 96, MSG_INVALID, MSG_HIDE_CLICKED);
}

PauseMenu::~PauseMenu()
{

}

void PauseMenu::Render()
{
    CM.Handle<Texture2D>(CID_MENU_THANKS_IDLE)->Render(GreeblesGame::GAME_AREA_MIN_X,
                                                       GreeblesGame::GAME_AREA_MIN_Y);

    for (auto mc : menuChoices)
        mc->Render();
}
