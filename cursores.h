// Class automatically generated by Dev-C++ New Class wizard

#ifndef CURSORES_H
#define CURSORES_H

#include "fl_scope.h" // inheriting class's header file

// Clase para generar los cursores del instrumento Analizador L�gico
class Cursores : public Fl_Scope
{
	public:
		// class constructor
		Cursores(int,int,int,int,const char * = 0);
		// class destructor
		~Cursores();
		bool bcursor;
		int iposx;
		
   protected:

            void draw(int,int,int,int);
            void draw();
};

#endif // CURSORES_H