#include <GLFW/glfw3.h>

#include <video/WindowManager.h>

#include "GreeblesGame.h"

using namespace SOAR;
using namespace Video;

GreeblesGame::GreeblesGame()
{

}

GreeblesGame::~GreeblesGame()
{

}

GreeblesGame& GreeblesGame::GetInstance()
{
    static GreeblesGame instance;

    return instance;
}

void GreeblesGame::Run()
{
    if (!WM.CreateWindow(GAME_WINDOW_ID, WINDOW_WIDTH, WINDOW_HEIGHT, "Greebles!"))
        return;

    WM.MakeWindowActive(GAME_WINDOW_ID);
    GLFWwindow* mainWindow = WM.Handle(GAME_WINDOW_ID);

    while (!glfwWindowShouldClose(mainWindow))
    {


        WM.Update();
    }
}
