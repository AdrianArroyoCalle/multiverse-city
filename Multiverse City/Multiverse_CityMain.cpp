/***************************************************************
 * Name:      Multiverse_CityMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Adrian Arroyo Calle (adrian.arroyocalle@gmail.com)
 * Created:   2012-10-01
 * Copyright: Adrian Arroyo Calle (sites.google.com/site/divelmedia)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "Multiverse_CityMain.h"
#define IMAGE_PATH "/home/julian/multiverse-city/"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

#include "librerias.h"

BEGIN_EVENT_TABLE(Multiverse_CityFrame, wxFrame)
    EVT_CLOSE(Multiverse_CityFrame::OnClose)
    EVT_MENU(idMenuQuit, Multiverse_CityFrame::OnQuit)
    EVT_MENU(idMenuAbout, Multiverse_CityFrame::OnAbout)
END_EVENT_TABLE()

Multiverse_CityFrame::Multiverse_CityFrame(wxFrame *frame, const wxString& title)
    : wxFrame(frame, -1, title)
{
    //Leer imagen

    //wxString ImagePath="/home/julian/multiverse-city";
	//Iniciar App
    wxInitAllImageHandlers();
    wxBitmap bitmap;
  if (bitmap.LoadFile(_("/usr/share/multiverse-city/media/splash.png"), wxBITMAP_TYPE_PNG))
  {
      wxSplashScreen* splash = new wxSplashScreen(bitmap,
          wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT,
          6000, NULL, -1, wxDefaultPosition, wxDefaultSize,
          wxSIMPLE_BORDER|wxSTAY_ON_TOP);
  }
  wxYield();


#if wxUSE_MENUS
    // create a menu bar
    wxMenuBar* mbar = new wxMenuBar();
    wxMenu* fileMenu = new wxMenu(_T(""));
    fileMenu->Append(idMenuQuit, _("&Quit\tAlt-F4"), _("Exit of Multiverse City"));
    mbar->Append(fileMenu, _("&File"));

    wxMenu* helpMenu = new wxMenu(_T(""));
    helpMenu->Append(idMenuAbout, _("&About\tF1"), _("About the author"));
    mbar->Append(helpMenu, _("&Help"));

    SetMenuBar(mbar);
#endif // wxUSE_MENUS
    SetSize(300,400);

    wxPanel* panel=new wxPanel(this);
    wxButton* cargar=new wxButton(panel,ID_CARGAR,_("Load a city and Play"),wxPoint(100,100));
    wxButton* nuevo=new wxButton(panel,ID_NUEVO,_("Play new city"),wxPoint(100,200));
    Connect( ID_CARGAR,wxEVT_COMMAND_BUTTON_CLICKED,wxCommandEventHandler(Multiverse_CityFrame::Cargar) );
    Connect( ID_NUEVO,wxEVT_COMMAND_BUTTON_CLICKED,wxCommandEventHandler(Multiverse_CityFrame::Nuevo) );

#if wxUSE_STATUSBAR
    // create a status bar with some information about the used wxWidgets version
    CreateStatusBar(2);
    SetStatusText(_("Multiverse City 1.0"),0);
    SetStatusText(_("Try also Azpazeta and Monopoly"), 1);
#endif // wxUSE_STATUSBAR

}


Multiverse_CityFrame::~Multiverse_CityFrame()
{
}

void Multiverse_CityFrame::OnClose(wxCloseEvent &event)
{
    int confirmar=wxMessageBox(_("Do you really want to exit Multiverse City?"),_("Please, confirm"),wxICON_QUESTION|wxYES_NO);
    if(confirmar==wxYES)
    {
      Destroy();

    }

}

void Multiverse_CityFrame::OnQuit(wxCommandEvent &event)
{
        int confirmar=wxMessageBox(_("Do you really want to exit Multiverse City?"),_("Please, confirm"),wxICON_QUESTION|wxYES_NO);
    if(confirmar==wxYES)
    {
      Destroy();

    }
}

void Multiverse_CityFrame::OnAbout(wxCommandEvent &event)
{
    wxAboutDialogInfo aboutInfo;
        aboutInfo.SetName(_("Multiverse City"));
        //aboutInfo.SetVersion(_(FULLVERSION_STRING));
        aboutInfo.SetDescription(_("Launcher for Multiverse City in Ubuntu"));
        aboutInfo.SetCopyright(_("(C) 2012"));
        aboutInfo.SetWebSite(_("http://sites.google.com/site/divelmedia"));
        aboutInfo.AddDeveloper(_("Adrián Arroyo Calle"));

        wxAboutBox(aboutInfo);
    wxMessageBox(_("Try also Azpazeta"));
}
void Multiverse_CityFrame::Cargar(wxCommandEvent& event)
{
    if(ComprobarArchivos()==false){
        int iniciar=wxMessageBox(_("Do you really want to open Multiverse City with missing files?"),_("Please, confirm"),wxICON_WARNING|wxYES_NO);
        if(iniciar!=wxYES){
        Destroy();
        }else{
        //Elegir fichero

        }
    }
    wxFileDialog* openfile = new wxFileDialog(this,wxT("Open MultiverseCity saves"),wxT(""),wxT(""),wxT("MultiverseCity Save Files(*.mct)|*.mct"),wxFD_OPEN);

       int eleccion= openfile->ShowModal();
        if ( eleccion== wxID_CANCEL){
            return;}
    wxString filePath=openfile->GetPath();
    wxString system_call=_("/usr/games/multiverse-city/mct ")+filePath;
    system(system_call.mb_str());

}
void Multiverse_CityFrame::Nuevo(wxCommandEvent& event)
{
        if(ComprobarArchivos()==false){
        int iniciar=wxMessageBox(_("Do you really want to open Multiverse City with missing files?"),_("Please, confirm"),wxICON_WARNING|wxYES_NO);
        if(iniciar!=wxYES){
        Destroy();
        }else{
        //Iniciar MultiverseCity en nueva partida

        }
    }
    system("/usr/games/multiverse-city/mct NEW");

}
bool Multiverse_CityFrame::ComprobarArchivos()
{
    /*char ActualPath[2048];
    getcwd(ActualPath,2048);
    wxString mystring = wxString::FromUTF8(ActualPath);
    wxPuts(mystring);
    //Abrimos un ZIP que contiene las imágenes, están según la variable ImagePath
    if(wxFileExists(_("/usr/share/multiverse-city/media/template.png"))==false){wxMessageBox(_("Error 404: Missing files"),_("Error 404"),wxICON_ERROR|wxOK);return false;}else{return true;}
    */
    return true;
}
