/**
 * TAKEN FROM: http://olecam.online.fr/wxNoLabelCheckBox/
 */

/////////////////////////////////////////////////////////////////////////////
// Name:        wxNoLabelCheckBox.h
// Purpose:     
// Author:      Olivier Le Cam
// Modified by: 
// Created:     25/03/2008 19:01:21
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _WXNOLABELCHECKBOX_H_
#define _WXNOLABELCHECKBOX_H_

#include "wx/imaglist.h"

class wxNoLabelCheckBox : public wxPanel
{    
    DECLARE_DYNAMIC_CLASS(wxNoLabelCheckBox)
    DECLARE_EVENT_TABLE()

public:
    wxNoLabelCheckBox();
    wxNoLabelCheckBox(wxWindow* parent, 
                      wxWindowID id = wxID_ANY, 
                      const wxString& name = wxCheckBoxNameStr, 
                      const wxPoint& pos = wxDefaultPosition, 
                      const wxSize& size = wxDefaultSize, 
                      long style = 0);
    ~wxNoLabelCheckBox();
    void OnClicked(wxMouseEvent& event);
    void OnKeyUp(wxKeyEvent& event);
    void OnPaint(wxPaintEvent& event);
    virtual void SetValue(bool value);
    virtual bool GetValue() const;
    virtual bool IsChecked() const;

private:
    bool m_state;
    wxImageList* m_pImageList;

    void switchCheck();
};

#endif

