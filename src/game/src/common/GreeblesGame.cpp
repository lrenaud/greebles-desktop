#include <iostream>
#include <sstream>

#include <IL/il.h>
#include <IL/ilu.h>
#include <IL/ilut.h>
#include <GLFW/glfw3.h>

#include <base/state/StateMachineStack.h>
#include <base/Telegram.h>
#include <content/ContentManager.h>
#include <Macros.h>
#include <math/Rectangle.h>
#include <util/BlockedThread.h>
#include <util/Log.h>
#include <video/Scene.h>
#include <video/Texture.h>
#include <video/Texture2D.h>
#include <video/TiledTexture2D.h>
#include <video/WindowManager.h>

#include "ContentIds.h"
#include "CustomSettings.h"
#include "EntityIds.h"
#include "GeneralSettings.h"
#include "GlobalGameState.h"
#include "GreeblesGame.h"
#include "JoinSettings.h"
#include "menu/MainMenuState.h"
#include "PlayerSettings.h"

using namespace std;

using namespace SOAR;
using namespace Video;
using namespace Math;
using namespace Util;

GreeblesGame::GreeblesGame():BaseEntity(GAME_ID)
{
    if (WM.CreateWindow(GAME_WINDOW_ID, WINDOW_WIDTH, WINDOW_HEIGHT, "Greebles!"))
        WM.MakeWindowActive(GAME_WINDOW_ID);

    stateStack = new StateMachineStack<GreeblesGame>(this);
    stateStack->SetGlobalState(&GlobalGameState::GetInstance());
    stateStack->PushState(&MainMenuState::GetInstance());

    if (!BlockedThread::CanSpawn())
        LOG_FATAL << "BlockedThread::Spawn not supported on this system";
}

GreeblesGame::~GreeblesGame()
{
    SAFE_DELETE(stateStack);
}

GreeblesGame& GreeblesGame::GetInstance()
{
    static GreeblesGame instance;

    return instance;
}

void GreeblesGame::Run()
{
    Scene::Enable2D();

    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    glClearColor(0.0f, 1.0f, 0.0f, 0.0f);

    running = true;
    while (running)
    {
        /**
         * Update the game state
         */
        Update();

        /**
         * Render everything
         */
        Render();

        /**
         * Update the window manager
         */
        WM.Update();
    }
}

void GreeblesGame::Update()
{
    stateStack->Update();
}

bool GreeblesGame::HandleMessage(const Telegram& msg)
{
    if (stateStack->HandleMessage(msg))
        return true;

    switch (msg.message)
    {

    }

    return false;
}

void GreeblesGame::Render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_TEXTURE_RECTANGLE_NV);
    glEnable(GL_BLEND);

    stateStack->Render();

    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_RECTANGLE_NV);
}

void GreeblesGame::Quit()
{
    running = false;
}

void GreeblesGame::Hide()
{
    GLFWwindow* gameWindow = WM.Handle(GAME_WINDOW_ID);
    glfwIconifyWindow(gameWindow);
}

bool GreeblesGame::LaunchApp(const char* appName, const char* appArgs)
{
    stringstream command;

#ifdef LINUX
    command << "./";
#elif MACOSX
    command << "./";
#endif

    command << appName;

#ifdef WINDOWS 
    command << ".exe";
#endif

    command << " " << appArgs;
    int retCode = BlockedThread::Spawn(command.str().c_str());
    if (retCode != 0)
    {
        LOG_RECOVERABLE << "Setup returned code: " << retCode;
        return false;
    }
    
    // Refresh General and Player Settings

    return false;
}