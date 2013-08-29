#include <string>
#include <sstream>

#include <Macros.h>
#include <util/Log.h>

#include "JoinApp.h"
#include "JoinFrame.h"
#include "Utility.h"
#include "LocalHumanStringFormatter.h"

using namespace SOAR;

bool JoinApp::OnInit()
{
    if (!wxApp::OnInit())
        return false;

    Util::Log::GetInstance()->SetFilterLevel(Util::Log::MessageLevel::LOG_ALL);

    frame = new JoinFrame(_("Join Network Game?"), 
                           wxPoint(50, 50),
                           wxSize(APP_WIDTH, APP_HEIGHT),
                           wxSYSTEM_MENU |  wxCAPTION | wxCLOSE_BOX | wxSTAY_ON_TOP | wxFRAME_TOOL_WINDOW);

    frame->UpdatePlayerInfoMsg(playerInfoMsg);
    frame->Show(true);

    SetTopWindow(frame);

    return true;
}

int JoinApp::OnRun()
{
    int retCode = wxApp::OnRun();

    // if (frame->WasCanceled())
    //     return 1;

    return retCode;
}

int JoinApp::OnExit()
{
    return 0;
}

void JoinApp::OnInitCmdLine(wxCmdLineParser& parser)
{
    parser.SetDesc(cmdLineDesc);
    parser.SetSwitchChars(wxT("-"));
}

bool JoinApp::OnCmdLineParsed(wxCmdLineParser& parser)
{
    long localPlayers, humanPlayers;
    parser.Found(wxT("l"), &localPlayers);
    parser.Found(wxT("h"), &humanPlayers);

    stringstream playerStream;
    playerStream << LocalHumanStringFormatter::GetInfoStr(localPlayers, humanPlayers);
    string playerStr = playerStream.str();

    playerInfoMsg = Utility::StringToWxString(playerStr);

    return true;
}