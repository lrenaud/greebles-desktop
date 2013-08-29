#include "wx/wx.h"

#include "SetupFrame.h"

class SetupApp : public wxApp
{
    SetupFrame* frame = nullptr;

	static const int APP_WIDTH			= 0;
	static const int APP_HEIGHT			= 0;

    virtual bool OnInit();
    virtual int OnExit();
};

DECLARE_APP(SetupApp)