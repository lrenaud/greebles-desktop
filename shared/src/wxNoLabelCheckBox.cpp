/**
 * TAKEN FROM: http://olecam.online.fr/wxNoLabelCheckBox/
 */

/////////////////////////////////////////////////////////////////////////////
// Name:        wxNoLabelCheckBox.cpp
// Purpose:     
// Author:      Olivier Le Cam
// Modified by: 
// Created:     25/03/2008 19:01:23
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#include "wx/wx.h"

#include "wxNoLabelCheckBox.h"
#include "wx/renderer.h"

IMPLEMENT_DYNAMIC_CLASS(wxNoLabelCheckBox, wxStaticBitmap)

BEGIN_EVENT_TABLE(wxNoLabelCheckBox, wxStaticBitmap)
    EVT_LEFT_UP(wxNoLabelCheckBox::OnClicked)
END_EVENT_TABLE()

wxNoLabelCheckBox::wxNoLabelCheckBox()
{
    m_pImageList = NULL;
    m_state = false;
}

wxNoLabelCheckBox::wxNoLabelCheckBox(wxWindow* parent, wxWindowID id, const wxString& name, const wxPoint& pos, const wxSize& size, long style)
    :wxStaticBitmap(parent, id, wxNullBitmap, pos, size, style, name)
{
    m_pImageList = new wxImageList(16, 16, true);

    wxBitmap bitmap(16, 16);
    wxMemoryDC mdc(bitmap);

    mdc.Clear(); // needed?
    wxRendererNative::Get().DrawCheckBox(this, mdc, wxRect(0, 0, 16, 16), 0);
    mdc.SelectObject(wxNullBitmap);
    m_pImageList->Add(bitmap);

    mdc.Clear(); // needed?
    mdc.SelectObject(bitmap);
    wxRendererNative::Get().DrawCheckBox(this, mdc, wxRect(0, 0, 16, 16), wxCONTROL_CHECKED);
    mdc.SelectObject(wxNullBitmap);
    m_pImageList->Add(bitmap);

    m_state = false;
    SetBitmap(m_pImageList->GetBitmap(0));
}

wxNoLabelCheckBox::~wxNoLabelCheckBox()
{
    if (m_pImageList)
        delete m_pImageList;
}

void wxNoLabelCheckBox::OnClicked(wxMouseEvent& event)
{
    m_state = ! m_state;
    SetBitmap(m_pImageList->GetBitmap(m_state ? 1 : 0));
    event.Skip();
}

void wxNoLabelCheckBox::SetValue(bool value)
{
    m_state = value;
    SetBitmap(m_pImageList->GetBitmap(value ? 1 : 0));
}

bool wxNoLabelCheckBox::GetValue() const
{
    return m_state;
}

bool wxNoLabelCheckBox::IsChecked() const
{
    return (m_state != false);
}