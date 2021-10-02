//
// Created by anerruption on 9/29/21.
//

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "../include/WebaxFrame.hpp"
#include "../include/WebaxEventIDs.hpp"
#include "../../../lib/include/csock/HttpRequest.hpp"
#include "../../../include/Util.hpp"

#include <sstream>

WebaxFrame::WebaxFrame() : wxFrame(nullptr, wxID_ANY, wxT("Webax Web Browser"))
{
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
    wxMessageBox(wxT("A web browser built from scratch using a custom engine and wxWidgets."),
                 wxT("About Webax"), wxOK | wxICON_INFORMATION);
}

void WebaxFrame::OnHomePage(wxCommandEvent& event)
{
    wxFrameBase::SetStatusText(wxT("Navigating to the home page..."));

    char* website = "https://www.duckduckgo.com:80/index.html";
    HttpClientSession session = HttpClientSession::Create(website);

    // Make the request headers
    std::stringstream ss;
    ss << "GET " << session.page << " HTTP/1.1\r\n";
    ss << "Host: " << session.host << "\r\n";
    ss << "Accept: text/html\r\n";
    ss << "Connection: close\r\n";
    ss << "\r\n\r\n";

    // Send a GET request to the website to get its content
    char* response = HttpRequest::Get(session, (char*)ss.str().c_str());

    if (response != nullptr)
    {
        wxFrameBase::SetStatusText(wxT("Printing to console..."));
        std::cout << response << std::endl;

        free(response);
        wxFrameBase::SetStatusText(wxT("Done!"));
    } else wxFrameBase::SetStatusText(wxT("Address is unavailable."));
}