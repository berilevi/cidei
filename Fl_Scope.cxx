#ifndef Fl_Scope_Version
#define Fl_Scope_Version "V0.0.2"
#define DEBUG 0

/******************************************************************************
*                      Fl_Scope.cxx
*
* A simple widget that simulates an oscilloscope type trace.
* Input is 8 bit.
* Data starts from left and moves right, then starts scrolling.
* The buffer is teh same as the width of the widget.
*
* Use ->add(unsigned char); to add next data point to the scope.
* 
* Author: Michael Pearce <mike@slavelighting.com>
*
* Started: 18 March 2003
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
********************************************************************************
*                  Version Information
********************************************************************************
* V0.1.0 - 14 February 2005
* Lots of changes:
*  Different Redraw modes added
*  Uses signed int for data
*  Has signed and unsigned display modes
********************************************************************************
* V0.0.2 - 6 August 2003
* Moved x(int) etc to  protected. 
********************************************************************************
* V0.0.1 - 4 August 2003
*  Work on the drawing functions.... seems to keep a blank!
********************************************************************************
* V0.0.0 - 1 August 2003
*  Modified for use with Makefile.
*  Added Version() function to return code version.
********************************************************************************
* V0.0.0 - 1 October 2007
*  Modified for use with two channels.
*  Overload the function Add
********************************************************************************
* V0.0.0 - 12 December 2007
*  Change the comments language into spanish
*******************************************************************************/


#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include "Fl_Scope.h"
#include <stdlib.h>
#include <stdio.h>

void Fl_Scope::draw(){
 draw(x(),y(),w(),h());
}

