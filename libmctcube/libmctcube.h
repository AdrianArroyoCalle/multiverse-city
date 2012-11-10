#ifndef LIBMCTCUBE_H_INCLUDED
#define LIBMCTCUBE_H_INCLUDED

#ifdef WIN32
#	ifdef MCTCUBE_EXPORTS
#		define MCTCUBE_API __declspec(dllexport)
#	else
#		define MCTCUBE_API __declspec(dllimport)
#	endif
#endif

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




class MCTCUBE_API Casilla{




public:
	Casilla(MCTCasilla id);
	wxBitmap	GetBitmap();
	int			x;		//Coordenada X
	int			y;		//Coordenada Y
	wxBitmap	actual;
	void		SetBitmap(wxBitmap nuevo);
	void		SetCasilla(MCTCasilla id);
	MCTCasilla	GetCasilla();
private:
	MCTCasilla	lacasilla;





};

class MCTCUBE_API AlertBox{

public:
AlertBox(wxString title,wxString message);
void Show(wxWindow* window);
wxString mytitle;
wxString mymessage;


};


#endif // LIBMCTCUBE_H_INCLUDED
