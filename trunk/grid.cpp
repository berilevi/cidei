// Class automatically generated by Dev-C++ New Class wizard

#include "grid.h" // class's header file
#include <FL/Fl.H>
#include <FL/fl_draw.H>

// class constructor
grid::grid(int X,int Y,int W,int H,const char *l): Fl_Scope(X,Y,W,H,l){
               
	x(X);y(Y);w(W);h(H);
    bgrid = 0; 
}


void grid::draw(){
 draw(x(),y(),w(),h());
}

void grid::draw(int xx, int yy, int ww, int hh){
    
   fl_push_clip(12,12,391,315); 
    
   fl_color(FL_WHITE);  
   fl_line_style(FL_DOT);
   
   if (bgrid){
   
   
      fl_line(12, 50, 391, 50);
      fl_line(12, 88, 391, 88);
      fl_line(12, 126, 391, 126);
      fl_line_style(0);
      fl_line(12, 164, 391, 164);
      fl_line_style(FL_DOT);
      fl_line(12, 202, 391, 202);
      fl_line(12, 240, 391, 240);
      fl_line(12, 278, 391, 278);
   
   
      fl_line(50, 12, 50, 315);
      fl_line(88, 12, 88, 315);
      fl_line(126, 12, 126, 315);
      fl_line(164, 12, 164, 315);
      fl_line_style(0);
      fl_line(202, 12, 202, 315);
      fl_line_style(FL_DOT);
      fl_line(240, 12, 240, 315);
      fl_line(278, 12, 278, 315);
      fl_line(316, 12, 316, 315);
      fl_line(354, 12, 354, 315);
   }
   
   else {
        fl_line_style(0);
        fl_line(202, 12, 202, 315);
        fl_line(12, 164, 391, 164);
   }
     
   fl_pop_clip();      
        
}

// class destructor
grid::~grid()
{
	// insert your code here
}
