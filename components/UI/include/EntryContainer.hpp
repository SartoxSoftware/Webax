//
// Created by anerruption on 10/1/21.
//

#ifndef WEBAX_ENTRYCONTAINER_HPP
#define WEBAX_ENTRYCONTAINER_HPP

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

// An EntryContainer is kind of like a text box
class EntryContainer : public wxWindow
{
    bool pressedDown;

    static const int containerHeight = 50;

public:
    EntryContainer(wxFrame* parent);

    int containerWidth;

    void paintEvent(wxPaintEvent &evt);
    void paintNow();

    void render(wxDC &dc);

    // Some useful events
    void mouseMoved(wxMouseEvent &event);
    void mouseDown(wxMouseEvent &event);
    void mouseWheelMoved(wxMouseEvent &event);
    void mouseReleased(wxMouseEvent &event);
    void rightClick(wxMouseEvent &event);
    void mouseLeftWindow(wxMouseEvent &event);
    void keyPressed(wxKeyEvent &event);
    void keyReleased(wxKeyEvent &event);

    DECLARE_EVENT_TABLE()
};

#endif //WEBAX_ENTRYCONTAINER_HPP
