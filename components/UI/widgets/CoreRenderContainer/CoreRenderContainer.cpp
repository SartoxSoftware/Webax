//
// Created by anerruption on 10/1/21.
//

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "../../include/CoreRenderContainer.hpp"

BEGIN_EVENT_TABLE(CoreRenderContainer, wxPanel)

                EVT_MOTION(CoreRenderContainer::mouseMoved)
                EVT_LEFT_DOWN(CoreRenderContainer::mouseDown)
                EVT_LEFT_UP(CoreRenderContainer::mouseReleased)
                EVT_RIGHT_DOWN(CoreRenderContainer::rightClick)
                EVT_LEAVE_WINDOW(CoreRenderContainer::mouseLeftWindow)
                EVT_KEY_DOWN(CoreRenderContainer::keyPressed)
                EVT_KEY_UP(CoreRenderContainer::keyReleased)
                EVT_MOUSEWHEEL(CoreRenderContainer::mouseWheelMoved)

                // catch paint events
                EVT_PAINT(CoreRenderContainer::paintEvent)

END_EVENT_TABLE()

CoreRenderContainer::CoreRenderContainer(wxFrame* parent) : wxWindow(parent, wxID_ANY)
{
    wxWindowBase::SetMinSize(wxSize(containerWidth, containerHeight));
    pressedDown = false;
}

/*
 * Called by the system of by wxWidgets when the panel needs
 * to be redrawn. You can also trigger this call by
 * calling Refresh()/Update().
 */

void CoreRenderContainer::paintEvent(wxPaintEvent &evt)
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
void CoreRenderContainer::paintNow()
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
void CoreRenderContainer::render(wxDC &dc)
{
    dc.SetBrush(*wxWHITE_BRUSH);
    dc.DrawRectangle(0, 0, containerWidth, containerHeight);
}

void CoreRenderContainer::mouseDown(wxMouseEvent& event)
{
    pressedDown = true;
    paintNow();
}

void CoreRenderContainer::mouseReleased(wxMouseEvent& event)
{
    pressedDown = false;
    paintNow();

    wxMessageBox(wxT("You pressed a CoreRenderContainer"));
}

void CoreRenderContainer::mouseLeftWindow(wxMouseEvent& event)
{
    if (pressedDown)
    {
        pressedDown = false;
        paintNow();
    }
}

// Unused events
void CoreRenderContainer::mouseMoved(wxMouseEvent& event) {}
void CoreRenderContainer::mouseWheelMoved(wxMouseEvent& event) {}
void CoreRenderContainer::rightClick(wxMouseEvent& event) {}
void CoreRenderContainer::keyPressed(wxKeyEvent& event) {}
void CoreRenderContainer::keyReleased(wxKeyEvent& event) {}