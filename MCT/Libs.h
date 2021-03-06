#ifndef LIBS_H_INCLUDED
#define LIBS_H_INCLUDED
//Standar
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>
#include <map>

//Linux
#ifdef linux
#include <unistd.h>
#include <pthread.h>
#endif
//Windows
#ifdef WIN32
#include <Windows.h>
#endif
//wxWidgets
#include <wx/wx.h>
#include <wx/aboutdlg.h>
#include <wx/bitmap.h>
#include <wx/filefn.h>
#include <wx/splash.h>
#include <wx/filedlg.h>
#include <wx/event.h>
#include <wx/cmdline.h>
#include <wx/dc.h>
#include <wx/filedlg.h>
#include <wx/zipstrm.h>
#include <wx/wfstream.h>
#include <wx/txtstrm.h>
#include <wx/filesys.h>
#include <wx/dcmemory.h>
#include <wx/dcbuffer.h>
#include <wx/cmndata.h>
#include <wx/printdlg.h>
#include <wx/dcprint.h>
#include <wx/print.h>
#include <wx/progdlg.h>
//Locales
#include "main.h"
#include "Path.h"
#include "VarGlobal.h"
#ifndef LIBMCTCUBE_H_INCLUDED
#include "MCTFrame.h"
#endif
#include "../libmctcube/libmctcube.h"
#include "../divcore/divcore.h"
//libVLC
#if defined(WIN32) && defined(VLC)
#include <vlc/vlc.h>
#endif
#ifdef linux
#include <vlc/vlc.h>
#endif

#endif // LIBS_H_INCLUDED
