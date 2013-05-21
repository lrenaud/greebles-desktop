#include "wx/wx.h"

#include "SetupApp.h"
#include "SetupFrame.h"

BEGIN_EVENT_TABLE(SetupFrame, wxFrame)

    EVT_CHECKBOX   (myID_P1_ENABLED,    SetupFrame::OnP1EnabledChange)

    EVT_CHOICE     (myID_DIFFICULTY,    SetupFrame::OnDifficultyChange)
    EVT_CHECKBOX   (myID_SOUND,         SetupFrame::OnSoundChange)
    EVT_CHECKBOX   (myID_MUSIC,         SetupFrame::OnMusicChange) 

	EVT_BUTTON     (wxID_CANCEL,        SetupFrame::OnCancel)
	EVT_BUTTON     (wxID_SAVE,          SetupFrame::OnSave)

END_EVENT_TABLE()

IMPLEMENT_APP(SetupApp)

