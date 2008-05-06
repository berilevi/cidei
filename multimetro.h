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
#include <FL/Fl_Help_Dialog.h>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Check_Button.H>
#include <iostream>
#include <string>


#include <FL/Fl_Box.H>

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
        //Fl_Help_Dialog *manualMult;      
		//Variable que almacena el valor entero de la medicion realizada con el hardware
		long int ivalorConversion;
		//Variable que almacena el valor ye escalado que se presentar� al usuario.
        double fvalorEscalado;
		//Variable representa el valor de la medici�n realizada con algun instrumento del mult�metro
		char cvalor[7];
		//Display del mult�metro donde el usuario observa el resultado de la medici�n.
		Fl_7Seg *odispMult;
		// M�todo para colocar el valor de la medici�n en el display.
		void setDispMult(char [4]);
		//Agrupa los botones e indicadores del mult�metro.
	    Fl_Group *ogroup_mult;
		// class constructor
		Multimetro();
		// class destructor
		~Multimetro();
		//Callback del bot�n de encendido / apagado del mult�metro.
		static void cbMultOn(Fl_Widget*, void *);
		inline void cbMultOnIn();
		
private:
        //Callback del timer para realizar la solicitud de datos del mult�metro al hardware.
         static void cbTimerMult(void *);
         inline void cbTimerMultIn();
         //Callback del bot�n que activa la ayuda del instrumento. 
         static void cbHelpMult(Fl_Widget*, void *);
         inline void cbHelpMultIn();
         //Callback del bot�n que activa la ayuda flotante de los botones del instrumento.
         static void cbAyudaMult(Fl_Widget*, void *);
         inline void cbAyudaMultIn(); 
         //Envia la informaci�n al hardware para configurar cada instrumento del multimetro.
         void configInstrumento(int);
         //Calcula el valor de la medici�n en el rango de escala en que se encuentre.
         void escalarValor(int);
		//Varaible que representa los instrumentos que contiene el mult�metro.
		inst instrument;
		// Boton que habilita la ayuda para el uso del instrumento.
        Fl_Button *ohelpMult;
        //Bot�n que habilita la ayuda flotante para el uso de los botones del instrumento. 
        Fl_Check_Button *oayudaMult;
		//Bot�n de activaci�n del medidor de voltaje en ac.
		Fl_Button *ovoltAc;
		//
		Fl_Box *boxVac;
		//Bot�n de activaci�n del medidor de voltaje en dc.
	    Fl_Button *ovoltDc;
	    //Bot�n de activaci�n del medidor de corriente en ac.
	    Fl_Button *oampAc;
	    //Bot�n de activaci�n del medidor de corriente en dc.
	    Fl_Button *oampDc;
	    //Bot�n de activaci�n del medidor de resistencia.
	    Fl_Button *oohm;
	    //Bot�n de activaci�n del medidor de continuidad.
	    Fl_Button *ocontinuidad;
	    //Callback del bot�n que activa el medidor de voltaje en ac.
        static void cbVoltAc(Fl_Widget*, void *);
        inline void cbVoltAcIn();
        //Callback del bot�n que activa el medidor de voltaje en dc.
        static void cbVoltDc(Fl_Widget*, void *);
        inline void cbVoltDcIn();
        //Callback del bot�n que activa el medidor de corriente en ac.
        static void cbAmpAc(Fl_Widget*, void *);
        inline void cbAmpAcIn();
        //Callback del bot�n que activa el medidor de corriente en dc.
        static void cbAmpDc(Fl_Widget*, void *);
        inline void cbAmpDcIn();
        //Callback del bot�n que activa el medidor de resistencia 
        static void cbOhm(Fl_Widget*, void *);
        inline void cbOhmIn();
        //Callback del bot�n que activa el medidor de continuidad
        static void cbCont(Fl_Widget*, void *);
        inline void cbContIn();
	    //Boton para encender el instrumento multimetro.
        Fl_Light_Button *omultOn;
        // Widget para colocar en texto las unidades de medida de la medici�n realizada con el mult�metro.
        Fl_Box *ounidades;
};

#endif // MULTIMETRO_H
