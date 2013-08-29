#include "wx/wx.h"

#include "ZapFrame.h"

class ZapApp : public wxApp
{
    ZapFrame* frame = nullptr;

    static const int APP_WIDTH          = 0;
    static const int APP_HEIGHT         = 0;

    virtual bool OnInit();
    virtual int OnExit();
};

DECLARE_APP(ZapApp)