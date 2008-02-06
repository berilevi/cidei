// Class automatically generated by Dev-C++ New Class wizard

#include "canal.h" // class's header file

Canal::Canal(int x, int y, int w, int h, const char *l, int ncolo) {
             
     ncolor = ncolo;

     ogroup_ch = new Fl_Group (x,y,w,h,"");
     ogroup_ch->box(FL_ENGRAVED_FRAME);
     ogroup_ch->deactivate();
     opos_x = new Fl_Knob ((x+85),(y+9),60,60,"Y-Pos");
     opos_x->labelsize(9);
     opos_x->color(180);
     opos_x->scaleticks(0);
     opos_x->cursor(50);
     opos_x->range(-100,100);
     opos_x->step(1);
     opos_x->round(1);
     ovolt_div = new Fl_Knob ((x+10),(y+75),75,75,"Vol/Div");
     ovolt_div->step(1);
     ovolt_div->labelsize(9);
     ovolt_div->color(147);
     ovolt_div->type(8);
     ovolt_div->scaleticks(11);
     ovolt_div->range(1,12);
     omenu_v_div = new Fl_Choice((x+93),(y+105),50,18,"");
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
     osel_acople = new Fl_Repeat_Button((x+15),(y+180),45,18,"Acople");
     osel_acople->labelsize(10);
     oacop_gnd = new Fl_Box((x+120),(y+188),10,10,"Gnd");
     oacop_gnd->labelsize(10);
     oacop_gnd->box(FL_BORDER_BOX);
     oacop_gnd->align(FL_ALIGN_TOP);
     oacop_dc  = new Fl_Box((x+100),(y+188),10,10,"Dc");
     oacop_dc->labelsize(10);
     oacop_dc->box(FL_BORDER_BOX);
     oacop_dc->align(FL_ALIGN_TOP);
     oacop_ac  = new Fl_Box((x+78),(y+188),10,10,"Ac");
     oacop_ac->labelsize(10);
     oacop_ac->box(FL_BORDER_BOX);
     oacop_ac->align(FL_ALIGN_TOP);    
     ogroup_ch->end();
}
 
// class destructor
Canal::~Canal(){
	// insert your code here
}


/*
 * M�todo para calcular el valor pico a pico de la se�al
 * adquirida por el canal del osciloscopio
 */
float Canal::vpp(){
      int icont;
      int imayor = 0;         // Inicializar el valor mayor
      int imenor = 500;       // Inicializar el valor menor
      
      for (icont=0; icont< DATA_OSC-1; icont++){
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





