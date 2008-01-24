// Class automatically generated by Dev-C++ New Class wizard

#include "multimetro.h" // class's header file


// class constructor
Multimetro::Multimetro(){
                            
    Fl_Tooltip::disable();
    strcpy(cvalor,"0.000");
    strcpy(cnombre,"mult.txt"); 
    ogroup_mult = new Fl_Group (735,5,285,360,"");
    ogroup_mult->box(FL_ENGRAVED_FRAME);
    ogroup_mult->box(FL_UP_BOX);
    ogroup_mult->deactivate();
    odisp_mult  = new Fl_7Seg (740,53,230,99);
    odisp_mult->color(FL_BLACK);
    odisp_mult->thickness(5);
    odisp_mult->dot_len(7);
    odisp_mult->align_text(FL_ALIGN_RIGHT);
    odisp_mult->segment_gap(2);
    odisp_mult->value("00.0");
    ounidades = new Fl_Box (968,53,43,99,"");
    ounidades->labelsize(20);
    ounidades->labelcolor(FL_WHITE);
    ounidades->box(FL_FLAT_BOX);
    ounidades->color(FL_BLACK);
    ohelp_mult  = new Fl_Button (785,340,40,16,"Help");
    ohelp_mult->labelsize(10);
    //ohelp_mult->tooltip("Inicia la ayuda de usuario para el uso del mult�metro");
    ovolt_ac = new Fl_Button(765,189,63,35,"V_ac");
    ovolt_ac->clear();
    ovolt_ac->box(FL_UP_BOX);
    ovolt_dc = new Fl_Button(842,189,63,35,"V_dc");
    ovolt_dc->box(FL_UP_BOX);
    oamp_ac = new Fl_Button(922,190,63,35,"A_ac");
    oamp_ac->box(FL_UP_BOX);
    oamp_dc = new Fl_Button(765,273,63,35,"A_dc");
    oamp_dc->box(FL_UP_BOX);
    oohm = new Fl_Button(842,273,63,35,"R");
    oohm->box(FL_UP_BOX);
    ocontinuidad = new Fl_Button(922,273,63,35,"Cont");
    ocontinuidad->box(FL_UP_BOX);
    
    ogroup_mult-> end();
      
    omult_on = new Fl_Light_Button(745,325,38,30,"ON");
    omult_on->labelsize(9); 
    omult_on->callback(cb_mult_on, this);
    ovolt_ac->callback(cb_volt_ac, this);
    ovolt_dc->callback(cb_volt_dc, this);
    oamp_ac->callback(cb_amp_ac, this);
    oamp_dc->callback(cb_amp_dc, this);
    oohm->callback(cb_ohm, this);
    ocontinuidad->callback(cb_cont, this);
}

// class destructor
Multimetro::~Multimetro(){
	// insert your code here
}


/*
 * Este m�todo es el callback del boton que activa el multimetro
*/
void Multimetro::cb_mult_on(Fl_Widget* pboton, void *any){
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
        Encapsular('K','a','1','0',0x00,0x00);
        Transmision();
        if (bhardware){
           ogroup_mult->activate();
           Fl_Tooltip::enable();
        }
        else {
             fl_message("Error de hardware");
             omult_on->value(0);
        }
     }
     if (omult_on->value()== 0){
        activar(0);
        ogroup_mult->deactivate();
        Fl_Tooltip::disable(); 
     } 
}

/**
* Este m�todo coloca el valor de la medici�n en el display
* del mult�metro.
*/
void Multimetro::set_disp_mult(char svalor [4]){
     odisp_mult->value((svalor));      
}

/**
 * Este m�todo es el callback del timer para realizar la solicitud 
 * de datos del canal 1 del osciloscopio al hardware.  
*/
void Multimetro::cb_timer_mult(void *pany){
     Multimetro* pmult=(Multimetro*)pany;
     pmult->cb_timer_mult_in();
}

/**
 * Esta funci�n acompa�a la funci�n cb_timer_ch1 para realizar los llamados de 
 * callback del timer 
*/
void Multimetro::cb_timer_mult_in(){
     Encapsular('K','p','1','0',0x00,0x00);
     Transmision();
     escalar_valor(1);
     set_disp_mult((buf_mult));
     Fl::repeat_timeout(0.5, cb_timer_mult, this);
}


