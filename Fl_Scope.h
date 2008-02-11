#ifndef Fl_Scope_H
#define Fl_Scope_H
/***********************************************************
*                        Fl_Scope.h
*
* Author: Michael Pearce
*
* Started: 1 August 2003
*
* Copyright: Copyright 2003 Michael Pearce All Rights reserved.
*
* Licence:   GNU/GPL 
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program (GNU.txt); if not, write to the Free Software
* Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
* or visit http://www.gnu.org/licenses/licenses.html

*
************************************************************
*   See Fl_Scope.cxx for Version Information
***********************************************************/

#ifndef Fl_Widget_H
#include <FL/Fl_Widget.H>
#include <FL/Fl_Ask.H>
#include <stdlib.h>
#include <string.h>
#endif


#define FL_SCOPE_TRACE_SCROLL     0
#define FL_SCOPE_TRACE_LOOP       1
#define FL_SCOPE_TRACE_LOOP_CLEAR 2

#define FL_SCOPE_REDRAW_OFF 0
#define FL_SCOPE_REDRAW_FULL 1
#define FL_SCOPE_REDRAW_ALWAYS 2

#define FL_SCOPE_DOT  0
#define FL_SCOPE_LINE 1

#define FL_SCOPE_SIGNED    0
#define FL_SCOPE_UNSIGNED  1

class FL_EXPORT Fl_Scope : public Fl_Widget
{
  int       _x,_y,_w,_h;               /* Posicion y tamaño del Screen */

  
  int ScopeDataPos;                    /* Contador para recorrer los datos que se van a graficar*/
  
  Fl_Color _TraceColour;               /* Color de la traza */
  Fl_Color _TraceColour2;              /* Color de la traza */
  Fl_Color _BackColour;                /* Color de fondo del screen*/
  Fl_Color _TextColour;                /* Color de texto */

  int TraceType;                       /* Modo de colocar los datos de las señales en el screen*/
  int RedrawMode;                      /* Modo de actualizar la grafica de las señales*/
  int LineType;                        /* Tipo de linea con la que se grafican las señales*/
  int DataType;                        /* Tipo de datos que se le envian para graficar*/

  int ivez;                            /* Contador de veces que entra a graficar en modo dual*/
  
protected:

  void draw(int,int,int,int);          /* Metodo para graficar*/

  int handle(int,int,int,int,int);     
    
  void draw();
  
  /* These are protected because changing the size screws up the buffer */

  void x(int X){ _x=X;};
  void y(int Y){ _y=Y;};
  void w(int W){ _w=W;};
  void h(int H){ _h=H;};
  
  
  
public:

  int ScopeDataSize;                           /* Tamaño de los arreglos de datos que se van a graficar*/

  int *ScopeData;                             /* Apuntador al arreglo dinamico del canal 1 */
  
  int *ScopeData2;                            /* Apuntador al arreglo dinamico del canal 2 */     

  bool bdual;                                 /* Variable para saber si se va a graficar en modo dual */
  
  bool blissajous;                            /* Variable para saber si se va a graficar figuras de lissajous*/
  
  bool bch1;                                  /* Variable que indica si el canal 1 del osciloscopio esta activo*/
  
  bool bch2;                                  /* Variable que indica si el canal 2 del osciloscopio esta activo*/
  
  bool banalizador;                           /* Variable que indica si el analizador está activo */
    
  int ipos_x;                                 /* Variable para desplazar la grafica horizontalmente*/
  
  int imuestra;                               /* Número de muestra en el analizador*/
  
  int ipos_muestra;                           /* Posición del número de muestra del analizador*/
  
  int x(){return _x;};                        /* Posicion horizontal del Screen */

  int y(){return _y;};                        /* Posicion vertical del Screen */

  int w(){return _w;};                        /* Ancho del Screen*/ 

  int h(){return _h;};                        /* Altura del Screen*/

  
  int tracetype(){return TraceType;};         
  void tracetype(int t){TraceType=t;};
  
  int redrawmode(){return RedrawMode;};
  void redrawmode(int t){RedrawMode=t;};
  
  int linetype(){return LineType;};
  void linetype(int t){LineType=t;};
  
  
  int datatype(){return DataType;};
  void datatype(int t){DataType=t;};
  

  int Add(int);                               /* Adicionar un dato a la grafica */ 
  
  int Add(int, int);                          /* Adicionar datos cuando se usan los dos canales para graficar */
   
  Fl_Color TraceColour(){return _TraceColour;};
  void     TraceColour(Fl_Color c){_TraceColour=c;};
  
  Fl_Color TraceColour2(){return _TraceColour2;};
  void     TraceColour2(Fl_Color c2){_TraceColour2= c2;};

  Fl_Color BackColour(){return _BackColour;};
  void     BackColour(Fl_Color c){_BackColour=c;};
  
  Fl_Color TextColour(){return _TextColour;};
  void     TextColour(Fl_Color c){_TextColour=c;};

  virtual int handle(int);
  Fl_Scope(int,int,int,int,const char * = 0);
  ~Fl_Scope();
  
};


/**************** END OF FILE ******************************/
#endif

