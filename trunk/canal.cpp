// Class automatically generated by Dev-C++ New Class wizard

#include "canal.h" // class's header file

//Constructor de la calse

Canal::Canal(int x, int y, int w, int h, const char *l, int ncolo) {
             
     ncolor = ncolo;                                               //Color de la gr�fica 
     ogroup_ch = new Fl_Group (x,y,w,h,"");                        
     ogroup_ch->box(FL_ENGRAVED_FRAME);
     ogroup_ch->deactivate();
     opos_x = new Fl_Knob ((x+85),(y+9),60,60,"Y-Pos");            //Bot�n para modificar la posici�n vertical de la gr�fica
     opos_x->labelsize(9);
     opos_x->color(180);
     opos_x->scaleticks(0);
     opos_x->cursor(50);
     opos_x->range(-100,100);
     opos_x->step(1);
     opos_x->round(1);
     ovolt_div = new Fl_Knob ((x+10),(y+75),75,75,"Vol-Div");      //Selector de escala de Voltios por Divisi�n
     ovolt_div->step(1);
     ovolt_div->labelsize(9);
     ovolt_div->color(147);
     ovolt_div->type(8);
     ovolt_div->scaleticks(11);
     ovolt_div->range(0,11);
     omenu_v_div = new Fl_Choice((x+85),(y+105),60,18,"");    //Men� de las escalas de Voltios por Divisi�n
     omenu_v_div->labelsize(10);
     omenu_v_div->align(FL_ALIGN_TOP);
     omenu_v_div->add("5",0,(Fl_Callback *)cb_vdiv5,this);
     omenu_v_div->add("2",0,(Fl_Callback *)cb_vdiv2,this);
     omenu_v_div->add("1",0,(Fl_Callback *)cb_vdiv1,this);
     omenu_v_div->add("05",0,(Fl_Callback *)cb_vdiv05,this);
     omenu_v_div->add("02",0,(Fl_Callback *)cb_vdiv02,this);
     omenu_v_div->add("01",0,(Fl_Callback *)cb_vdiv01,this);
     omenu_v_div->add("50m",0,(Fl_Callback *)cb_vdiv50m,this);
     omenu_v_div->add("20m",0,(Fl_Callback *)cb_vdiv20m,this);
     omenu_v_div->add("10m",0,(Fl_Callback *)cb_vdiv10m,this);
     omenu_v_div->add("5m",0,(Fl_Callback *)cb_vdiv5m,this);
     omenu_v_div->add("2m",0,(Fl_Callback *)cb_vdiv2m,this);
     omenu_v_div->add("1m",0,(Fl_Callback *)cb_vdiv1m,this);
     osel_acople = new Fl_Repeat_Button((x+15),(y+180),45,18,"Acople");   //Bot�n selector del tipo de acople del canal.
     osel_acople->labelsize(10);
     oacop_gnd = new Fl_Box((x+120),(y+188),10,10,"Gnd");                 //Indicador de acople gnd del canal. 
     oacop_gnd->labelsize(10);
     oacop_gnd->box(FL_ENGRAVED_BOX);
     oacop_gnd->align(FL_ALIGN_TOP);
     oacop_dc  = new Fl_Box((x+100),(y+188),10,10,"Dc");                  //Indicador de acople Dc del canal
     oacop_dc->labelsize(10);
     oacop_dc->box(FL_ENGRAVED_BOX);
     oacop_dc->align(FL_ALIGN_TOP);
     oacop_ac  = new Fl_Box((x+78),(y+188),10,10,"Ac");                   //Indicador de acople Ac del canal
     oacop_ac->labelsize(10);
     oacop_ac->box(FL_ENGRAVED_BOX);
     oacop_ac->align(FL_ALIGN_TOP);    
     ogroup_ch->end();
}
 
// class destructor
Canal::~Canal(){

}


/*******************************************************************************
 * Canal::cb_vdivXX: Callbacks del men� de voltios por divisi�n para modificar 
 *                   la posici�n de la perilla selectora de la escala de voltios
 *                   por divisi�n.
 * Est�n los 12 callbacks pertenecientes a cada una de las escalas que tiene el
 * men�. 
*******************************************************************************/

void Canal::cb_vdiv5(Fl_Widget* psel, void *pany){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     Canal* pcanal=(Canal*)pany;
     pcanal->cb_vdiv5_in(pselector);
}

