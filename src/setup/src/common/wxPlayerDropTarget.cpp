#include <iostream>
#include <algorithm>

#include "wx/wx.h"
#include "wx/dnd.h"

#include "wxPlayerDropTarget.h"
#include "PlayerSettings.h"
#include "Utility.h"

using namespace std;

wxPlayerDropTarget::wxPlayerDropTarget(wxPanel* ownerPanel, PlayerSettings* ownerSettings)
{
    this->ownerPanel = ownerPanel;
    this->ownerSettings = ownerSettings;
}

bool wxPlayerDropTarget::OnDropText(wxCoord x, wxCoord y, const wxString& text)
{
    // So, we have a pointer to one player's settings, ownerSettings
    // The other pointer is in the text we received. 
    // It's a pointer to the playerSettings pointer.
    // Now we need to convert it to a real pointer and re-assign them.
    
    // string otherPSStr(text.ToAscii());

    // PlayerSettings** otherPSPtrPtr = nullptr;
    // otherPSPtrPtr = Utility::StringToPtr<PlayerSettings**>(otherPSStr);

    // cout << "otherPSPtrPtr: " << otherPSStr << endl;

    return true;
}