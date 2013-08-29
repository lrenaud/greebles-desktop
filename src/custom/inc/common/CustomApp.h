#include "wx/wx.h"
#include "wx/cmdline.h"

#include "CustomFrame.h"
#include "Utility.h"

class CustomApp : public wxApp
{
    CustomFrame* frame = nullptr;

    wxString     playerInfoMsg;
    bool         isNetworkGame;

    static const int APP_WIDTH          = 390;
    static const int APP_HEIGHT         = 255;

    virtual bool OnInit();
    virtual int OnExit();

    virtual void OnInitCmdLine(wxCmdLineParser& parser);
    virtual bool OnCmdLineParsed(wxCmdLineParser& parser);
};

static const wxCmdLineEntryDesc cmdLineDesc[] = 
{
    {
        wxCMD_LINE_OPTION,
        MywxT("l"),
        MywxT("local"),
        MywxT("Number of Local Players"),
        wxCMD_LINE_VAL_NUMBER,
        wxCMD_LINE_OPTION_MANDATORY
    },
    {
        wxCMD_LINE_OPTION,
        MywxT("h"),
        MywxT("human"),
        MywxT("Number of Local Human Players"),
        wxCMD_LINE_VAL_NUMBER,
        wxCMD_LINE_OPTION_MANDATORY
    },
    {
        wxCMD_LINE_SWITCH,
        MywxT("n"),
        MywxT("network"),
        MywxT("Signals that this is a network game"),
    },
    {
        wxCMD_LINE_NONE
    }
};

DECLARE_APP(CustomApp)