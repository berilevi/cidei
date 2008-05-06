// Class automatically generated by Dev-C++ New Class wizard

#include "canal.h" // class's header file

//Constructor de la calse

Canal::Canal(int x, int y, int w, int h, const char *l, int ncolo) {
             
     ncolor = ncolo;                                               //Color de la gr�fica 
     ogroupCh = new Fl_Group (x,y,w,h,"");
     ogroupCh->box(FL_ENGRAVED_FRAME);
     ogroupCh->deactivate();
     //oposx = new Fl_Knob ((x+1),(y+67),60,60,"Y-Pos");            //Bot�n para modificar la posici�n vertical de la gr�fica
     oposx = new Fl_Dial ((x+7),(y+88),40,40,"Y-Pos");            //Bot�n para modificar la posici�n vertical de la gr�fica
     oposx->labelsize(9);
     oposx->box(FL_NO_BOX);
     //oposx->color(180);
     //oposx->scaleticks(0);
     //oposx->cursor(50);
     oposx->range(-100,100);
     oposx->step(1);
     oposx->round(1);
     ovoltDiv = new Fl_Knob ((x+62),(y+67),80,80,"Vol-Div");      //Selector de escala de Voltios por Divisi�n
     ovoltDiv->step(1);
     ovoltDiv->labelsize(9);
     ovoltDiv->color(147);
     ovoltDiv->type(8);
     ovoltDiv->scaleticks(11);
     ovoltDiv->range(0,11);
     omenuvDiv = new Fl_Choice((x+58),(y+30),92,29,"");    //Men� de las escalas de Voltios por Divisi�n
     omenuvDiv->labelsize(10);
     omenuvDiv->align(FL_ALIGN_TOP);
     omenuvDiv->down_box();
     omenuvDiv->add("5",0,(Fl_Callback *)cbVdiv5,this);
     omenuvDiv->add("2",0,(Fl_Callback *)cbVdiv2,this);
     omenuvDiv->add("1",0,(Fl_Callback *)cbVdiv1,this);
     omenuvDiv->add("05",0,(Fl_Callback *)cbVdiv05,this);
     omenuvDiv->add("02",0,(Fl_Callback *)cbVdiv02,this);
     omenuvDiv->add("01",0,(Fl_Callback *)cbVdiv01,this);
     omenuvDiv->add("50m",0,(Fl_Callback *)cbVdiv50m,this);
     omenuvDiv->add("20m",0,(Fl_Callback *)cbVdiv20m,this);
     omenuvDiv->add("10m",0,(Fl_Callback *)cbVdiv10m,this);
     omenuvDiv->add("5m",0,(Fl_Callback *)cbVdiv5m,this);
     omenuvDiv->add("2m",0,(Fl_Callback *)cbVdiv2m,this);
     omenuvDiv->add("1m",0,(Fl_Callback *)cbVdiv1m,this);
     oselAcople = new Fl_Repeat_Button((x+6),(y+167),40,15,"Acople");   //Bot�n selector del tipo de acople del canal.
     oselAcople->labelsize(10);
     oacopGnd = new Fl_Box((x+114),(y+167),20,14,"Gnd");                 //Indicador de acople gnd del canal. 
     oacopGnd->labelsize(10);
     oacopGnd->box(FL_ENGRAVED_BOX);
     oacopGnd->align(FL_ALIGN_TOP);
     oacopDc  = new Fl_Box((x+90),(y+167),14,14,"Dc");                  //Indicador de acople Dc del canal
     oacopDc->labelsize(10);
     oacopDc->box(FL_ENGRAVED_BOX);
     oacopDc->align(FL_ALIGN_TOP);
     oacopAc  = new Fl_Box((x+66),(y+167),14,14,"Ac");                   //Indicador de acople Ac del canal
     oacopAc->labelsize(10);
     oacopAc->box(FL_ENGRAVED_BOX);
     oacopAc->align(FL_ALIGN_TOP);
     ogroupCh->end();
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

void Canal::cbVdiv5(Fl_Widget* psel, void *pany){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     Canal* pcanal=(Canal*)pany;
     pcanal->cbVdiv5In(pselector);
}

void Canal::cbVdiv5In(Fl_Widget* psel){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     ovoltDiv->value(pselector->value());
     Encapsular('A','c','1','1',0x00,0x00);
     Transmision();
}

void Canal::cbVdiv2(Fl_Widget* psel, void *pany){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     Canal* pcanal=(Canal*)pany;
     pcanal->cbVdiv2In(pselector);
}

void Canal::cbVdiv2In(Fl_Widget* psel){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     ovoltDiv->value(pselector->value());
     Encapsular('A','c','1','2',0x00,0x00);
     Transmision();
}

void Canal::cbVdiv1(Fl_Widget* psel, void *pany){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     Canal* pcanal=(Canal*)pany;
     pcanal->cbVdiv1In(pselector);
}

void Canal::cbVdiv1In(Fl_Widget* psel){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     ovoltDiv->value(pselector->value());
     Encapsular('A','c','1','3',0x00,0x00);
     Transmision();
}

void Canal::cbVdiv05(Fl_Widget* psel, void *pany){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     Canal* pcanal=(Canal*)pany;
     pcanal->cbVdiv05In(pselector);
}

void Canal::cbVdiv05In(Fl_Widget* psel){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     ovoltDiv->value(pselector->value());
     Encapsular('A','c','1','4',0x00,0x00);
     Transmision();
}

void Canal::cbVdiv02(Fl_Widget* psel, void *pany){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     Canal* pcanal=(Canal*)pany;
     pcanal->cbVdiv02In(pselector);
}

void Canal::cbVdiv02In(Fl_Widget* psel){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     ovoltDiv->value(pselector->value());
     Encapsular('A','c','1','5',0x00,0x00);
     Transmision();
}

void Canal::cbVdiv01(Fl_Widget* psel, void *pany){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     Canal* pcanal=(Canal*)pany;
     pcanal->cbVdiv01In(pselector);
}

void Canal::cbVdiv01In(Fl_Widget* psel){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     ovoltDiv->value(pselector->value());
     Encapsular('A','c','1','6',0x00,0x00);
     Transmision();
}

void Canal::cbVdiv50m(Fl_Widget* psel, void *pany){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     Canal* pcanal=(Canal*)pany;
     pcanal->cbVdiv50mIn(pselector);
}

void Canal::cbVdiv50mIn(Fl_Widget* psel){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     ovoltDiv->value(pselector->value());
     Encapsular('A','c','1','7',0x00,0x00);
     Transmision();
}

void Canal::cbVdiv20m(Fl_Widget* psel, void *pany){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     Canal* pcanal=(Canal*)pany;
     pcanal->cbVdiv20mIn(pselector);
}

void Canal::cbVdiv20mIn(Fl_Widget* psel){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     ovoltDiv->value(pselector->value());
     Encapsular('A','c','1','8',0x00,0x00);
     Transmision();
}

void Canal::cbVdiv10m(Fl_Widget* psel, void *pany){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     Canal* pcanal=(Canal*)pany;
     pcanal->cbVdiv10mIn(pselector);
}

void Canal::cbVdiv10mIn(Fl_Widget* psel){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     ovoltDiv->value(pselector->value());
     Encapsular('A','c','1','9',0x00,0x00);
     Transmision();
}

void Canal::cbVdiv5m(Fl_Widget* psel, void *pany){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     Canal* pcanal=(Canal*)pany;
     pcanal->cbVdiv5mIn(pselector);
}

void Canal::cbVdiv5mIn(Fl_Widget* psel){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     ovoltDiv->value(pselector->value());
     Encapsular('A','c','1','A',0x00,0x00);
     Transmision();
}

void Canal::cbVdiv2m(Fl_Widget* psel, void *pany){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     Canal* pcanal=(Canal*)pany;
     pcanal->cbVdiv2mIn(pselector);
}

void Canal::cbVdiv2mIn(Fl_Widget* psel){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     ovoltDiv->value(pselector->value());
     Encapsular('A','c','1','B',0x00,0x00);
     Transmision();
}

void Canal::cbVdiv1m(Fl_Widget* psel, void *pany){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     Canal* pcanal=(Canal*)pany;
     pcanal->cbVdiv1mIn(pselector);
}

void Canal::cbVdiv1mIn(Fl_Widget* psel){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     ovoltDiv->value(pselector->value());
     Encapsular('A','c','1','C',0x00,0x00);
     Transmision();
}
