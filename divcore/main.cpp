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
#include "divcore.h"


Thread::Thread()
{
    #ifdef WIN32


    #else
       // pthread_t mythread;
       // pthread_create(&mythread, NULL,thread, NULL);


    #endif



}

Sound::Sound(wxString file)
{
libvlc_instance_t * inst;
     libvlc_media_player_t *mp;
     libvlc_media_t *m;

     /* Load the VLC engine */
     inst = libvlc_new (0, NULL);

     /* Create a new item */
     m = libvlc_media_new_path (inst, file.c_str());

     /* Create a media player playing environement */
     mp = libvlc_media_player_new_from_media (m);

     /* No need to keep the media now */
     libvlc_media_release (m);



     /* play the media_player */
     libvlc_media_player_play (mp);
}
void Sound::Play(bool play)
{



}
