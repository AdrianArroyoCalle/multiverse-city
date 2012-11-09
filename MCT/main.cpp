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
