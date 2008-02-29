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



/*******************************************************************************
* DispOsc: Clase para graficar en la pantalla del osciloscopio los valores de
*          configuraci�n de los canales y del instrumento.
* Se grafican carcateres con la informacion que est� configurada en el instru-
* mento osciloscopio dentro de la pantalla.
*******************************************************************************/
class DispOsc : public Fl_Widget{
      
      // Posicion del Texto 
      int _x,_y;      
      // Color de texto                
      Fl_Color _TextColour;                
      
protected:
          
          // Sobrecarga del m�todo para graficar
          void draw(int,int,int,int);         
          // M�todo heredado para graficar 
          void draw();
          //M�todos para asignar la posici�n de los mensajes graficados
          void x(int X){ _x=X;};
          void y(int Y){ _y=Y;};

public:
       
      // Nombre del canal
      char ccanal[4];                      
      // Escala de voltios por divisi�n
      char cv_div[10];                    
      // Tipo de acople
      char cacople[4];                    
      // Escala de tiempo por divisi�n
      char ct_div[10];                     
      // Canal fuente del trigger
      char ctrigger[7];                   
      // Posicion horizontal del Texto 
      int x(){return _x;};                        
      // Posicion vertical del Texto 
      int y(){return _y;};                        
       //M�todo para asignar el color al texto
       Fl_Color TextColour(){return _TextColour;};
       void     TextColour(Fl_Color c){_TextColour=c;};
	   // class constructor
	   DispOsc(int,int,int,int,const char * = 0);
       // class destructor
	   ~DispOsc();
};

#endif // MENSAJES_H
