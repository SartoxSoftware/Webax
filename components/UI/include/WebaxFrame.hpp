//
// Created by anerruption on 9/29/21.
//

#ifndef WEBAX_WEBAXFRAME_HPP
#define WEBAX_WEBAXFRAME_HPP

class WebaxFrame : public wxFrame
{
public:
    WebaxFrame();
private:
    void OnHomePage(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
};

#endif //WEBAX_WEBAXFRAME_HPP
