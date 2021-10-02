//
// Created by anerruption on 10/1/21.
//

#ifndef WEBAX_CORERENDERCONTAINER_HPP
#define WEBAX_CORERENDERCONTAINER_HPP

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class CoreRenderContainer : public wxWindow
{
    bool pressedDown;

public:
    int containerWidth, containerHeight, entryHeight;

    CoreRenderContainer(wxFrame* parent);

    void paintEvent(wxPaintEvent & evt);
    void paintNow();

    void render(wxDC& dc);

    // Some useful events
    void mouseMoved(wxMouseEvent& event);
    void mouseDown(wxMouseEvent& event);
    void mouseWheelMoved(wxMouseEvent& event);
    void mouseReleased(wxMouseEvent& event);
    void rightClick(wxMouseEvent& event);
    void mouseLeftWindow(wxMouseEvent& event);
    void keyPressed(wxKeyEvent& event);
    void keyReleased(wxKeyEvent& event);

    DECLARE_EVENT_TABLE()
};

#endif //WEBAX_CORERENDERCONTAINER_HPP