/******************************************************************************
* Fl_Scope::draw: Grafica los datos que se le envian a la clase con el metodo add. 
*       Si el tipo de grafica es FL_SCOPE_LINE la grafica se realiza a partir de 
*       dos pares ordenados (x1, y1), (x2, y2) entre los que se traza una linea.
*       El valor de y1 y y2 es apuntado por Ptr y Ptr2 respectivamente del arreglo 
*       ScopeData. 
*       Las coordenadas x1 y x2 de la grafica salen a partir del valor del 
*       parametro xx que es la posicion horizontal de la pantalla. 
*       Si el osciloscopio está graficando los dos canales se usan los apuntadores
*       ptrjp y ptrjp2 para apuntar al arreglo con los datos para el canal 2. 
*       
* bdual: Si vale 1 indica que los datos que se van a graficar corresponden a 
*        operaciones de suma o resta de los datos de los 2 canales o para graficar 
*        figuras de lissajous.
*        Si vale 0 indica que se van a graficar los datos independientes de cada 
*        canal.
*        
*
*******************************************************************************/
void Fl_Scope::draw(int xx, int yy, int ww, int hh){
     
 int *Ptr;                                                      /* Apuntador auxiliar a y1 para graficar los datos del canal 1 */
 int *Ptr2;                                                     /* Apuntador auxiliar a y2 para graficar los datos del canal 1 */
 int *ptrjp;                                                    /* Apuntador auxiliar a y1 para graficar los datos del canal 2*/
 int *ptrjp2;                                                   /* Apuntador auxiliar a y2 para graficar los datos del canal 2*/
 int count;
 int Yval,Yval2;
 int valor_y;
 
 fl_push_clip(xx,yy,ww-1,hh);                                     /* Establece el área de la gráfica */
 fl_draw_box(FL_DOWN_BOX,xx,yy,ww,hh,_BackColour);              /* Dibujo del Cuadro de grafica Screen */
 
 fl_color( FL_WHITE);                                           /* Ajustar el color para dibujar las divisiones del Screen*/
 fl_line_style(FL_DOT);                                         /* Tipo de linea punteada para las divisones del screen*/

 fl_line_style(0);                                              /* Retornar al tipo de linea continuo*/
 fl_color(_TraceColour);                                        /* Retornar al color de linea para las graficas del osciloscopio*/

 Ptr2=Ptr=ScopeData;                                            /* Inicializar los apuntadores al inicio del arreglo dinamico del canal 1*/
 Ptr2++;                                                        /* Apuntar al segundo dato del arreglo dinamico del canal 1*/
 
 ptrjp2=ptrjp=ScopeData2;                                       /* Inicializar los apuntadores al inicio del arreglo dinamico del canal 2*/ 
 ptrjp2++;                                                      /* Apuntar al segundo dato del arreglo dinamico del canal 2*/

 
 if (bdual== 0){                                                /* Si el osciloscopio no esta en modo dual*/
    for(count=0;count<ScopeDataSize-1;count++){                 /* Ciclo para recorrer los arreglos dinamicos y graficarlos*/
       switch(LineType){
             default:
             case FL_SCOPE_LINE:  
                  if(DataType==FL_SCOPE_UNSIGNED){ 
                     if (bch1== 1 && bch2== 1){
                        fl_color( FL_YELLOW);                                                      
                        fl_line(xx+ipos_x,(yy+hh) - (int)((float)*Ptr * ((float)hh/65535.0)),xx+4+ipos_x,(yy+hh) - (int)((float)*Ptr2 * ((float)hh/65535.0)));
                        fl_color( FL_GREEN);
                        fl_line(xx+ipos_x,(yy+hh) - (int)((float)*ptrjp * ((float)hh/65535.0)),xx+4+ipos_x,(yy+hh) - (int)((float)*ptrjp2 * ((float)hh/65535.0)));
                        xx= xx+4;
                     }                                                    
                     else if (bch1== 1 && bch2 == 0){
                          fl_color( FL_YELLOW);
                          fl_line(xx+ipos_x,(yy+hh) - (int)((float)*Ptr * ((float)hh/65535.0)),xx+4+ipos_x,(yy+hh) - (int)((float)*Ptr2 * ((float)hh/65535.0))); 
                          xx= xx+4;
                     }
                     else if (bch2 == 1 && bch1== 0){
                          fl_color( FL_GREEN);
                          fl_line(xx+ipos_x,(yy+hh) - (int)((float)*ptrjp * ((float)hh/65535.0)),xx+4+ipos_x,(yy+hh) - (int)((float)*ptrjp2 * ((float)hh/65535.0))); 
                          xx= xx+4;
                     }
                     else{
                          if (banalizador == 1){
                             fl_color(_TraceColour);
                             if (xx < 419+ipos_x){
                                fl_line(xx-ipos_x,(yy+hh) - (int)((float)*Ptr * ((float)hh/65535.0)),xx-ipos_x,(yy+hh) - (int)((float)*Ptr2 * ((float)hh/65535.0)));  
                                xx++;
                             }
                          }
                     }  
                  }
                  else{
                       Yval=(int) (  (float)((int)*Ptr) * (float)hh/(65535.0/2.0));
                       Yval2=(int) (  (float)((int)*Ptr2) * (float)hh/(65535.0/2.0));
                  }
             break;
             case FL_SCOPE_DOT:
                  if(DataType==FL_SCOPE_UNSIGNED){
                     fl_point(xx,(yy+hh) - (int)((float)*Ptr * ((float)hh/65535.0)) );
                  }
                  else{
                       Yval=(int) (  (float)((int)*Ptr) * (float)hh/(65535.0/2.0));
                       fl_point(xx,(yy+(hh/2)) - Yval);
                  }
             break;  
      }
   
      Ptr2++;                                                    /* Se incrementa en 1 la direccion de los apuntadores*/
      Ptr++;
      ptrjp2++;
      ptrjp++;
      
      fl_color(_TraceColour);  
    }
}

else if (bdual==1){                                              /* Si el oscilocpio esta en modo de operación dual*/
   if (ivez >0){                                                 /* Para que se grafique despues de la primera operacion entre los datos de las señales*/
      for(count=0;count<ScopeDataSize-1;count++){
          if (blissajous == 1){
             fl_color(FL_RED);
             fl_line((xx+ww)-(int)((float)*Ptr*((float)ww/65535.0)), (yy+hh) - (int)((float)*ptrjp * ((float)hh/65535.0)), 
                     (xx+ww)-(int)((float)*Ptr2*((float)ww/65535.0)),(yy+hh) - (int)((float)*ptrjp2 * ((float)hh/65535.0))); 
          }
          else{
               fl_color(_TraceColour);
               fl_line(xx+ipos_x,(yy+hh) - (int)((float)*Ptr * ((float)hh/65535.0)),xx+1+ipos_x,(yy+hh) - (int)((float)*Ptr2 * ((float)hh/65535.0))); 
               xx++;
          }

          Ptr2++;                                                /* Incrementar en 1 la direccion de los apuntadores*/
          Ptr++;
          ptrjp2++;
          ptrjp++;
      }
   }
}
 
   /* pop the clip */
   fl_pop_clip();                                                 /* Cerrar el area donde se va a graficar*/
}



