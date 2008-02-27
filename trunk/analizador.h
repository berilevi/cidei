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


#define TAM_ALMACENADO 40
#define ESPERA_TRIGGER 20


using namespace std;

/*******************************************************************************
 * Analizador: Clase que representa las funcionees del instrumento Analizador
 *             L�gico.
 * El instrumento puede capturar el estado binario de un bus de se�ales digitales 
 * de 8 canales y el hardware lo env�a en un dato hexadecimal de 2 car�cteres.
 * TAM_ALMACENADO: Constante que representa el n�mero m�ximo de muestras que 
 *                 puede almacenar el instrumento.
 * El instrumento tiene 2 modos de captura:
 * 1.  Modo de captura sin disparo: El instrumento capturar� el numero de 
 *                                  muestras especificado sin ning�n tipo de
 *                                  condici�n.
 * 2. Modo de captura con disparo: El usario configura un estado de flanco de
 *                                 subida o bajada en alguno de los 8 canales
 *                                 para iniciar el muestreo; si despues de un
 *                                 tiempo configurado no se encontro el evento,
 *                                 el instrumento tomar� las muestras.
 * Las muestras se realizar�n de acuerdo a una frecuencia configurada por el
 * usuario.
 * El instrumento cuenta con un cursor que ayuda al usuario a interpretar el 
 * dato muestreado en un instante de tiempo y ver su representaci�n en 3 siste-
 * mas de numeraci�n: binaria, decimal y hexadecimal, que el usuario selecciona
 * en  un men�.
*******************************************************************************/
class Analizador : public Instrumento {
	public:
        // class constructor
		Analizador();
		// class destructor
		~Analizador();
		//N�mero de muestras que se pueden almacenar.
	    int inum_muestras;
	    // Ventana de ayuda de uso del instrumento.
        Fl_Help_Dialog *manual; 
		//Contador de datos almacenados en el arreglo
	    int idatapos;
	    //Arreglo donde se almacenan las muestras en cadenas de caracteres de datos binarios de 8 bists
	    char pdata_analizador [TAM_ALMACENADO][9];
        //char **pdata_analizador hexadecimal;
	    int idatosDecimal [TAM_ALMACENADO];
        //Objetos de la clase scope que representa la pantalla del analizador donde se grafica la se�al digital.
		Fl_Scope *apantalla_ch1, *apantalla_ch2, *apantalla_ch3, *apantalla_ch4, *apantalla_ch5,
                 *apantalla_ch6, *apantalla_ch7, *apantalla_ch8;
        //Cursor para identificar el dato graficado
	    Cursores *ocursor; 
        //Grilla del analizador 
		grid*  ogrilla;       
	    //N�mero de la muestra.
	    Mensajes *otexto_muestra; 
        //Bot�n para activar el disparo por flanco de subida
	    Fl_Button *oflancosubida;
	    //Bot�n para activar el disparo por flanco de bajada
	    Fl_Button *oflancobajada;
        // Bot�n para seleccionar el canal con el que se activa el disparo por flancos
        Fl_Spinner *oselector;
        //Agrupa los botones e indicadores del analizador
	    Fl_Group *ogroup_ana;
	    //Contiene el nombre del instrumento
	    Fl_Box *obox_nombre;
        //Bot�n para prender/apagar el instrumento analizador
        Fl_Light_Button *oana_on;
        //Bot�n para iniciar el muestreo en el instrumento analizador
        Fl_Light_Button *omuestrear_on;
        // Bot�n para activar la grilla en el instrumento 
        Fl_Light_Button *ogrilla_on;
        // Bot�n que habilita el almacenamiento de datos en archivos planos de texto.
        Fl_Button *olog_ana;
        //Bot�n que habilita la ayuda para el uso del instrumento.
        Fl_Button *ohelp_ana;
        //Boton que habilita la ayuda flotante para el uso de los botones. 
        Fl_Check_Button *oayuda_ana;
        //Selector del tipo de representaci�n del dato graficado. 
        Fl_Choice *orep_dato;
        //Selector de la frecuencia de muestreo del analizador. 
        Fl_Choice *ofrec_muestreo;
        //Scroll para desplazar los datos graficados.  
        Fl_Scrollbar *oscroll;
        //Bot�n para desplazar la grafica horizontalmente  
        Fl_Knob *odes_horizontal;
	    //Agrupa las herramientas e indicadores del analizador
        Fl_Group *ogroup_ana_botones;
        //Ventana de opciones de trigger.
	    Fl_Box *obox_trigger;
	    //Agrupa las herramientas e indicadores del analizador
        Fl_Group *ogroup_trigger;
        //Bot�n para cerrar la ventana de opciones de trigger. 
        Fl_Button *ocerrar_trigger;
	    // Boton para activar el muestreo en el instrumento con o sin trigger
        Fl_Light_Button *otrigger_on;
		//Callback del bot�n de encendido del analizador. 
		static void cb_ana_on(Fl_Widget*, void *);
		inline void cb_ana_on_in();
		//Callback del bot�n para activar o desactivar la grilla en la pantalla del analizador
		static void cb_grilla(Fl_Widget*, void *);
		inline void cb_grilla_in();
		//Callback del bot�n que desplaza las graficas horizontalmente
		static void cb_horizontal(Fl_Widget*, void *);
		inline void cb_horizontal_in();
		//Callback del bot�n que despliega las opciones del trigger 
		static void cb_trigger_on(Fl_Widget*, void *);
		inline void cb_trigger_on_in();
		//Callback del bot�n que cierra la ventana de opciones del trigger
		static void cb_cerrar_trigger(Fl_Widget*, void *);
		inline void cb_cerrar_trigger_in();
		//Callback del bot�n que habilita el muestreo en el analizador
		static void cb_muestrear(Fl_Widget*, void *);
		inline void cb_muestrear_in();
		//Callback del bot�n que activa el trigger por flanco de subida
		static void cb_subida(Fl_Widget*, void *);
		inline void cb_subida_in();
		//Callback del boton que activa el trigger por flanco de bajada
		static void cb_bajada(Fl_Widget*, void *);
		inline void cb_bajada_in();
		//Callback del scroll que dezplaza el cursor del instrumento
		static void cb_scroll_cursor(Fl_Widget*, void *);
		inline void cb_scroll_cursor_in();
		//M�todo que recorre el arreglo pdata_analizador[] y gr�fica sus datos en los canales en pantalla
		void graficar_datos();
		
