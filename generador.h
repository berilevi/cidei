// Class automatically generated by Dev-C++ New Class wizard

#ifndef GENERADOR_H
#define GENERADOR_H

#include "instrumento.h"                    //Inheriting class's header file
#include <FL/Fl_Group.H>
#include <Fl/fl_Light_Button.h>
#include <Fl/fl_Button.h>
#include <FL/Fl_Repeat_Button.H>
#include "Fl_7Seg.H"                        //Class's header file
#include "fl_Knob.h"
#include <FL/Fl_Counter.H>

/**
 * Clase que representa el funcionamiento del instrumento 
 * generador de se�ales.
 */
class Generador : public Instrumento
{
	public:
		// class constructor
		Generador();
		// class destructor
		~Generador();
	private:
         /**
		 * Agrupa los botones e indicadores del generador de se�ales
	     */
		Fl_Group *ogroup_generador;
		/**
		 * Agrupa los botones para ajustar la frecuencia de la se�al generada
	     */
		Fl_Group *ogroup_frecuencia;
		/**
		 * Agrupa los botones e indicadores para seleccionar la se�al generada
	     */
		Fl_Group *ogroup_senal;
		/**
		 * Agrupa los botones para seleccionar la amplitud y nivel de offset de 
		 * la se�al generada.
	     */
		Fl_Group *ogroup_amplitud;
		/**
		 * Boton para prender el instrumento generador de se�ales
	     */
		Fl_Light_Button *ogen_on;
		/**
		 * Display del generador donde el usuario observa el valor de frecuencia
         * que el usuario configura.
		*/
		Fl_7Seg *odisp_gen;
		/**
		 * Boton que habilita la ayuda al usuario sobre el manejo del instrumento 
		*/
        Fl_Button *ohelp_gen;
        /**
		 * Boton para seleccionar el tipo de se�al que se debe generar con el 
         * instrumento.
		*/
        Fl_Repeat_Button *osel_gen;
        /**
		 * Indicador luminoso de seleccion de generar se�al de tipo  
         * sinusoidal
		*/
        Fl_Light_Button *oseno;
        /**
		 * Indicador luminoso de seleccion de generar se�al de tipo  
         * cuadrada
		*/
        Fl_Light_Button *ocuadrada;
        /**
		 * Indicador luminoso de seleccion de generar se�al de tipo  
         * triangular.
		*/
        Fl_Light_Button *otriangulo;
        /**
		 * Indicador luminoso del valor de la frecuencia en la escala de mili-Hertz  
		*/
        Fl_Light_Button *omHz;
        /**
		 * Indicador luminoso del valor de la frecuencia en la escala de Hertz  
		*/
        Fl_Light_Button *oHz;
        /**
		 * Indicador luminoso del valor de la frecuencia en la escala de Mega-Hertz  
		*/
        Fl_Light_Button *oMeHz;
        /**
		 * Boton de ajuste lineal fino de la frecuencia de la se�al seleccionada  
         * por el ususario.
		*/
        Fl_Knob *ofrec_gen;
        /**
		 * Boton de seleccion de rango de frecuencias de la se�al seleccionada  
         * por el ususario para ajuste grueso.
		*/
        Fl_Counter *oescala_frec;
        /**
		 * Boton de ajuste lineal de la amplitud de la se�al seleccionada  
         * por el ususario.
		*/
        Fl_Knob *oamplitud;
        /**
		 * Boton de ajuste lineal del nivel de offset de la se�al seleccionada  
         * por el ususario.
		*/
        Fl_Knob *ooffset;  
        /**
		 * Este m�todo es el callback del boton de encendido del generador de
         * se�ales.
		 */
		static void cb_generador_on(Fl_Widget*, void *);
		/**
		 * Esta funci�n acompa�a la funci�n  cb_generador_on 
		 * para realizar los llamados de callback del boton de encendido
		 * del generador.
		 */
		inline void cb_generador_on_in();
        
};

#endif // GENERADOR_H
