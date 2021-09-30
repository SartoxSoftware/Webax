//
// Created by anerruption on 9/29/21.
//

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "../include/WebaxApp.hpp"
#include "../include/WebaxFrame.hpp"
//#include "../../../tests/include/NetworkTest1.hpp"

bool WebaxApp::OnInit()
{
    //NetworkTest1::Execute();

    auto *frame = new WebaxFrame;
    frame->Show(true);
    return true;
}