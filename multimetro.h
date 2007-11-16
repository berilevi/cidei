// Class automatically generated by Dev-C++ New Class wizard

#ifndef MULTIMETRO_H
#define MULTIMETRO_H

#include "instrumento.h" // inheriting class's header file
#include "Fl_7Seg.H"     // inheriting class's header file
//#include "SevenSegment.h"
#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <Fl/fl_Light_Button.h>
#include <FL/Fl_Repeat_Button.H>
#include <FL/fl_ask.H>
#include <iostream>
#include <string>


using namespace std;

/**
 * Esta clase representa las funcionees del instrumento
 * multimetro
 */
class Multimetro : public Instrumento
{
	public:
	enum inst
		{
             volt_ac,
             volt_dc,
             amp_ac, 
             amp_dc,
             ohm,
             continuidad
        };
		/**
		 * Esta variable representa la escala con la que se realizo 
		 * la medicion con algun instrumento del multimetro
	    */
		int iescala;
		/**
		 * Esta variable representa el valor de la medici�n realizada
		 * con algun instrumento del multimetro
		*/
		char cvalor[6];
		/**
		 * Este objeto representa el display del mult�metro 
		 * donde el usuario observa el resultado de la medici�n.
		*/
		Fl_7Seg *odisp_mult;
		/**
		 * Este m�todo coloca el valor de la medici�n en el display
		 * del mult�metro.
		*/
		void set_disp_mult(char [4]);
		 /**
		 * Agrupa los botones e indicadores del multimetro
		 */
	    Fl_Group *ogroup_mult;
	    
		// class constructor
		Multimetro();
		// class destructor
		~Multimetro();
        /**
		 * Este m�todo es el callback del boton selector de instrumentos
		 * en el mult�metro debe ir acompa�ada de una funci�n inline para
         * poder realizar los callbacks. 
		 */
		static void cb_sel_instrumento(Fl_Widget*, void *);
		/**
		 * Esta funci�n acompa�a la funci�n  cb_sel_instrumento 
		 * para realizar los llamados de callback del selector de instrumento
		 * en el multimetro 
		 */
		inline void cb_sel_instrumento_in();
		/**
		 * Este m�todo es el callback del boton de encendido
		 * del mult�metro debe ir acompa�ada de una funci�n inline para
         * poder realizar los callbacks. 
		 */
		static void cb_mult_on(Fl_Widget*, void *);
		/**
		 * Esta funci�n acompa�a la funci�n  cb_mult_on 
		 * para realizar los llamados de callback del boton de encendido
		 * del multimetro 
		 */
		inline void cb_mult_on_in();
		
private:
        /**
         * Este m�todo es el callback del timer para realizar la solicitud 
         * de datos del mult�metro al hardware.  
         */   
         static void cb_timer_mult(void *);
         /**
         * Esta funci�n acompa�a la funci�n cb_timer_mult
         * para realizar los llamados de callback del timer 
         */
         inline void cb_timer_mult_in();
		/**
		 * Esta varaible representa los instrumentos que contiene
		 * el multimetro
		 */
		inst instrument;
		/**
		 * Este indicador luminoso indica que est� activado el volt�metro
		 * de corriente alterna
		 */
		Fl_Light_Button *ov_ac; 
		/**
		 * Este indicador luminoso indica que est� activado el volt�metro
		 * de corriente continua
		 */
	    Fl_Light_Button *ov_dc;
	    /**
		 * Este indicador luminoso indica que est� activado el amper�metro
		 * de corriente alterna
		 */
	    Fl_Light_Button *oa_ac;
	    /**
		 * Este indicador luminoso indica que est� activado el amper�metro
		 * de corriente continua
		 */
	    Fl_Light_Button *oa_dc;
	    /**
		 * Este indicador luminoso indica que est� activado el ohmetro
		 * 
		 */
	    Fl_Light_Button *oohmetro;
	    /**
		 * Este indicador luminoso indica que est� activado el medidor
		 * de continuidad
		 */
	    Fl_Light_Button *ocont;
};

#endif // MULTIMETRO_H
