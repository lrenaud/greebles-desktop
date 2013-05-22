#ifndef SETUP_FRAME_H
#define SETUP_FRAME_H

#include "wx/wx.h"

#include "wxNoLabelCheckBox.h"
#include "PlayerSettings.h"

enum
{
	myID_P1_ENABLED,
	myID_P1_NAME,
	myID_P1_TYPE,

	myID_P2_ENABLED,
	myID_P2_NAME,
	myID_P2_TYPE,

	myID_P3_ENABLED,
	myID_P3_NAME,
	myID_P3_TYPE,

	myID_P4_ENABLED,
	myID_P4_NAME,
	myID_P4_TYPE,

	myID_SOUND,
	myID_MUSIC,
	myID_DIFFICULTY
};

class SetupFrame : public wxFrame
{
private:
	DECLARE_EVENT_TABLE()

	static const int FRAME_WIDTH				= 400;
	static const int FRAME_HEIGHT				= 600;

	static const int PADDING					= 10;

	static const int PLAYER_CONFIG_BOX_SIZE		= 180;

	static const int MAX_NAME_LENGTH			= 10;

protected:

	/**
	 * GENERATED COMPONENT LIST
	 */
	wxStaticText* playersAndKeysLabel;
	wxNoLabelCheckBox* p1EnabledCheckBox;
	wxTextCtrl* p1Name;
	
	wxButton* p1UpButton;
	
	wxButton* p1LeftButton;
	wxButton* p1PushButton;
	wxButton* p1RightButton;
	
	wxButton* p1DownButton;
	
	wxChoice* p1Type;
	wxStaticBitmap* p1Image;
	wxNoLabelCheckBox* p2EnabledCheckBox;
	wxTextCtrl* p2Name;
	
	wxButton* p2UpButton;
	
	wxButton* p2LeftButton;
	wxButton* p2PushButton;
	wxButton* p2RightButton;
	
	wxButton* p2DownButton;
	
	wxChoice* p2Type;
	wxStaticBitmap* p2Image;
	wxNoLabelCheckBox* p3EnabledCheckBox;
	wxTextCtrl* p3Name;
	
	wxButton* p3UpButton;
	
	wxButton* p3LeftButton;
	wxButton* p3PushButton;
	wxButton* p3RightButton;
	
	wxButton* p3DownButton;
	
	wxChoice* p3Type;
	wxStaticBitmap* p3Image;
	wxNoLabelCheckBox* p4EnabledCheckBox;
	wxTextCtrl* p4Name;
	
	wxButton* p4UpButton;
	
	wxButton* p4LeftButton;
	wxButton* p4PushButton;
	wxButton* p4RightButton;
	
	wxButton* p4DownButton;
	
	wxChoice* p4Type;
	wxStaticBitmap* p4Image;
	wxCheckBox* soundCheckBox;
	wxCheckBox* musicCheckBox;
	wxStaticText* difficultyLabel;
	wxChoice* difficultyComboBox;
	wxButton* cancelButton;
	wxButton* saveButton;

public:
	SetupFrame(const wxString& title, const wxPoint& position, const wxSize& size, long style=wxDEFAULT_FRAME_STYLE);
	~SetupFrame();

	void OnP1EnabledChange(wxCommandEvent& event);
	void OnP1NameChange(wxCommandEvent& event);
	void OnP1TypeChange(wxCommandEvent& event);

	void OnP2EnabledChange(wxCommandEvent& event);
	void OnP2NameChange(wxCommandEvent& event);
	void OnP2TypeChange(wxCommandEvent& event);

	void OnP3EnabledChange(wxCommandEvent& event);
	void OnP3NameChange(wxCommandEvent& event);
	void OnP3TypeChange(wxCommandEvent& event);

	void OnP4EnabledChange(wxCommandEvent& event);
	void OnP4NameChange(wxCommandEvent& event);
	void OnP4TypeChange(wxCommandEvent& event);

	void OnDifficultyChange(wxCommandEvent& event);
	void OnSoundChange(wxCommandEvent& event);
	void OnMusicChange(wxCommandEvent& event);

	void OnCancel(wxCommandEvent& event);
	void OnSave(wxCommandEvent& event);	

private:

	const static int 	PLAYER_COUNT = 4;

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
	PlayerSettings* 	playerSettings[PLAYER_COUNT];	

	/**
	 * Refreshes the GUI to reflect the current state of GeneralSettings
	 */
	void refresh();

};

#endif
