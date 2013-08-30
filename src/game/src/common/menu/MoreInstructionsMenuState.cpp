#include <base/Telegram.h>
#include <base/MessageDispatcher.h>
#include <util/Log.h>

#include "EntityIds.h"
#include "Messages.h"
#include "GreeblesGame.h"
#include "Macros.h"
#include "menu/InstructionsMenu.h"
#include "menu/InstructionsMenuState.h"

using namespace SOAR;
using namespace Base;

InstructionsMenuState::InstructionsMenuState()
{
    menu = new InstructionsMenu();
}

InstructionsMenuState::~InstructionsMenuState()
{
    SAFE_DELETE(menu);   
}

InstructionsMenuState& InstructionsMenuState::GetInstance()
{
    static InstructionsMenuState instance;

    return instance;
}

void InstructionsMenuState::Enter(GreeblesGame* g)
{
    
}

void InstructionsMenuState::Execute(GreeblesGame* g)
{
    menu->Update();
}

void InstructionsMenuState::Exit(GreeblesGame* g)
{`
    
}

bool InstructionsMenuState::OnMessage(GreeblesGame* g, const Telegram& msg)
{
    switch (msg.message)
    {
        case MSG_MORE_CLICKED:
            // g->stateStack->PushState(&MoreInstructionsMenuState::GetInstance());
            return true;

        case MSG_DONE_CLICKED:
            g->stateStack->PopState();
            return true;
    }

    return false;
}

void InstructionsMenuState::Render(GreeblesGame* g)
{
    menu->Render();
}

