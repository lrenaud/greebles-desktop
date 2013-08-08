#include <iostream>
#include <algorithm>

#include "wx/wx.h"
#include "wx/dnd.h"

#include "wxPlayerDropTarget.h"
#include "PlayerSettings.h"
#include "Utility.h"

using namespace std;

wxPlayerDropTarget::wxPlayerDropTarget(wxPanel* ownerPanel, PlayerSettings** ownerSettings)
{
    this->ownerPanel = ownerPanel;
    this->ownerSettings = ownerSettings;
}

bool wxPlayerDropTarget::OnDropText(wxCoord x, wxCoord y, const wxString& text)
{
    // So, we have a pointer to one player's settings, ownerSettings
    // The source pointer is in the text we received. 
    // It's a pointer to the playerSettings pointer.
    // Now we need to convert it to a real pointer and re-assign them.    

    // Swap Pointers
    string sourcePSStr(text.ToAscii());

    PlayerSettings** sourcePSPtrPtr = nullptr;
    sourcePSPtrPtr = Utility::StringToPtr<PlayerSettings*>(sourcePSStr);

    swap(*sourcePSPtrPtr, *ownerSettings);

    // We also need to actually exchange the id's so that when these get saved,
    // they get saved with the right position.
    int temp = (*sourcePSPtrPtr)->Id();
    (*sourcePSPtrPtr)->SetId((*ownerSettings)->Id());
    (*ownerSettings)->SetId(temp);

    return true;
}