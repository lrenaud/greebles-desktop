#ifndef WX_PLAYER_DROP_TARGET_H
#define WX_PLAYER_DROP_TARGET_H

#include "wx/wx.h"
#include "wx/dnd.h"

#include "PlayerSettings.h"

class wxPlayerDropTarget : public wxTextDropTarget
{
private:

    wxPanel*            ownerPanel = nullptr;
    
    PlayerSettings**    ownerSettings = nullptr;

public:

    wxPlayerDropTarget(wxPanel* ownerPanel, PlayerSettings** ownerSettings);

    virtual bool OnDropText(wxCoord x, wxCoord y, const wxString& text);

};  

#endif