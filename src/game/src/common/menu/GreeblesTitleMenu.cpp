#include <content/ContentManager.h>
#include <video/Texture2D.h>

#include "ContentIds.h"
#include "GreeblesGame.h"
#include "menu/GreeblesTitleMenu.h"
#include "Messages.h"

using namespace SOAR;
using namespace Video;

GreeblesTitleMenu::GreeblesTitleMenu()
{
    // Initialize Menu Choices
    ADD_GT_MC(25, 10, 44, 70, MSG_INVALID, MSG_INVALID);
    ADD_GT_MC(72, 10, 39, 70, MSG_INVALID, MSG_INVALID);
    ADD_GT_MC(116, 10, 38, 70, MSG_INVALID, MSG_INVALID);
    ADD_GT_MC(158, 10, 38, 70, MSG_INVALID, MSG_INVALID);
    ADD_GT_MC(196, 10, 44, 70, MSG_INVALID, MSG_INVALID);
    ADD_GT_MC(240, 10, 39, 70, MSG_INVALID, MSG_INVALID);
    ADD_GT_MC(285, 10, 38, 70, MSG_INVALID, MSG_INVALID);
    ADD_GT_MC(330, 10, 32, 70, MSG_INVALID, MSG_INVALID);
}

GreeblesTitleMenu::~GreeblesTitleMenu()
{

}
