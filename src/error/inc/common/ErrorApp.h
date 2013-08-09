#include "wx/wx.h"

#include "ErrorFrame.h"

class ErrorApp : public wxApp
{
    ErrorFrame* frame = nullptr;

    static const int APP_WIDTH          = -1;
    static const int APP_HEIGHT         = -1;

    virtual bool OnInit();
    virtual int OnExit();
};

DECLARE_APP(ErrorApp)