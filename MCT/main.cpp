/***************************************************************
 * Name:      main.cpp
 * Purpose:   Code for Application Class
 * Author:    Adrian Arroyo Calle (adrian.arroyocalle@gmail.com)
 * Created:   2012-10-01
 * Copyright: Adrian Arroyo Calle (sites.google.com/site/divelmedia)
 * License: GPLv3
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "Libs.h"



IMPLEMENT_APP(MCTApp);

bool MCTApp::OnInit()
{
    SetAppName(wxT("Multiverse City"));
	SetVendorName(wxT("Adrián Arroyo Calle for Divel"));
	if(wxApp::argc>=2)
	{

	}
    MCTFrame* frame = new MCTFrame(0L, _("Multiverse City"));

    frame->Show();
    #ifdef PTHREAD
        pthread_t mythread;
        pthread_create(&mythread, NULL, Music, NULL);
    #endif PTHREAD

    return true;
}
void MCTApp::OnInitCmdLine(wxCmdLineParser& parser)
{
    parser.SetDesc (g_cmdLineDesc);
    // must refuse '/' as parameter starter or cannot use "/path" style paths
    parser.SetSwitchChars (wxT("-"));
}

bool MCTApp::OnCmdLineParsed(wxCmdLineParser& parser)
{
    //silent_mode = parser.Found(wxT("s"));
    // to get at your unnamed parameters use
    wxArrayString files;
        for (int i = 0; i < parser.GetParamCount(); i++)
    {
            files.Add(parser.GetParam(i));
    }

    // and other command line parameters

    // then do what you need with them.

    return true;
}
void* Music(void* var){



    libvlc_instance_t *vlc;
         libvlc_media_list_t *ml;
    libvlc_media_list_player_t *mlp;
    libvlc_media_player_t *mp;
    libvlc_media_t *md1, *md2;

    vlc = libvlc_new (0, NULL);
    ml = libvlc_media_list_new(vlc);

    md1 = libvlc_media_new_path(vlc, "file:///usr/share/multiverse-city/audio/TheGiantTrees.mp3");
    md2 = libvlc_media_new_path(vlc, "file:///usr/share/multiverse-city/audio/Everyday.mp3");

    libvlc_media_list_add_media(ml, md1);
    libvlc_media_list_add_media(ml, md2);

    libvlc_media_release(md1);
    libvlc_media_release(md2);

    mlp = libvlc_media_list_player_new(vlc);

    mp = libvlc_media_player_new(vlc);


    libvlc_media_list_player_set_media_list(mlp, ml);

    libvlc_media_list_player_play(mlp);
     /*libvlc_instance_t * inst;
     libvlc_media_t *m;
     libvlc_media_list_player_t* list;



     //Reproducir un sonido
     inst = libvlc_new (0, NULL);

     // Create a new item
     m = libvlc_media_new_path (inst, "file:///usr/share/multiverse-city/audio/TheGiantTrees.mp3");

     // Create a media player playing environement
     mp = libvlc_media_player_new_from_media (m);

     // No need to keep the media now
     libvlc_media_release (m);

    libvlc_media_player_play (mp);*/


     /*sleep (10); /* Let it play a bit

     /* Stop playing
     libvlc_media_player_stop (mp);

     /* Free the media_player
     libvlc_media_player_release (mp);

     libvlc_release (inst);*/




}

