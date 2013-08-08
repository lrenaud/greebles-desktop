#ifndef NEW_KEY_DIALOG_H
#define NEW_KEY_DIALOG_H

#include <string>

#include <wx/wx.h>

#include "wxFocusableStaticText.h"

using namespace std;

class NewKeyDialog : public wxDialog
{
private:

    /**
     * Dialog Components
     */
    wxBoxSizer*                            sizer          = nullptr;
    wxFocusableStaticText*                 dialogMsg      = nullptr;

public:

    NewKeyDialog(wxWindow* parent);
    ~NewKeyDialog();

    NewKeyDialog(const NewKeyDialog& other)=delete;
    NewKeyDialog& operator=(const NewKeyDialog& rhs)=delete;

    virtual int ShowModal();
    virtual void EndModal(int retCode);

    void OnKeyUp(wxKeyEvent& event);

};

#endif