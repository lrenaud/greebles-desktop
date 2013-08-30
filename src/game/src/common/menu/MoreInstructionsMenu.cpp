#include <content/ContentManager.h>
#include <video/Texture2D.h>

#include "ContentIds.h"
#include "GreeblesGame.h"
#include "menu/MoreInstructionsMenu.h"
#include "Messages.h"

using namespace SOAR;
using namespace Video;

MoreInstructionsMenu::MoreInstructionsMenu()
{
    // Initialize Menu Choices
    
}

MoreInstructionsMenu::~MoreInstructionsMenu()
{

}

void MoreInstructionsMenu::Render()
{
    CM.Handle<Texture2D>(CID_MENU_INSTRUCTIONS_1_IDLE)->Render(GreeblesGame::GAME_AREA_MIN_X,
                                                               GreeblesGame::GAME_AREA_MIN_Y);

    for (auto mc : menuChoices)
        mc->Render();
}
