// Class automatically generated by Dev-C++- New Class wizard

#include "generador.h" // class's header file

// class constructor
Generador::Generador()
{
	ogroup_generador = new Fl_Group (540,370,460,310,"");
	ogroup_generador->box(FL_ENGRAVED_BOX);
	ogroup_generador->deactivate();
	odisp_gen = new Fl_7Seg(555,380,269,100,""); 
    odisp_gen->box(FL_EMBOSSED_FRAME);
    odisp_gen->value("2.345");
    omHz = new Fl_Light_Button(830,390,10,10,"mHz");
    omHz->labelsize(10);
    omHz->box(FL_NO_BOX);
    omHz->align(FL_ALIGN_RIGHT);
    oHz = new Fl_Light_Button(830,420,10,10,"Hz");
    oHz->labelsize(10);
    oHz->box(FL_NO_BOX);
    oHz->align(FL_ALIGN_RIGHT);
    oMeHz = new Fl_Light_Button(830,450,10,10,"MHz");
    oMeHz->labelsize(10);
    oMeHz->box(FL_NO_BOX);
    oMeHz->align(FL_ALIGN_RIGHT);
    ohelp_gen  = new Fl_Button (550,655,40,18,"Help");
    ohelp_gen->labelsize(10);
    ogroup_senal = new Fl_Group (700,490,125,150,"");
    ogroup_senal->box(FL_ENGRAVED_BOX);
	ogroup_senal->deactivate();
    osel_gen = new Fl_Repeat_Button(715,610,100,20,"Funci�n");
    osel_gen->labelsize(12);
    oseno = new Fl_Light_Button(725,515,10,10,"Seno");
    oseno->labelsize(12);
    oseno->box(FL_NO_BOX);
    oseno->align(FL_ALIGN_RIGHT);
    ocuadrada = new Fl_Light_Button(725,545,10,10,"Cuadrada");
    ocuadrada->labelsize(12);
    ocuadrada->box(FL_NO_BOX);
    ocuadrada->align(FL_ALIGN_RIGHT);
    otriangulo = new Fl_Light_Button(725,575,10,10,"Triangulo");
    otriangulo->labelsize(12);
    otriangulo->box(FL_NO_BOX);
    otriangulo->align(FL_ALIGN_RIGHT);
    ogroup_senal->end();
    ogroup_frecuencia = new Fl_Group (560,490,120,150,"");
    ogroup_frecuencia->box(FL_ENGRAVED_BOX);
	ogroup_frecuencia->deactivate();
    ofrec_gen = new Fl_Knob (580,500,80,80,"Frecuencia");
    ofrec_gen->color(147);
    ofrec_gen->type(8);
    oescala_frec = new Fl_Counter(570,610,100,20,""); 
    oescala_frec->labelsize(10);
    ogroup_frecuencia->end();
    ogroup_amplitud = new Fl_Group (880,380,110,260,"");
    ogroup_amplitud->box(FL_ENGRAVED_BOX);
	ogroup_amplitud->deactivate();
    oamplitud = new Fl_Knob (900,530,70,70,"Amplitud");
    oamplitud->color(180);
    oamplitud->type(8); 
    oamplitud->labelsize(11);
    ooffset = new Fl_Knob (900,400,70,70,"Offset");
    ooffset->color(180);
    ooffset->type(8); 
    ooffset->labelsize(11);
    ogroup_amplitud->end();
    
    
    
	ogroup_generador-> end();
	
	ogen_on = new Fl_Light_Button(960,655,30,20,"ON");  
    ogen_on->labelsize(9);     
}

// class destructor
Generador::~Generador()
{
	// insert your code here
}
