#include "../inc/SetupApp.h"
#include "../inc/SetupFrame.h"

bool SetupApp::OnInit()
{
    SetupFrame *frame = new SetupFrame( _("Hello World"), wxPoint(50, 50), wxSize(450, 340) );
    frame->Show(true);
    SetTopWindow(frame);
    return true;
}