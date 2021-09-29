//
// Created by anerruption on 9/29/21.
//

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "../include/WebaxApp.hpp"
#include "../include/WebaxFrame.hpp"

bool WebaxApp::OnInit()
{
    auto *frame = new WebaxFrame;
    frame->Show(true);
    return true;
}