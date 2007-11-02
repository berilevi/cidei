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
class Osciloscopio : public Instrumento, public Fl_Widget
{
	public:
		// class constructor
		Osciloscopio(int x, int y, int w, int h, const char *l, int ncol):Instrumento(), Fl_Widget(x,y,w,h,l)
        {   
                
            icolor = ncol;
            strcpy(cnombre,"osc.txt");  
            
            opantalla = new Fl_Scope(8,8,380, 304,"");  // Instancia de scope
            opantalla ->TraceColour(FL_WHITE);
            opantalla->tracetype(FL_SCOPE_TRACE_LOOP);
            opantalla->redrawmode(FL_SCOPE_REDRAW_FULL);
            opantalla->linetype(FL_SCOPE_LINE);
            
            oosc_on = new Fl_Light_Button(650,340,30,20,"ON");
            oosc_on->labelsize(9);
                        
            ogroup_osc = new Fl_Group (5,5,680,360,"");    // Agrupa los elementos del osciloscopio
            ogroup_osc->box(FL_ENGRAVED_FRAME); 
            ogroup_osc->deactivate();
            canal1 = new Canal(400,9,130,230,"",100); 
            canal2 = new Canal(545,9,130,230,"",250);
            //oosc_on = new Fl_Light_Button(650,340,30,20,"ON");
            //oosc_on->labelsize(9);
            osel_ch = new Fl_Repeat_Button(110,335,40,18,"Canal");
            osel_ch->labelsize(10);
            och1 = new Fl_Light_Button(160,340,10,10,"CH1");
            och1->labelsize(10);
            och1->box(FL_NO_BOX);
            och1->align(FL_ALIGN_TOP);
            och2 = new Fl_Light_Button(185,340,10,10,"CH2");
            och2->labelsize(10);
            och2->box(FL_NO_BOX);
            och2->align(FL_ALIGN_TOP);
            odual_menu = new Fl_Repeat_Button(230,335,40,18,"Dual");
            odual_menu->labelsize(10);
            odual_menu->deactivate();
            osuma = new Fl_Light_Button(290,340,10,10,"Suma");
            osuma->labelsize(10);
            osuma->box(FL_NO_BOX);
            osuma->align(FL_ALIGN_TOP);
            oresta = new Fl_Light_Button(325,340,10,10,"Resta");
            oresta->labelsize(10);
            oresta->box(FL_NO_BOX);
            oresta->align(FL_ALIGN_TOP);
            ox_y = new Fl_Light_Button(355,340,10,10,"X_Y");
            ox_y->labelsize(10);
            ox_y->box(FL_NO_BOX);
            ox_y->align(FL_ALIGN_TOP);
            olog_osc  = new Fl_Button (15,320,40,18,"Log");
            olog_osc->labelsize(10);
            ohelp_osc  = new Fl_Button (15,342,40,18,"Help");
            ohelp_osc->labelsize(10);
            ogroup_osc->end();  
            
            ogroup_tdiv = new Fl_Group (400,243,240,115,"");    //Agrupa los controles de tiempo por divisi�n
            ogroup_tdiv->box(FL_ENGRAVED_FRAME);
            ogroup_tdiv->deactivate();
            otiempo_div = new Fl_Knob (405,250,70,70,"T_DIV");
            otiempo_div->color(147);
            otiempo_div->type(8);
            otiempo_div->labelsize(9);
            otiempo_div->scaleticks(17);
            otiempo_div->range(0,17);
            omenu_t_div = new Fl_Choice(415,335,50,20,"");
            omenu_t_div->add("0.5 s");
            omenu_t_div->add("0.2 s");
            omenu_t_div->add("0.1 s");
            omenu_t_div->add("50 m");
            omenu_t_div->add("20 m");
            omenu_t_div->add("10 m");
            omenu_t_div->add("5 m");
            omenu_t_div->add("2 m");
            omenu_t_div->add("1 m");
            omenu_t_div->add("0.5 m");
            omenu_t_div->add("0.2 m");
            omenu_t_div->add("0.1 m");
            omenu_t_div->add("50 u");
            omenu_t_div->add("20 u");
            omenu_t_div->add("10 u");
            omenu_t_div->add("5 u");
            omenu_t_div->add("2 u");
            omenu_t_div->add("1 u");            
            opos_y = new Fl_Knob (495,255,50,50,"X-Pos");
            opos_y->color(180);
            opos_y->scaleticks(0);
            opos_y->cursor(40);
            opos_y->range(0,10);
            ov_posx = new Fl_Value_Output(500,335,50,20,"");
            osel_trigger = new Fl_Repeat_Button(580,310,40,18,"Trigger");  
            osel_trigger->labelsize(10);
            otrigger_ch1 = new Fl_Light_Button(580,275,10,10,"Ch1");
            otrigger_ch1->labelsize(10);
            otrigger_ch1->box(FL_NO_BOX);
            otrigger_ch1->align(FL_ALIGN_RIGHT);
            otrigger_ch2 = new Fl_Light_Button(580,295,10,10,"Ch2");
            otrigger_ch2->labelsize(10);
            otrigger_ch2->box(FL_NO_BOX);
            otrigger_ch2->align(FL_ALIGN_RIGHT);
            ogroup_tdiv->end();
                        
            osel_ch->callback(cb_sel_ch, this);
            odual_menu->callback(cb_dual_menu, this);    
            osel_trigger->callback(cb_sel_trigger, this);
            otiempo_div->callback(cb_tiempo_div, this);
            opos_y->callback(cb_pos_y, this);
            oosc_on->callback(cb_osc_on, this);
            olog_osc->callback(cb_log_osc, this);
        }
		// class destructor
		~Osciloscopio();
		void Setbsuma(bool bx); // sets the value of bsuma
		void Setbx_y(bool bx); // sets the value of bx_y
		void Setipos_x(int ix); // sets the value of npos_x
		void Setit_div(int ix); // sets the value of nt_div
		void Setifrec_muestreo(int ix); // sets the value of nfrec_muestreo
		void Setinivel_trigger(int ix); // sets the value of nnivel_trigger
		/**
		 * M�todo para realizar la gr�fica de la pantalla y la 
		 * cuadricula del osciloscopio
		 */
		void draw();
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
		 * La funci�n recorrer_datos recorre el arreglo idatos y envia punto 
         * por punto los datos para graficar.
		*/
		void recorrer_datos();
         /**
         * Este m�todo es el callback del timer para realizar la solicitud 
         * de datos del canal 1 del osciloscopio al hardware.  
         */   
         static void cb_timer_ch1(void *);
         /**
         * Esta funci�n acompa�a la funci�n cb_timer_ch1
         * para realizar los llamados de callback del timer 
         */
         inline void cb_timer_ch1_in();
         /**
         * Este m�todo es el callback del timer para realizar la solicitud 
         * de datos del canal 2 osciloscopio al hardware.  
         */   
         static void cb_timer_ch2(void *);
         /**
         * Esta funci�n acompa�a la funci�n cb_timer_ch2
         * para realizar los llamados de callback del timer 
         */
         inline void cb_timer_ch2_in();
         /**
         * Este m�todo es el callback del timer para realizar la solicitud 
         * de datos de los 2 canales del osciloscopio simulteneamente al hardware.  
         */   
         static void cb_timer_dual_ch(void *);
         /**
         * Esta funci�n acompa�a la funci�n cb_timer_dual_ch
         * para realizar los llamados de callback del timer 
         */
         inline void cb_timer_dual_ch_in();
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
