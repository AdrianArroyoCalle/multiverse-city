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
    /*EVT_PAINT(MCTFrame::Paint)
    EVT_MOTION(MCTFrame::Motion)
    EVT_KEY_DOWN(MCTFrame::Tecla)
    EVT_CHAR(MCTFrame::Tecla)
    EVT_CHAR_HOOK(MCTFrame::Tecla)*/
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
  this->SetSize(1366,768);
  ShowFullScreen(true, wxFULLSCREEN_ALL);
  Panel* panel=new Panel(this);
  panel->SetSize(1366,768);
  panel->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(Panel::Tecla));
  panel->Connect(wxEVT_PAINT,wxPaintEventHandler(Panel::Paint));
  panel->Connect(wxEVT_LEFT_UP,wxMouseEventHandler(Panel::Motion));
  //panel->Connect(wxEVT_MOTION,wxMouseEventHandler(Panel::Motion));
  wxClientDC dc(panel);
  panel->Renderizar(dc);


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
Panel::Panel(wxFrame* frame) : wxPanel(frame){




}
void Panel::Renderizar(wxDC& dc)
{

    /*wxBitmap rejilla(_("/usr/share/multiverse-city/media/rejilla.png"),wxBITMAP_TYPE_PNG);
    dc.DrawBitmap(rejilla,wxPoint(1,1));*/

    //Se comprobará el archivo y se cargarán solo las imágenes que posea el archivo. Podemos usar structs en otra parte. Se verificará todo uno a uno en otro archivo y mostrar en panmtalla


    wxBitmap Template(_("/usr/share/multiverse-city/media/template.png"),wxBITMAP_TYPE_PNG);
    wxBitmap valla(_("/usr/share/multiverse-city/media/valla.png"),wxBITMAP_TYPE_PNG);
    int escribir=0;
    int x=1,y=1;
    int lineasx,lineasy;
    //Son 74x54 PIX los cuadros
    //Son 19x15 y los del centro que son 19-17 y 15-13
    //Cuadros principales
    for(lineasy=1;lineasy!=15;lineasy++){
        for(lineasx=1;lineasx!=19;lineasx++){
            dc.DrawBitmap(Template,wxPoint(x*73/2,y*53/2));
            x+=2;


        }
        y+=2;
        x=1;




    }
    //Cuadros secundarios
    x=0;
    y=0;
    for(lineasy=1;lineasy!=13;lineasy++){
        for(lineasx=1;lineasx!=17;lineasx++){
            dc.DrawBitmap(Template,wxPoint(x*73/2,y*53/2));

            x+=2;


        }
        y+=2;
        x=0;




    }






    //dc.DrawBitmap(Template,wxPoint(x,y));
   /* while(escribir!=553){
    //dc.DrawBitmap(Template,wxPoint(x*74-74,y*54-112-54));
    dc.DrawBitmap(Template,wxPoint(x*74/2,y*54/2));
    if(x==19){
        x=0;y+=54/2;
    }else{
        x++;
    }
    escribir++;
    /*switch(escribir)
    {
        case 19:{x=-37;y+=54/2;wxPrintf(_("Aqui"));}break;
        case (19+17):{x=0;y+=54/2;wxPrintf(_("Aqui"));}break;
        case (19+17+19):{x=-37;y+=54/2;}break;
        case (19+17+19+17):{x=0;y+=54/2;}break;
        default:{x++;if(x==10)x=0;}


    }


    }*/

}

void Panel::Paint(wxPaintEvent& event)
{
    wxPaintDC dc(this);
    Renderizar(dc);
}
void Panel::Motion(wxMouseEvent& event)
{
    switch(screen){
        case 1:{
            int myx=event.GetX();
            int myy=event.GetY();
            if((myx>500+39 && myx<500+147) && (myy>300+102 && myy<300+122)){
            //Salir
            wxExit();
            }else{
            screen=0;
            wxPaintDC dc(this);
            Renderizar(dc);

            }




        }break;




    }


}
void Panel::Tecla(wxKeyEvent& event)
{

    int tecla= event.GetKeyCode();
    switch(tecla){
    case WXK_ESCAPE:
    {
        wxBitmap alertbox(_("/usr/share/multiverse-city/media/alertbox.png"),wxBITMAP_TYPE_PNG);
        wxClientDC dc(this);
        dc.DrawBitmap(alertbox,wxPoint(500,300));
        dc.DrawText(_("DivCity"),wxPoint(500+38,300+22));
        dc.DrawText(_("¿Deseas salir de DivCity?"),wxPoint(500+62,300+62));
        screen=1;
        /* Metodo cutre
        int salir=wxMessageBox(_("¿Deseas salir?"),_("DivCity"),wxICON_QUESTION|wxYES_NO);
        if(salir==wxYES){
            this->Destroy();
            wxExit();
        }*/



    }break;
    case WXK_SPACE:
    {

    }break;
    }
}
