#include <string>
#include <sstream>

#include <Macros.h>
#include <util/Log.h>

#include "GreeblesDatabase.h"
#include "CustomApp.h"
#include "CustomFrame.h"
#include "Utility.h"
#include "LocalHumanStringFormatter.h"

using namespace std;

bool CustomApp::OnInit()
{
    if (!wxApp::OnInit())
        return false;

    Util::Log::GetInstance()->SetFilterLevel(Util::Log::MessageLevel::LOG_ALL);

    frame = new CustomFrame(_("Custom Game Settings"), 
                           wxPoint(50, 50),
                           wxSize(APP_WIDTH, APP_HEIGHT),
                           wxSYSTEM_MENU |  wxCAPTION | wxCLOSE_BOX | wxSTAY_ON_TOP | wxFRAME_TOOL_WINDOW);

    frame->UpdatePlayerInfoMsg(playerInfoMsg);
    frame->HandleGameType(isNetworkGame);
    frame->Show(true);

    SetTopWindow(frame);

    return true;
}

int CustomApp::OnExit()
{
    return 0;
}

void CustomApp::OnInitCmdLine(wxCmdLineParser& parser)
{
    parser.SetDesc(cmdLineDesc);
    parser.SetSwitchChars(wxT("-"));
}

bool CustomApp::OnCmdLineParsed(wxCmdLineParser& parser)
{
    long localPlayers, humanPlayers;
    parser.Found(wxT("l"), &localPlayers);
    parser.Found(wxT("h"), &humanPlayers);

    stringstream playerStream;
    playerStream << LocalHumanStringFormatter::GetInfoStr(localPlayers, humanPlayers);
    string playerStr = playerStream.str();

    playerInfoMsg = Utility::StringToWxString(playerStr);

    isNetworkGame = parser.Found(wxT("n"));

    return true;
}