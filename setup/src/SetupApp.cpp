#include <Log.h>

#include "SetupApp.h"
#include "SetupFrame.h"

bool SetupApp::OnInit()
{
    SetupFrame *frame = new SetupFrame(_("Greebles Setup"), 
									   wxPoint(50, 50),
									   wxSize(APP_WIDTH, APP_HEIGHT),
									   wxSYSTEM_MENU |  wxCAPTION | wxCLOSE_BOX | wxSTAY_ON_TOP | wxFRAME_TOOL_WINDOW);

    frame->Show(true);

    SetTopWindow(frame);

    return true;
}