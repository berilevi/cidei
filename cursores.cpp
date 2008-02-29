// Class automatically generated by Dev-C++ New Class wizard

#include "cursores.h" // class's header file
#include <FL/Fl.H>
#include <FL/fl_draw.H>

/*******************************************************************************
* Cursores::Cursores: Constructor de la clase Cursores.
*                     Dibuja el cursor del instrumento analizador l�gico para 
*                     se�alar un dato graficado en la pantalla y ver su repre-
*                     sentaci�n en 3  sistemas de nuemraci�n.
* Se inicializan las variables y la posici�n del cursor.
*******************************************************************************/
Cursores::Cursores(int X,int Y,int W,int H,const char *l): Fl_Scope(X,Y,W,H,l){
                       
	x(X);y(Y);w(W);h(H);     //Inicializaci�n de la posici�n del cursor
    bcursor = 0;             //Inicia deshabilitado el cursor
    iposx = 0;               //Posici�n inicial del cursor.
}

/*******************************************************************************
* Cursores::draw(): M�todo heredado para graficar.
* Se debe sobrecargar este m�todo para modificarlo ya que es heredado de la 
* clase FL_SCOPE.
* Solamente se env�an como parametro al m�todo sobrecargado la posici�n y tama�o
* de los gr�ficos.  
*******************************************************************************/
void Cursores::draw(){
 draw(x(),y(),w(),h());
}

/*******************************************************************************
* Cursores::draw(int,int,int,int): Sobrecarga del m�todo draw(), para dibujar el 
*                                  cursor del instrumento analizador l�gico.
* iposx: Valor ajustado por el usuario para posicionar el cursor. 
*******************************************************************************/
void Cursores::draw(int xx, int yy, int ww, int hh){
     fl_push_clip(xx,yy,ww,hh);
     fl_color(FL_YELLOW);                     //Color del cursor
     fl_line(xx+iposx, yy, xx+iposx, hh);     //Dibujar la l�nea
     fl_pop_clip();
}

/*******************************************************************************
* Destructor de clase
*******************************************************************************/ 
Cursores::~Cursores(){
}
