#include <base/Telegram.h>
#include <base/MessageDispatcher.h>
#include <util/Log.h>

#include "ContentIds.h"
#include "EntityIds.h"
#include "Messages.h"
#include "GreeblesGame.h"
#include "Macros.h"
#include "menu/MenuChoice.h"
#include "menu/InstructionsMenu.h"
#include "menu/MoreInstructionsMenuState.h"

using namespace SOAR;
using namespace Base;

MoreInstructionsMenuState::MoreInstructionsMenuState()
{
    menu = new InstructionsMenu();
}

MoreInstructionsMenuState::~MoreInstructionsMenuState()
{
    SAFE_DELETE(menu);   
}

MoreInstructionsMenuState& MoreInstructionsMenuState::GetInstance()
{
    static MoreInstructionsMenuState instance;

    return instance;
}

void MoreInstructionsMenuState::Execute(GreeblesGame* g)
{
    menu->Update();
}

bool MoreInstructionsMenuState::OnMessage(GreeblesGame* g, const Telegram& msg)
{
    switch (msg.message)
    {
        case MSG_MORE_CLICKED:
            // g->stateStack->PushState(&MoreMoreInstructionsMenuState::GetInstance());
            return true;

        case MSG_DONE_CLICKED:
            g->stateStack->PopState();
            return true;
    }

    return false;
}

void MoreInstructionsMenuState::Render(GreeblesGame* g)
{
    menu->Render();
}

void MoreInstructionsMenuState::SetTextureCids()
{
    MenuChoice::hoverCid = CID_MENU_INSTRUCTIONS_2_HOVER;
    MenuChoice::pressedCid = CID_MENU_INSTRUCTIONS_2_PRESSED;
}
