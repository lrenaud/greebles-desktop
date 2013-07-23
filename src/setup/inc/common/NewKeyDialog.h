#ifndef NEW_KEY_DIALOG_H
#define NEW_KEY_DIALOG_H

#include <string>

#include <wx/wx.h>

#include "wxFocusableStaticText.h"

using namespace std;

class NewKeyDialog : public wxDialog
{
private:

    DECLARE_EVENT_TABLE()

    /**
     * Dialog Components
     */
    wxBoxSizer*                            sizer          = nullptr;
    wxFocusableStaticText*                 dialogMsg      = nullptr;

public:

    NewKeyDialog(wxWindow* parent);
    ~NewKeyDialog();

    virtual int ShowModal();
    virtual void EndModal(int retCode);

    void OnKeyUp(wxKeyEvent& event);

};

#endif