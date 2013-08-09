#ifndef ERROR_FRAME_H
#define ERROR_FRAME_H

#include "wx/wx.h"

class ErrorFrame : public wxFrame
{
protected:

    /**
     * GENERATED COMPONENT LIST
     */
    wxPanel* masterPanel;
    wxStaticBitmap* warningIcon;
    wxStaticText* messageLabel;
    wxButton* okButton;

public:

    ErrorFrame(const wxString& title, const wxPoint& position, const wxSize& size, long style=wxDEFAULT_FRAME_STYLE);
    ~ErrorFrame();

    // No copying allowed
    ErrorFrame(const ErrorFrame& other)=delete;
    ErrorFrame& operator=(const ErrorFrame& rhs)=delete;

};

#endif
