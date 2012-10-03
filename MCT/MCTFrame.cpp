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

#include "MCTFrame.h"
#include "Libs.h"

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

#include "Libs.h"
#include "MCTFrame.h"

BEGIN_EVENT_TABLE(MCTFrame, wxFrame)
    //EVT_CLOSE(MCTFrame::OnClose)
    //EVT_MENU(idMenuQuit, MCTFrame::OnQuit)
    //EVT_MENU(idMenuAbout, MCTFrame::OnAbout)
END_EVENT_TABLE()

MCTFrame::MCTFrame(wxFrame *frame, const wxString& title)
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
/*

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
#endif // wxUSE_STATUSBAR*/

}
MCTFrame::~MCTFrame(){



}
