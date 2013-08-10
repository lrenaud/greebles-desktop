#include "wx/wx.h"

#include "SetupFrame.h"

class SetupApp : public wxApp
{
    SetupFrame* frame = nullptr;

	static const int APP_WIDTH			= -1;
	static const int APP_HEIGHT			= -1;

    virtual bool OnInit();
    virtual int OnExit();
};

DECLARE_APP(SetupApp)