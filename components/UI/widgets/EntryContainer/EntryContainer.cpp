//
// Created by anerruption on 10/1/21.
//

#include "../../include/EntryContainer.hpp"

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

BEGIN_EVENT_TABLE(EntryContainer, wxPanel)

                EVT_MOTION(EntryContainer::mouseMoved)
                EVT_LEFT_DOWN(EntryContainer::mouseDown)
                EVT_LEFT_UP(EntryContainer::mouseReleased)
                EVT_RIGHT_DOWN(EntryContainer::rightClick)
                EVT_LEAVE_WINDOW(EntryContainer::mouseLeftWindow)
                EVT_KEY_DOWN(EntryContainer::keyPressed)
                EVT_KEY_UP(EntryContainer::keyReleased)
                EVT_MOUSEWHEEL(EntryContainer::mouseWheelMoved)

                // catch paint events
                EVT_PAINT(EntryContainer::paintEvent)

END_EVENT_TABLE()

EntryContainer::EntryContainer(wxFrame* parent) : wxWindow(parent, wxID_ANY)
{
    wxWindowBase::SetMinSize(wxSize(containerWidth, containerHeight));
    pressedDown = false;
}

/*
 * Called by the system of by wxWidgets when the panel needs
 * to be redrawn. You can also trigger this call by
 * calling Refresh()/Update().
 */

void EntryContainer::paintEvent(wxPaintEvent &evt)
{
    // depending on your system you may need to look at double-buffered dcs
    wxPaintDC dc(this);
    render(dc);
}

/*
 * Alternatively, you can use a clientDC to paint on the panel
 * at any time. Using this generally does not free you from
 * catching paint events, since it is possible that e.g. the window
 * manager throws away your drawing when the window comes to the
 * background, and expects you will redraw it when the window comes
 * back (by sending a paint event).
 */
void EntryContainer::paintNow()
{
    // depending on your system you may need to look at double-buffered dcs
    wxClientDC dc(this);
    render(dc);
}

/*
 * Here we do the actual rendering. I put it in a separate
 * method so that it can work no matter what type of DC
 * (e.g. wxPaintDC or wxClientDC) is used.
 */
void EntryContainer::render(wxDC &dc)
{
    dc.SetBrush(*wxWHITE_BRUSH);
    dc.DrawRectangle(0, 0, containerWidth, containerHeight);
}

void EntryContainer::mouseDown(wxMouseEvent& event)
{
    pressedDown = true;
    paintNow();
}

void EntryContainer::mouseReleased(wxMouseEvent& event)
{
    pressedDown = false;
    paintNow();

    wxMessageBox(wxT("You pressed an EntryContainer"));
}

void EntryContainer::mouseLeftWindow(wxMouseEvent& event)
{
    if (pressedDown)
    {
        pressedDown = false;
        paintNow();
    }
}

// Unused events
void EntryContainer::mouseMoved(wxMouseEvent& event) {}
void EntryContainer::mouseWheelMoved(wxMouseEvent& event) {}
void EntryContainer::rightClick(wxMouseEvent& event) {}
void EntryContainer::keyPressed(wxKeyEvent& event) {}
void EntryContainer::keyReleased(wxKeyEvent& event) {}