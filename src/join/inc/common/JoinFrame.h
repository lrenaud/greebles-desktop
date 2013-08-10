#ifndef JOIN_FRAME_H
#define JOIN_FRAME_H

#include "wx/wx.h"

class JoinFrame : public wxFrame
{
protected:

    /**
     * GENERATED COMPONENT LIST
     */
    wxPanel* masterPanel;
    wxStaticText* playersMsgLabel;
    wxStaticText* connectLabel;
    wxTextCtrl* hostTextCtrl;
    wxButton* cancelButton;
    wxButton* connectButton;

public:

    JoinFrame(const wxString& title, const wxPoint& position, const wxSize& size, long style=wxDEFAULT_FRAME_STYLE);
    ~JoinFrame();

    // No copying allowed
    JoinFrame(const JoinFrame& other)=delete;
    JoinFrame& operator=(const JoinFrame& rhs)=delete;

    void UpdatePlayerInfoMsg(wxString playerInfoMsg);
};

#endif
