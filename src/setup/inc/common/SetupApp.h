#include "wx/wx.h"

#include "SetupFrame.h"

class SetupApp : public wxApp
{
    SetupFrame* frame = nullptr;

	static const int APP_WIDTH			= 400;
	static const int APP_HEIGHT			= 600;

    virtual bool OnInit();
    virtual int OnExit();
};

DECLARE_APP(SetupApp)