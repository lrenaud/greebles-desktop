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
    ADD_GT_MC(27, 11, 44, 55, MSG_INVALID, MSG_INVALID);
    ADD_GT_MC(72, 24, 39, 42, MSG_INVALID, MSG_INVALID);
    ADD_GT_MC(116, 24, 38, 42, MSG_INVALID, MSG_INVALID);
    ADD_GT_MC(158, 24, 38, 42, MSG_INVALID, MSG_INVALID);
    ADD_GT_MC(195, 11, 45, 55, MSG_INVALID, MSG_INVALID);
    ADD_GT_MC(240, 14, 39, 54, MSG_INVALID, MSG_INVALID);
    ADD_GT_MC(285, 24, 38, 43, MSG_INVALID, MSG_INVALID);
    ADD_GT_MC(330, 24, 33, 42, MSG_INVALID, MSG_INVALID);
}

GreeblesTitleMenu::~GreeblesTitleMenu()
{

}
