#include <string>

#include "Utility.h"
#include "wxFocusableStaticText.h"

wxFocusableStaticText::wxFocusableStaticText(wxWindow* parent, const char* text):
    wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxWANTS_CHARS)
{
    sizer = new wxBoxSizer(wxVERTICAL);

    label = new wxStaticText(this, wxID_ANY, Utility::StringToWxString(text));    
    sizer->Add(label, 0, wxEXPAND, 5);

    SetSizerAndFit(sizer);
}

wxFocusableStaticText::~wxFocusableStaticText()
{

}