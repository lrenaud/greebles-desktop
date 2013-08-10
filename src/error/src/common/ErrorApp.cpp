#include <iostream>

#include <Macros.h>
#include <util/Log.h>

#include "ErrorApp.h"
#include "ErrorFrame.h"

using namespace std;
using namespace SOAR;

bool ErrorApp::OnInit()
{
    if (!wxApp::OnInit())
        return false;

    wxInitAllImageHandlers();

    Util::Log::GetInstance()->SetFilterLevel(Util::Log::MessageLevel::LOG_ALL);

    frame = new ErrorFrame(_("Error!"), 
                           wxPoint(50, 50),
                           wxSize(APP_WIDTH, APP_HEIGHT),
                           wxSYSTEM_MENU |  wxCAPTION | wxCLOSE_BOX | wxSTAY_ON_TOP | wxFRAME_TOOL_WINDOW);

    frame->SetErrorMessage(errorMsg);
    frame->Show(true);

    SetTopWindow(frame);

    return true;
}

int ErrorApp::OnExit()
{
    return 0;
}

void ErrorApp::OnInitCmdLine(wxCmdLineParser& parser)
{
    parser.SetDesc(cmdLineDesc);
    parser.SetSwitchChars(wxT("-"));
}

bool ErrorApp::OnCmdLineParsed(wxCmdLineParser& parser)
{
    errorMsg = wxT("{NO ERROR MESSAGE RECEIVED}");

    if (parser.GetParamCount() > 0)
        errorMsg = parser.GetParam(0);

    return true;
}