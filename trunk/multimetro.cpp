// Class automatically generated by Dev-C++ New Class wizard

#include "multimetro.h" // class's header file

int isec_mult;

// class constructor
Multimetro::Multimetro(){
    Fl_Repeat_Button *oSel_mult;
    isec_mult=0;
    strcpy(cvalor,"0.000");
    strcpy(cnombre,"mult.txt"); 
    omult_on = new Fl_Light_Button(960,280,30,20,"ON");
    omult_on->labelsize(9);
    ogroup_mult = new Fl_Group (695,5,300,300,"");
    ogroup_mult->box(FL_ENGRAVED_FRAME);
    ogroup_mult->deactivate();
    odisp_mult  = new Fl_7Seg (710,15,230,105);
    odisp_mult->box(FL_EMBOSSED_FRAME);
    odisp_mult->segment_gap(2);
    odisp_mult->value("1234");
    
    oSel_mult = new Fl_Repeat_Button(768,230,150,25,"Selecci�n de Instrumento");
    oSel_mult->labelsize(12);
    ov_ac = new Fl_Light_Button(745,160,10,10,"V_ac");
    ov_ac->labelsize(12);
    ov_ac->box(FL_NO_BOX);
    ov_ac->align(FL_ALIGN_RIGHT);
    ov_dc = new Fl_Light_Button(825,160,10,10,"V_dc");
    ov_dc->labelsize(12);
    ov_dc->box(FL_NO_BOX);
    ov_dc->align(FL_ALIGN_RIGHT);
    oa_ac = new Fl_Light_Button(905,160,10,10,"A_ac");
    oa_ac->labelsize(12);
    oa_ac->box(FL_NO_BOX);
    oa_ac->align(FL_ALIGN_RIGHT);
    oa_dc = new Fl_Light_Button(745,200,10,10,"A_dc");
    oa_dc->labelsize(12);
    oa_dc->box(FL_NO_BOX);
    oa_dc->align(FL_ALIGN_RIGHT);
    oohmetro = new Fl_Light_Button(825,200,10,10,"R");
    oohmetro->labelsize(12);
    oohmetro->box(FL_NO_BOX);
    oohmetro->align(FL_ALIGN_RIGHT);
    ocont = new Fl_Light_Button(905,200,10,10,"Cont");
    ocont->labelsize(12);
    ocont->box(FL_NO_BOX);
    ocont->align(FL_ALIGN_RIGHT);      
    ogroup_mult-> end();
     
    oSel_mult->callback(cb_sel_instrumento, this);
    omult_on->callback(cb_mult_on, this);
}

// class destructor
Multimetro::~Multimetro()
{
	// insert your code here
}

/*
 * Este m�todo es el callback del boton selector de instrumentos
 * en el mult�metro
 */
void Multimetro::cb_sel_instrumento(Fl_Widget* pboton, void *any)
{
     Multimetro* pmult=(Multimetro*)any;
     pmult->cb_sel_instrumento_in();
}

/**
* Esta funci�n acompa�a la funci�n  cb_sel_instrumento 
* para realizar los llamados de callback del selector de instrumento
* en el multimetro 
*/
void Multimetro::cb_sel_instrumento_in(){
     if (isec_mult==0){
     Fl::remove_timeout(cb_timer_mult, this);
     ocont->value(0);
     ov_ac->value(1);
     instrument = volt_ac;
     config_instrumento(volt_ac);
     }
     if (isec_mult==1){
     Fl::remove_timeout(cb_timer_mult, this);
     ov_ac->value(0);
     ov_dc->value(1);
     instrument = volt_dc;
     config_instrumento(volt_dc);
     }
     if (isec_mult==2){
     Fl::remove_timeout(cb_timer_mult, this);
     fl_alert("Verifique las puntas de prueba");
     ov_dc->value(0);
     oa_ac->value(1);
     instrument = amp_ac;
     config_instrumento(amp_ac);
     }
     if (isec_mult==3){
     Fl::remove_timeout(cb_timer_mult, this);
     oa_ac->value(0);
     oa_dc->value(1);
     instrument = amp_dc;
     config_instrumento(amp_dc);
     }
     if (isec_mult==4){
     Fl::remove_timeout(cb_timer_mult, this);
     oa_dc->value(0);
     oohmetro->value(1);
     instrument = ohm;
     config_instrumento(ohm);
     }
     if (isec_mult==5){
     Fl::remove_timeout(cb_timer_mult, this);
     oohmetro->value(0);
     ocont->value(1);
     instrument = continuidad;
     config_instrumento(ohm);
     isec_mult=-1;
     }
     isec_mult++;
}

