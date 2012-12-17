#ifndef DIVCORE_H_INCLUDED
#define DIVCORE_H_INCLUDED

#include "../MCT/Libs.h"

#ifdef WIN32
#	ifdef DIVCORE_EXPORTS
#		define DIVCORE_API __declspec(dllexport)
#	else
#		define DIVCORE_API __declspec(dllimport)
#	endif
#else
#       define DIVCORE_API
#endif



class Online{};

class DIVCORE_API Thread{
    public:
    Thread();
};

class Sound{
    public:
    Sound(wxString file);
    void Play(bool play);
};

class Paint{};
class Files{};


#endif // DIVCORE_H_INCLUDED
