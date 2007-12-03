// Class automatically generated by Dev-C++ New Class wizard
#ifndef OSCILOSCOPIO_H
#define OSCILOSCOPIO_H

#include "instrumento.h"         // Cabecera de la superclase
#include "Fl_Scope.h"            // Clase para presentar las gr�ficas
#include "canal.h"               
#include <FL/Fl.H>
#include <FL/Fl_Widget.H>        // inheriting class's header file
#include <FL/fl_draw.h>          // header file for drawing
#include <FL/Fl_Group.H>         
#include <Fl/fl_Light_Button.h>
#include <FL/Fl_Repeat_Button.H>
#include "fl_Knob.h"
#include <FL/Fl_Choice.H>
#include <FL/Fl_Value_Output.H>
#include <FL/Fl_Ask.H>
#include <math.h>
#include <pthread.h>
#include <string.h>

/**
 * La clase Osciloscopio representa las funcionalidades del instrumento
 * oscilscopio.
 * Esta clase hereda tambien de la clase Fl_Widget para poder realizar gr�ficas. 
*/

class Osciloscopio : public Instrumento
{
	public:
		// class constructor
		Osciloscopio(int x, int y, int w, int h, const char *l, int ncol);
		// class destructor
		~Osciloscopio();
		void Setbsuma(bool bx); // sets the value of bsuma
		void Setbx_y(bool bx); // sets the value of bx_y
		void Setipos_x(int ix); // sets the value of npos_x
		void Setit_div(int ix); // sets the value of nt_div
		void Setifrec_muestreo(int ix); // sets the value of nfrec_muestreo
		void Setinivel_trigger(int ix); // sets the value of nnivel_trigger
		/**
		 * M�todo para sumar las se�ales adquiridas por los 2 canales
		 * del instrumento.
		 */
		void sumar(int [], int[]);
		/**
		 * M�todo para restar las se�ales adquiridas por los 2 canales
		 * del instrumento 
		 */
		void restar(int[], int[]);
		/**
		 * M�todo para realizar gr�ficas de lissajous con las se�ales 
		 * de los 2 canales.
		 */
		void lissajous(int[], int[]);
		/**
		 * M�todo para asignar el valor de la variable 
		 * bdual
		 */
		void Setbdual(bool x); // sets the value of bdual
		/**
		 * Objeto que agrupa la pantalla, los canales y controles
		 * que componen el osciloscopio.
		 */
        Fl_Group *ogroup_osc;
        /**
		 * Objeto que agrupa los controles de tiempo por divisi�n y posici�n 
		 * de la grafica rescpecto del eje y en el osciloscopio.
		 */
        Fl_Group *ogroup_tdiv;
        /**
		 * Bot�n para seleccionar el (los) canal(es) activo(s)  
		 * en el osciloscopio.
	    */
        Fl_Repeat_Button *osel_ch;
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
		 * Boton que habilita el almacenamiento de datos en archivos planos de 
		 * texto.
	    */
        Fl_Button *olog_osc;
        /**
		 * Boton que habilita la ayuda para el uso del instrumento. 
	    */
        Fl_Button *ohelp_osc;
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
		 * Objeto de la calse scope que representa la pantalla del osciloscopio 
		 * donde se grafica la se�al digitalizada por el canal.
		*/
		Fl_Scope*  opantalla;
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
    	
