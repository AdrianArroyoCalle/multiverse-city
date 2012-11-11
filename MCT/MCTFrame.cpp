/***************************************************************
 * Name:      Multiverse_CityMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Adrian Arroyo Calle (adrian.arroyocalle@gmail.com)
 * Created:   2012-10-01
 * Copyright: Adrian Arroyo Calle (sites.google.com/site/divelmedia)
 * License: LGPL License
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
  if (bitmap.LoadFile(_(SPLASH), wxBITMAP_TYPE_PNG))
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
  panel->Cargar(dc);


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


Casilla* bitmapactual[1000];


Panel::Panel(wxFrame* frame) : wxPanel(frame){




}

void Panel::Renderizar(wxDC& dc)
{

    /*wxBitmap rejilla(_("/usr/share/multiverse-city/media/rejilla.png"),wxBITMAP_TYPE_PNG);
    dc.DrawBitmap(rejilla,wxPoint(1,1));*/

    //Se comprobará el archivo y se cargarán solo las imágenes que posea el archivo. Podemos usar structs en otra parte. Se verificará todo uno a uno en otro archivo y mostrar en panmtalla



    int escribir=0;
    int ax=1,ay=1,bx=0,by=0;
    int lineasx,lineasy;
    srand(time(NULL));
    //Son 74x54 PIX los cuadros
    //Son 19x15 y los del centro que son 19-17 y 15-13
    //Cuadros principales

    int count=0;






    for(lineasy=1;lineasy!=28;lineasy++){

        for(lineasx=1;lineasx!=19;lineasx++){
            wxBitmap bitmap=bitmapactual[count]->GetBitmap();
            dc.DrawBitmap(bitmap,wxPoint(bx*73/2,by*53/2));
            bitmapactual[count]->x=bx*73/2;
            bitmapactual[count]->y=by*53/2;
            count++;
            bx+=2;


        }
        for(lineasx=1;lineasx!=19;lineasx++){

            wxBitmap bitmap=bitmapactual[count]->GetBitmap();
            dc.DrawBitmap(bitmap,wxPoint(ax*73/2,ay*53/2));
            bitmapactual[count]->x=ax*73/2;
            bitmapactual[count]->y=ay*53/2;
            ax+=2;
            count++;


        }

        ay+=2;
        ax=1;
        by+=2;
        bx=0;


    }
    //Cuadros secundarios
    ax=0;
    ay=0;
    wxBitmap toolbox(_(TOOLBOX),wxBITMAP_TYPE_PNG);
    dc.DrawBitmap(toolbox,wxPoint(1,1));
    dc.SetTextBackground(_("WHITE"));
    dc.SetTextForeground(_("WHITE"));
    dc.DrawText(wxString::Format(_("Dinero: %d"),money),wxPoint(1,1));
    /*
    for(lineasy=1;lineasy!=13;lineasy++){
        for(lineasx=1;lineasx!=17;lineasx++){
            MCTCasilla bloque;
            int azar=rand()%6+1;
            switch(azar){case 1:bloque=CLEAN;break; case 2: bloque=VALLA;break; case 3:bloque=RES1;break; case 4:bloque=RES2;break; case 5:bloque=OFICINA;break;case 6:bloque=INDUSTRIA;break;}
            Casilla bitmapactual(bloque);
            wxBitmap bitmap=bitmapactual.GetBitmap();
            dc.DrawBitmap(bitmap,wxPoint(x*73/2,y*53/2));

            x+=2;


        }
        y+=2;
        x=0;




    }*/






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
        case MAIN:{

            if(event.GetY()<100)
            {
                if(event.GetX()<306)
                {//INDUSTRIA


                    screen=IND;



                }
                if(event.GetX()>306 && event.GetX()<760)
                {//Residencial
                    screen=RES;
                }
                if(event.GetX()>760 && event.GetX()<1111)
                {//Comercio
                    screen=COM;
                }
                if(event.GetX()>1111)
                {//Destrozar
                    screen=DESTROY;
                }
            }else
            {


            int numero=GetCasilla(event.GetX(),event.GetY());

            wxClientDC dc(this);
            Renderizar(dc);
            wxBitmap dibujo(_(POINTER),wxBITMAP_TYPE_PNG);
            dc.DrawBitmap(dibujo,wxPoint(bitmapactual[numero]->x,bitmapactual[numero]->y));
            }




        }break;
        case EXIT:{
            int myx=event.GetX();
            int myy=event.GetY();
            if((myx>500+39 && myx<500+147) && (myy>300+102 && myy<300+122)){
            //Salir
            wxExit();
            }else{
            screen=MAIN;
            wxPaintDC dc(this);
            Renderizar(dc);

            }




        }break;
        case IND:
        {
            int numero=GetCasilla(event.GetX(),event.GetY());
            bitmapactual[numero]->SetCasilla(INDUSTRIA);
            wxPaintDC dc(this);
            Renderizar(dc);
            money-=500;




        }break;
                case RES:
        {
            int numero=GetCasilla(event.GetX(),event.GetY());
            bitmapactual[numero]->SetCasilla(RES1);
            wxPaintDC dc(this);
            Renderizar(dc);
            money-=200;



        }break;
                case COM:
        {
            int numero=GetCasilla(event.GetX(),event.GetY());
            bitmapactual[numero]->SetCasilla(OFICINA);
            wxPaintDC dc(this);
            Renderizar(dc);
            money-=300;



        }break;
                case DESTROY:
        {
            int numero=GetCasilla(event.GetX(),event.GetY());
            bitmapactual[numero]->SetCasilla(CLEAN);
            wxPaintDC dc(this);
            Renderizar(dc);
            money-=100;




        }break;
        case MROAD:
        {
            int numero=GetCasilla(event.GetX(),event.GetY());
            bitmapactual[numero]->SetCasilla(ROAD);
            wxPaintDC dc(this);
            Renderizar(dc);
            money-=50;




        }break;




    }


}
void Panel::Tecla(wxKeyEvent& event)
{

    int tecla= event.GetKeyCode();
    switch(tecla){
    case WXK_ESCAPE:
    {
        AlertBox mensaje(_("DivCity"),_("¿Deseas salir de DivCity?"));
        mensaje.Show(this);
        screen=EXIT;
        /* Metodo cutre
        int salir=wxMessageBox(_("¿Deseas salir?"),_("DivCity"),wxICON_QUESTION|wxYES_NO);
        if(salir==wxYES){
            this->Destroy();
            wxExit();
        }*/



    }break;
    case WXK_SPACE:
    {
        screen=MAIN;

    }break;
    case 'R':
    {
        screen=MROAD;
    }break;
    case 'G':
    {
        wxFileDialog guardar(this,_("Guardar partida DivCity"),_(""),_(""),_("Partidas DivCity (*.mct)|*.mct"),wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
         if (guardar.ShowModal() == wxID_CANCEL)
            return;
        Guardar(guardar.GetPath());
    }break;
    case 'C':
    {
        wxFileDialog abrir(this,_("Cargar partida de DivCity"),_(""),_(""),_("Partidas DivCity (*.mct)|*.mct"),wxFD_OPEN|wxFD_FILE_MUST_EXIST);
        if (abrir.ShowModal() == wxID_CANCEL)
            return;
        CargarMCT(abrir.GetPath());
    }break;
    case 'S':
    {
        //Take a screenshot
    }
    }
}
int Panel::GetCasilla(int a,int b)
{

int count=0;
int c,d;

do
{
    if(count>500){wxMessageBox(_("FAILS!"));break;}
    c=bitmapactual[count]->x;
    d=bitmapactual[count]->y;
    count++;


}while(!((a+73/2>=c && a-73/2<=c) && (b+73/2-85>=d && b-73/2-85<=d)));








return count-1;
}
void Panel::Guardar(wxString path)
{
    printf("TODO BIEN");
    wxFFileOutputStream out(path+_(".mct"));
    wxZipOutputStream zip(out);
    wxTextOutputStream txt(zip);
    wxString sep(wxFileName::GetPathSeparator());

    printf("TODO BIEN");
    zip.PutNextEntry(_T("VERSION"));
    printf("TODO BIEN");
    txt << _T("DivCity:1\n");
    printf("TODO BIEN");
    zip.PutNextEntry(_T("VAR-DATA") + sep + _T("DATA"));
    printf("TODO BIEN");
    txt << wxString::Format(_("DATA\nMONEY:%d\n"),money);
    printf("TODO BIEN");
    zip.PutNextEntry(_("USER-DATA")+sep+_("USER"));
    printf("TODO BIEN");
    txt << wxString::Format(_("USER\nNAME:TEST\nAGE:14\nEMAIL:nothing@gmail.com"));
    printf("TODO BIEN");
    zip.PutNextEntry(_("CITY-DATA")+sep+_("BUILDINGS"));
    printf("TODO BIEN");
    txt << _T("CITY-DATA/BUILDINGS\nContent:");
    printf("TODO BIEN");
    MCTCasilla id=INDUSTRIA;
    printf("TODO BIEN");


int lineasy, lineasx,count, bx, ax, ay, by;
    for(lineasy=1;lineasy!=28;lineasy++){

        for(lineasx=1;lineasx!=19;lineasx++){
            printf("I");
            //id=bitmapactual[count]->GetCasilla();
            count++;
            bx+=2;

            txt << id << _("\n");


        }
        for(lineasx=1;lineasx!=19;lineasx++){
            printf("I");
            //id=bitmapactual[count]->GetCasilla();
            ax+=2;
            count++;

            txt << id << _("\n");


        }

        ay+=2;
        ax=1;
        by+=2;
        bx=0;


    }



zip.Close();



}
void Panel::Cargar(wxDC& dc)
{

    int escribir=0;
    int ax=1,ay=1,bx=0,by=0;
    int lineasx,lineasy;
    srand(time(NULL));
    money=50000;
    //Son 74x54 PIX los cuadros
    //Son 19x15 y los del centro que son 19-17 y 15-13
    //Cuadros principales

    int count=0;






    for(lineasy=1;lineasy!=28;lineasy++){

        for(lineasx=1;lineasx!=19;lineasx++){
            MCTCasilla bloque;
            int azar=rand()%7+1;
            switch(azar){case 1:bloque=CLEAN;break; case 2: bloque=VALLA;break; case 3:bloque=RES1;break; case 4:bloque=RES2;break; case 5:bloque=OFICINA;break;case 6:bloque=INDUSTRIA;break;case 7:bloque=ROAD;break;}
            bitmapactual[count]=new Casilla(bloque);
            //bitmapactual[count](bloque);
            wxBitmap bitmap=bitmapactual[count]->GetBitmap();
            dc.DrawBitmap(bitmap,wxPoint(bx*73/2,by*53/2));
            bitmapactual[count]->x=bx*73/2;
            bitmapactual[count]->y=by*53/2;
            count++;
            bx+=2;


        }
        for(lineasx=1;lineasx!=19;lineasx++){
            MCTCasilla bloque;

            int azar=rand()%7+1;
            switch(azar){case 1:bloque=CLEAN;break; case 2: bloque=VALLA;break; case 3:bloque=RES1;break; case 4:bloque=RES2;break; case 5:bloque=OFICINA;break;case 6:bloque=INDUSTRIA;break;case 7:bloque=ROAD;break;}
            bitmapactual[count]=new Casilla(bloque);
           // bitmapactual[count](bloque);
            wxBitmap bitmap=bitmapactual[count]->GetBitmap();
            dc.DrawBitmap(bitmap,wxPoint(ax*73/2,ay*53/2));
            bitmapactual[count]->x=ax*73/2;
            bitmapactual[count]->y=ay*53/2;
            ax+=2;
            count++;


        }

        ay+=2;
        ax=1;
        by+=2;
        bx=0;


    }
    //Cuadros secundarios
    ax=0;
    ay=0;
    wxBitmap toolbox(_(TOOLBOX),wxBITMAP_TYPE_PNG);
    dc.DrawBitmap(toolbox,wxPoint(1,1));

    screen=MAIN;




}
void Panel::CargarMCT(wxString path)
{
std::auto_ptr<wxZipEntry> entry;
// convert the local name we are looking for into the internal format

// open the zip
wxFFileInputStream in(path);
wxZipInputStream zip(in);
wxString name = wxZipEntry::GetInternalName(_("VERSION"));
// call GetNextEntry() until the required internal name is found
char mybuffer[2048];
int contar=0;
char version;
do
{
entry.reset(zip.GetNextEntry());
//wxMessageBox(entry->GetInternalName());
}
while (entry.get() != NULL && entry->GetInternalName() != _("VERSION"));
if (entry.get() != NULL)
{

    zip.Read(mybuffer, 2048);


}
for(contar=0;contar<strlen(mybuffer);contar++) {
printf("%c",mybuffer[contar]);
if(mybuffer[contar]==':'){version=mybuffer[contar+1];break;}
}
wxMessageBox(wxString::Format(_("Version: %c"),version));







//VAR-DATA

do
{
entry.reset(zip.GetNextEntry());
}
while (entry.get() != NULL && entry->GetInternalName() != _("VAR-DATA/DATA"));
if (entry.get() != NULL)
{

    zip.Read(mybuffer, 2048);


}
for(contar=0;contar<strlen(mybuffer);contar++) {
printf("%c",mybuffer[contar]);
int factor=1;
int valor;
money=0;
if(mybuffer[contar]==':'){
    //Money
    for(contar=strlen(mybuffer);mybuffer[contar]!=':';contar--)
    {
        switch(mybuffer[contar])
        {
            case '1':valor=1;printf("%d",valor);break;
            case '2':valor=2;printf("%d",valor);break;
            case '3':valor=3;printf("%d",valor);break;
            case '4':valor=4;printf("%d",valor);break;
            case '5':valor=5;printf("%d",valor);break;
            case '6':valor=6;printf("%d",valor);break;
            case '7':valor=7;printf("%d",valor);break;
            case '8':valor=8;printf("%d",valor);break;
            case '9':valor=9;printf("%d",valor);break;
            case '0':valor=0;printf("%d",valor);break;
            default: printf("ERROR");

        }
        money+=valor*factor;
        factor*=10;
        printf("\n%ld",money);
    }
    money/=100;
    wxMessageBox(wxString::Format(_("Dinero: %ld"),money));


    break;}
}







//CITY-DATA

do
{
entry.reset(zip.GetNextEntry());
}
while (entry.get() != NULL && entry->GetInternalName() != _("CITY-DATA/BUILDINGS"));
if (entry.get() != NULL)
{

    zip.Read(mybuffer, 2048);


}
for(contar=0;contar<strlen(mybuffer);contar++) {
printf("%c",mybuffer[contar]);
if(mybuffer[contar]==':'){version=mybuffer[contar+1];break;}
}










}
