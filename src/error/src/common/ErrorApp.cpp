#include <Macros.h>
#include <util/Log.h>

#include "ErrorApp.h"
#include "ErrorFrame.h"

using namespace SOAR;

bool ErrorApp::OnInit()
{
    wxInitAllImageHandlers();

    Util::Log::GetInstance()->SetFilterLevel(Util::Log::MessageLevel::LOG_ALL);

    frame = new ErrorFrame(_("Error!"), 
                           wxPoint(50, 50),
                           wxSize(APP_WIDTH, APP_HEIGHT),
                           wxSYSTEM_MENU |  wxCAPTION | wxCLOSE_BOX | wxSTAY_ON_TOP | wxFRAME_TOOL_WINDOW);

    frame->Show(true);

    SetTopWindow(frame);

    return true;
}

int ErrorApp::OnExit()
{
    return 0;
}