/*******************************************************************************
*   Fl_Scope::Add: Adiciona un dato al arreglo dinámico que contiene los datos
*             que se van a graficar.
*   TraceType: Los datos de las señales se adicionan al arreglo dependiendo como 
*              el usuario desea que se genere la gráfica:
*   FL_SCOPE_TRACE_SCROLL: Los datos se corren a la izquierda del arreglo y 
*                          luego se adicionan los otros al final. 
*   FL_SCOPE_TRACE_LOOP_CLEAR: Cuando el arreglo se encuentra completo, se limpia
*                              y se vuelven a adicionar los datos al comienzo.
*   FL_SCOPE_TRACE_LOOP: Los datos se adicionan al arreglo y cuando éste esta 
*                        completo se vuelven a insertar desde el comienzo.
*   ScopeDataPos: Posición en el eje x donde se deben graficar los datos que se
*                 han alamacenado en el arreglo dinámico 
*   RedrawMode: Representa la forma en que se refresacan las gráficas de los datos 
*   FL_SCOPE_REDRAW_OFF: Nunca refresca la gráfica.
*   FL_SCOPE_REDRAW_FULL: Refresca la gráfica cuando se ha completado el trazo 
*                         completo de toda la pantalla. 
*   FL_SCOPE_REDRAW_ALWAYS: Refresca la gráfica cada vez que se adiciona un dato
*    
*******************************************************************************/

int Fl_Scope::Add(int data){

 int *Ptr;                                                     /* Apuntador auxiliar para adicionar los datos al arreglo*/
 int *Ptr2;                                                    /* Apuntador auxiliar para adicionar los datos al arreglo*/
 int count;                                                    /* Contador auxiliar para recorrer los arreglos*/
 
 if(ScopeDataPos > ScopeDataSize){                             /* Solo recorrer el arreglo hasta el tamaño de la pantalla*/
    ScopeDataPos=0;
 }
 
 switch(TraceType)  
                                            /* Adicionar los datos al arreglo dependiendo el tipo de grafica*/
 {
   default:
   case FL_SCOPE_TRACE_SCROLL:
        Ptr=Ptr2=ScopeData;
        Ptr2++;
        for(count=0;count<ScopeDataSize;count++){
           *Ptr=*Ptr2;
           Ptr++;Ptr2++;
        }
        *Ptr=data;
   break;
   case FL_SCOPE_TRACE_LOOP_CLEAR:
        if(ScopeDataPos==0) {
           Ptr=ScopeData;
           for(count=0;count<=ScopeDataSize;count++){
              *Ptr=0;
              Ptr++;
           }
        }
   break;  
   case FL_SCOPE_TRACE_LOOP:
        Ptr=ScopeData;
        Ptr+=ScopeDataPos;
        *Ptr=data;
        break;
 }
 
 ScopeDataPos++;                                               /* Incrementar el dato hasta donde se va a graficar*/
 
 switch(RedrawMode) {                                          /* Forma de refresco de la gráfica en la pantalla*/                    
       case FL_SCOPE_REDRAW_OFF:
       break;
       case FL_SCOPE_REDRAW_FULL:
            if(ScopeDataPos == ScopeDataSize) redraw();
       break;
       default:
       case FL_SCOPE_REDRAW_ALWAYS:
            redraw();
       break;
 }
 return(1); 
}

/*******************************************************************************
* Fl_Scope::Add Overload: Adiciona datos para ser graficados a 2 arreglos 
*               dinamicos cuando el osciloscopio tiene activos los dos canales. 
*               Es una sobrecarga del método Fl_Scope::Add.
*******************************************************************************/

int Fl_Scope::Add(int data, int data2){

    int *Ptr;
    int *ptrjp;    

    if (ScopeDataPos > ScopeDataSize){
       ScopeDataPos = 0;
    } 

    Ptr = ScopeData;
    Ptr += ScopeDataPos;
    *Ptr = data;
   
    ptrjp = ScopeData2;
    ptrjp+=ScopeDataPos;
    *ptrjp=data2;

    ScopeDataPos++;
    ivez++;
       
    redraw(); 

    return(1);   
}

