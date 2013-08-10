#include "wx/wx.h"
#include "wx/button.h"

#include "CustomFrame.h"

CustomFrame::CustomFrame(const wxString& title, const wxPoint& pos, const wxSize& size, long style)
       : wxFrame(NULL, -1, title, pos, size, style)
{
    /**
     * THE FOLLOWING CODE WAS GENERATED BY wxFormBuilder v3.1.59 Beta on Ubuntu 13.04
     * - 8/8/13 - I added the master panel to hold everything. This is not in the designer.
     * - 8/10/13 - Updated wxFormBuilder, brought project forward. Everything
     *             here is now in the designer.
     */

    this->SetSizeHints( wxDefaultSize, wxSize( -1,-1 ) );
    
    wxBoxSizer* masterSizer;
    masterSizer = new wxBoxSizer( wxVERTICAL );
    
    masterPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    wxBoxSizer* masterVBoxSizer;
    masterVBoxSizer = new wxBoxSizer( wxVERTICAL );
    
    wxBoxSizer* topSizer;
    topSizer = new wxBoxSizer( wxVERTICAL );
    
    playerCountLabel = new wxStaticText( masterPanel, wxID_ANY, wxT("There is 1 local player (all human)"), wxDefaultPosition, wxDefaultSize, 0 );
    playerCountLabel->Wrap( -1 );
    topSizer->Add( playerCountLabel, 0, wxALIGN_CENTER_VERTICAL|wxALL, 8 );
    
    unlimitedLivesCheckBox = new wxCheckBox( masterPanel, wxID_ANY, wxT("Unlimited Lives"), wxDefaultPosition, wxDefaultSize, 0 );
    unlimitedLivesCheckBox->SetValue(true); 
    topSizer->Add( unlimitedLivesCheckBox, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxLEFT, 5 );
    
    
    masterVBoxSizer->Add( topSizer, 1, wxEXPAND, 5 );
    
    wxFlexGridSizer* flexGridSizer;
    flexGridSizer = new wxFlexGridSizer( 4, 2, 0, 0 );
    flexGridSizer->SetFlexibleDirection( wxBOTH );
    flexGridSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    
    startLevelLabel = new wxStaticText( masterPanel, wxID_ANY, wxT("Start game at level:"), wxDefaultPosition, wxDefaultSize, 0 );
    startLevelLabel->Wrap( -1 );
    flexGridSizer->Add( startLevelLabel, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxLEFT, 8 );
    
    wxBoxSizer* startLevelSizer;
    startLevelSizer = new wxBoxSizer( wxHORIZONTAL );
    
    startLevelValue = new wxTextCtrl( masterPanel, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
    startLevelValue->SetMaxLength( 0 ); 
    startLevelSizer->Add( startLevelValue, 0, wxALL, 5 );
    
    startLevelLimitLabel = new wxStaticText( masterPanel, wxID_ANY, wxT("(1-70)"), wxDefaultPosition, wxDefaultSize, 0 );
    startLevelLimitLabel->Wrap( -1 );
    startLevelSizer->Add( startLevelLimitLabel, 0, wxALIGN_CENTER_VERTICAL, 5 );
    
    
    flexGridSizer->Add( startLevelSizer, 0, 0, 0 );
    
    timeLimitCheckBox = new wxCheckBox( masterPanel, wxID_ANY, wxT("Game time limit:"), wxDefaultPosition, wxDefaultSize, 0 );
    flexGridSizer->Add( timeLimitCheckBox, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxLEFT, 5 );
    
    wxBoxSizer* timeLimitSizer;
    timeLimitSizer = new wxBoxSizer( wxHORIZONTAL );
    
    timeLimitValue = new wxTextCtrl( masterPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    timeLimitValue->SetMaxLength( 0 ); 
    timeLimitSizer->Add( timeLimitValue, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
    
    minutesLabel = new wxStaticText( masterPanel, wxID_ANY, wxT("(minutes)"), wxDefaultPosition, wxDefaultSize, 0 );
    minutesLabel->Wrap( -1 );
    timeLimitSizer->Add( minutesLabel, 0, wxALIGN_CENTER_VERTICAL, 5 );
    
    
    flexGridSizer->Add( timeLimitSizer, 0, 0, 5 );
    
    levelEndsCheckBox = new wxCheckBox( masterPanel, wxID_ANY, wxT("Level ends when"), wxDefaultPosition, wxDefaultSize, 0 );
    flexGridSizer->Add( levelEndsCheckBox, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxLEFT, 5 );
    
    wxBoxSizer* remainingPlayersSizer;
    remainingPlayersSizer = new wxBoxSizer( wxHORIZONTAL );
    
    remainingPlayersValue = new wxTextCtrl( masterPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    remainingPlayersValue->SetMaxLength( 0 ); 
    remainingPlayersSizer->Add( remainingPlayersValue, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
    
    remainingPlayersLabel = new wxStaticText( masterPanel, wxID_ANY, wxT("human players remain."), wxDefaultPosition, wxDefaultSize, 0 );
    remainingPlayersLabel->Wrap( -1 );
    remainingPlayersSizer->Add( remainingPlayersLabel, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );
    
    
    flexGridSizer->Add( remainingPlayersSizer, 0, 0, 5 );
    
    advertiseCheckBox = new wxCheckBox( masterPanel, wxID_ANY, wxT("Advertise game:"), wxDefaultPosition, wxDefaultSize, 0 );
    flexGridSizer->Add( advertiseCheckBox, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxLEFT, 5 );
    
    advertiseNameValue = new wxTextCtrl( masterPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    advertiseNameValue->SetMaxLength( 0 ); 
    flexGridSizer->Add( advertiseNameValue, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
    
    
    masterVBoxSizer->Add( flexGridSizer, 0, wxEXPAND, 5 );
    
    wxBoxSizer* buttonSizer;
    buttonSizer = new wxBoxSizer( wxHORIZONTAL );
    
    cancelButton = new wxButton( masterPanel, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    buttonSizer->Add( cancelButton, 0, wxALL, 5 );
    
    startButton = new wxButton( masterPanel, wxID_ANY, wxT("Start"), wxDefaultPosition, wxDefaultSize, 0 );
    buttonSizer->Add( startButton, 0, wxALL, 5 );
    
    
    masterVBoxSizer->Add( buttonSizer, 0, wxALIGN_RIGHT|wxBOTTOM, 5 );
    
    
    masterPanel->SetSizer( masterVBoxSizer );
    masterPanel->Layout();
    masterVBoxSizer->Fit( masterPanel );
    masterSizer->Add( masterPanel, 0, 0, 0 );
    
    
    this->SetSizer( masterSizer );
    this->Layout();
    masterSizer->Fit( this );
}

CustomFrame::~CustomFrame()
{

}

void CustomFrame::HandleGameType(bool isNetworkGame)
{
    if (isNetworkGame)
        return;

    // If it's not a network game, disable the network related components
    advertiseCheckBox->Disable();
    advertiseNameValue->Disable();
}

void CustomFrame::UpdatePlayerInfoMsg(wxString playerInfoMsg)
{
    playerCountLabel->SetLabel(playerInfoMsg);
}
