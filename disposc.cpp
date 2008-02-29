#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include "disposc.h" // class's header file

/*******************************************************************************
* Mensajes::draw(): M�todo heredado para graficar.
* Se debe sobrecargar este m�todo para modificarlo ya que es heredado de la 
* clase FL_WIDGET.
* Solamente se env�an como parametro al m�todo sobrecargado la posici�n y tama�o
* de los gr�ficos.
*******************************************************************************/
void DispOsc::draw(){
 draw(x(),y(),w(),h());
}

/*******************************************************************************
* DispOsc::draw(int,int,int,int): Sobrecarga del m�todo draw() para graficar los
*                                 mensajes de la configuraci�n del instrumento 
*                                 osciloscopio en la pantalla.
* Se grafica en la pantalla del osciloscopio la siguiente informaci�n de la con-
* figuraci�n del instrumento y de cada uno de los canales:
* - ccanal: Nombre del canal "Chx" x = 1 � 2.
* - cv_div: Escala de voltios por divisi�n configurada del canal "xxV/Dv".
* - cacople: Acople configurado para el canal: "AC", "DC", "GND".
* - ct_div: Escala de tiempo por divisi�n configurada: "xxS/Dv".
* - ctrigger: Canal configurado como fuente del trigger: "Trg-Chx" x = 1 � 2.
* La informaci�n que solo tiene que ver con el canal especifico, se grafica en 
* la parte superior de la pantalla:
* - Canal 1: Cuarto superior izquierdo.
* - Canal 2: Cuarto superior derecho.
* La informaci�n de la configuraci�n del instrumento que no tiene que ver solo 
* con los canales, se grafica en la parte superior de la pantalla:
* ct_div y ctrigger.
*******************************************************************************/
void DispOsc::draw(int xx, int yy, int ww, int hh){
     fl_color(_TextColour);
	 fl_font(FL_HELVETICA_BOLD,12);
     fl_draw(ccanal,xx+10,yy+15);
     fl_draw(cv_div,xx+40,yy+15);
     fl_draw(cacople,xx+90,yy+15);
     fl_draw(ct_div,xx+10,yy+310);
     fl_draw(ctrigger,xx+80,yy+310);
}


/*******************************************************************************
* DispOsc::DispOsc: Constructor de la clase DispOsc.
* Grafica mensajes en la pantalla del osciloscopio relacionados con la configu-
* raci�n del instrumento.
* Se inicializan el color y las cadenas de caracteres que contienen lo que se 
* va a graficar. 
*******************************************************************************/
DispOsc::DispOsc(int X, int Y, int W, int H, const char *l):Fl_Widget(X,Y,W,H,l){                      
         x(X);y(Y);
         TextColour(Fl_Color(84));
         strcpy(ccanal,"    ");
         strcpy(cv_div,"      ");
         strcpy(cacople,"    ");
         strcpy(ct_div,"      ");
         strcpy(ctrigger,"      ");
}


/******************************************************************************* 
* DispOsc::~DispOsc: Destructor de la clase
*******************************************************************************/
DispOsc::~DispOsc(){
	
}
