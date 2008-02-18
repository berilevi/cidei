// Class automatically generated by Dev-C++ New Class wizard

#ifndef MULTIMETRO_H
#define MULTIMETRO_H

#include "instrumento.h" // inheriting class's header file
#include "Fl_7Seg.H"     // inheriting class's header file
#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <Fl/fl_Light_Button.h>
#include <FL/Fl_Repeat_Button.H>
#include <FL/Fl_Help_Dialog.h>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>
#include <iostream>
#include <string>

#include <windows.h> 


#define FACTOR_VDC_1 2560
#define FACTOR_VDC_2 256
#define FACTOR_VDC_3 25,6
#define FACTOR_VDC_4 2,56
#define FACTOR_VDC_5 0,256


using namespace std;

/*******************************************************************************
 * Mult�metro: Clase que representa las funciones del instrumento mult�metro con
 *             6 tipos de medici�n:
 * Volt�metro AC: Mide la magnitud de voltaje True RMS de una se�al alterna.
 * Volt�metro DC: Mide la magnitud de voltaje de una se�al continua.
 * Amper�metro AC: Mide la magnitud de corriente de una se�al alterna.
 * Amper�metro DC: Mide la magnitud de corriente de una se�al continua. 
 * Resistencia: Mide la magnitud de resistencia el�ctrica.
 * Continuidad: Reviza la continuidad el�ctrica.             
*******************************************************************************/
class Multimetro : public Instrumento
{
	public:
        // Variable enumerada con los 6 instrumentos que hacen parte del mult�imetro   
        enum inst {
             volt_ac,
             volt_dc,
             amp_ac, 
             amp_dc,
             ohm,
             continuidad
        };   
		//Ventana de ayuda de uso del instrumento.
        Fl_Help_Dialog *Manual;        
		//Variable que almacena el valor entero de la medicion realizada con el hardware  
		long int ivalor_conversion;
		//Variable que almacena el valor ye escalado que se presentar� al usuario.
        double fvalor_escalado;
		//Variable representa el valor de la medici�n realizada con algun instrumento del mult�metro
		char cvalor[7];
		//Display del mult�metro donde el usuario observa el resultado de la medici�n.
		Fl_7Seg *odisp_mult;
		// M�todo para colocar el valor de la medici�n en el display.
		void set_disp_mult(char [4]);
		//Agrupa los botones e indicadores del mult�metro.
	    Fl_Group *ogroup_mult;
		// class constructor
		Multimetro();
		// class destructor
		~Multimetro();
		//Callback del bot�n de encendido / apagado del mult�metro.
		static void cb_mult_on(Fl_Widget*, void *);
		inline void cb_mult_on_in();
		
private:
        //Callback del timer para realizar la solicitud de datos del mult�metro al hardware.    
         static void cb_timer_mult(void *);
         inline void cb_timer_mult_in();
         //Callback del bot�n que activa la ayuda del instrumento. 
         static void cb_help(Fl_Widget*, void *);
         inline void cb_help_in();
         //Envia la informaci�n al hardware para configurar cada instrumento del multimetro.
         void config_instrumento(int);
         //Calcula el valor de la medici�n en el rango de escala en que se encuentre.
         void escalar_valor(int);
		//Varaible que representa los instrumentos que contiene el mult�metro.
		inst instrument;
		// Boton que habilita la ayuda para el uso del instrumento.
        Fl_Button *ohelp_mult;
		//Bot�n de activaci�n del medidor de voltaje en ac.
		Fl_Button *ovolt_ac;
		//Bot�n de activaci�n del medidor de voltaje en dc.
	    Fl_Button *ovolt_dc;
	    //Bot�n de activaci�n del medidor de corriente en ac.
	    Fl_Button *oamp_ac;
	    //Bot�n de activaci�n del medidor de corriente en dc.
	    Fl_Button *oamp_dc;
	    //Bot�n de activaci�n del medidor de resistencia.
	    Fl_Button *oohm;
	    //Bot�n de activaci�n del medidor de continuidad.
	    Fl_Button *ocontinuidad;
	    //Callback del bot�n que activa el medidor de voltaje en ac.
        static void cb_volt_ac(Fl_Widget*, void *);
        inline void cb_volt_ac_in();
        //Callback del bot�n que activa el medidor de voltaje en dc.   
        static void cb_volt_dc(Fl_Widget*, void *);
        inline void cb_volt_dc_in();
        //Callback del bot�n que activa el medidor de corriente en ac.   
        static void cb_amp_ac(Fl_Widget*, void *);
        inline void cb_amp_ac_in();
        //Callback del bot�n que activa el medidor de corriente en dc.   
        static void cb_amp_dc(Fl_Widget*, void *);
        inline void cb_amp_dc_in();
        //Callback del bot�n que activa el medidor de resistencia   
        static void cb_ohm(Fl_Widget*, void *);
        inline void cb_ohm_in();
        //Callback del bot�n que activa el medidor de continuidad    
        static void cb_cont(Fl_Widget*, void *);
        inline void cb_cont_in();
	    //Boton para encender el instrumento multimetro.
        Fl_Light_Button *omult_on;
        // Widget para colocar en texto las unidades de medida de la medici�n realizada con el mult�metro.
        Fl_Box *ounidades;
};

#endif // MULTIMETRO_H
