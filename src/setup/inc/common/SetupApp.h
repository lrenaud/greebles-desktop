#include "wx/wx.h"

class SetupApp : public wxApp
{
	static const int APP_WIDTH			= 400;
	static const int APP_HEIGHT			= 600;

    virtual bool OnInit();
};

DECLARE_APP(SetupApp)