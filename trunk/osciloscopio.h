// Class automatically generated by Dev-C++ New Class wizard
#ifndef OSCILOSCOPIO_H
#define OSCILOSCOPIO_H

#include <FL/Fl.H>
#include "instrumento.h"                    // Cabecera de la superclase
#include "Fl_Scope.h"                       // Clase graficar las se�ales
#include "grid.h"
#include "canal.h"                          // Cabecera de la clase canal
#include <FL/Fl_Widget.H>                   // inheriting class's header file
#include <FL/Fl_Group.H>         
#include <Fl/fl_Light_Button.h>
#include <FL/Fl_Repeat_Button.H>
#include "fl_Knob.h"
#include <FL/Fl_Choice.H>
#include <FL/Fl_Ask.H>
#include <FL/Fl_Check_Button.H>
#include <math.h>
#include <iostream>
#include <string.h>

/**
 * La clase Osciloscopio representa las funcionalidades del instrumento
 * oscilscopio.
*/

class Osciloscopio : public Instrumento
{
	public:
		// Constructor de clase
		Osciloscopio(int x, int y, int w, int h, const char *l, int ncol);
		// Destructor de clase
		~Osciloscopio();
		/**
		 * Objeto que agrupa la pantalla, los canales y controles
		 * que componen el osciloscopio.
		 */
        Fl_Group *ogroup_osc;
        /**
		 * Objeto que agrupa los controles de tiempo por divisi�n en el 
         * osciloscopio.
		 */
        Fl_Group *ogroup_tdiv;
        /**
		 * Objeto que agrupa los controles de seleccion de fuente y posici�n 
		 * del trigger en el osciloscopio.
		 */
        Fl_Group *ogroup_trigger;
        /**
		 * Objeto que agrupa el control de la posici�n de las graficas respecto 
		 * al eje x en el osciloscopio.
		 */
        Fl_Group *ogroup_pos;
        /**
		 * Objeto que agrupa el control de detencion de la grafica en el 
         * osciloscopio.
		 */
        Fl_Group *ogroup_stop;
        /**
		 * Objeto que agrupa las opciones de operaciones entre las graficas en el 
         * osciloscopio cuando se encuantran activos los dos canales.
		 */
        Fl_Group *ogroup_dual;
        /**
		 * Canal 1 del osciloscopio
	    */
        Canal *canal1; 
        /**
		 * Canal 2 del osciloscopio
	    */
        Canal *canal2;	
        /**
		 * Boton para iniciar el instrumento osciloscopio
	    */
        Fl_Light_Button *oosc_on;
        /**
		 * Boton de repetici�n para seleccionar la fuente de trigger para la
		 * adquicisi�n y digitalizaci�n de las se�ales.
	    */
        Fl_Repeat_Button *osel_trigger;
        /**
		 * Boton de repetici�n para seleccionar la operaci�n del osciloscopio
		 * en modo dual.
	    */
        Fl_Repeat_Button *odual_menu;  
        /**
		 * Boton que detiene la solicitud de datos al hardware para detener las
         * graficas que se presentan en la pantalla del osciloscopio.
	    */
        Fl_Light_Button *ostop;
        /**
		 * Boton que habilita el almacenamiento de datos en archivos planos de 
		 * texto.
	    */
        Fl_Button *olog_osc;
        /**
		 * Boton que habilita la ayuda para el uso del instrumento. 
	    */
        Fl_Button *ohelp_osc;
        /**
		 * Boton que habilita la ayuda flotante para el uso de los botones del
         * instrumento. 
	    */
        Fl_Check_Button *oayuda_osc;
        /**
		 * Selector de la escala de tiempo por divisi�n para la visualizaci�n 
		 * de la(s) se�al(es) adquirida(s).
	    */
        Fl_Knob *otiempo_div;   
        /**
		 * Perilla de desplazamiento de la se�al de forma horizontal.
	    */
        Fl_Knob *opos_y;
        /**
		 * Perilla de seleccion del nivel de disparo del trigger.
	    */
        Fl_Knob *onivel_trigger;
        /**
		 * Objeto de la calse scope que representa la pantalla del osciloscopio 
		 * donde se grafica la se�al digitalizada por el canal.
		*/
		Fl_Scope*  opantalla;
		/**
		 * Objeto de la calse scope que representa la pantalla del osciloscopio 
		 * donde se grafica la se�al digitalizada por el canal.
		*/
		grid*  ogrilla;
		/**
		 * Variable que contiene el valor del dato que se envia para adicionar 
		 * a la gr�fica del canal 1 en el m�todo recorrer datos.
		*/
		int idato_graf_ch1;
		/**
		 * Variable que contiene el valor del dato que se envia para adicionar 
		 * a la gr�fica del canal 2 en el m�todo recorrer datos.
		*/
		int idato_graf_ch2;
		/**
         * Este m�todo es el callback del timer para realizar la solicitud 
         * de los vectores de datos de los canales del osciloscopio.  
         */   
         static void cb_timer_vectores(void *);
         /**
         * Esta funci�n acompa�a la funci�n cb_timer_vectores
         * para realizar los llamados de callback del timer. 
         */
         inline void cb_timer_vectores_in();
         /**
         * Este m�todo es el callback del timer para realizar la solicitud 
         * de datos uno a uno en el osciloscopio.  
         */   
         static void cb_timer(void *);
         /**
         * Esta funci�n acompa�a la funci�n cb_timer para realizar los llamados 
         * de callback del timer de solicitud de muestras una a una 
         */
         inline void cb_timer_in();  
         /**
         * Este m�todo es el callback del boton de ayuda flotante de los botones 
         * del instrumento en el osciloscopio.  
         */   
         static void cb_ayuda(Fl_Widget*, void *);
         /**
         * Esta funci�n acompa�a la funci�n cb_ayuda para realizar los llamados 
         * de callback del boton de ayuda flotante. 
         */
         inline void cb_ayuda_in();       
    	
