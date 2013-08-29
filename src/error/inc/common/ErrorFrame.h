#ifndef ERROR_FRAME_H
#define ERROR_FRAME_H

#include "wx/wx.h"

enum
{
    myID_OK
};

class ErrorFrame : public wxFrame
{
protected:

    const static int WRAP_LENGTH = 450;

    /**
     * GENERATED COMPONENT LIST
     */
    wxPanel* masterPanel;
    wxStaticBitmap* warningIcon;
    wxBoxSizer* messageSizer;
    wxStaticText* messageLabel;
    wxButton* okButton;

public:

    ErrorFrame(const wxString& title, const wxPoint& position, const wxSize& size, long style=wxDEFAULT_FRAME_STYLE);
    ~ErrorFrame();

    // No copying allowed
    ErrorFrame(const ErrorFrame& other)=delete;
    ErrorFrame& operator=(const ErrorFrame& rhs)=delete;

    void SetErrorMessage(wxString& errorMsg);

    // Event Handler for Ok Button
    void OnOk(wxCommandEvent& event);

};

#endif
