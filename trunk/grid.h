// Class automatically generated by Dev-C++ New Class wizard

#ifndef GRID_H
#define GRID_H

#include "fl_scope.h" // inheriting class's header file

// No description
class grid : public Fl_Scope
{
	public:
   
		// class constructor
		grid(int,int,int,int,const char * = 0);
		// class destructor
		~grid();
		// activar grilla o ejes
		bool bgrid;
		
protected:

  void draw(int,int,int,int);
  void draw();	
		
};

#endif // GRID_H