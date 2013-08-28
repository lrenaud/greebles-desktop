#include <content/ContentManager.h>
#include <video/Texture2D.h>

#include "ContentIds.h"
#include "GreeblesGame.h"
#include "menu/NetMenu.h"
#include "Messages.h"

using namespace SOAR;
using namespace Video;

NetMenu::NetMenu()
{
    // Initialize Menu Choices
    ADD_NET_MC(36, 356, 160, 110, MSG_INVALID, MSG_CANCEL_CLICKED);
    ADD_NET_MC(444, 356, 160, 110, MSG_INVALID, MSG_PLAY_CLICKED);
}

NetMenu::~NetMenu()
{

}

void NetMenu::Render()
{
    CM.Handle<Texture2D>(CID_MENU_NET_IDLE)->Render(GreeblesGame::GAME_AREA_MIN_X,
                                                    GreeblesGame::GAME_AREA_MIN_Y);

    for (auto mc : menuChoices)
        mc->Render();
}
