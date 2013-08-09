#include "wx/wx.h"

#include "ZapFrame.h"

class ZapApp : public wxApp
{
    ZapFrame* frame = nullptr;

    static const int APP_WIDTH          = -1;
    static const int APP_HEIGHT         = -1;

    virtual bool OnInit();
    virtual int OnExit();
};

DECLARE_APP(ZapApp)