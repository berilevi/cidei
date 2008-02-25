// Class automatically generated by Dev-C++ New Class wizard

#ifndef ANALIZADOR_H
#define ANALIZADOR_H

#include "instrumento.h" // inheriting class's header file
#include "Fl_7Seg.H"     // inheriting class's header file
#include <FL/Fl.H>
#include "fl_Knob.h"
#include <FL/Fl_Group.H>
#include <Fl/fl_Light_Button.h>
#include <Fl/fl_Button.h>
#include <FL/Fl_Repeat_Button.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Value_Output.H>
#include <FL/Fl_Scrollbar.H>
#include <FL/Fl_Spinner.H>
#include "Fl_Scope.h"
#include "cursores.h"
#include "grid.h"
#include "mensajes.h"
#include <FL/Fl_Group.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Help_Dialog.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string>


#define TAM_ALMACENADO 35
#define ESPERA_TRIGGER 10

using namespace std;

/**
 * Esta clase representa las funcionees del instrumento
 * multimetro
*/
class Analizador : public Instrumento {
	public:
        // class constructor
		Analizador();
		// class destructor
		~Analizador();
		/**
		 * N�mero de muestras que se van a almacenar 
		*/
	    int inum_muestras;
	    /**
		 *  Ventana de ayuda de uso del instrumento.
	    */
        Fl_Help_Dialog *manual; 
		/**
		 * Contador de datos almacenados en el arreglo din�mico 
		*/
	    int idatapos;
		/**
		 * Matriz din�mica para almacenar los datos del analizador
		 */
	    //char **pdata_analizador;
	    char pdata_analizador [TAM_ALMACENADO][9];
	    //char **pdata_analizador hexadecimal;
	    //char cdatosHexa [TAM_ALMACENADO];
        //char **pdata_analizador hexadecimal;
	    int idatosDecimal [TAM_ALMACENADO];
        /**
		 * Objeto de la clase scope que representa la pantalla del analizador 
		 * donde se grafica la se�al digitalizada por el canal.
		*/
		Fl_Scope *apantalla_ch1, *apantalla_ch2, *apantalla_ch3, *apantalla_ch4, *apantalla_ch5,
                 *apantalla_ch6, *apantalla_ch7, *apantalla_ch8;
         /**
		 * Cursor para identificar el dato graficado
		 */
	    Cursores *ocursor; 
        /**
		 * Grilla del analizador 
		*/
		grid*  ogrilla;       
	     /**
		 * Numero de la muestra
		 */
	    Mensajes *otexto_muestra; 
        /**
		 * Bot�n para activar el disparo por flanco de subida
		 */
	    Fl_Button *oflancosubida;
	    /**
		 * Bot�n para activar el disparo por flanco de bajada
		 */
	    Fl_Button *oflancobajada;
        /**
		 * Bot�n para seleccionar el canal con el que se activa el disparo por flancos
		*/
        Fl_Spinner *oselector;
        /**
		 * Agrupa los botones e indicadores del analizador
		 */
	    Fl_Group *ogroup_ana;
	    /**
		 * Contiene el nombre del instrumento
		 */
	    Fl_Box *obox_nombre;
        /**
		 * Boton para iniciar el instrumento analizador
	    */
        Fl_Light_Button *oana_on;
        /**
		 * Boton para iniciar el muestreo en el instrumento analizador
	    */
        Fl_Light_Button *omuestrear_on;
        /**
		 * Bot�n para activar la grilla en el instrumento 
	    */
        Fl_Light_Button *ogrilla_on;
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
		 * Boton que habilita la ayuda flotante para el uso de los botones. 
	    */
        Fl_Check_Button *oayuda_ana;
        /**
		 * Selector del tipo de representaci�n del dato graficado.    
	    */  
        Fl_Choice *orep_dato;
        /**
		 * Selector de la frecuencia de muestreo del analizador.    
	    */  
        Fl_Choice *ofrec_muestreo;
        /**
		 * Scroll para desplazar los datos graficados.    
	    */
        Fl_Scrollbar *oscroll;
        /**
		 * Bot�n para desplazar la grafica horizontalmente   
		*/
        Fl_Knob *odes_horizontal;
	    /**
        * Agrupa las herramientas e indicadores del analizador
        */
        Fl_Group *ogroup_ana_botones;
        /**
		 *  Ventana de opciones de trigger.
		 */
	    Fl_Box *obox_trigger;
	    /**
        * Agrupa las herramientas e indicadores del analizador
        */
        Fl_Group *ogroup_trigger;
        /**
		 * Boton para cerrar la ventana de opciones de trigger. 
	    */
        Fl_Button *ocerrar_trigger;
	    /**
		 * Boton para activar el muestreo en el instrumento con o sin trigger
	    */
        Fl_Light_Button *otrigger_on;
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
		 * Callback del boton para activar o desactivar la grilla en la 
         * pantalla del analizador
		 */
		static void cb_grilla(Fl_Widget*, void *);
		/**
		 * Funcion que acompa�a a la funcion cb_grilla para realizar los
		 * llamados de callback para activar o desactivar la grilla en la 
         * pantalla del analizador 
		 */
		inline void cb_grilla_in();
		/**
		 * Callback para el bot�n que desplaza las graficas horizontalmente
		*/		 		 
		static void cb_horizontal(Fl_Widget*, void *);
		/**
		 * Callback para el bot�n que desplaza las graficas horizontalmente
		 */
		inline void cb_horizontal_in();
		/**
		 * Callback para el boton que despliega las opciones del trigger 
		*/		 		 
		static void cb_trigger_on(Fl_Widget*, void *);
		/**
		 *  Callback para el boton que despliega las opciones del trigger 
		 */
		inline void cb_trigger_on_in();
		/**
		 * Callback para el boton que 
		*/		 		 
		static void cb_cerrar_trigger(Fl_Widget*, void *);
		/**
		 *  Callback para el boton que 
		*/
		inline void cb_cerrar_trigger_in();
		/**
		 * Callback del boton que habilita el muestreo en el analizador
		 */
		static void cb_muestrear(Fl_Widget*, void *);
		/**
		 * Callback del boton que habilita el muestreo en el analizador
		 */
		inline void cb_muestrear_in();
		/**
		 * Callback del boton que activa el trigger por flanco de subida
		 */
		static void cb_subida(Fl_Widget*, void *);
		/**
		 * Callback del boton que activa el trigger por flanco de subida
		 */
		inline void cb_subida_in();
		/**
		 * Callback del boton que activa el trigger por flanco de bajada
		 */
		static void cb_bajada(Fl_Widget*, void *);
		/**
		 * Callback del boton que activa el trigger por flanco de bajada
		 */
		inline void cb_bajada_in();
		/**
		 * Callback del scroll que dezplaza el cursor del instrumento
		 */
		static void cb_scroll_cursor(Fl_Widget*, void *);
		/**
		 * Callback del scroll que dezplaza el cursor del instrumento
		 */
		inline void cb_scroll_cursor_in();
		/**
		 * Esta funcion recorre los buffers de los diferentes canales del
		 * analizador logico y grafica sus datos en los canales en pantalla
		 */
		void graficar_datos();
		
