// Class automatically generated by Dev-C++ New Class wizard


#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include "mensajes.h" // class's header file


void Mensajes::draw(){
 draw(x(),y(),w(),h());
}


void Mensajes::draw(int xx, int yy, int ww, int hh){
     
     float fpos = inum_muestras/2;
     fl_color(_TextColour);
	 fl_font(FL_HELVETICA,10);
	 for (int i=0;i<inum_muestras;i++){
         itoa((i+inum_inicial),text,10);
         if (i+inum_inicial > 9)
            fl_draw(text,(fpos+(inum_muestras*i)+(xx-6)),yy);
         else
            fl_draw(text,(fpos+(inum_muestras*i)+(xx-3)),yy);
     }
}


// class constructor
Mensajes::Mensajes(int X, int Y, int W, int H, const char *l):Fl_Widget(X,Y,W,H,l){                      
     x(X);y(Y);
     TextColour(Fl_Color(0));
     strcpy(text,"   ");
     inum_muestras = 20;
     inum_inicial = 0;
}


// class destructor
Mensajes::~Mensajes(){
	// insert your code here
}
