#include <Macros.h>
#include <util/Log.h>

#include "JoinApp.h"
#include "JoinFrame.h"

using namespace SOAR;

bool JoinApp::OnInit()
{
    Util::Log::GetInstance()->SetFilterLevel(Util::Log::MessageLevel::LOG_ALL);

    frame = new JoinFrame(_("Join Network Game?"), 
                           wxPoint(50, 50),
                           wxSize(APP_WIDTH, APP_HEIGHT),
                           wxSYSTEM_MENU |  wxCAPTION | wxCLOSE_BOX | wxSTAY_ON_TOP | wxFRAME_TOOL_WINDOW);

    frame->Show(true);

    SetTopWindow(frame);

    return true;
}

int JoinApp::OnExit()
{
    return 0;
}
