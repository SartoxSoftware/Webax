//
// Created by anerruption on 9/29/21.
//

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/sizer.h>
#endif

#include "../include/WebaxApp.hpp"
#include "../include/WebaxFrame.hpp"
#include "../include/WebaxEventIDs.hpp"
#include "../include/EntryContainer.hpp"
#include "../include/CoreRenderContainer.hpp"

bool WebaxApp::OnInit()
{
    // Set up all image handlers
    wxInitAllImageHandlers();

    // Set up all menus and such
    auto* sizer = new wxBoxSizer(wxVERTICAL);
    auto* frame = new WebaxFrame;

    auto* menuFile = new wxMenu;
    menuFile->Append(ID_HOMEPAGE, wxT("&Home page\tCtrl-H"),
                         wxT("Go to the current home page"));
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    auto* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    auto* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, wxT("&File"));
    menuBar->Append(menuHelp, wxT("&Help"));

    // Set up the frame's properties
    frame->SetSize(800, 600);

    frame->SetMenuBar(menuBar);

    frame->CreateStatusBar();
    frame->SetStatusText(wxT("Welcome to Webax!"));

    wxSize size = frame->GetSize();

    // Set up all custom widgets
    // TODO: Fix
    /*auto* entry = new EntryContainer(frame);
    entry->containerWidth = size.GetWidth();

    sizer->Add(entry, 0, wxALL, 5);

    auto* render = new CoreRenderContainer(frame);
    render->containerWidth = size.GetWidth();
    render->containerHeight = size.GetHeight();
    render->entryHeight = entry->GetSize().GetHeight();

    sizer->Add(render, 0, wxALL, 5);*/

    // And finally, set up the frame's sizer and show the actual frame
    frame->SetSizer(sizer);
    frame->Show(true);

    return true;
}