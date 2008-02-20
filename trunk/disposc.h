// Class automatically generated by Dev-C++ New Class wizard

#ifndef DISPOSC_H
#define DISPOSC_H

#ifndef Fl_Widget_H
#include <FL/Fl_Widget.H>
#include <FL/Fl_Ask.H>

#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;
#endif



// Clase para mostrar mensajes en texto
class DispOsc : public Fl_Widget{
      int       _x,_y;                     /* Posicion del Texto */
      Fl_Color _TextColour;                /* Color de texto */
      

protected:
          
          void draw(int,int,int,int);          /* Metodo para graficar*/
          void draw();
          void x(int X){ _x=X;};
          void y(int Y){ _y=Y;};

public:
       
      char ccanal[4];                      /* Nombre del canal*/
      char cv_div[10];                      /* Escala de voltios por divisi�n*/
      char cacople[4];                     /* Tipo de acople*/
      char ct_div[10];                      /* Escala de tiempo por divisi�n*/
      char ctrigger[7];                    /* Canal fuente del trigger*/
       
       int x(){return _x;};                        /* Posicion horizontal del Texto */

       int y(){return _y;};                        /* Posicion vertical del Texto */
       
       Fl_Color TextColour(){return _TextColour;};
       void     TextColour(Fl_Color c){_TextColour=c;};
       
	   // class constructor
	   DispOsc(int,int,int,int,const char * = 0);
       // class destructor
	   ~DispOsc();
};

#endif // MENSAJES_H
