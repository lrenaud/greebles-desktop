#include "wx/wx.h"
#include "wx/cmdline.h"

#include "ErrorFrame.h"

class ErrorApp : public wxApp
{
    ErrorFrame* frame = nullptr;

    wxString    errorMsg;

    static const int APP_WIDTH          = -1;
    static const int APP_HEIGHT         = -1;

    virtual bool OnInit();
    virtual int OnExit();

    virtual void OnInitCmdLine(wxCmdLineParser& parser);
    virtual bool OnCmdLineParsed(wxCmdLineParser& parser);
};

static const wxCmdLineEntryDesc cmdLineDesc[] = 
{
    { // The Error message to display
        wxCMD_LINE_PARAM, 
        NULL,
        NULL,
        wxT("Error Message"),
        wxCMD_LINE_VAL_STRING,
        wxCMD_LINE_PARAM_OPTIONAL
    },
    { // Terminate List
        wxCMD_LINE_NONE
    }
};

DECLARE_APP(ErrorApp)