#include <iostream>

#include <IL/il.h>
#include <IL/ilu.h>
#include <IL/ilut.h>
#include <GLFW/glfw3.h>

#include <base/state/StateMachineStack.h>
#include <content/ContentManager.h>
#include <Macros.h>
#include <math/Rectangle.h>
#include <util/Log.h>
#include <video/Scene.h>
#include <video/Texture.h>
#include <video/Texture2D.h>
#include <video/TiledTexture2D.h>
#include <video/WindowManager.h>

#include "ContentIds.h"
#include "GreeblesGame.h"
#include "GlobalGameState.h"

using namespace std;

using namespace SOAR;
using namespace Video;
using namespace Math;

GreeblesGame::GreeblesGame()
{
    if (WM.CreateWindow(GAME_WINDOW_ID, WINDOW_WIDTH, WINDOW_HEIGHT, "Greebles!"))
        WM.MakeWindowActive(GAME_WINDOW_ID);

    stateStack = new StateMachineStack<GreeblesGame>(this);
    stateStack->SetGlobalState(&GlobalGameState::GetInstance());
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

    GLFWwindow* mainWindow = WM.Handle(GAME_WINDOW_ID);    

    while (!glfwWindowShouldClose(mainWindow))
    {

        /**
         * Update the game state
         */
        update();

        /**
         * Render everything
         */
        render();

        /**
         * Update the window manager
         */
        WM.Update();
    }
}

void GreeblesGame::update()
{
    stateStack->Update();
}

void GreeblesGame::render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_TEXTURE_RECTANGLE_NV);
    glEnable(GL_BLEND);

    stateStack->Render();

    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_RECTANGLE_NV);
}
