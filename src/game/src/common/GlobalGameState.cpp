#include <content/ContentManager.h>
#include <video/Texture.h>
#include <video/Texture2D.h>
#include <video/TiledTexture2D.h>

#include "ContentIds.h"
#include "GlobalGameState.h"
#include "GreeblesGame.h"

#include "textures/BorderTop.h"
#include "textures/BorderBottom.h"
#include "textures/BorderLeft.h"
#include "textures/BorderRight.h"
#include "textures/Title.h"
#include "textures/TitleHover.h"
#include "textures/TitlePressed.h"
#include "textures/TitleDimmed.h"
#include "textures/Instructions1.h"
#include "textures/Instructions1Hover.h"
#include "textures/Instructions1Pressed.h"
#include "textures/Instructions2.h"
#include "textures/Instructions2Hover.h"
#include "textures/Instructions2Pressed.h"
#include "textures/Pause.h"
#include "textures/PauseHover.h"
#include "textures/PausePressed.h"
#include "textures/Net.h"
#include "textures/NetHover.h"
#include "textures/NetPressed.h"
#include "textures/Thanks.h"
#include "textures/ThanksHover.h"
#include "textures/ThanksPressed.h"
#include "textures/Patterns.h"
#include "textures/Players.h"
#include "textures/Blocks.h"
#include "textures/PercentageBarBackground.h"
#include "textures/PercentageBarForeground.h"
#include "textures/Numbers.h"
#include "textures/TitleBackground.h"

using namespace SOAR;
using namespace Video;

GlobalGameState::GlobalGameState()
{

}

GlobalGameState::~GlobalGameState()
{

}

GlobalGameState& GlobalGameState::GetInstance()
{
    static GlobalGameState instance;

    return instance;
}

void GlobalGameState::Enter(GreeblesGame* g)
{
    /**
     * LOAD CONTENT
     */
    
    /**
     * Load Textures
     */
    Texture::UseTarget(GL_TEXTURE_RECTANGLE_NV);

    CM.LoadRaw<Texture2D>(CID_BORDER_TOP, BorderTop, sizeof(BorderTop));
    CM.LoadRaw<Texture2D>(CID_BORDER_BOTTOM, BorderBottom, sizeof(BorderBottom));
    CM.LoadRaw<Texture2D>(CID_BORDER_LEFT, BorderLeft, sizeof(BorderLeft));
    CM.LoadRaw<Texture2D>(CID_BORDER_RIGHT, BorderRight, sizeof(BorderRight));

    CM.LoadRaw<Texture2D>(CID_MENU_TITLE_IDLE, Title, sizeof(Title));
    CM.LoadRaw<Texture2D>(CID_MENU_TITLE_HOVER, TitleHover, sizeof(TitleHover));
    CM.LoadRaw<Texture2D>(CID_MENU_TITLE_PRESSED, TitlePressed, sizeof(TitlePressed));
    CM.LoadRaw<Texture2D>(CID_MENU_TITLE_DIMMED, TitleDimmed, sizeof(TitleDimmed));
    CM.LoadRaw<Texture2D>(CID_MENU_INSTRUCTIONS_1_IDLE, Instructions1, sizeof(Instructions1));
    CM.LoadRaw<Texture2D>(CID_MENU_INSTRUCTIONS_1_HOVER, Instructions1Hover, sizeof(Instructions1Hover));
    CM.LoadRaw<Texture2D>(CID_MENU_INSTRUCTIONS_1_PRESSED, Instructions1Pressed, sizeof(Instructions1Pressed));
    CM.LoadRaw<Texture2D>(CID_MENU_INSTRUCTIONS_2_IDLE, Instructions2, sizeof(Instructions2));
    CM.LoadRaw<Texture2D>(CID_MENU_INSTRUCTIONS_2_HOVER, Instructions2Hover, sizeof(Instructions2Hover));
    CM.LoadRaw<Texture2D>(CID_MENU_INSTRUCTIONS_2_PRESSED, Instructions2Pressed, sizeof(Instructions2Pressed));
    CM.LoadRaw<Texture2D>(CID_MENU_PAUSE_IDLE, Pause, sizeof(Pause));
    CM.LoadRaw<Texture2D>(CID_MENU_PAUSE_HOVER, PauseHover, sizeof(PauseHover));
    CM.LoadRaw<Texture2D>(CID_MENU_PAUSE_PRESSED, PausePressed, sizeof(PausePressed));
    CM.LoadRaw<Texture2D>(CID_MENU_NET_IDLE, Net, sizeof(Net));
    CM.LoadRaw<Texture2D>(CID_MENU_NET_HOVER, NetHover, sizeof(NetHover));
    CM.LoadRaw<Texture2D>(CID_MENU_NET_PRESSED, NetPressed, sizeof(NetPressed));
    CM.LoadRaw<Texture2D>(CID_MENU_THANKS_IDLE, Thanks, sizeof(Thanks));
    CM.LoadRaw<Texture2D>(CID_MENU_THANKS_HOVER, ThanksHover, sizeof(ThanksHover));
    CM.LoadRaw<Texture2D>(CID_MENU_THANKS_PRESSED, ThanksPressed, sizeof(ThanksPressed));

    CM.LoadRaw<TiledTexture2D>(CID_PATTERNS, Patterns, sizeof(Patterns));
    CM.LoadRaw<TiledTexture2D>(CID_PLAYERS, Players, sizeof(Players));
    CM.LoadRaw<TiledTexture2D>(CID_BLOCKS, Blocks, sizeof(Blocks));
    CM.LoadRaw<Texture2D>(CID_PERCENT_BACKGROUND, PercentageBarBackground, sizeof(PercentageBarBackground));
    CM.LoadRaw<Texture2D>(CID_PERCENT_FOREGROUND, PercentageBarForeground, sizeof(PercentageBarForeground));
    CM.LoadRaw<TiledTexture2D>(CID_NUMBERS, Numbers, sizeof(Numbers));
    CM.LoadRaw<Texture2D>(CID_TITLE_BACKGROUND, TitleBackground, sizeof(TitleBackground));

    /**
     * Load Sound Effects
     */
    
    /**
     * Load Music
     */
}

void GlobalGameState::Execute(GreeblesGame* g)
{

}

void GlobalGameState::Exit(GreeblesGame* g)
{

}

void GlobalGameState::Render(GreeblesGame* g)
{
    CM.Handle<TiledTexture2D>(CID_BORDER_TOP)->Render(0, 0);
    CM.Handle<TiledTexture2D>(CID_BORDER_BOTTOM)->Render(0, g->GAME_AREA_MAX_Y);
    CM.Handle<TiledTexture2D>(CID_BORDER_LEFT)->Render(0, g->GAME_AREA_MIN_Y);
    CM.Handle<TiledTexture2D>(CID_BORDER_RIGHT)->Render(g->GAME_AREA_MAX_X, g->GAME_AREA_MIN_Y);
}