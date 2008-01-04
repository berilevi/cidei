// Class automatically generated by Dev-C++ New Class wizard

#include "canal.h" // class's header file
//int isec_acople;

Canal::Canal(int x, int y, int w, int h, const char *l, int ncolo):Instrumento() {
             
     ncolor = ncolo;

     ogroup_ch = new Fl_Group (x,y,w,h,"");
     ogroup_ch->box(FL_ENGRAVED_FRAME);
     ogroup_ch->deactivate();
     ogroup_pos = new Fl_Group ((x+5),(y+7),140,70,"");
     ogroup_pos->box(FL_ENGRAVED_FRAME);
     opos_x = new Fl_Knob ((x+45),(y+11),50,50,"Y-Pos");
     opos_x->labelsize(9);
     opos_x->color(180);
     opos_x->scaleticks(0);
     opos_x->cursor(50);
     opos_x->range(-100,100);
     opos_x->step(1);
     opos_x->round(1);
     ogroup_pos->end();
     ogroup_v_div = new Fl_Group ((x+5),(y+79),140,90,"");
     ogroup_v_div->box(FL_ENGRAVED_FRAME);
     ovolt_div = new Fl_Knob ((x+15),(y+85),70,70,"Vol/Div");
     ovolt_div->labelsize(9);
     ovolt_div->color(147);
     ovolt_div->type(8);
     ovolt_div->scaleticks(11);
     ovolt_div->range(0,11);
     omenu_v_div = new Fl_Choice((x+90),(y+110),50,18,"");
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
     ogroup_v_div->end();
     ogroup_acople = new Fl_Group ((x+5),(y+172),140,33,"");
     ogroup_acople->box(FL_ENGRAVED_FRAME);
     osel_acople = new Fl_Repeat_Button((x+20),(y+180),45,18,"Acople");
     osel_acople->labelsize(10);
     oacop_gnd = new Fl_Light_Button((x+120),(y+188),10,10,"Gnd");
     oacop_gnd->labelsize(10);
     oacop_gnd->box(FL_NO_BOX);
     oacop_gnd->align(FL_ALIGN_TOP);
     oacop_dc  = new Fl_Light_Button((x+100),(y+188),10,10,"Dc");
     oacop_dc->labelsize(10);
     oacop_dc->box(FL_NO_BOX);
     oacop_dc->align(FL_ALIGN_TOP);
     oacop_ac  = new Fl_Light_Button((x+78),(y+188),10,10,"Ac");
     oacop_ac->labelsize(10);
     oacop_ac->box(FL_NO_BOX);
     oacop_ac->align(FL_ALIGN_TOP);
     ogroup_acople->end();
     
     ogroup_ch->end();
     opos_x->callback(cb_posx, this);          //Callback selector de pos de la se�al.
}

 
// class destructor
Canal::~Canal(){
	// insert your code here
}


// sets the value of nv_div
void Canal::Setnv_div(int x){
	nv_div = x;
}


// sets the value of npos_y
void Canal::Setnpos_y(int x){
	npos_y = x;
}


// sets the value of bgnd
void Canal::Setbgnd(bool x){
	bgnd = x;
}


// sets the value of bac
void Canal::Setbac(bool x){
	bac = x;
}


// sets the value of bdc
void Canal::Setbdc(bool x){
	bdc = x;
}


/*
 * M�todo para calcular el valor pico a pico de la se�al
 * adquirida por el canal del osciloscopio
 */
float Canal::vpp(){
      int icont;
      int imayor = 0;         // Inicializar el valor mayor
      int imenor = 500;       // Inicializar el valor menor
      
      for (icont=0; icont<inum_datos; icont++){
          if (idatos[icont]>imayor){
              imayor = idatos[icont];               
          }
          if (idatos[icont]< imenor){
             imenor = idatos[icont];
          }                                
      }  
      dvolt_pp = imayor - imenor; 
      return dvolt_pp;                  
}

/*
 * M�todo para calcular la frecuencia de la se�al (periodica) 
 * adquirida por el canal del osciloscopio
 */
float Canal::frecuencia(){
	/* TODO (#1#): Implement Canal::frecuencia() */
}



/**
 * Este m�todo es el callback del selector de posici�n de la se�al
 * del canal del osciloscopio debe ir acompa�ada de una funci�n 
 * inline para poder realizar los callbacks. 
*/
void Canal::cb_posx(Fl_Widget* psel, void *pany){
     Fl_Knob *pselector = (Fl_Knob *)psel;
     Canal* pcanal=(Canal*)pany;       
     pcanal->cb_posx_in(pselector);
}

/**
 * Esta funci�n acompa�a la funci�n  cb_posx  
 * para realizar los llamados de callback del selector de posicion
 * de la se�al del canal en el osciloscopio 
*/
void Canal::cb_posx_in(Fl_Widget* psel){
     Fl_Knob *pselector = (Fl_Knob *)psel;
     Setnpos_y((pselector->value())+37500);
}