   private: 
        /**
		 * Este m�todo es el callback del boton selector de acople
		 * del canal 1 del osciloscopio debe ir acompa�ada de una funci�n 
         * inline para poder realizar los callbacks. 
		 */
		static void cb_acople1(Fl_Widget*, void *);
		/**
		 * Esta funci�n acompa�a la funci�n  cb_acople1  
		 * para realizar los llamados de callback del selector de acople
		 * del canal 1 en el osciloscopio 
		 */
		inline void cb_acople1_in();
		/**
		 * Este m�todo es el callback del boton selector de acople
		 * del canal 2 del osciloscopio debe ir acompa�ada de una funci�n 
         * inline para poder realizar los callbacks. 
		 */
		static void cb_acople2(Fl_Widget*, void *);
		/**
		 * Esta funci�n acompa�a la funci�n  cb_acople2  
		 * para realizar los llamados de callback del selector de acople
		 * del canal 2 en el osciloscopio 
		 */
		inline void cb_acople2_in();
        /**
		 * Este m�todo es el callback del selector de la escala de volt/div
		 * del canal 1 del osciloscopio debe ir acompa�ada de una funci�n 
         * inline para poder realizar los callbacks. 
		 */
		static void cb_volt_div1(Fl_Widget*, void *);
		/**
		 * Esta funci�n acompa�a la funci�n  cb_volt_div1  
		 * para realizar los llamados de callback del selector de la escala
		 * de volt/div del canal en el osciloscopio 
		 */
		inline void cb_volt_div1_in(Fl_Widget*);  
		/**
		 * Este m�todo es el callback del selector de la escala de volt/div
		 * del canal 2 del osciloscopio debe ir acompa�ada de una funci�n 
         * inline para poder realizar los callbacks. 
		 */
		static void cb_volt_div2(Fl_Widget*, void *);
		/**
		 * Esta funci�n acompa�a la funci�n  cb_volt_div2   
		 * para realizar los llamados de callback del selector de la escala
		 * de volt/div del canal en el osciloscopio 
		 */
		inline void cb_volt_div2_in(Fl_Widget*); 
		/**
		 * Rutina para solicitar las muestras de las se�ales en el osciloscopio. 
		*/
		void muestreo_timer(int);
         /**
		 * Calback para la escala de 0.5s por divisi�n
		*/
		static void cb_tdiv05s(Fl_Widget*, void *);
		/**
         * Esta funci�n acompa�a la funci�n cb_tdiv05s para realizar los 
         * llamados de callback de las escalas de tiempo por division 
         */
		inline void cb_tdiv05s_in(Fl_Widget*);
		/**
		 * Calback para la escala de 0.2s por divisi�n
		*/
		static void cb_tdiv02s(Fl_Widget*, void *);
		/**
         * Esta funci�n acompa�a la funci�n cb_tdiv02s para realizar los 
         * llamados de callback de las escalas de tiempo por division 
         */
		inline void cb_tdiv02s_in(Fl_Widget*);
		/**
		 * Calback para la escala de 0.1s por divisi�n
		*/
		static void cb_tdiv01s(Fl_Widget*, void *);
		/**
         * Esta funci�n acompa�a la funci�n cb_tdiv01s para realizar los 
         * llamados de callback de las escalas de tiempo por division 
         */
		inline void cb_tdiv01s_in(Fl_Widget*);
		/**
		 * Calback para la escala de 50 ms por divisi�n
		*/
		static void cb_tdiv50ms(Fl_Widget*, void *);
		/**
         * Esta funci�n acompa�a la funci�n cb_tdiv50ms para realizar los 
         * llamados de callback de las escalas de tiempo por division 
         */
		inline void cb_tdiv50ms_in(Fl_Widget*);
		/**
		 * Calback para la escala de 20 ms por divisi�n
		*/
		static void cb_tdiv20ms(Fl_Widget*, void *);
		/**
         * Esta funci�n acompa�a la funci�n cb_tdiv05s para realizar los 
         * llamados de callback de las escalas de tiempo por division 
         */
		inline void cb_tdiv20ms_in(Fl_Widget*);
		/**
		 * Calback para la escala de 10 ms por divisi�n
		*/
		static void cb_tdiv10ms(Fl_Widget*, void *);
		/**
         * Esta funci�n acompa�a la funci�n cb_tdiv10ms para realizar los 
         * llamados de callback de las escalas de tiempo por division 
         */
		inline void cb_tdiv10ms_in(Fl_Widget*);
		/**
		 * Calback para la escala de 5 ms por divisi�n
		*/
		static void cb_tdiv5ms(Fl_Widget*, void *);
		/**
         * Esta funci�n acompa�a la funci�n cb_tdiv5ms para realizar los 
         * llamados de callback de las escalas de tiempo por division 
         */
		inline void cb_tdiv5ms_in(Fl_Widget*);
		/**
		 * Calback para la escala de 2ms por divisi�n
		*/
		static void cb_tdiv2ms(Fl_Widget*, void *);
		/**
         * Esta funci�n acompa�a la funci�n cb_tdiv2ms para realizar los 
         * llamados de callback de las escalas de tiempo por division 
         */
		inline void cb_tdiv2ms_in(Fl_Widget*);
		/**
		 * Calback para la escala de 1ms por divisi�n
		*/
		static void cb_tdiv1ms(Fl_Widget*, void *);
		/**
         * Esta funci�n acompa�a la funci�n cb_tdiv1ms para realizar los 
         * llamados de callback de las escalas de tiempo por division 
         */
		inline void cb_tdiv1ms_in(Fl_Widget*);
		/**
		 * Calback para la escala de 0.5ms por divisi�n
		*/
		static void cb_tdiv05ms(Fl_Widget*, void *);
		/**
         * Esta funci�n acompa�a la funci�n cb_tdiv05ms para realizar los 
         * llamados de callback de las escalas de tiempo por division 
         */
		inline void cb_tdiv05ms_in(Fl_Widget*);
		/**
		 * Calback para la escala de 0.2ms por divisi�n
		*/
		static void cb_tdiv02ms(Fl_Widget*, void *);
		/**
         * Esta funci�n acompa�a la funci�n cb_tdiv02ms para realizar los 
         * llamados de callback de las escalas de tiempo por division 
         */
		inline void cb_tdiv02ms_in(Fl_Widget*);
		/**
		 * Calback para la escala de 0.1ms por divisi�n
		*/
		static void cb_tdiv01ms(Fl_Widget*, void *);
		/**
         * Esta funci�n acompa�a la funci�n cb_tdiv01ms para realizar los 
         * llamados de callback de las escalas de tiempo por division 
         */
		inline void cb_tdiv01ms_in(Fl_Widget*);
		/**
		 * Calback para la escala de 50us por divisi�n
		*/
		static void cb_tdiv50us(Fl_Widget*, void *);
		/**
         * Esta funci�n acompa�a la funci�n cb_tdiv50us para realizar los 
         * llamados de callback de las escalas de tiempo por division 
         */
		inline void cb_tdiv50us_in(Fl_Widget*);
		/**
		 * Calback para la escala de 20us por divisi�n
		*/
		static void cb_tdiv20us(Fl_Widget*, void *);
		/**
         * Esta funci�n acompa�a la funci�n cb_tdiv20us para realizar los 
         * llamados de callback de las escalas de tiempo por division 
         */
		inline void cb_tdiv20us_in(Fl_Widget*);
		/**
		 * Calback para la escala de 10us por divisi�n
		*/
		static void cb_tdiv10us(Fl_Widget*, void *);
		/**
         * Esta funci�n acompa�a la funci�n cb_tdiv10us para realizar los 
         * llamados de callback de las escalas de tiempo por division 
         */
		inline void cb_tdiv10us_in(Fl_Widget*);
		/**
		 * Calback para la escala de 5us por divisi�n
		*/
		static void cb_tdiv5us(Fl_Widget*, void *);
		/**
         * Esta funci�n acompa�a la funci�n cb_tdiv5us para realizar los 
         * llamados de callback de las escalas de tiempo por division 
         */
		inline void cb_tdiv5us_in(Fl_Widget*);
		/**
		 * Calback para la escala de 2us por divisi�n
		*/
		static void cb_tdiv2us(Fl_Widget*, void *);
		/**
         * Esta funci�n acompa�a la funci�n cb_tdiv2us para realizar los 
         * llamados de callback de las escalas de tiempo por division 
         */
		inline void cb_tdiv2us_in(Fl_Widget*);
		/**
		 * Calback para la escala de 1us por divisi�n
		*/
		static void cb_tdiv1us(Fl_Widget*, void *);
		/**
         * Esta funci�n acompa�a la funci�n cb_tdiv1us para realizar los 
         * llamados de callback de las escalas de tiempo por division 
         */
		inline void cb_tdiv1us_in(Fl_Widget*);
         /**
		 * La funci�n recorrer_datos recorre el arreglo idatos y envia punto 
         * por punto los datos para graficar.
		*/
		void recorrer_datos(int);
		/**
		 * La funci�n recorrer_datos recorre el arreglo idatos y envia punto 
         * por punto los datos para graficar.
		*/
		void config_canal();
		/**
		 * Callback del boton para encender el canal 1 del osciloscopio 
		 */
		static void cb_ch1_on(Fl_Widget*, void *);
		/**
		 * Funcion que acompa�a a la funcion cb_ch1_on para realizar los
		 * llamados de callback para encender el canal 1 del osciloscopio
		 */
		inline void cb_ch1_on_in();
		/**
		 * Callback del boton para encender el canal 2 del osciloscopio
		 */
		static void cb_ch2_on(Fl_Widget*, void *);
		/**
		 * Funcion que acompa�a a la funcion cb_ch2_on para realizar los
		 * llamados de callback para encender el canal 2 del osciloscopio 
		 */
		inline void cb_ch2_on_in();
		/**
		 * Callback del boton para activar o desactivar la grilla en la 
         * pantalla del osciloscopio
		 */
		static void cb_grilla(Fl_Widget*, void *);
		/**
		 * Funcion que acompa�a a la funcion cb_grilla para realizar los
		 * llamados de callback para activar o desactivar la grilla en la 
         * pantalla del osciloscopio 
		 */
		inline void cb_grilla_in();
		/**
		 * Callback del boton para detener la grafica en la pantalla del osciloscopio
		 */
		static void cb_stop(Fl_Widget*, void *);
		/**
		 * Funcion que acompa�a a la funcion cb_stop para realizar los
		 * llamados de callback para detener en la pantalla del osciloscopio 
		 */
		inline void cb_stop_in();
		/**
		 * Este m�todo es el callback del boton del menu de las funciones
		 * duales de graficas en el osciloscopio, debe ir acompa�ada de una 
         * funci�n inline para poder realizar los callbacks. 
		 */
		static void cb_dual_menu(Fl_Widget*, void *);
		/**
		 * Esta funci�n acompa�a la funci�n  cb_menu_dual 
		 * para realizar los llamados de callback del menu de funciones duales
		 * de graficas en el osciloscopio 
		 */
		inline void cb_dual_menu_in();
		/**
		 * Este m�todo es el callback del boton selector de la fuente del 
		 * disparo (trigger) en el osciloscopio, debe ir acompa�ada de una 
         * funci�n inline para poder realizar los callbacks. 
		 */
		static void cb_sel_trigger(Fl_Widget*, void *);
		/**
		 * Esta funci�n acompa�a la funci�n  cb_sel_trigger 
		 * para realizar los llamados de callback del boton selector de la
		 * fuente del trigger en el osciloscopio 
	    */
		inline void cb_sel_trigger_in();
		/**
		 * Este m�todo es el callback del boton que enciende el osciloscopio 
		 * debe ir acompa�ada de una funci�n inline para poder realizar los callbacks. 
		 */
		static void cb_osc_on(Fl_Widget*, void *);
		/**
		 * Esta funci�n acompa�a la funci�n  cb_osc_on 
		 * para realizar los llamados de callback del boton que enciende
		 * el osciloscopio 
	    */
		inline void cb_osc_on_in();
		/**
		 * Este m�todo es el callback del boton que activa el almacenamiento en 
         * archivos planos de texto de los datos capturados para el osciloscopio,  
		 * debe ir acompa�ada de una funci�n inline para poder realizar los callbacks. 
		 */
		static void cb_log_osc(Fl_Widget*, void *);
		/**
		 * Esta funci�n acompa�a la funci�n  cb_log_osc para realizar los 
         * llamados de callback del boton que activa el almacenamiento en archivos
         * planos de texto de los datos capturados para el osciloscopio. 
	    */
		inline void cb_log_osc_in();
		/**
		 * Este m�todo es el callback del boton selector de la escala de 
		 * tiempo por divisi�n en el osciloscopio, debe ir acompa�ada de una 
         * funci�n inline para poder realizar los callbacks. 
		 */
		static void cb_tiempo_div(Fl_Widget*, void *);
		/**
		 * Esta funci�n acompa�a la funci�n  cb_tiempo_div 
		 * para realizar los llamados de callback del boton selector de la
		 * escala de tiempo por divisi�n en el osciloscopio 
	    */
		inline void cb_tiempo_div_in(Fl_Widget*);
		/**
		 * Este m�todo es el callback del boton selector de la posici�n 
		 * de la se�al respecto al eje y en el osciloscopio, debe ir acompa�ada 
         * de una funci�n inline para poder realizar los callbacks. 
		 */
		static void cb_pos_y(Fl_Widget*, void *);
		/**
		 * Esta funci�n acompa�a la funci�n  cb_pos_y 
		 * para realizar los llamados de callback del boton selector de la
		 * posici�n de la se�al respecto al eje y en el osciloscopio 
	    */
		inline void cb_pos_y_in(Fl_Widget*);
		/**
		 * Variable que representa el color de fondo de la pantalla del
		 * osciloscopio
		 */
		int icolor;
		/**
		 * Bot�n indicador luminoso para activar el canal 1 del osciloscopio
		 */
		Fl_Light_Button *och1_on;
		/**
		 * Bot�n indicador luminoso para activar el canal 2 del osciloscopio
		 */
		Fl_Light_Button *och2_on;
        /**
		 * Indicador luminoso que indica que est� activado el modo dual
		 * de suma de se�ales de los dos canales  
		 */
        Fl_Light_Button *osuma;
        /**
		 * Indicador luminoso que indica que est� activado el modo dual
		 * de diferencia de se�ales de los dos canales  
		 */
        Fl_Light_Button *oresta;
        /**
		 * Indicador luminoso quqe indica que est� activado el modo dual
		 * de gr�fica de se�ales de lissajous  
		 */
        Fl_Light_Button *ox_y;
        /**
		 * Menu desplegable para seleccionar la escala de tiempo por divisi�n 
		 * del osciloscopio
	     */
        Fl_Choice *omenu_t_div;
        /**
		 * Indicador luminoso que indica que est� activado el trigger del
		 * canal 1  
		 */
        Fl_Light_Button *otrigger_ch1;
        /**
		 * Indicador luminoso que indica que est� activado el trigger del
		 * canal 2  
		 */
        Fl_Light_Button *otrigger_ch2;
        /**
		 * Bot�n para activar o desactivar la grilla de la pantalla del osciloscopio
		 */
        Fl_Light_Button *ogrilla_on;
        /**
		 * Vriable que almacena el caracter de la escala de tiempo por division  
		 */
        char ct_div;
        
};

#endif // OSCILOSCOPIO_H