  private:
         /**
         * Callback del bot�n que activa la ayuda del instrumento  
         */   
         static void cb_help(Fl_Widget*, void *);
         /**
         * Callback del bot�n que activa la ayuda del instrumento 
         */
         inline void cb_help_in();
         /**
		 * Este m�todo es el callback del boton que activa el almacenamiento en 
         * archivos planos los datos capturados para el analizador l�gico   
		 */
		static void cb_log_ana(Fl_Widget*, void *);
		inline void cb_log_ana_in(); 
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
         //Callback de la primera frecuencia de muestreo del analizador 
		 static void cbfrec1(Fl_Widget*, void *);
		 inline void cbfrec1_in();
		 //Callback de la segunda frecuencia de muestreo del analizador 
		 static void cbfrec2(Fl_Widget*, void *);
		 inline void cbfrec2_in();
		 //Callback de la tercera frecuencia de muestreo del analizador 
		 static void cbfrec3(Fl_Widget*, void *);
		 inline void cbfrec3_in();
		 //Callback de la cuarta frecuencia de muestreo del analizador 
		 static void cbfrec4(Fl_Widget*, void *);
		 inline void cbfrec4_in();
         /**
		 * Esta funcion separa los datos enviados desde el hardware para cada
		 * canal del analizador logico.
		 */
		void separar_canales();
		/**
		 * N�mero de datos representados en la pantalla. 
	     */
		int igraf_datos;
		/**
		 * valor msb recibido en binario. 
	     */
		char  recibido_msb[5],recibido_msb2[5];
		/**
		 * valor lsb recibido en binario. 
	     */
		char  recibido_lsb[5], recibido_lsb2[5];
		/**
		 * Valor de 8 bits actual recibido en binario. 
	     */
		char  cbyte_actual[9];
		/**
		 * Estado del trigger del dispositivo. 
	    */
		bool btrigger;
		/**
		 * Estado del muestreo del analizador. 
	    */
		bool bmuestreando;
		/**
		 * Estado del timer que espera el trigger del dispositivo. 
	    */
		bool btimer_trigger;
		/**
		 * Funci�n para determinar si ocurrio el evento que dispara el muestreo
	    */
		bool trigger();
		/**
		 * Funci�n para almacenar muestras.
	    */
		void almacenar();
		/**
		 * Control de tiempo de muestreo. 
	    */
		Fl_Value_Slider *omuestreo;
		/**
		 * Valor del dato binario de 8 bits en el 1er tiempo de muestreo 
	    */
		Fl_Output *odato1;
	    Fl_Output *odatoprueba;
         
};

#endif // ANALIZADOR_H
