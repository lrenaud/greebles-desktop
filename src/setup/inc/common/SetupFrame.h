#ifndef SETUP_FRAME_H
#define SETUP_FRAME_H

#include "wx/wx.h"

#include <math/Rectangle.h>

#include "wxNoLabelCheckBox.h"
#include "PlayerSettings.h"
#include "NewKeyDialog.h"

using namespace SOAR;
using namespace Math;

enum
{
	myID_MASTER_PANEL=0,

	myID_P1_PANEL,
	myID_P1_ENABLED,
	myID_P1_NAME,
	myID_P1_TYPE,
	myID_P1_UP,   
	myID_P1_DOWN, 
	myID_P1_LEFT, 
	myID_P1_RIGHT,
	myID_P1_PUSH, 

	myID_P2_PANEL,
	myID_P2_ENABLED,
	myID_P2_NAME,
	myID_P2_TYPE,
	myID_P2_UP,   
	myID_P2_DOWN, 
	myID_P2_LEFT, 
	myID_P2_RIGHT,
	myID_P2_PUSH, 

	myID_P3_PANEL,
	myID_P3_ENABLED,
	myID_P3_NAME,
	myID_P3_TYPE,
	myID_P3_UP,   
	myID_P3_DOWN, 
	myID_P3_LEFT, 
	myID_P3_RIGHT,
	myID_P3_PUSH, 

	myID_P4_PANEL,
	myID_P4_ENABLED,
	myID_P4_NAME,
	myID_P4_TYPE,
	myID_P4_UP,   
	myID_P4_DOWN, 
	myID_P4_LEFT, 
	myID_P4_RIGHT,
	myID_P4_PUSH, 

	myID_SOUND,
	myID_MUSIC,
	myID_DIFFICULTY
};

class SetupFrame : public wxFrame
{
private:

	static const int FRAME_WIDTH				= 400;
	static const int FRAME_HEIGHT				= 600;

	static const int PADDING					= 10;

	static const int PLAYER_CONFIG_BOX_SIZE		= 180;

	static const int MAX_NAME_LENGTH			= 10;

protected:

	/**
	 * GENERATED COMPONENT LIST
	 */
	wxPanel* masterPanel = nullptr;
	wxStaticText* playersAndKeysLabel = nullptr;

	wxPanel* p1Panel = nullptr;
	wxNoLabelCheckBox* p1EnabledCheckBox = nullptr;
	wxTextCtrl* p1Name = nullptr;
	wxButton* p1LeftButton = nullptr;
	wxButton* p1RightButton = nullptr;
	wxButton* p1UpButton = nullptr;
	wxButton* p1DownButton = nullptr;
	wxButton* p1PushButton = nullptr;
	wxChoice* p1Type = nullptr;
	wxStaticBitmap* p1Image = nullptr;

	wxPanel* p2Panel = nullptr;
	wxNoLabelCheckBox* p2EnabledCheckBox = nullptr;
	wxTextCtrl* p2Name = nullptr;
	wxButton* p2LeftButton = nullptr;
	wxButton* p2RightButton = nullptr;
	wxButton* p2UpButton = nullptr;
	wxButton* p2DownButton = nullptr;
	wxButton* p2PushButton = nullptr;
	wxChoice* p2Type = nullptr;
	wxStaticBitmap* p2Image = nullptr;

	wxPanel* p3Panel = nullptr;
	wxNoLabelCheckBox* p3EnabledCheckBox = nullptr;
	wxTextCtrl* p3Name = nullptr;
	wxButton* p3LeftButton = nullptr;
	wxButton* p3RightButton = nullptr;
	wxButton* p3UpButton = nullptr;
	wxButton* p3DownButton = nullptr;
	wxButton* p3PushButton = nullptr;
	wxChoice* p3Type = nullptr;
	wxStaticBitmap* p3Image = nullptr;