	    private: 
        /**
		 * Este m�todo es el callback del boton selector de acople
		 * del canal del osciloscopio debe ir acompa�ada de una funci�n 
         * inline para poder realizar los callbacks. 
		 */
		static void cb_acople(Fl_Widget*, void *);
		/**
		 * Esta funci�n acompa�a la funci�n  cb_acople  
		 * para realizar los llamados de callback del selector de acople
		 * del canal en el osciloscopio 
		 */
		inline void cb_acople_in();
        /**
		 * Este m�todo es el callback del selector de la escala de volt/div
		 * del canal del osciloscopio debe ir acompa�ada de una funci�n 
         * inline para poder realizar los callbacks. 
		 */
		static void cb_volt_div(Fl_Widget*, void *);
		/**
		 * Esta funci�n acompa�a la funci�n  cb_volt_div  
		 * para realizar los llamados de callback del selector de la escala
		 * de volt/div del canal en el osciloscopio 
		 */
		inline void cb_volt_div_in(Fl_Widget*);  
        /**
		 * Rutina para solicitar los cuatro vectores de las muestras de las 
         * se�ales en el osciloscopio. 
		*/
	//	void muestrear(int);
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
		 * Este m�todo es el callback del boton selector de canal
		 * en el osciloscopio debe ir acompa�ada de una funci�n inline para
         * poder realizar los callbacks. 
		 */
		static void cb_sel_ch(Fl_Widget*, void *);
		/**
		 * Esta funci�n acompa�a la funci�n  cb_sel_ch 
		 * para realizar los llamados de callback del selector de canal
		 * en el osciloscopio 
		 */
		inline void cb_sel_ch_in();
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
		 * Esta variable representa la activaci�n de la suma de las 
		 * se�ales de los dos canales.
		 */
		bool bsuma;
		 /**
		 * Esta variable representa la activaci�n de la diferencia de las 
		 * se�ales de los dos canales.
		 */
		bool bresta;
		/**
		 * Esta variable representa la activaci�n de la gr�fica de las
		 * figuras de lissajous
		 */
		bool bx_y;
		/**
		 * Esta variable representa la posici�n de las gr�ficas respecto 
		 * del eje y
		 */
		int ipos_x;
		/**
		 * Esta variable representa la escala de tiempo por divisi�n
		 * que el ususario ha seleccionado.
		 */
		int it_div;
		/**
		 * Esta variable representa la frecuencia a la que se est�n
		 * digitalizando las se�ales.
		 */
		int ifrec_muestreo;
		/**
		 * Esta variable representa el nivel de voltaje en el cual se 
		 * produce el disparo para la digitalizaci�n de las se�ales.
		 */
		int inivel_trigger;
		/**
		 * Esta variable representa la activaci�n del modo dual del
		 * osciloscopio
		 */
		bool bdual;
		/**
		 * Esta variable representa el color de fondo de la pantalla del
		 * osciloscopio
		 */
		int icolor;
		/**
		 * Este indicador luminoso indica que est� activado el canal 1
		 * del osciloscopio
		 */
		Fl_Light_Button *och1;
		/**
		 * Este indicador luminoso indica que est� activado el canal 2
		 * del osciloscopio
		 */
        Fl_Light_Button *och2;
        /**
		 * Este indicador luminoso indica que est� activado el modo dual
		 * de suma de se�ales de los dos canales  
		 */
        Fl_Light_Button *osuma;
        /**
		 * Este indicador luminoso indica que est� activado el modo dual
		 * de diferencia de se�ales de los dos canales  
		 */
        Fl_Light_Button *oresta;
        /**
		 * Este indicador luminoso indica que est� activado el modo dual
		 * de gr�fica de se�ales de lissajous  
		 */
        Fl_Light_Button *ox_y;
        /**
		 * Menu desplegable para seleccionar la escala de tiempo por divisi�n 
		 * del osciloscopio
	     */
        Fl_Choice *omenu_t_div;
        /**
		 * Panel para visualizar la posici�n de la se�al respecto al eje y 
		 * de la se�al.   
	     */
        Fl_Value_Output *ov_posx;
        /**
		 * Este indicador luminoso indica que est� activado el trigger del
		 * canal 1  
		 */
        Fl_Light_Button *otrigger_ch1;
        /**
		 * Este indicador luminoso indica que est� activado el trigger del
		 * canal 2  
		 */
        Fl_Light_Button *otrigger_ch2;
        
};

#endif // OSCILOSCOPIO_H