void Canal::cb_vdiv5_in(Fl_Widget* psel){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     ovolt_div->value(pselector->value());
     Encapsular('A','c','1','1',0x00,0x00);
     Transmision();
}

void Canal::cb_vdiv2(Fl_Widget* psel, void *pany){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     Canal* pcanal=(Canal*)pany;
     pcanal->cb_vdiv2_in(pselector);
}

void Canal::cb_vdiv2_in(Fl_Widget* psel){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     ovolt_div->value(pselector->value());
     Encapsular('A','c','1','2',0x00,0x00);
     Transmision();
}

void Canal::cb_vdiv1(Fl_Widget* psel, void *pany){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     Canal* pcanal=(Canal*)pany;
     pcanal->cb_vdiv1_in(pselector);
}

void Canal::cb_vdiv1_in(Fl_Widget* psel){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     ovolt_div->value(pselector->value());
     Encapsular('A','c','1','3',0x00,0x00);
     Transmision();
}

void Canal::cb_vdiv05(Fl_Widget* psel, void *pany){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     Canal* pcanal=(Canal*)pany;
     pcanal->cb_vdiv05_in(pselector);
}

void Canal::cb_vdiv05_in(Fl_Widget* psel){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     ovolt_div->value(pselector->value());
     Encapsular('A','c','1','4',0x00,0x00);
     Transmision();
}

void Canal::cb_vdiv02(Fl_Widget* psel, void *pany){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     Canal* pcanal=(Canal*)pany;
     pcanal->cb_vdiv02_in(pselector);
}

void Canal::cb_vdiv02_in(Fl_Widget* psel){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     ovolt_div->value(pselector->value());
     Encapsular('A','c','1','5',0x00,0x00);
     Transmision();
}

void Canal::cb_vdiv01(Fl_Widget* psel, void *pany){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     Canal* pcanal=(Canal*)pany;
     pcanal->cb_vdiv01_in(pselector);
}

void Canal::cb_vdiv01_in(Fl_Widget* psel){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     ovolt_div->value(pselector->value());
     Encapsular('A','c','1','6',0x00,0x00);
     Transmision();
}

void Canal::cb_vdiv50m(Fl_Widget* psel, void *pany){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     Canal* pcanal=(Canal*)pany;
     pcanal->cb_vdiv50m_in(pselector);
}

void Canal::cb_vdiv50m_in(Fl_Widget* psel){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     ovolt_div->value(pselector->value());
     Encapsular('A','c','1','7',0x00,0x00);
     Transmision();
}

void Canal::cb_vdiv20m(Fl_Widget* psel, void *pany){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     Canal* pcanal=(Canal*)pany;
     pcanal->cb_vdiv20m_in(pselector);
}

void Canal::cb_vdiv20m_in(Fl_Widget* psel){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     ovolt_div->value(pselector->value());
     Encapsular('A','c','1','8',0x00,0x00);
     Transmision();
}

void Canal::cb_vdiv10m(Fl_Widget* psel, void *pany){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     Canal* pcanal=(Canal*)pany;
     pcanal->cb_vdiv10m_in(pselector);
}

void Canal::cb_vdiv10m_in(Fl_Widget* psel){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     ovolt_div->value(pselector->value());
     Encapsular('A','c','1','9',0x00,0x00);
     Transmision();
}

void Canal::cb_vdiv5m(Fl_Widget* psel, void *pany){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     Canal* pcanal=(Canal*)pany;
     pcanal->cb_vdiv5m_in(pselector);
}

void Canal::cb_vdiv5m_in(Fl_Widget* psel){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     ovolt_div->value(pselector->value());
     Encapsular('A','c','1','A',0x00,0x00);
     Transmision();
}

void Canal::cb_vdiv2m(Fl_Widget* psel, void *pany){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     Canal* pcanal=(Canal*)pany;
     pcanal->cb_vdiv2m_in(pselector);
}

void Canal::cb_vdiv2m_in(Fl_Widget* psel){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     ovolt_div->value(pselector->value());
     Encapsular('A','c','1','B',0x00,0x00);
     Transmision();
}

void Canal::cb_vdiv1m(Fl_Widget* psel, void *pany){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     Canal* pcanal=(Canal*)pany;
     pcanal->cb_vdiv1m_in(pselector);
}

void Canal::cb_vdiv1m_in(Fl_Widget* psel){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     ovolt_div->value(pselector->value());
     Encapsular('A','c','1','C',0x00,0x00);
     Transmision();
}
