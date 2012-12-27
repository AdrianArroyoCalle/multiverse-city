// The functions contained in this file are pretty dummy
// and are included only as a placeholder. Nevertheless,
// they *will* get included in the shared library if you
// don't remove them :)
//
// Obviously, you 'll have to write yourself the super-duper
// functions to include in the resulting library...
// Also, it's not necessary to write every function in this file.
// Feel free to add more files in this project. They will be
// included in the resulting library.
#include "libmctcube.h"





Casilla::Casilla(MCTCasilla id){
	wxInitAllImageHandlers();
switch(id){
case CLEAN:{actual=wxBitmap(_(CLEAN_PATH),wxBITMAP_TYPE_PNG);}break;
    case VALLA:{actual=wxBitmap(_(VALLA_PATH),wxBITMAP_TYPE_PNG);}break;
    case OFICINA:{actual=wxBitmap(_(OFICINA_PATH),wxBITMAP_TYPE_PNG);}break;
    case RES1:{actual=wxBitmap(_(AMARILLA_PATH),wxBITMAP_TYPE_PNG);}break;
    case RES2:{actual=wxBitmap(_(RESIDENCIA_MODERNA_PATH),wxBITMAP_TYPE_PNG);}break;
    case INDUSTRIA:{actual=wxBitmap(_(INDUSTRIA_PATH),wxBITMAP_TYPE_PNG);}break;
    case ROAD:{actual=wxBitmap(_(ROAD_PATH),wxBITMAP_TYPE_PNG);}break;
    case PARK:{actual=wxBitmap(_(PARK_PATH),wxBITMAP_TYPE_PNG);}break;
    case TECH:{actual=wxBitmap(_(INDUSTRIATECH_0_PATH),wxBITMAP_TYPE_PNG);}break;
    default:{}








}
lacasilla=id;


}
wxBitmap Casilla::GetBitmap(){




return actual;
}
void Casilla::SetBitmap(wxBitmap nuevo){

actual=nuevo;


}
void Casilla::Iniciar()
{
    //Se cargan los bitmaps en RAM
}
void Casilla::SetCasilla(MCTCasilla id)
{
	wxInitAllImageHandlers();
    switch(id){
    case CLEAN:{actual=wxBitmap(_(CLEAN_PATH),wxBITMAP_TYPE_PNG);}break;
    case VALLA:{actual=wxBitmap(_(VALLA_PATH),wxBITMAP_TYPE_PNG);}break;
    case OFICINA:{actual=wxBitmap(_(OFICINA_PATH),wxBITMAP_TYPE_PNG);}break;
    case RES1:{actual=wxBitmap(_(AMARILLA_PATH),wxBITMAP_TYPE_PNG);}break;
    case RES2:{actual=wxBitmap(_(RESIDENCIA_MODERNA_PATH),wxBITMAP_TYPE_PNG);}break;
    case INDUSTRIA:{actual=wxBitmap(_(INDUSTRIA_PATH),wxBITMAP_TYPE_PNG);}break;
    case ROAD:{actual=wxBitmap(_(ROAD_PATH),wxBITMAP_TYPE_PNG);}break;
    case PARK:{actual=wxBitmap(_(PARK_PATH),wxBITMAP_TYPE_PNG);}break;
    case TECH:{actual=wxBitmap(_(INDUSTRIATECH_0_PATH),wxBITMAP_TYPE_PNG);}break;
    default:{}








}
lacasilla=id;

}
wxBitmap Casilla::GetSuper(int altura)
{
    switch(lacasilla)
    {
        case OFICINA:{
            switch(altura)
            {
                case 1: return wxBitmap(_(OFICINA2_PATH),wxBITMAP_TYPE_PNG);
            }

        }
        case TECH:{
            switch(altura)
            {
                case 1: return wxBitmap(_(INDUSTRIATECH_1_PATH),wxBITMAP_TYPE_PNG);
            }

        }
        default: return wxBitmap(_(VOID_PATH),wxBITMAP_TYPE_PNG);//No necesita más
    }

}
MCTCasilla Casilla::GetCasilla()
{

return lacasilla;
}

AlertBox::AlertBox(wxString title, wxString message)
{
    mytitle=title;
    mymessage=message;
}
void AlertBox::Show(wxWindow* window)
{
	wxInitAllImageHandlers();
     wxBitmap alertbox(_(ALERTBOX),wxBITMAP_TYPE_PNG);
        wxClientDC dc(window);
        dc.DrawBitmap(alertbox,wxPoint(500,300));
        dc.DrawText(mytitle,wxPoint(500+38,300+22));
        dc.DrawText(mymessage,wxPoint(500+62,300+62));
}

