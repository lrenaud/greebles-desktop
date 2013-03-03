#include "wx/wx.h"

#include "../inc/SetupApp.h"
#include "../inc/SetupFrame.h"

BEGIN_EVENT_TABLE(SetupFrame, wxFrame)
	EVT_MENU(ID_Quit, SetupFrame::OnQuit)
	EVT_MENU(ID_About, SetupFrame::OnAbout)
END_EVENT_TABLE()

IMPLEMENT_APP(SetupApp)

