//
// Created by anerruption on 9/29/21.
//

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "../include/WebaxFrame.hpp"
#include "../include/WebaxEventIDs.hpp"

WebaxFrame::WebaxFrame() : wxFrame(nullptr, wxID_ANY, "Webax Web Browser")
{
    auto *menuFile = new wxMenu;
    menuFile->Append(ID_HOMEPAGE, "&Home page\tCtrl-H",
                         "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    auto *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    auto *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    wxFrameBase::SetSize(800, 600);

    wxFrameBase::SetMenuBar(menuBar);

    wxFrameBase::CreateStatusBar();
    wxFrameBase::SetStatusText("Welcome to Webax!");

    Bind(wxEVT_MENU, &WebaxFrame::OnHomePage, this, ID_HOMEPAGE);
    Bind(wxEVT_MENU, &WebaxFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &WebaxFrame::OnExit, this, wxID_EXIT);
}

void WebaxFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void WebaxFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("A web browser built from scratch using a custom engine and wxWidgets.",
                 "About Webax", wxOK | wxICON_INFORMATION);
}

void WebaxFrame::OnHomePage(wxCommandEvent& event)
{
    wxFrameBase::SetStatusText("Navigating to the home page...");
}