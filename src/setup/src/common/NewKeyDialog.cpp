#include <iostream>

#include <wx/wx.h>

#include <input/Keyboard.h>
#include <util/Log.h>

#include "NewKeyDialog.h"
#include "AllowedKeys.h"
#include "KeyTranslator.h"
#include "wxFocusableStaticText.h"

using namespace std;

using namespace SOAR;

NewKeyDialog::NewKeyDialog(wxWindow* parent): wxDialog(parent, wxID_ANY, wxT("Test"))
{
    sizer = new wxBoxSizer(wxVERTICAL);

    dialogMsg = new wxFocusableStaticText(this, "Press New Key");
    dialogMsg->SetFocus();
    sizer->Add(dialogMsg, 1, wxEXPAND | wxALL, 20);

    SetSizerAndFit(sizer);

    dialogMsg->Connect(wxID_ANY, wxEVT_KEY_UP, wxKeyEventHandler(NewKeyDialog::OnKeyUp), NULL, this);
}

NewKeyDialog::~NewKeyDialog()
{

}

void NewKeyDialog::OnKeyUp(wxKeyEvent& event)
{
    int wxKey = event.GetKeyCode();
    int glfwKey = KeyTranslator::GetInstance().TranslateWXKToGLFW(wxKey);

    if (KEY_ALLOWED(glfwKey))
    {
        /** 
         * This is my hack to get around wxWidgets not distinguishing between
         * left/right modifiers. 
         *
         * The Raw key codes for the left side buttons are odd. The key translator
         * always returns the Right-side GLFW code for ctrl, shift, and alt.
         *
         * So, if the GFLW key is one of these three, (they're sequential: 345-347)
         * then we check to see if the raw key code is odd. If it is, than we switch
         * the GLFW code to the left side code, which is 4 less than the right side code.
         */
        if (glfwKey >= GLFW_KEY_RIGHT_SHIFT && glfwKey <= GLFW_KEY_RIGHT_ALT &&
            event.GetRawKeyCode() % 2 == 1)
            glfwKey -= 4;

        this->EndModal(glfwKey);   
    }
}
