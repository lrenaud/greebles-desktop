#include <iostream>

#include <wx/wx.h>

#include <Keyboard.h>

#include "NewKeyDialog.h"
#include "AllowedKeys.h"
#include "KeyTranslator.h"

using namespace std;

using namespace SOAR;

NewKeyDialog::NewKeyDialog(wxWindow* parent): wxDialog(parent, wxID_ANY, wxT(""))
{
    sizer = new wxBoxSizer(wxVERTICAL);

    dialogMsg = new wxStaticText( this, wxID_ANY, wxT("Press New Key"));
    dialogMsg->SetFocus();
    sizer->Add(dialogMsg, 1, wxEXPAND | wxALL, 20);

    pollTimer = new wxTimer(this, wxID_ANY);

    SetSizerAndFit(sizer);
}

NewKeyDialog::~NewKeyDialog()
{

}

int NewKeyDialog::ShowModal()
{
    pollTimer->Start(50);

    return wxDialog::ShowModal();
}

void NewKeyDialog::EndModal(int retCode)
{
    pollTimer->Stop();

    wxDialog::EndModal(retCode);
}

void NewKeyDialog::pollKeys(wxTimerEvent& event)
{
    for (auto key : ALLOWED_KEYS)
    {   
        int newKey = KeyTranslator::GetInstance().TranslateGLFWToWXK(key);
        if (wxGetKeyState((wxKeyCode)newKey))
        {
            // KEY WAS HIT, Handle it!
            // Don't allow duplicate keys, notify if key isn't allowed
            this->EndModal(0);
        }
    }
}
