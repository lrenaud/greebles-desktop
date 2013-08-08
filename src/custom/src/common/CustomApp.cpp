#include <Macros.h>
#include <util/Log.h>

#include "GreeblesDatabase.h"
#include "CustomApp.h"
#include "CustomFrame.h"

bool CustomApp::OnInit()
{
    Util::Log::GetInstance()->SetFilterLevel(Util::Log::MessageLevel::LOG_ALL);

    frame = new CustomFrame(_("Custom Game Settings"), 
                           wxPoint(50, 50),
                           wxSize(APP_WIDTH, APP_HEIGHT),
                           wxSYSTEM_MENU |  wxCAPTION | wxCLOSE_BOX | wxSTAY_ON_TOP | wxFRAME_TOOL_WINDOW);

    frame->Show(true);

    SetTopWindow(frame);

    return true;
}

int CustomApp::OnExit()
{
    return 0;
}
