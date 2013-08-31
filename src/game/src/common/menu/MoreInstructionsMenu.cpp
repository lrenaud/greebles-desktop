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
    ADD_MI_MC(0, 0, 86, 57, MSG_SPECIAL_NAME_HOVER, MSG_INVALID);
    ADD_MI_MC(148, 0, 259, 55, MSG_LEVEL_TITLE_HOVER, MSG_INVALID);
    ADD_MI_MC(520, 0, 120, 233, MSG_PLAYER_INFO_HOVER, MSG_INVALID);
    ADD_MI_MC(507, 396, 133, 84, MSG_PERCENT_HOVER, MSG_INVALID);
    ADD_MI_MC(216, 90, 210, 85, MSG_PUSH_HOVER, MSG_INVALID);
    ADD_MI_MC(57, 151, 98, 98, MSG_CRUSH_HOVER, MSG_INVALID);
    ADD_MI_MC(18, 406, 181, 79, MSG_SQUISH_HOVER, MSG_INVALID);

    ADD_MI_MC(404, 275, 126, 86, MSG_INVALID, MSG_DONE_CLICKED);
}

MoreInstructionsMenu::~MoreInstructionsMenu()
{

}

void MoreInstructionsMenu::Render()
{
    CM.Handle<Texture2D>(CID_MENU_INSTRUCTIONS_2_IDLE)->Render(GreeblesGame::GAME_AREA_MIN_X,
                                                               GreeblesGame::GAME_AREA_MIN_Y);

    for (auto mc : menuChoices)
        mc->Render();
}
