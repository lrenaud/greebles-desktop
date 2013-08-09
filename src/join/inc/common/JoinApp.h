#include "wx/wx.h"

#include "JoinFrame.h"

class JoinApp : public wxApp
{
    JoinFrame* frame = nullptr;

    static const int APP_WIDTH          = -1;
    static const int APP_HEIGHT         = -1;

    virtual bool OnInit();
    virtual int OnExit();
};

DECLARE_APP(JoinApp)