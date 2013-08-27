#include <math/Rectangle.h>
#include <util/state/StateMachine.h>

#include "GreeblesGame.h"
#include "Macros.h"
#include "menu/MenuChoice.h"

using namespace SOAR;
using namespace Math;

MenuChoice::MenuChoice(const Rectangle<int>& texturePosition)
{
    this->texturePosition = texturePosition;
    
    this->windowPosition = texturePosition;
    this->windowPosition.x += GreeblesGame::GAME_AREA_MIN_X;
    this->windowPosition.y += GreeblesGame::GAME_AREA_MIN_Y;

    stateMachine = new StateMachine<MenuChoice>(this);
}

MenuChoice::~MenuChoice()
{
    SAFE_DELETE(stateMachine);
}

void MenuChoice::Update()
{
    stateMachine->Update();
}

void MenuChoice::Render()
{
    stateMachine->Render();
}

const Rectangle<int>& MenuChoice::WindowPosition()
{
    return windowPosition;
}

const Rectangle<int>& MenuChoice::TexturePosition()
{
    return texturePosition;
}
