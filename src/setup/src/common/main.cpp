#include "wx/wx.h"

#include "SetupApp.h"
#include "SetupFrame.h"
#include "NewKeyDialog.h"

BEGIN_EVENT_TABLE(SetupFrame, wxFrame)

    EVT_CHECKBOX    (myID_P1_ENABLED,       SetupFrame::OnP1EnabledChange)
    EVT_TEXT        (myID_P1_NAME,          SetupFrame::OnP1NameChange)
    EVT_CHOICE      (myID_P1_TYPE,          SetupFrame::OnP1TypeChange)
    EVT_BUTTON      (myID_P1_UP,            SetupFrame::OnP1Up)
    EVT_BUTTON      (myID_P1_DOWN,          SetupFrame::OnP1Down)
    EVT_BUTTON      (myID_P1_LEFT,          SetupFrame::OnP1Left)
    EVT_BUTTON      (myID_P1_RIGHT,         SetupFrame::OnP1Right)
    EVT_BUTTON      (myID_P1_PUSH,          SetupFrame::OnP1Push)

    EVT_CHECKBOX    (myID_P2_ENABLED,       SetupFrame::OnP2EnabledChange)
    EVT_TEXT        (myID_P2_NAME,          SetupFrame::OnP2NameChange)
    EVT_CHOICE      (myID_P2_TYPE,          SetupFrame::OnP2TypeChange)
    EVT_BUTTON      (myID_P2_UP,            SetupFrame::OnP2Up)
    EVT_BUTTON      (myID_P2_DOWN,          SetupFrame::OnP2Down)
    EVT_BUTTON      (myID_P2_LEFT,          SetupFrame::OnP2Left)
    EVT_BUTTON      (myID_P2_RIGHT,         SetupFrame::OnP2Right)
    EVT_BUTTON      (myID_P2_PUSH,          SetupFrame::OnP2Push)

    EVT_CHECKBOX    (myID_P3_ENABLED,       SetupFrame::OnP3EnabledChange)
    EVT_TEXT        (myID_P3_NAME,          SetupFrame::OnP3NameChange)
    EVT_CHOICE      (myID_P3_TYPE,          SetupFrame::OnP3TypeChange)
    EVT_BUTTON      (myID_P3_UP,            SetupFrame::OnP3Up)
    EVT_BUTTON      (myID_P3_DOWN,          SetupFrame::OnP3Down)
    EVT_BUTTON      (myID_P3_LEFT,          SetupFrame::OnP3Left)
    EVT_BUTTON      (myID_P3_RIGHT,         SetupFrame::OnP3Right)
    EVT_BUTTON      (myID_P3_PUSH,          SetupFrame::OnP3Push)

    EVT_CHECKBOX    (myID_P4_ENABLED,       SetupFrame::OnP4EnabledChange)
    EVT_TEXT        (myID_P4_NAME,          SetupFrame::OnP4NameChange)
    EVT_CHOICE      (myID_P4_TYPE,          SetupFrame::OnP4TypeChange)
    EVT_BUTTON      (myID_P4_UP,            SetupFrame::OnP4Up)
    EVT_BUTTON      (myID_P4_DOWN,          SetupFrame::OnP4Down)
    EVT_BUTTON      (myID_P4_LEFT,          SetupFrame::OnP4Left)
    EVT_BUTTON      (myID_P4_RIGHT,         SetupFrame::OnP4Right)
    EVT_BUTTON      (myID_P4_PUSH,          SetupFrame::OnP4Push)

    EVT_CHOICE      (myID_DIFFICULTY,       SetupFrame::OnDifficultyChange)
    EVT_CHECKBOX    (myID_SOUND,            SetupFrame::OnSoundChange)
    EVT_CHECKBOX    (myID_MUSIC,            SetupFrame::OnMusicChange) 

	EVT_BUTTON      (wxID_CANCEL,           SetupFrame::OnCancel)
	EVT_BUTTON      (wxID_SAVE,             SetupFrame::OnSave)

END_EVENT_TABLE()


BEGIN_EVENT_TABLE(NewKeyDialog, wxDialog)

    EVT_KEY_UP        (NewKeyDialog::OnKeyUp)

END_EVENT_TABLE()


IMPLEMENT_APP(SetupApp)

