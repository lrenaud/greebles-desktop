#ifndef NEW_KEY_DIALOG_H
#define NEW_KEY_DIALOG_H

#include <string>

#include <wx/wx.h>

using namespace std;

class NewKeyDialog : public wxDialog
{
private:

    DECLARE_EVENT_TABLE()

    /**
     * Dialog Components
     */
    wxBoxSizer*                            sizer          = nullptr;
    wxStaticText*                          dialogMsg      = nullptr;

    wxTimer*                               pollTimer      = nullptr;

public:

    NewKeyDialog(wxWindow* parent);
    ~NewKeyDialog();

    virtual int ShowModal();
    virtual void EndModal(int retCode);

private:

    void pollKeys(wxTimerEvent& event);

};

#endif