	wxPanel* p4Panel = nullptr;
	wxNoLabelCheckBox* p4EnabledCheckBox = nullptr;
	wxTextCtrl* p4Name = nullptr;
	wxButton* p4LeftButton = nullptr;
	wxButton* p4RightButton = nullptr;
	wxButton* p4UpButton = nullptr;
	wxButton* p4DownButton = nullptr;
	wxButton* p4PushButton = nullptr;
	wxChoice* p4Type = nullptr;
	wxStaticBitmap* p4Image = nullptr;

	wxCheckBox* soundCheckBox = nullptr;
	wxCheckBox* musicCheckBox = nullptr;
	wxStaticText* difficultyLabel = nullptr;
	wxChoice* difficultyChoice = nullptr;
	wxButton* cancelButton = nullptr;
	wxButton* saveButton = nullptr;

public:

	SetupFrame(const wxString& title, const wxPoint& position, const wxSize& size, long style=wxDEFAULT_FRAME_STYLE);
	~SetupFrame();

	// No copying allowed
	SetupFrame(const SetupFrame& other)=delete;
	SetupFrame& operator=(const SetupFrame& rhs)=delete;

	void OnP1MouseDrag(wxMouseEvent& event);
	void OnP1EnabledChange(wxCommandEvent& event);
	void OnP1NameChange(wxCommandEvent& event);
	void OnP1TypeChange(wxCommandEvent& event);
	void OnP1Up(wxCommandEvent& event);
	void OnP1Down(wxCommandEvent& event);
	void OnP1Left(wxCommandEvent& event);
	void OnP1Right(wxCommandEvent& event);
	void OnP1Push(wxCommandEvent& event);

	void OnP2MouseDrag(wxMouseEvent& event);
	void OnP2EnabledChange(wxCommandEvent& event);
	void OnP2NameChange(wxCommandEvent& event);
	void OnP2TypeChange(wxCommandEvent& event);
	void OnP2Up(wxCommandEvent& event);
	void OnP2Down(wxCommandEvent& event);
	void OnP2Left(wxCommandEvent& event);
	void OnP2Right(wxCommandEvent& event);
	void OnP2Push(wxCommandEvent& event);

	void OnP3MouseDrag(wxMouseEvent& event);
	void OnP3EnabledChange(wxCommandEvent& event);
	void OnP3NameChange(wxCommandEvent& event);
	void OnP3TypeChange(wxCommandEvent& event);
	void OnP3Up(wxCommandEvent& event);
	void OnP3Down(wxCommandEvent& event);
	void OnP3Left(wxCommandEvent& event);
	void OnP3Right(wxCommandEvent& event);
	void OnP3Push(wxCommandEvent& event);

	void OnP4MouseDrag(wxMouseEvent& event);
	void OnP4EnabledChange(wxCommandEvent& event);
	void OnP4NameChange(wxCommandEvent& event);
	void OnP4TypeChange(wxCommandEvent& event);
	void OnP4Up(wxCommandEvent& event);
	void OnP4Down(wxCommandEvent& event);
	void OnP4Left(wxCommandEvent& event);
	void OnP4Right(wxCommandEvent& event);
	void OnP4Push(wxCommandEvent& event);

	void OnDifficultyChange(wxCommandEvent& event);
	void OnSoundChange(wxCommandEvent& event);
	void OnMusicChange(wxCommandEvent& event);

	void OnCancel(wxCommandEvent& event);
	void OnSave(wxCommandEvent& event);	

private:

	const static int 	PLAYER_COUNT = 4;

	const static int 	PLAYER_RECT_WIDTH = 184;
	const static int 	PLAYER_RECT_HEIGHT = 203;

	enum
	{
		P1=0,
		P2,
		P3,
		P4
	};

	/**
	 * Player Settings Instances
	 */
	PlayerSettings* 	playerSettings[PLAYER_COUNT] = {nullptr, nullptr, nullptr, nullptr};	

	/**
	 * Dialog for receiving new key presses
	 */
	NewKeyDialog*		newKeyDlg = nullptr;

	/**
	 * Refreshes the GUI to reflect the current state of GeneralSettings
	 */
	void refresh();

};

#endif
