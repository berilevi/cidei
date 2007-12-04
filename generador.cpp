// Class automatically generated by Dev-C++- New Class wizard

#include "generador.h" // class's header file
#include <math.h>

int isec_generador;

// class constructor
Generador::Generador()
{
    isec_generador = 0;
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
    ofrec_gen->labelsize(9);
    ofrec_gen->range(0,50);
    ovalor_frec = new Fl_Value_Output(590,590,60,20,"");
    oescala_frec = new Fl_Simple_Counter(570,615,100,20,""); 
    oescala_frec->step(10);
    ogroup_frecuencia->end();
    ogroup_amplitud = new Fl_Group (880,380,110,260,"");
    ogroup_amplitud->box(FL_ENGRAVED_BOX);
	ogroup_amplitud->deactivate();
    oamplitud = new Fl_Knob (900,530,70,70,"Amplitud");
    oamplitud->color(180);
    oamplitud->type(8); 
    oamplitud->labelsize(11);
    oamplitud->range(0.0,2.5);
    ooffset = new Fl_Knob (900,400,70,70,"Offset");
    ooffset->color(180);
    ooffset->type(8); 
    ooffset->labelsize(11);
    ooffset->range(-5,5);
    ogroup_amplitud->end();
 
	ogroup_generador-> end();
	
	ogen_on = new Fl_Light_Button(960,655,30,20,"ON");  
    ogen_on->labelsize(9);     
    
    ogen_on->callback(cb_generador_on, this);
    osel_gen->callback(cb_sel_gen, this);
    ofrec_gen->callback(cb_frec_gen, this);
    oamplitud->callback(cb_amplitud, this);
    ooffset->callback(cb_offset, this);

}


/*
 * Este m�todo es el callback del boton que activa el generador de se�ales
*/
void Generador::cb_generador_on(Fl_Widget* pboton, void *any)
{
     Generador* pgener=(Generador*)any;
     pgener->cb_generador_on_in();
}

/**
 * Esta funci�n acompa�a la funci�n  cb_generador_on para activar el  
 * generador de se�ales
*/
void Generador::cb_generador_on_in(){
     if (ogen_on->value()== 1){
        activar(1);
        Encapsular('I','a','1','0',0x00,0x00);
        Transmision();
        if (bhardware){
           ogroup_generador->activate();
           ogroup_frecuencia->activate();
           ogroup_senal->activate();
           ogroup_amplitud->activate();
           oseno->value(1);
        }
        else {
             fl_message("Error de hardware");
        }
     }
     if (ogen_on->value()== 0){
        activar(0);
        ogroup_generador->deactivate(); 
     } 
     isec_generador++;
}

/*
 * Este m�todo es el callback del boton que selecciona el tipo de se�al que va a 
 * ser generada.
*/
void Generador::cb_sel_gen(Fl_Widget* pboton, void *any)
{
     Generador* pgener=(Generador*)any;
     pgener->cb_sel_gen_in();
}

/**
 * Esta funci�n acompa�a la funci�n  cb_sel_gen para seleccionar el tipo de se�al 
 * que va a ser generada.
*/
void Generador::cb_sel_gen_in(){
     if (isec_generador==0){
        Encapsular('I','i','1','1',0x00,0x00);
        Transmision();
        if (bhardware){
           otriangulo->value(0);
           oseno->value(1);
        }
        else {
             fl_message("Error de hardware");
        }
     }
     if (isec_generador==1){
        Encapsular('I','i','1','3',0x00,0x00);
        Transmision();
        if (bhardware){
           oseno->value(0);                    
           ocuadrada->value(1);
        }
        else {
             fl_message("Error de hardware");
        }
     }
     if (isec_generador==2){
        Encapsular('I','i','1','2',0x00,0x00);
        Transmision();
        if (bhardware){
           ocuadrada->value(0);
           otriangulo->value(1);
        }
        else {
             fl_message("Error de hardware");
        }
        isec_generador=-1;
     }
     isec_generador++;
}


/*
 * Este m�todo es el callback del boton que selecciona la frecuencia de la se�al 
 * que va a ser generada.
*/
void Generador::cb_frec_gen(Fl_Widget* pboton, void *any)
{
     Generador* pgener=(Generador*)any;
     pgener->cb_frec_gen_in();
}

/**
 * Esta funci�n acompa�a la funci�n  cb_frec_gen para seleccionar la frecuencia 
 * de la se�al que va a ser generada.
*/
void Generador::cb_frec_gen_in(){
     long double in = 0.18626451561698509610066226162263;         //Factor multiplicativo para la frecuencia
     int sd;
     int icont;
     int ilong;
     ovalor_frec->value(ofrec_gen->value()*5.3687);
     sd = int(in*ofrec_gen->value());
     itoa(sd,frec_hexa,16);
     ilong = strlen(frec_hexa);
     for (icont = 7; icont > 0; icont --){
         if(ilong > 0){
            if (frec_hexa[icont-ilong]>60){                                                        
               frec_hexa[ilong-1]=frec_hexa[ilong-1]-32;                                                            
            }
            else{
                 trama_control[icont]= frec_hexa[ilong-1];
            }
         }
         else{
             trama_control[icont] = '0'; 
         }
         ilong--;
     }
     trama_control[0] = 0x05;
     trama_control[8] = 0x00;
     Transmision();
}



/*
 * Este m�todo es el callback del boton que selecciona la amplitud de la se�al 
 * que va a ser generada.
*/
void Generador::cb_amplitud(Fl_Widget* pboton, void *any)
{
     Generador* pgener=(Generador*)any;
     pgener->cb_amplitud_in();
}

/**
 * Esta funci�n acompa�a la funci�n  cb_amplitud para seleccionar la amplitud 
 * de la se�al que va a ser generada.
*/
void Generador::cb_amplitud_in(){
     itoa(oamplitud->value()*102,amplitud_hexa,16);
     fl_message("amp es : %s",amplitud_hexa);
}



/*
 * Este m�todo es el callback del boton que selecciona el nivel de offset de la se�al 
 * que va a ser generada.
*/
void Generador::cb_offset(Fl_Widget* pboton, void *any)
{
     Generador* pgener=(Generador*)any;
     pgener->cb_offset_in();
}

/**
 * Esta funci�n acompa�a la funci�n  cb_offset para seleccionar el nivel de offset 
 * de la se�al que va a ser generada.
*/
void Generador::cb_offset_in(){
     int ilong;                                               
     itoa(int((ooffset->value()*25.6)+128),offset_hexa,16);
     ilong = strlen(offset_hexa);
     if (offset_hexa[0] > 60){
           offset_hexa[0]= offset_hexa[0]-32;
        }
        if (offset_hexa[1] > 60){
           offset_hexa[1]= offset_hexa[1]-32;
        }
     if (ilong>1){
        trama_control[4]= offset_hexa[0];
        trama_control[5]= offset_hexa[1];
     }
     else{
        trama_control[4]= '0';
        trama_control[5]= offset_hexa[1];
     }
     trama_control[0]= 0x01;
     trama_control[1]= 'I';
     trama_control[2]= 'n';
     trama_control[3]= '2';
     trama_control[6]= 0x04;
     trama_control[7]= 0x00;
     Transmision();
     if (~bhardware)
           fl_message("Error de hardware");
}


// class destructor
Generador::~Generador()
{
	// insert your code here
}
