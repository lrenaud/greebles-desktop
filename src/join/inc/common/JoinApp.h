#include "wx/wx.h"
#include "wx/cmdline.h"

#include "JoinFrame.h"

class JoinApp : public wxApp
{
    JoinFrame* frame = nullptr;

    wxString     playerInfoMsg;

    static const int APP_WIDTH          = -1;
    static const int APP_HEIGHT         = -1;

    virtual bool OnInit();
    virtual int OnRun();
    virtual int OnExit();

    virtual void OnInitCmdLine(wxCmdLineParser& parser);
    virtual bool OnCmdLineParsed(wxCmdLineParser& parser);
};

static const wxCmdLineEntryDesc cmdLineDesc[] = 
{
    {
        wxCMD_LINE_OPTION,
        wxT("l"),
        wxT("local"),
        wxT("Number of Local Players"),
        wxCMD_LINE_VAL_NUMBER,
        wxCMD_LINE_OPTION_MANDATORY
    },
    {
        wxCMD_LINE_OPTION,
        wxT("h"),
        wxT("human"),
        wxT("Number of Local Human Players"),
        wxCMD_LINE_VAL_NUMBER,
        wxCMD_LINE_OPTION_MANDATORY
    },
    {
        wxCMD_LINE_NONE
    }
};

DECLARE_APP(JoinApp)