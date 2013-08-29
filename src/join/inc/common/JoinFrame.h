#ifndef JOIN_FRAME_H
#define JOIN_FRAME_H

#include "wx/wx.h"

enum
{
    myID_HOST=0,

    myID_CANCEL,
    myID_CONNECT
};

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

    /**
     * Lets us know if Cancel was hit instead of connect
     */
    bool canceled;

public:

    JoinFrame(const wxString& title, const wxPoint& position, const wxSize& size, long style=wxDEFAULT_FRAME_STYLE);
    ~JoinFrame();

    // No copying allowed
    JoinFrame(const JoinFrame& other)=delete;
    JoinFrame& operator=(const JoinFrame& rhs)=delete;

    void UpdatePlayerInfoMsg(wxString playerInfoMsg);

    bool WasCanceled()const{return canceled;}

    // Event Handlers
    void OnHostChange(wxCommandEvent& event);

    void OnCancel(wxCommandEvent& event);
    void OnConnect(wxCommandEvent& event);

private:

    /**
     * Refreshes the GUI with the data in the SEttings obejct
     */
    void refresh();

    /**
     * This method will disable the connect button if the host is empty
     */
    void refreshConnectButton();
};

#endif
