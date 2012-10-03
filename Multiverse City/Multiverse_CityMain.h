/***************************************************************
 * Name:      Multiverse_CityMain.h
 * Purpose:   Defines Application Frame
 * Author:    Adrian Arroyo Calle (adrian.arroyocalle@gmail.com)
 * Created:   2012-10-01
 * Copyright: Adrian Arroyo Calle (sites.google.com/site/divelmedia)
 * License:
 **************************************************************/

#ifndef MULTIVERSE_CITYMAIN_H
#define MULTIVERSE_CITYMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "Multiverse_CityApp.h"

class Multiverse_CityFrame: public wxFrame
{
    public:
        Multiverse_CityFrame(wxFrame *frame, const wxString& title);
        ~Multiverse_CityFrame();
    private:
        enum
        {
            idMenuQuit = 1000,
            idMenuAbout,
            ID_CARGAR,
            ID_NUEVO
        };
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void Cargar(wxCommandEvent& event);
        void Nuevo(wxCommandEvent& event);
        bool ComprobarArchivos();
        DECLARE_EVENT_TABLE()

};


#endif // MULTIVERSE_CITYMAIN_H
