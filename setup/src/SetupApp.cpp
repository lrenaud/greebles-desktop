#include <Log.h>

#include "../inc/SetupApp.h"
#include "../inc/SetupFrame.h"

bool SetupApp::OnInit()
{
	SOAR::Log::GetInstance()->Message(SOAR::Log::MessageLevel::FATAL_ERROR) << "Hello World!";
	SOAR::Log::GetInstance()->Flush();

    SetupFrame *frame = new SetupFrame(_("Greebles Setup"), 
									   wxPoint(50, 50),
									   wxSize(APP_WIDTH, APP_HEIGHT),
									   wxSYSTEM_MENU |  wxCAPTION | wxCLOSE_BOX | wxSTAY_ON_TOP | wxFRAME_TOOL_WINDOW);

    frame->Show(true);

    SetTopWindow(frame);

    return true;
}