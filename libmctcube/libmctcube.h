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



class Casilla{

int x; //Coordenada X
int y; //Coordenada Y
wxBitmap actual;
public:
Casilla(MCTCasilla id);
wxBitmap GetBitmap();






};


#endif // LIBMCTCUBE_H_INCLUDED