/*******************************************************************************
*                   handle(int)
*      Entry point for the event handling
*******************************************************************************/
int Fl_Scope::handle(int event)
{
  if (event == FL_PUSH && Fl::visible_focus()) Fl::focus(this);

  return handle(event,
    x()+Fl::box_dx(box()),
    y()+Fl::box_dy(box()),
    w()-Fl::box_dw(box()),
    h()-Fl::box_dh(box()));

}
/*******************************************************************************
*                   handle(int,int,int,int,int)
*
*              Sort out what handles need to be done!!
*******************************************************************************/
int Fl_Scope::handle(int event, int X, int Y, int W, int H)
{

 /* Check for Misc Things */
 switch (event)
 {
  case FL_PUSH:
   if (!Fl::event_inside(X, Y, W, H)) return 0;
   //handle_push();

  case FL_DRAG:
   return 0;

  case FL_RELEASE:
     //handle_release();
    return 0;

  case FL_KEYBOARD :
    switch (Fl::event_key())
    {
      case FL_Up:
       //return 1;
      case FL_Down:
       //return 1;
      case FL_Left:
       //return 1;
      case FL_Right:
        //return 1;
      default:
        return 0;
    }
    // break not required because of switch...
  case FL_FOCUS :
  case FL_UNFOCUS :
    if (Fl::visible_focus())
    {
      redraw();
      return 1;
    } else return 0;

  case FL_ENTER :
  case FL_LEAVE :
    //return 1;
  default:
    return 0;
  }
}



/*******************************************************************************
*                         Fl_Scope::Fl_Scope
*******************************************************************************/
Fl_Scope::Fl_Scope(int X, int Y, int W, int H, const char *l):Fl_Widget(X,Y,W,H,l){

 int *Ptr;
 int *ptrjp;     
 int count;
 
 x(X);y(Y);w(W);h(H);                                  /* Tamaño del Screen*/
 box(FL_DOWN_BOX);                                     /* Tipo de bordes del Screen*/
 BackColour(Fl_Color(0));                              /* Color de fondo Negro*/
 TextColour(Fl_Color(0));                              /* Color de texto Negro*/
 TraceColour(FL_YELLOW);                                /* Color de grafica Blanco*/
 TraceColour2(FL_GREEN);                                /* Color de grafica Verde*/
 
 Ptr=ScopeData=(int*)calloc(W,sizeof(int));            /* Crear el arreglo de datos para graficar canal 1*/
 ptrjp=ScopeData2=(int*)calloc(W,sizeof(int));         /* Crear el arreglo de datos para graficar canal 2*/
  
 ScopeDataSize=W-1;                                    /* Inicialización de las variables y métodos de la clase*/                                    

 ScopeDataPos=0;
 
 bdual = 0;
 
 blissajous = 0;
 
 bch1 = 0;
 
 bch1 = 0;
 
 banalizador = 0; 
  
 ivez = 0;
 
 ipos_x = 0;
 
 ipos_muestra = 25;
 
                           /*Configuraciones por defecto de la clase*/
                           
 
 tracetype(FL_SCOPE_TRACE_SCROLL);                     /* Tipo de almacenamiento de los datos en los arreglos*/

 redrawmode(FL_SCOPE_REDRAW_ALWAYS);                   /* Tipo de refresco de la gráfica*/
 
 linetype(FL_SCOPE_LINE);                              /* Tipo de linea con la que se grafica*/
 
 datatype(FL_SCOPE_UNSIGNED);                          
 
 for(count=0;count<W;count++){                          /* Inicialización en cero de los arreglos dinamicos */
    *Ptr=0;
    Ptr++;
    *ptrjp=0; 
    ptrjp++; 
 }

}

/*******************************************************************************
*               Fl_Scope::~Fl_Scope
*******************************************************************************/
Fl_Scope::~Fl_Scope(){
 free(ScopeData);                                        /* Liberar la memoria de los arreglos*/
 free(ScopeData2);
}


/*************** END OF FILE **************************************************/
#endif



