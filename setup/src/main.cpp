#include "wx/wx.h"

#include "../inc/SetupApp.h"
#include "../inc/SetupFrame.h"

BEGIN_EVENT_TABLE(SetupFrame, wxFrame)

	EVT_BUTTON     (wxID_CANCEL,        SetupFrame::OnCancel)
	EVT_BUTTON     (wxID_SAVE,          SetupFrame::OnSave)

END_EVENT_TABLE()

IMPLEMENT_APP(SetupApp)

