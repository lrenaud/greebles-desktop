#include <content/ContentManager.h>
#include <video/Texture2D.h>

#include "ContentIds.h"
#include "GreeblesGame.h"
#include "menu/ThanksMenu.h"
#include "Messages.h"

using namespace SOAR;
using namespace Video;

ThanksMenu::ThanksMenu()
{
    // Initialize Menu Choices
    ADD_TM_MC(463, 352, 160, 110, MSG_INVALID, MSG_DONE_CLICKED);
}

ThanksMenu::~ThanksMenu()
{

}

void ThanksMenu::Render()
{
    CM.Handle<Texture2D>(CID_MENU_THANKS_IDLE)->Render(GreeblesGame::GAME_AREA_MIN_X,
                                                       GreeblesGame::GAME_AREA_MIN_Y);

    for (auto mc : menuChoices)
        mc->Render();
}
