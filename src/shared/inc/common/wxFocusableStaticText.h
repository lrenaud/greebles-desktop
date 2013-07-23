#ifndef WX_FOCUSABLE_STATIC_TEXT
#define WX_FOCUSABLE_STATIC_TEXT

#include <wx/wx.h>

class wxFocusableStaticText : public wxPanel
{
private:

    wxBoxSizer*                sizer = nullptr;
    wxStaticText*              label = nullptr;

public:

    wxFocusableStaticText(wxWindow* parent, const char* text);
    ~wxFocusableStaticText();

};

#endif
