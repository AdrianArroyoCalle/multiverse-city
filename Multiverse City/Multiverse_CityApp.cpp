/***************************************************************
 * Name:      Multiverse_CityApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Adrian Arroyo Calle (adrian.arroyocalle@gmail.com)
 * Created:   2012-10-01
 * Copyright: Adrian Arroyo Calle (sites.google.com/site/divelmedia)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "Multiverse_CityApp.h"
#include "Multiverse_CityMain.h"

IMPLEMENT_APP(Multiverse_CityApp);

bool Multiverse_CityApp::OnInit()
{
    Multiverse_CityFrame* frame = new Multiverse_CityFrame(0L, _("Multiverse City Launcher"));

    frame->Show();

    return true;
}
