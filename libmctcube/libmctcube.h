#ifndef LIBMCTCUBE_H_INCLUDED
#define LIBMCTCUBE_H_INCLUDED

#include "../MCT/Libs.h"
typedef enum{
    CLEAN,
    VALLA,
    OFICINA,
    RES1,
    INDUSTRIA,
    RES2,
    ROAD


} MCTCasilla;




typedef class Casilla{




public:
Casilla(MCTCasilla id);
wxBitmap GetBitmap();
int x; //Coordenada X
int y; //Coordenada Y
wxBitmap actual;
void SetBitmap(wxBitmap nuevo);
void SetCasilla(MCTCasilla id);
MCTCasilla GetCasilla();
private:
MCTCasilla lacasilla;





}Casilla;

class AlertBox{

public:
AlertBox(wxString title,wxString message);
void Show(wxWindow* window);
wxString mytitle;
wxString mymessage;


};


#endif // LIBMCTCUBE_H_INCLUDED
