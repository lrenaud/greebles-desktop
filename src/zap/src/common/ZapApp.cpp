#include <Macros.h>
#include <util/Log.h>

#include "ZapApp.h"
#include "ZapFrame.h"

using namespace SOAR;

bool ZapApp::OnInit()
{
    wxInitAllImageHandlers();

    Util::Log::GetInstance()->SetFilterLevel(Util::Log::MessageLevel::LOG_ALL);

    frame = new ZapFrame(_("Are you sure?"), 
                           wxPoint(50, 50),
                           wxSize(APP_WIDTH, APP_HEIGHT),
                           wxSYSTEM_MENU |  wxCAPTION | wxCLOSE_BOX | wxSTAY_ON_TOP | wxFRAME_TOOL_WINDOW);

    frame->Show(true);

    SetTopWindow(frame);

    return true;
}

int ZapApp::OnExit()
{
    return 0;
}
