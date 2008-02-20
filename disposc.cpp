#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include "disposc.h" // class's header file




void DispOsc::draw(){
 draw(x(),y(),w(),h());
}


void DispOsc::draw(int xx, int yy, int ww, int hh){
     fl_color(_TextColour);
	 fl_font(FL_HELVETICA_BOLD,11);
     fl_draw(ccanal,xx+10,yy+15);
     fl_draw(cv_div,xx+40,yy+15);
     fl_draw(cacople,xx+90,yy+15);
     fl_draw(ct_div,xx+10,yy+310);
     fl_draw(ctrigger,xx+80,yy+310);
}



// class constructor
DispOsc::DispOsc(int X, int Y, int W, int H, const char *l):Fl_Widget(X,Y,W,H,l){                      
         x(X);y(Y);
         TextColour(Fl_Color(84));
         strcpy(ccanal,"    ");
         strcpy(cv_div,"      ");
         strcpy(cacople,"    ");
         strcpy(ct_div,"      ");
         strcpy(ctrigger,"      ");
}


// class destructor
DispOsc::~DispOsc(){
	// insert your code here
}
