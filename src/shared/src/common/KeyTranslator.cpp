#include <wx/wx.h>
#include <GLFW/glfw3.h>

#include "KeyTranslator.h"

KeyTranslator::KeyTranslator()
{
    populateTranslationMap();
}

KeyTranslator::~KeyTranslator()
{

}

KeyTranslator& KeyTranslator::GetInstance()
{
    static KeyTranslator instance;

    return instance;
}

int KeyTranslator::TranslateGLFWToWXK(int glfwKey)
{
    if (!glfwToWxKeys.count(glfwKey))
        glfwKey = GLFW_KEY_UNKNOWN;

    return glfwToWxKeys[glfwKey];
}

void KeyTranslator::populateTranslationMap()
{
    glfwToWxKeys.clear();

    glfwToWxKeys = {
        { GLFW_KEY_UNKNOWN,         GLFW_KEY_UNKNOWN },
        { GLFW_KEY_SPACE,           WXK_SPACE },
        { GLFW_KEY_APOSTROPHE,      39 },
        { GLFW_KEY_COMMA,           44 },
        { GLFW_KEY_MINUS,           45 },
        { GLFW_KEY_PERIOD,          46 },
        { GLFW_KEY_SLASH,           47 },
        { GLFW_KEY_0,               48 },
        { GLFW_KEY_1,               49 },
        { GLFW_KEY_2,               50 },
        { GLFW_KEY_3,               51 },
        { GLFW_KEY_4,               52 },
        { GLFW_KEY_5,               53 },
        { GLFW_KEY_6,               54 },
        { GLFW_KEY_7,               55 },
        { GLFW_KEY_8,               56 },
        { GLFW_KEY_9,               57 },
        { GLFW_KEY_SEMICOLON,       59 },
        { GLFW_KEY_EQUAL,           61 },
        { GLFW_KEY_A,               65 },
        { GLFW_KEY_B,               66 },
        { GLFW_KEY_C,               67 },
        { GLFW_KEY_D,               68 },
        { GLFW_KEY_E,               69 },
        { GLFW_KEY_F,               70 },
        { GLFW_KEY_G,               71 },
        { GLFW_KEY_H,               72 },
        { GLFW_KEY_I,               73 },
        { GLFW_KEY_J,               74 },
        { GLFW_KEY_K,               75 },
        { GLFW_KEY_L,               76 },
        { GLFW_KEY_M,               77 },
        { GLFW_KEY_N,               78 },
        { GLFW_KEY_O,               79 },
        { GLFW_KEY_P,               80 },
        { GLFW_KEY_Q,               81 },
        { GLFW_KEY_R,               82 },
        { GLFW_KEY_S,               83 },
        { GLFW_KEY_T,               84 },
        { GLFW_KEY_U,               85 },
        { GLFW_KEY_V,               86 },
        { GLFW_KEY_W,               87 },
        { GLFW_KEY_X,               88 },
        { GLFW_KEY_Y,               89 },
        { GLFW_KEY_Z,               90 },
        { GLFW_KEY_LEFT_BRACKET,    91 },
        { GLFW_KEY_BACKSLASH,       92 },
        { GLFW_KEY_RIGHT_BRACKET,   93 },
        { GLFW_KEY_GRAVE_ACCENT,    96 },
        { GLFW_KEY_WORLD_1,         GLFW_KEY_UNKNOWN },
        { GLFW_KEY_WORLD_2,         GLFW_KEY_UNKNOWN },
        { GLFW_KEY_ESCAPE,          WXK_ESCAPE },
        { GLFW_KEY_ENTER,           WXK_RETURN },
        { GLFW_KEY_TAB,             WXK_TAB },
        { GLFW_KEY_BACKSPACE,       WXK_BACK },
        { GLFW_KEY_INSERT,          WXK_INSERT },
        { GLFW_KEY_DELETE,          WXK_DELETE },
        { GLFW_KEY_RIGHT,           WXK_RIGHT },
        { GLFW_KEY_LEFT,            WXK_LEFT },
        { GLFW_KEY_DOWN,            WXK_DOWN },
        { GLFW_KEY_UP,              WXK_UP },
        { GLFW_KEY_PAGE_UP,         WXK_PAGEUP },
        { GLFW_KEY_PAGE_DOWN,       WXK_PAGEDOWN },
        { GLFW_KEY_HOME,            WXK_HOME },
        { GLFW_KEY_END,             WXK_END },
        { GLFW_KEY_CAPS_LOCK,       WXK_CAPITAL },
        { GLFW_KEY_SCROLL_LOCK,     WXK_SCROLL },
        { GLFW_KEY_NUM_LOCK,        WXK_NUMLOCK },
        { GLFW_KEY_PRINT_SCREEN,    319 },
        { GLFW_KEY_PAUSE,           WXK_PAUSE },
        { GLFW_KEY_F1,              WXK_F1 },
        { GLFW_KEY_F2,              WXK_F2 },
        { GLFW_KEY_F3,              WXK_F3 },
        { GLFW_KEY_F4,              WXK_F4 },
        { GLFW_KEY_F5,              WXK_F5 },
        { GLFW_KEY_F6,              WXK_F6 },
        { GLFW_KEY_F7,              WXK_F7 },
        { GLFW_KEY_F8,              WXK_F8 },
        { GLFW_KEY_F9,              WXK_F9 },
        { GLFW_KEY_F10,             WXK_F10 },
        { GLFW_KEY_F11,             WXK_F11 },
        { GLFW_KEY_F12,             WXK_F12 },
        { GLFW_KEY_F13,             WXK_F13 },
        { GLFW_KEY_F14,             WXK_F14 },
        { GLFW_KEY_F15,             WXK_F15 },
        { GLFW_KEY_F16,             WXK_F16 },
        { GLFW_KEY_F17,             WXK_F17 },
        { GLFW_KEY_F18,             WXK_F18 },
        { GLFW_KEY_F19,             WXK_F19 },
        { GLFW_KEY_F20,             WXK_F20 },
        { GLFW_KEY_F21,             WXK_F21 },
        { GLFW_KEY_F22,             WXK_F22 },
        { GLFW_KEY_F23,             WXK_F23 },
        { GLFW_KEY_F24,             WXK_F24 },
        { GLFW_KEY_F25,             GLFW_KEY_UNKNOWN },
        { GLFW_KEY_KP_0,            WXK_NUMPAD0 },
        { GLFW_KEY_KP_1,            WXK_NUMPAD1 },
        { GLFW_KEY_KP_2,            WXK_NUMPAD2 },
        { GLFW_KEY_KP_3,            WXK_NUMPAD3 },
        { GLFW_KEY_KP_4,            WXK_NUMPAD4 },
        { GLFW_KEY_KP_5,            WXK_NUMPAD5 },
        { GLFW_KEY_KP_6,            WXK_NUMPAD6 },
        { GLFW_KEY_KP_7,            WXK_NUMPAD7 },
        { GLFW_KEY_KP_8,            WXK_NUMPAD8 },
        { GLFW_KEY_KP_9,            WXK_NUMPAD9 },
        { GLFW_KEY_KP_DECIMAL,      WXK_NUMPAD_DECIMAL },
        { GLFW_KEY_KP_DIVIDE,       WXK_NUMPAD_DIVIDE },
        { GLFW_KEY_KP_MULTIPLY,     WXK_NUMPAD_MULTIPLY },
        { GLFW_KEY_KP_SUBTRACT,     WXK_NUMPAD_SUBTRACT },
        { GLFW_KEY_KP_ADD,          WXK_NUMPAD_ADD },
        { GLFW_KEY_KP_ENTER,        WXK_NUMPAD_ENTER },
        { GLFW_KEY_KP_EQUAL,        WXK_NUMPAD_EQUAL },
        { GLFW_KEY_LEFT_SHIFT,      WXK_SHIFT },
        { GLFW_KEY_LEFT_CONTROL,    WXK_CONTROL },
        { GLFW_KEY_LEFT_ALT,        WXK_ALT },
        { GLFW_KEY_LEFT_SUPER,      GLFW_KEY_UNKNOWN },
        { GLFW_KEY_RIGHT_SHIFT,     WXK_SHIFT },
        { GLFW_KEY_RIGHT_CONTROL,   WXK_CONTROL },
        { GLFW_KEY_RIGHT_ALT,       WXK_ALT },
        { GLFW_KEY_RIGHT_SUPER,     GLFW_KEY_UNKNOWN },
        { GLFW_KEY_MENU,            GLFW_KEY_UNKNOWN }
    };
}