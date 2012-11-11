#ifndef MCTFRAME_H_INCLUDED
#define MCTFRAME_H_INCLUDED
#include "Libs.h"

class MCTFrame;
typedef enum{
    DESTROY,
    RES,
    IND,
    COM,
    EXIT,
    MAIN,
    MROAD,
    PRINT

} MCTEvent;


class Panel: public wxPanel
{
    public:
    Panel(wxFrame* frame);
            void Renderizar(wxDC& dc);
            void Cargar(wxDC& dc);
        void Paint(wxPaintEvent& event);
        void Motion(wxMouseEvent& event);
        void Tecla(wxKeyEvent& event);
        void Guardar(wxString path);
        void CargarMCT(wxString path);
        int GetCasilla(int a,int b);
        private:
        MCTEvent screen;
        long int money;


};


class MCTFrame: public wxFrame
{
    public:
        MCTFrame(wxFrame *frame, const wxString& title);
        ~MCTFrame();
    private:
        enum
        {
            idMenuQuit = 1000,
            idMenuAbout,
            ID_CARGAR,
            ID_NUEVO
        };
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void Cargar(wxCommandEvent& event);
        void Nuevo(wxCommandEvent& event);
        bool ComprobarArchivos();

        DECLARE_EVENT_TABLE()

};



#endif
