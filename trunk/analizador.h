// Class automatically generated by Dev-C++ New Class wizard

#ifndef ANALIZADOR_H
#define ANALIZADOR_H

#include "instrumento.h" // inheriting class's header file
#include "Fl_7Seg.H"     // inheriting class's header file
#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <Fl/fl_Light_Button.h>
#include <FL/Fl_Repeat_Button.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Value_Output.H>
#include "Fl_Scope.h"
#include "fl_Knob.h"
#include <FL/Fl_Group.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Box.H>
#include <iostream>
#include <string>

using namespace std;

/**
 * Esta clase representa las funcionees del instrumento
 * multimetro
 */
class Analizador : public Instrumento
{
	public:
        // class constructor
		Analizador();
		// class destructor
		~Analizador();
        /**
		 * Objeto de la clase scope que representa la pantalla del analizador 
		 * donde se grafica la se�al digitalizada por el canal.
		*/
		Fl_Scope *apantalla_ch1, *apantalla_ch2, *apantalla_ch3, *apantalla_ch4, *apantalla_ch5,
                 *apantalla_ch6, *apantalla_ch7, *apantalla_ch8;
        /**
		 * Agrupa los botones e indicadores del analizador
		 */
	    Fl_Group *ogroup_ana;
        /**
		 * Boton para iniciar el instrumento analizador
	    */
        Fl_Light_Button *oana_on;
        /**
		 * Boton que habilita el almacenamiento de datos en archivos planos de 
		 * texto.
	    */
        Fl_Button *olog_ana;
        /**
		 * Boton que habilita la ayuda para el uso del instrumento. 
	    */
        Fl_Button *ohelp_ana;
	    /**
        * Agrupa las herramientas e indicadores del analizador
        */
        Fl_Group *ogroup_ana_botones;
		/**
		 * Este m�todo es el callback del boton de encendido
		 * del analizador debe ir acompa�ada de una funci�n inline para
         * poder realizar los callbacks. 
		 */
		static void cb_ana_on(Fl_Widget*, void *);
		/**
		 * Esta funci�n acompa�a la funci�n cb_ana_on 
		 * para realizar los llamados de callback del boton de encendido
		 * del analizador 
		 */
		inline void cb_ana_on_in();
		/**
		 * Esta funcion recorre los buffers de los diferentes canales del
		 * analizador logico y grafica sus datos en los canales en pantalla
		 */
		void graficar_datos();
		
  private:
        /**
		 * Boton para seleccionar el tiempo de muestreo del instrumento
		 * analizador logico.
		*/
        Fl_Knob *otiempo_muestreo;
        /**
         * Este m�todo es el callback del timer para realizar la solicitud 
         * de datos del analizador logico al hardware.  
         */   
         static void cb_timer_ana(void *);
         /**
         * Esta funci�n acompa�a la funci�n cb_timer_ana
         * para realizar los llamados de callback del timer 
         */
         inline void cb_timer_ana_in();
         /**
		 * Esta funcion separa los datos enviados desde el hardware para cada
		 * canal del analizador logico.
		 */
		void separar_canales();
		/**
		 * valor msb recibido en binario. 
	     */
		char  recibido_msb[9],recibido_msb2[9];
		/**
		 * valor lsb recibido en binario. 
	     */
		char  recibido_lsb[5], recibido_lsb2[5];
		
		 Fl_Box *caja;
         
};

#endif // ANALIZADOR_H
