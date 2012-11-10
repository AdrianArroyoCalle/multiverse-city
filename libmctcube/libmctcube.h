#ifndef LIBMCTCUBE_H_INCLUDED
#define LIBMCTCUBE_H_INCLUDED

#include "../MCT/Libs.h"
typedef enum{
    CLEAN,
    VALLA,
    OFICINA


} MCTCasilla;



class Casilla{

int x; //Coordenada X
int y; //Coordenada Y
public:
Casilla(MCTCasilla id);
wxBitmap GetBitmap();






};


#endif // LIBMCTCUBE_H_INCLUDED
