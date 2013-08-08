#ifndef CUSTOM_FRAME_H
#define CUSTOM_FRAME_H

#include "wx/wx.h"

enum
{
    myID_MASTER_PANEL=0,

};

class CustomFrame : public wxFrame
{
protected:

    /**
     * GENERATED COMPONENT LIST
     */
    wxStaticText* playerCountLabel;
    wxCheckBox* unlimitedLivesCheckBox;

    wxStaticText* startLevelLabel;
    wxTextCtrl* startLevelValue;
    wxStaticText* startLevelLimitLabel;

    wxCheckBox* timeLimitCheckBox;
    wxTextCtrl* timeLimitValue;
    wxStaticText* minutesLabel;

    wxCheckBox* levelEndsCheckBox;
    wxTextCtrl* remainingPlayersValue;
    wxStaticText* remainingPlayersLabel;

    wxCheckBox* advertiseCheckBox;
    wxTextCtrl* advertiseNameValue;

    wxButton* cancelButton;
    wxButton* startButton;

public:

    CustomFrame(const wxString& title, const wxPoint& position, const wxSize& size, long style=wxDEFAULT_FRAME_STYLE);
    ~CustomFrame();

    // No copying allowed
    CustomFrame(const CustomFrame& other)=delete;
    CustomFrame& operator=(const CustomFrame& rhs)=delete;

};

#endif
