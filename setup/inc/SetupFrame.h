#ifndef SETUP_FRAME_H
#define SETUP_FRAME_H

#include "wx/wx.h"

enum
{
	ID_Quit = 1,
	ID_About,
};

class SetupFrame : public wxFrame
{
public:
	SetupFrame(const wxString& title, const wxPoint& position, const wxSize& size);

	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);

	DECLARE_EVENT_TABLE()
};

#endif
