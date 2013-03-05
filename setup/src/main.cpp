#include "wx/wx.h"

#include "../inc/SetupApp.h"
#include "../inc/SetupFrame.h"

BEGIN_EVENT_TABLE(SetupFrame, wxFrame)
	EVT_MENU(ID_Cancel, SetupFrame::OnCancel)
	EVT_MENU(ID_Save, SetupFrame::OnSave)
END_EVENT_TABLE()

IMPLEMENT_APP(SetupApp)

