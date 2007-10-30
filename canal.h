// Class automatically generated by Dev-C++ New Class wizard

#ifndef CANAL_H
#define CANAL_H

#include "instrumento.h"         // inheriting class's header file
#include <FL/Fl_Widget.H>        // inheriting class's header file
#include <FL/fl_draw.h>          // header file for drawing
#include <FL/Fl_Group.H>         //          
#include <Fl/fl_Knob.h>
#include <FL/Fl_Value_Output.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Repeat_Button.H>
#include <Fl/fl_Light_Button.h>
#include <FL/Fl_Ask.H>
#include <math.h>

/**
 * Esta clase representa las funcionalidades de los canales
 * del osciloscopio
 */
class Canal : public Instrumento, public Fl_Widget
{
	public:
		// class constructor
		Canal(int x, int y, int w, int h, const char *l, int ncolo):Instrumento(), Fl_Widget(x,y,w,h,l)
        {
             
             Fl_Knob *ovolt_div;
             Fl_Knob *opos_x;
             Fl_Repeat_Button *osel_acople;
             ncolor = ncolo;
                     
             ogroup_ch = new Fl_Group (x,y,w,h,"");
             ogroup_ch->box(FL_ENGRAVED_FRAME);
             ogroup_ch->deactivate();
             ovolt_div = new Fl_Knob ((x+29),(y+101),70,70,"Vol/Div");
             ovolt_div->labelsize(9);
             ovolt_div->color(147);
             ovolt_div->type(8);
             ovolt_div->scaleticks(11);
             ovolt_div->range(0,11);
             opos_x = new Fl_Knob ((x+40),(y+11),50,50,"Y-Pos");
             opos_x->labelsize(9);
             opos_x->color(180);
             opos_x->scaleticks(0);
             opos_x->cursor(50);
             opos_x->range(0,5);
             ov_posy = new Fl_Value_Output((x+40),(y+71),50,16,"");
             omenu_v_div = new Fl_Choice((x+39),(y+181),50,18,"");
             omenu_v_div->add("5");
             omenu_v_div->add("2");
             omenu_v_div->add("1");
             omenu_v_div->add("0.5");
             omenu_v_div->add("0.2");
             omenu_v_div->add("0.1");
             omenu_v_div->add("50 m");
             omenu_v_div->add("20 m");
             omenu_v_div->add("10 m");
             omenu_v_div->add("5 m");
             omenu_v_div->add("2 m");
             omenu_v_div->add("1 m");
             osel_acople = new Fl_Repeat_Button((x+10),(y+204),45,18,"Acople");
             osel_acople->labelsize(10);
             oacop_gnd = new Fl_Light_Button((x+110),(y+213),10,10,"Gnd");
             oacop_gnd->labelsize(10);
             oacop_gnd->box(FL_NO_BOX);
             oacop_gnd->align(FL_ALIGN_TOP);
             oacop_dc  = new Fl_Light_Button((x+90),(y+213),10,10,"Dc");
             oacop_dc->labelsize(10);
             oacop_dc->box(FL_NO_BOX);
             oacop_dc->align(FL_ALIGN_TOP);
             oacop_ac  = new Fl_Light_Button((x+68),(y+213),10,10,"Ac");
             oacop_ac->labelsize(10);
             oacop_ac->box(FL_NO_BOX);
             oacop_ac->align(FL_ALIGN_TOP);
             
             ogroup_ch->end();
             osel_acople->callback(cb_acople, this);   //Callback selector de acoples.
             ovolt_div->callback(cb_volt_div, this);   //Callback selector de T/div.
             opos_x->callback(cb_posx, this);          //Callback selector de pos de la se�al.
             
        }
		// class destructor
		~Canal();
		void Setnv_div(int x); // sets the value of nv_div
		void Setnpos_y(int x); // sets the value of npos_y
		void Setbgnd(bool x); // sets the value of bgnd
		/**
		 * M�todo para realizar la gr�fica de la se�al adquirida por
		 * el canal del osciloscopio
		 */
		void draw();
		void Setbac(bool x); // sets the value of bac
		void Setbdc(bool x); // sets the value of bdc
		/**
		 * M�todo para calcular el valor pico a pico de la se�al
		 * adquirida por el canal del osciloscopio
		 */
		float vpp();
		/**
		 * M�todo para calcular la frecuencia de la se�al (periodica) 
		 * adquirida por el canal del osciloscopio
		 */
		float frecuencia();
		/**
		 * Grupo de los diferentes botones y selectores que componen
		 * el canal.
        */
		Fl_Group *ogroup_ch;
		/**
		 * Esta variable representa el color de la gr�fica de la se�al
		 * adquirida por el canal
	    */
		int ncolor;
		/**
		 * Esta varible representa el valor de voltios por divisi�n
		 * seleccionado por el usuario. 
		 */
		int nv_div;
		/**
		 * Esta variable representa la posici�n de la gr�fica del canal
		 * respecto al eje x 
		 */
		int npos_y;
		
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
		 * Este m�todo es el callback del selector de posici�n de la se�al
		 * del canal del osciloscopio debe ir acompa�ada de una funci�n 
         * inline para poder realizar los callbacks. 
		 */
		static void cb_posx(Fl_Widget*, void *);
		/**
		 * Esta funci�n acompa�a la funci�n  cb_posx  
		 * para realizar los llamados de callback del selector de posicion
		 * de la se�al del canal en el osciloscopio 
		 */
		inline void cb_posx_in(Fl_Widget*);
		/**
		 * Esta variable representa el valor pico a pico de la se�al 
		 * analizada con el osciloscopio
		 */
		float dvolt_pp;
		/**
		 * Esta variable representa el valor de la frecuencia de la se�al
		 * analizada.  
		 */
		float dv_frecuencia;
		/**
		 * Esta variable representa el estado de aterrizado del canal 
		 * del osciloscopio
		 */
		bool bgnd;
		/**
		 * Esta variable representa el estado del acople ac del 
		 * canal del osciloscopio
		 */
		bool bac;
		/**
		 * Esta variable representa el estado del acople dc del 
		 * canal del osciloscopio
		 */
		bool bdc;
		/**
		 * Este indicador luminoso indica que est� activado el acople
		 * gnd del canal  
		 */
        Fl_Light_Button *oacop_gnd;
        /**
		 * Este indicador luminoso indica que est� activado el acople
		 * ac del canal  
		 */
        Fl_Light_Button *oacop_ac;
        /**
		 * Este indicador luminoso indica que est� activado el acople
		 * dc del canal  
		 */
        Fl_Light_Button *oacop_dc;
        /**
		 * Menu desplegable para seleccionar la escala de voltios por divisi�n 
		 * del canal  
	     */
        Fl_Choice *omenu_v_div;
        /**
		 * Panel para visualizar la posici�n de la se�al respecto al eje x 
		 * de la se�al.   
	     */
        Fl_Value_Output *ov_posy;
        /**
		 * Perilla para ajustar la posici�n de la se�al respecto al eje x 
		 * de la se�al.   
	     */
        Fl_Knob *opos_x;
};

#endif // CANAL_H