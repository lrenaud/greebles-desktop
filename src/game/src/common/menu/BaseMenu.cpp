#include <vector>

#include <base/Telegram.h>
#include <Macros.h>
#include <util/Log.h>

#include "menu/BaseMenu.h"
#include "menu/MenuChoice.h"

using namespace SOAR;
using namespace Base;

BaseMenu::~BaseMenu()
{
    for (auto mc : menuChoices)
        SAFE_DELETE(mc);
}

void BaseMenu::Update()
{
    for (auto mc : menuChoices)
        mc->Update();
}

bool BaseMenu::HandleMessage(const Telegram& msg)
{
    return false;
}
