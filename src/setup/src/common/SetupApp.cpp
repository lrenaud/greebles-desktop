#include <Log.h>

#include "GreeblesDatabase.h"
#include "SetupApp.h"
#include "SetupFrame.h"
#include "GeneralSettings.h"

bool SetupApp::OnInit()
{
    // Make sure we can load .png files
    wxInitAllImageHandlers();

    Log::GetInstance()->SetFilterLevel(Log::MessageLevel::LOG_ALL);

    // Reload settings from DB
    GeneralSettings::GetInstance()->Refresh();

    SetupFrame *frame = new SetupFrame(_("Setup"), 
									   wxPoint(50, 50),
									   wxSize(APP_WIDTH, APP_HEIGHT),
									   wxSYSTEM_MENU |  wxCAPTION | wxCLOSE_BOX | wxSTAY_ON_TOP | wxFRAME_TOOL_WINDOW);

    frame->Show(true);

    SetTopWindow(frame);

    return true;
}