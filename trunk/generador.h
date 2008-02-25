// Class automatically generated by Dev-C++ New Class wizard

#ifndef GENERADOR_H
#define GENERADOR_H

#include "instrumento.h"                    //Inheriting class's header file
#include <FL/Fl_Group.H>
#include <Fl/fl_Light_Button.h>
#include <Fl/fl_Button.h>
#include <FL/Fl_Box.H>
#include <FL/Fl_Repeat_Button.H>
#include "Fl_7Seg.H"                        //Class's header file
#include "fl_Knob.h"
#include <FL/Fl_Counter.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Box.H>
#include <math.h>

/*******************************************************************************
 * Generador: Clase que representa el funcionamiento del instrumento generador 
 *            de se�ales.
 * El instrumento genera 3 clases de se�ales: Seno, Cuadrada y Tri�ngulo.
 * De cada una de las se�ales mensionadas se puede controlar la frecuencia, la           
 * amplitud y el nivel dc (offset).
 * El instrumento cuenta con un display donde se ver� la frecuencia configurada.
*******************************************************************************/
class Generador : public Instrumento
{
	public:
		// class constructor
		Generador();
		// class destructor
		~Generador();
	private:
		//valor de la frecuencia configurada en representaci�n hexadecimal.
		char frec_hexa [8];
		//valor de la amplitud de la se�al configurada en hexadecimal. 
		char amplitud_hexa [8];
		//valor del nivel de offset configurada en hexadecimal. 
		char offset_hexa [8];
        //Grupo de los botones e indicadores del generador de se�ales
		Fl_Group *ogroup_generador;
		//Grupo de los botones para ajustar la frecuencia de la se�al generada
		Fl_Group *ogroup_frecuencia;
		//Grupo de los botones e indicadores para seleccionar la se�al generada
		Fl_Group *ogroup_senal;
		//Grupo de los botones para seleccionar la amplitud de la se�al generada.
		Fl_Group *ogroup_amplitud;
		//Grupo de los botones para seleccionar el nivel de offset de la se�al generada.
		Fl_Group *ogroup_offset;
		//Contiene el nombre del instrumento.
	    Fl_Box *obox_nombre;
		//Bot�n para prender el instrumento generador de se�ales.
		Fl_Light_Button *ogen_on;
		//Display del generador donde se visualiza el valor de frecuencia configurado.
		Fl_7Seg *odisp_gen;
		//Bot�n que habilita la ayuda al usuario sobre el manejo del instrumento.
        Fl_Button *ohelp_gen;
        //Bot�n de seleccion de tipo de se�al seno.
        Fl_Button *oseno;
        //Bot�n de seleccion de tipo de se�al cuadrada.
        Fl_Button *ocuadrada;
        //Bot�n de seleccion de tipo de se�al tri�ngulo.
        Fl_Button *otriangulo;
        // Indicador del valor de la frecuencia en la escala de miliHertz.
        Fl_Box *omHz;
        // Indicador del valor de la frecuencia en la escala de Hertz.
        Fl_Box *oHz;
        // Indicador del valor de la frecuencia en la escala de MegaHertz.
        Fl_Box *oMeHz;
        // Bot�n de ajuste lineal de la frecuencia de la se�al.
        Fl_Knob *ofrec_gen;
        //Bot�n de ajuste lineal fino de la frecuencia de la se�al .
        Fl_Knob *ofrec_gen2;
        //Indicador del Valor de la frecuencia de la se�al seleccionada por el ususario.
        Fl_Value_Input *ovalor_frec;
        //Bot�n de ajuste lineal de la amplitud de la se�al seleccionada por el ususario.
        Fl_Knob *oamplitud;
        // Display que muestra el valor de la amplitud de la se�al seleccionada por el ususario.
        Fl_Output *odisp_amplitud;
        //Bot�n de ajuste lineal del nivel de offset de la se�al seleccionada por el ususario.
        Fl_Knob *ooffset;
        //Display que muestra el valor del nivel de offset de la se�al seleccionada por el ususario.
        Fl_Output *odisp_offset;  
        //Men� selector de escalas de frecuencia.    
        Fl_Choice *oescala_frecuencia;
        //Callback del bot�n de encendido/apagado del generador de se�ales.
		static void cb_generador_on(Fl_Widget*, void *);
		inline void cb_generador_on_in();
		//Callback del bot�n de selecci�n de se�al seno.
		static void cb_seno(Fl_Widget*, void *);
		inline void cb_seno_in();
		//Callback del bot�n de selecci�n de se�al cuadrada.
		static void cb_cuadrada(Fl_Widget*, void *);
		inline void cb_cuadrada_in();
		//Callback del bot�n de selecci�n de se�al tri�ngulo.
		static void cb_triangulo(Fl_Widget*, void *);
		inline void cb_triangulo_in();
		//Callback del bot�n que selecciona la frecuencia de la se�al generada.
		static void cb_frec_gen(Fl_Widget*, void *);
		inline void cb_frec_gen_in();
		//Calback para la escala de frecuencias hasta 1 Hertz
		static void cb_frec1(Fl_Widget*, void *);
		inline void cb_frec1_in(Fl_Widget*);
		//Calback para la escala de frecuencias hasta 100 Hertz
		static void cb_frec100(Fl_Widget*, void *);
		inline void cb_frec100_in(Fl_Widget*);
		// Calback para la escala de frecuencias hasta 500 Hertz
		static void cb_frec500(Fl_Widget*, void *);
		inline void cb_frec500_in(Fl_Widget*);
		// Calback para la escala de frecuencias hasta 1 KHz
		static void cb_frec1k(Fl_Widget*, void *);
		inline void cb_frec1k_in(Fl_Widget*);
		//Calback para la escala de frecuencias hasta 100 KHz
		static void cb_frec100k(Fl_Widget*, void *);
		inline void cb_frec100k_in(Fl_Widget*);
		//Calback para la escala de frecuencias hasta 500 KHz
		static void cb_frec500k(Fl_Widget*, void *);
		inline void cb_frec500k_in(Fl_Widget*);
		//Calback para la escala de frecuencias hasta 1 MHz
		static void cb_frec1m(Fl_Widget*, void *);
		inline void cb_frec1m_in(Fl_Widget*);
		//Callback del bot�n que selecciona la amplitud de la se�al generada.
		static void cb_amplitud(Fl_Widget*, void *);
		inline void cb_amplitud_in();
		//Callback del bot�n que selecciona el nivel de offset de la se�al generada.
		static void cb_offset(Fl_Widget*, void *);
		inline void cb_offset_in();
        
};

#endif // GENERADOR_H