/*
 * Este m�todo es el callback del boton que activa el multimetro
*/
void Multimetro::cb_mult_on(Fl_Widget* pboton, void *any)
{
     Multimetro* pmult=(Multimetro*)any;
     pmult->cb_mult_on_in();
}

/**
 * Esta funci�n acompa�a la funci�n  cb_mult_on para activar el  
 * multimetro
*/
void Multimetro::cb_mult_on_in(){
     if (omult_on->value()== 1){
        activar(1);
        ogroup_mult->activate();
     }
     if (omult_on->value()== 0){
        activar(0);
        ogroup_mult->deactivate(); 
     } 
}

/**
* Este m�todo coloca el valor de la medici�n en el display
* del mult�metro.
*/
void Multimetro::set_disp_mult(char svalor [4]){
     odisp_mult->value(svalor);      
}

/**
 * Este m�todo es el callback del timer para realizar la solicitud 
 * de datos del canal 1 del osciloscopio al hardware.  
*/
void Multimetro::cb_timer_mult(void *pany)
{
     Multimetro* pmult=(Multimetro*)pany;
     pmult->cb_timer_mult_in();
}

/**
 * Esta funci�n acompa�a la funci�n cb_timer_ch1
 * para realizar los llamados de callback del timer 
*/
void Multimetro::cb_timer_mult_in(){
     switch (instrument) {
            case volt_ac:
                 Encapsular('K','p','1','2');
                 Transmision();
                 set_disp_mult((buf_mult));
            case volt_dc:
                 Encapsular('K','p','1','1');
                 Transmision();
                 set_disp_mult((buf_mult));
            case amp_ac:
                 Encapsular('K','p','1','4');
                 Transmision();
                 set_disp_mult((buf_mult));
            case amp_dc:
                 Encapsular('K','p','1','3');
                 Transmision();
                 set_disp_mult((buf_mult));
            case ohm:
                 Encapsular('K','p','1','5');
                 Transmision();
                 set_disp_mult((buf_mult));
     ;}
     Fl::repeat_timeout(0.5, cb_timer_mult, this);
}


/**
 * Envia la informaci�n al hardware para configurar el instrumento
 * del multimetro
*/
void Multimetro::config_instrumento(int instrumento){
     switch (instrumento) {
            case volt_ac:
                 Encapsular('K','q','1','2');
                 Transmision();
                 if (bhardware)
                    //Fl::add_timeout(0.005, cb_timer_mult, this);
            case volt_dc:
                 Encapsular('K','q','1','1');
                 Transmision();
                 if (bhardware)
                    //Fl::add_timeout(0.005, cb_timer_mult, this);
            case amp_ac:
                 Encapsular('K','q','1','4');
                 Transmision();
                 if (bhardware)
                    //Fl::add_timeout(0.005, cb_timer_mult, this);
            case amp_dc:
                 Encapsular('K','q','1','3');
                 Transmision();
                 if (bhardware)
                    //Fl::add_timeout(0.005, cb_timer_mult, this); 
            case ohm:
                 Encapsular('K','q','1','5');
                 Transmision();
                 if (bhardware)
                    //Fl::add_timeout(0.005, cb_timer_mult, this); 
    ;}
}