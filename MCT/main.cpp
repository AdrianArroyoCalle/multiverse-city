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
    MCTFrame* frame = new MCTFrame(0L, _("Multiverse City"));

    frame->Show();

    return true;
}