/**
 * Envia la informaci�n al hardware para configurar el instrumento
 * del multimetro
*/
void Multimetro::config_instrumento(int instrumento){
     switch (instrumento) {
            case volt_ac:
                 Encapsular('K','q','1','2',0x00,0x00);
                 Transmision();
                 if (bhardware)
                 Fl::add_timeout(0.005, cb_timer_mult, this);
                 break;
            case volt_dc:
                 Encapsular('K','q','1','1',0x00,0x00);
                 Transmision();
                 if (bhardware)
                 Fl::add_timeout(0.005, cb_timer_mult, this);
                 break;
            case amp_ac:
                 Encapsular('K','q','1','4',0x00,0x00);
                 Transmision();
                 if (bhardware)
                 Fl::add_timeout(0.005, cb_timer_mult, this);
                 break;
            case amp_dc:
                 Encapsular('K','q','1','3',0x00,0x00);
                 Transmision();
                 if (bhardware)
                 Fl::add_timeout(0.005, cb_timer_mult, this); 
                 break;
            case ohm:
                 Encapsular('K','q','1','5',0x00,0x00);
                 Transmision();
                 if (bhardware)
                 Fl::add_timeout(0.005, cb_timer_mult, this); 
                 break;
    }
}


/**
 * Calcula el valor de la medicion en el rango de escala en que se encuentre
*/
void Multimetro::escalar_valor(int escala){
     double fvalor_escalado = 0.0;
     ivalor_conversion = atoi(buf_mult);
     fvalor_escalado = ivalor_conversion/20;
     sprintf(cvalor,"%.4g",fvalor_escalado);
}


/**
 * Callback del bot�n que activa el medidor de voltaje en ac
*/
void Multimetro::cb_volt_ac(Fl_Widget* pboton, void *any){
     Multimetro* pmult=(Multimetro*)any;
     pmult->cb_volt_ac_in();
}

/**
 * Callback del bot�n que activa el medidor de voltaje en ac
*/
void Multimetro::cb_volt_ac_in(){
     if (ovolt_ac->value()== 0){
        Fl::remove_timeout(cb_timer_mult, this);
        ovolt_dc->box(FL_UP_BOX);
        ovolt_dc->clear();
        oamp_ac->box(FL_UP_BOX);
        oamp_ac->clear();
        oamp_dc->box(FL_UP_BOX);
        oamp_dc->clear();
        oohm->box(FL_UP_BOX);
        oohm->clear();
        ocontinuidad->box(FL_UP_BOX);
        ocontinuidad->clear();                     
        ovolt_ac->box(FL_DOWN_BOX);
        ovolt_ac->set();
        instrument = volt_ac;
        ounidades->label("VAC");
        config_instrumento(volt_ac);
     }
     else{
          ovolt_ac->box(FL_UP_BOX);
          ovolt_ac->clear();
     }
}


/**
 * Callback del bot�n que activa el medidor de voltaje en dc
*/
void Multimetro::cb_volt_dc(Fl_Widget* pboton, void *any){
     Multimetro* pmult=(Multimetro*)any;
     pmult->cb_volt_dc_in();
}

/**
 * Callback del bot�n que activa el medidor de voltaje en dc
*/
void Multimetro::cb_volt_dc_in(){
     if (ovolt_dc->value()== 0){
        Fl::remove_timeout(cb_timer_mult, this);
        ovolt_ac->box(FL_UP_BOX);
        ovolt_ac->clear();
        oamp_ac->box(FL_UP_BOX);
        oamp_ac->clear();
        oamp_dc->box(FL_UP_BOX);
        oamp_dc->clear();
        oohm->box(FL_UP_BOX);
        oohm->clear();
        ocontinuidad->box(FL_UP_BOX);
        ocontinuidad->clear();                     
        ovolt_dc->box(FL_DOWN_BOX);
        ovolt_dc->set();
        instrument = volt_dc;
        ounidades->label("VDC");
        config_instrumento(volt_dc);
     }
     else{
          ovolt_dc->box(FL_UP_BOX);
          ovolt_dc->clear();
     }
}


/**
 * Callback del bot�n que activa el medidor de corriente en ac
*/
void Multimetro::cb_amp_ac(Fl_Widget* pboton, void *any){
     Multimetro* pmult=(Multimetro*)any;
     pmult->cb_amp_ac_in();
}