  private:
         //Callback del bot�n que activa la ayuda del instrumento  
         static void cb_help(Fl_Widget*, void *);
         inline void cb_help_in();
         //Callback del bot�n que activa el almacenamiento en archivos planos los datos capturados para el analizador l�gico   
		 static void cb_log_ana(Fl_Widget*, void *);
		 inline void cb_log_ana_in(); 
         //Callback del timer para realizar la solicitud de datos del analizador logico al hardware.  
         static void cb_timer_ana(void *);
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
         //M�todo que separa los datos enviados desde el hardware para cada canal del analizador logico.
		void separar_canales();
		// N�mero de datos representados en la pantalla. 
		int igraf_datos;
		//Arreglo que almacena el nible m�s significativo recibido en binario. 
		char  recibido_msb[5],recibido_msb2[5];
		//Arreglo que almacena el nible menos significativo recibido en binario. 
		char  recibido_lsb[5], recibido_lsb2[5];
		//Valor de 8 bits actual recibido en binario. 
		char  cbyte_actual[9];
		//Estado del trigger del dispositivo. 
		bool btrigger;
		//Estado del muestreo del analizador. 
		bool bmuestreando;
		//Estado del timer que espera el trigger del dispositivo. 
		bool btimer_trigger;
		//M�todo para determinar si ocurrio el evento que dispara el muestreo
		bool trigger();
		//M�todo para almacenar las muestras en el arreglopdata_analizador[].
		void almacenar();
		//Cuadro donde se muestra el valor se�alado por el cursor.
		Fl_Output *odato1;
	    Fl_Output *odatoprueba;
         
};

#endif // ANALIZADOR_H
