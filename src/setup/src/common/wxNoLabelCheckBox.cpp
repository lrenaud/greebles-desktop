/**
 * TAKEN FROM: http://olecam.online.fr/wxNoLabelCheckBox/
 */

/////////////////////////////////////////////////////////////////////////////
// Name:        wxNoLabelCheckBox.cpp
// Purpose:     
// Author:      Olivier Le Cam
// Modified by: Ben Draut, chaned to inherit from wxPanel (Jul 2013)
// Created:     25/03/2008 19:01:23
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#include "wx/wx.h"

#include "wxNoLabelCheckBox.h"
#include "wx/renderer.h"

IMPLEMENT_DYNAMIC_CLASS(wxNoLabelCheckBox, wxPanel)

BEGIN_EVENT_TABLE(wxNoLabelCheckBox, wxPanel)
    EVT_LEFT_UP     (wxNoLabelCheckBox::OnClicked)
    EVT_KEY_UP      (wxNoLabelCheckBox::OnKeyUp)
    EVT_PAINT       (wxNoLabelCheckBox::OnPaint)
END_EVENT_TABLE()

wxNoLabelCheckBox::wxNoLabelCheckBox()
{
    m_pImageList = NULL;
    m_state = false;
}

wxNoLabelCheckBox::wxNoLabelCheckBox(wxWindow* parent, wxWindowID id, const wxString& name, const wxPoint& pos, const wxSize& size, long style)
    : wxPanel(parent, id, pos, size, style, name)
{
    m_pImageList = new wxImageList(16, 16, true);

    wxBitmap bitmap(16, 16);
    wxMemoryDC mdc(bitmap);

    wxBrush brush(wxColour(242, 241, 240));
    mdc.SetBackground(brush);

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
}

wxNoLabelCheckBox::~wxNoLabelCheckBox()
{
    if (m_pImageList)
        delete m_pImageList;
}

void wxNoLabelCheckBox::OnClicked(wxMouseEvent& event)
{
    switchCheck();
    event.Skip();
}

void wxNoLabelCheckBox::OnKeyUp(wxKeyEvent& event)
{
    if (event.GetKeyCode() == WXK_SPACE)
    {
        switchCheck();
        event.Skip();
    }
}

void wxNoLabelCheckBox::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);
    dc.DrawBitmap(m_pImageList->GetBitmap(m_state ? 1 : 0), 0, 0, false);
}

void wxNoLabelCheckBox::SetValue(bool value)
{
    m_state = value;
    Refresh();
}

bool wxNoLabelCheckBox::GetValue() const
{
    return m_state;
}

bool wxNoLabelCheckBox::IsChecked() const
{
    return (m_state != false);
}

void wxNoLabelCheckBox::switchCheck()
{
    m_state = ! m_state;
    Refresh();

    // Dispatch Checkbox Event
    wxCommandEvent checkboxEvent(wxEVT_COMMAND_CHECKBOX_CLICKED, GetId());
    checkboxEvent.SetEventObject(this);
    GetEventHandler()->ProcessEvent(checkboxEvent);
}