/**
 * Callback del bot�n que activa el medidor de corriente en ac
*/
void Multimetro::cb_amp_ac_in(){
    if (oamp_ac->value()== 0){
        Fl::remove_timeout(cb_timer_mult, this);
        //fl_alert("Verifique las puntas de prueba");
        ovolt_ac->box(FL_UP_BOX);
        ovolt_ac->clear();
        ovolt_dc->box(FL_UP_BOX);
        ovolt_dc->clear();
        oamp_dc->box(FL_UP_BOX);
        oamp_dc->clear();
        oohm->box(FL_UP_BOX);
        oohm->clear();
        ocontinuidad->box(FL_UP_BOX);
        ocontinuidad->clear();                     
        oamp_ac->box(FL_DOWN_BOX);
        oamp_ac->set();
        instrument = amp_ac;
        ounidades->label("AAC");
        //fl_message("Verifique las puntas de prueba");
        config_instrumento(amp_ac);
     }
     else{
          oamp_ac->box(FL_UP_BOX);
          oamp_ac->clear();
     } 
}


/**
 * Callback del bot�n que activa el medidor de corriente en dc
*/
void Multimetro::cb_amp_dc(Fl_Widget* pboton, void *any){
     Multimetro* pmult=(Multimetro*)any;
     pmult->cb_amp_dc_in();
}

/**
 * Callback del bot�n que activa el medidor de corriente en dc
*/
void Multimetro::cb_amp_dc_in(){
    if (oamp_dc->value()== 0){
        Fl::remove_timeout(cb_timer_mult, this);
        fl_alert("Verifique las puntas de prueba");
        ovolt_ac->box(FL_UP_BOX);
        ovolt_ac->clear();
        ovolt_dc->box(FL_UP_BOX);
        ovolt_dc->clear();
        oamp_ac->box(FL_UP_BOX);
        oamp_ac->clear();
        oohm->box(FL_UP_BOX);
        oohm->clear();
        ocontinuidad->box(FL_UP_BOX);
        ocontinuidad->clear();                     
        oamp_dc->box(FL_DOWN_BOX);
        oamp_dc->set();
        instrument = amp_dc;
        ounidades->label("ADC");
        config_instrumento(amp_dc);
     }
     else{
          oamp_dc->box(FL_UP_BOX);
          oamp_dc->clear();
     } 
}


/**
 * Callback del bot�n que activa el medidor de resistencia
*/
void Multimetro::cb_ohm(Fl_Widget* pboton, void *any){
     Multimetro* pmult=(Multimetro*)any;
     pmult->cb_ohm_in();
}

/**
 * Callback del bot�n que activa el medidor de resistencia
*/
void Multimetro::cb_ohm_in(){
     if (oohm->value()== 0){
        Fl::remove_timeout(cb_timer_mult, this);
        ovolt_ac->box(FL_UP_BOX);
        ovolt_ac->clear();
        ovolt_dc->box(FL_UP_BOX);
        ovolt_dc->clear();
        oamp_dc->box(FL_UP_BOX);
        oamp_dc->clear();
        oamp_ac->box(FL_UP_BOX);
        oamp_ac->clear();
        ocontinuidad->box(FL_UP_BOX);
        ocontinuidad->clear();                     
        oohm->box(FL_DOWN_BOX);
        oohm->set();
        instrument = ohm;
        ounidades->label("R");
        config_instrumento(ohm);
     }
     else{
          oohm->box(FL_UP_BOX);
          oohm->clear();
     }
}


/**
 * Callback del bot�n que activa el medidor de continuidad
*/
void Multimetro::cb_cont(Fl_Widget* pboton, void *any){
     Multimetro* pmult=(Multimetro*)any;
     pmult->cb_cont_in();
}

/**
 * Callback del bot�n que activa el medidor de continuidad
*/
void Multimetro::cb_cont_in(){
     if (ocontinuidad->value()== 0){
        Fl::remove_timeout(cb_timer_mult, this);
        ovolt_ac->box(FL_UP_BOX);
        ovolt_ac->clear();
        ovolt_dc->box(FL_UP_BOX);
        ovolt_dc->clear();
        oamp_dc->box(FL_UP_BOX);
        oamp_dc->clear();
        oamp_ac->box(FL_UP_BOX);
        oamp_ac->clear();
        oohm->box(FL_UP_BOX);
        oohm->clear();                     
        ocontinuidad->box(FL_DOWN_BOX);
        ocontinuidad->set();
        instrument = continuidad;
        ounidades->label("Cont");
        config_instrumento(ohm);
     }
     else{
          ocontinuidad->box(FL_UP_BOX);
          ocontinuidad->clear();
     }
}
