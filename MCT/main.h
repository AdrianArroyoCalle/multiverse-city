#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <wx/app.h>
#include "Libs.h"

class MCTApp : public wxApp
{
    public:
        virtual bool OnInit();
        virtual void OnInitCmdLine(wxCmdLineParser& parser);
        virtual bool OnCmdLineParsed(wxCmdLineParser& parser);
};
static const wxCmdLineEntryDesc g_cmdLineDesc [] =
{
     { wxCMD_LINE_SWITCH, _("h"), _("help"), _("displays help on the command line parameters")},
        {wxCMD_LINE_PARAM, NULL, NULL,_("save file"), wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL},

     { wxCMD_LINE_NONE }
};

#endif // MAIN_H_INCLUDED
