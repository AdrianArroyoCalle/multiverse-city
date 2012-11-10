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

switch(id){
    case CLEAN:{actual=wxBitmap(_("/usr/share/multiverse-city/media/template.png"),wxBITMAP_TYPE_PNG);}break;
    case VALLA:{actual=wxBitmap(_("/usr/share/multiverse-city/media/valla.png"),wxBITMAP_TYPE_PNG);}break;
    case OFICINA:{actual=wxBitmap(_("/usr/share/multiverse-city/media/oficina.png"),wxBITMAP_TYPE_PNG);}break;
    case RES1:{actual=wxBitmap(_("/usr/share/multiverse-city/media/amarilla.png"),wxBITMAP_TYPE_PNG);}break;
    case RES2:{actual=wxBitmap(_("/usr/share/multiverse-city/media/residencia_moderna.png"),wxBITMAP_TYPE_PNG);}break;
    case INDUSTRIA:{actual=wxBitmap(_("/usr/share/multiverse-city/media/industria.png"),wxBITMAP_TYPE_PNG);}break;
    case ROAD:{actual=wxBitmap(_("/usr/share/multiverse-city/media/road.png"),wxBITMAP_TYPE_PNG);}break;
    default:{}








}



}
wxBitmap Casilla::GetBitmap(){




return actual;
}



