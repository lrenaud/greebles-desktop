#include "../inc/SetupApp.h"
#include "../inc/SetupFrame.h"

bool SetupApp::OnInit()
{
    SetupFrame *frame = new SetupFrame(_("Greebles Setup"), 
									   wxPoint(50, 50),
									   wxSize(APP_WIDTH, APP_HEIGHT),
									   wxSYSTEM_MENU |  wxCAPTION | wxFRAME_TOOL_WINDOW);

    frame->Show(true);

    SetTopWindow(frame);

    return true;
}