#include "GreeblesGame.h"
#include "menu/BaseMenuState.h"

void BaseMenuState::Enter(GreeblesGame* g)
{
    SetTextureCids();
}

void BaseMenuState::Exit(GreeblesGame* g)
{
    
}

void BaseMenuState::Pause(GreeblesGame* g)
{

}

void BaseMenuState::Resume(GreeblesGame* g)
{
    SetTextureCids();
}