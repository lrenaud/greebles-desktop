#include "wx/wx.h"

#include "CustomFrame.h"

class CustomApp : public wxApp
{
    CustomFrame* frame = nullptr;

    static const int APP_WIDTH          = 390;
    static const int APP_HEIGHT         = 255;

    virtual bool OnInit();
    virtual int OnExit();
};

DECLARE_APP(CustomApp)