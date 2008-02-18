// Class automatically generated by Dev-C++ New Class wizard

#include "multimetro.h" // class's header file


/*******************************************************************************
 * Mult�metro: Clase que representa las funciones del instrumento mult�metro con
 *             6 tipos de medici�n:
 * Volt�metro AC: Mide la magnitud de voltaje True RMS de una se�al alterna.
 * Volt�metro DC: Mide la magnitud de voltaje de una se�al continua.
 * Amper�metro AC: Mide la magnitud de corriente de una se�al alterna.
 * Amper�metro DC: Mide la magnitud de corriente de una se�al continua. 
 * Resistencia: Mide la magnitud de resistencia el�ctrica.
 * Continuidad: Reviza la continuidad el�ctrica.             
*******************************************************************************/
Multimetro::Multimetro(){
                            
    //Fl_Tooltip::disable();
    fvalor_escalado = 0.0;
    strcpy(cvalor,"0.000");                                                     //Inicializaci�n del valor mostrado en el dsiplay
    strcpy(cnombre,"mult.txt"); 
    ogroup_mult = new Fl_Group (735,5,285,360,"");                              //Inicio del grupo de los elementos del mult�metro
    ogroup_mult->box(FL_ENGRAVED_FRAME);
    ogroup_mult->box(FL_UP_BOX);
    ogroup_mult->deactivate();
    odisp_mult  = new Fl_7Seg (740,53,230,99);                                  //Display del mult�metro
    odisp_mult->color(FL_BLACK);
    odisp_mult->thickness(5);
    odisp_mult->dot_len(7);
    odisp_mult->align_text(FL_ALIGN_RIGHT);
    odisp_mult->segment_gap(2);
    odisp_mult->value("00.0");
    ounidades = new Fl_Box (968,53,43,99,"VAC");                                   //Display de las unidades de medida
    ounidades->labelsize(20);
    ounidades->labelcolor(FL_WHITE);
    ounidades->box(FL_FLAT_BOX);
    ounidades->color(FL_BLACK);
    ohelp_mult  = new Fl_Button (935,23,40,16,"Help");                          //Bot�n que inicia la ventana de ayuda de uso del instrumento.
    ohelp_mult->labelsize(9);
    //ohelp_mult->tooltip("Inicia la ayuda de usuario para el uso del mult�metro");
    ovolt_ac = new Fl_Button(765,189,63,35,"V_ac");                             //Bot�n que activa el instrumento volt�metro AC.   
    ovolt_ac->clear();
    ovolt_ac->box(FL_UP_BOX);
    ovolt_dc = new Fl_Button(842,189,63,35,"V_dc");                             //Bot�n que activa el instrumento volt�metro DC.
    ovolt_dc->box(FL_UP_BOX);
    oamp_ac = new Fl_Button(922,190,63,35,"A_ac");                              //Bot�n que activa el instrumento Amper�metro AC.
    oamp_ac->box(FL_UP_BOX);
    oamp_dc = new Fl_Button(765,273,63,35,"A_dc");                              //Bot�n que activa el instrumento Amper�metro DC.
    oamp_dc->box(FL_UP_BOX);
    oohm = new Fl_Button(842,273,63,35,"R");                                    //Bot�n que activa el instrumento Ohmetro.
    oohm->box(FL_UP_BOX);
    ocontinuidad = new Fl_Button(922,273,63,35,"Cont");                         //Bot�n que activa el instrumento Medidor de continuidad.
    ocontinuidad->box(FL_UP_BOX);
    
    Manual = new Fl_Help_Dialog;
    Manual->load("help_multimetro.html");                                       //Ventana de ayuda de uso del mult�metro
    
    ogroup_mult-> end();                                                        //Fin del grupo de elementos del mult�metro
      
    omult_on = new Fl_Light_Button(892,10,33,42,"ON");                          //Bot�n que enciende/apaga el instrumento
    omult_on->labelsize(9); 
    
    // Callbacks de los diferentes botones del instrumento
    omult_on->callback(cb_mult_on, this);
    ovolt_ac->callback(cb_volt_ac, this);
    ovolt_dc->callback(cb_volt_dc, this);
    oamp_ac->callback(cb_amp_ac, this);
    oamp_dc->callback(cb_amp_dc, this);
    oohm->callback(cb_ohm, this);
    ocontinuidad->callback(cb_cont, this);
    ohelp_mult->callback(cb_help,this);
}

// class destructor
Multimetro::~Multimetro(){
}


/*******************************************************************************
 * Multimetro::cb_mult_on: Callback del bot�n que activa/desactiva el mult�metro
 * El Callaback consta de la funci�n static e inline cb_mult_on y cb_mult_on_in.
 * Al encender el instrumento se inicia el instrumento volt�metro AC por defecto 
*******************************************************************************/
void Multimetro::cb_mult_on(Fl_Widget* pboton, void *any){
     Multimetro* pmult=(Multimetro*)any;
     pmult->cb_mult_on_in();
}

void Multimetro::cb_mult_on_in(){
     if (omult_on->value()== 1){                                                //Encender Mult�metro
        activar(1);
        Encapsular('K','a','1','0',0x00,0x00);                                  //Trama de inicio de mult�metro
        Transmision();
        if (bhardware){
           ogroup_mult->activate();
           cb_volt_ac_in();                                                     //Inicio por defecto de volt�metro AC
           ounidades->label("VAC");
           ounidades->redraw();
        }
        else {
             fl_message("Error de hardware");
             omult_on->value(0);
        }
     }
     if (omult_on->value()== 0){                                                //Apagar el Mult�metro
        Fl::remove_timeout(cb_timer_mult, this);
        activar(0);
        ovolt_ac->box(FL_UP_BOX);
        ovolt_ac->clear();
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
        ogroup_mult->deactivate();
        Fl_Tooltip::disable(); 
     } 
}

/*******************************************************************************
* Multimetro::set_disp_mult: M�todo para colocar el valor de la medici�n en el 
*                            display del mult�metro.
* svalor : Cadena de caracteres con el valor de la medici�n realizada
*******************************************************************************/
void Multimetro::set_disp_mult(char svalor [4]){
     odisp_mult->value((svalor));      
}

/*******************************************************************************
 * Multimetro::cb_timer_mult: Callback del timer para realizar la solicitud 
 *                            de datos del mult�metro.  
 * El Callaback consta de la funci�n static e inline cb_timer_mult y 
 * cb_timer_mult_in.
 * Se env�a una trama de solicitud de datos de mult�metro al hardware Mu04.
 * escalar_valor(x): Funci�n que se encarga de escalar el valor de la medida en 
 *                   la escala adecuada.
 *                   El param�tro es el valor de la escala que env�a el hardware.
 * set_disp_mult(): Se env�a el dato escalado para mostrarlo en el display.
 * Se repite el timer de solicitud de datos cada medio segundo. 
*******************************************************************************/

void Multimetro::cb_timer_mult(void *pany){
     Multimetro* pmult=(Multimetro*)pany;
     pmult->cb_timer_mult_in();
}

void Multimetro::cb_timer_mult_in(){
     Encapsular('K','p','1','0',0x00,0x00);
     Transmision();
     escalar_valor(imult_escala);
     set_disp_mult(cvalor);
     ounidades->redraw();
     Fl::repeat_timeout(0.5, cb_timer_mult, this);
}


/*******************************************************************************
 * Multimetro::config_instrumento: Envia la trama de selecci�n de instrumento al 
 *                                 hardware para configurar el mult�metro.
 * Este m�todo es llamado en los callbacks de los botones que seleccionan cada
 * instrumento del mult�metro.
 * Se env�a al hardware una trama de tipo [K,q,1,X,0,0] donde X es el n�emro del 
 * instrumento seleccionado:
 * X = 1: Volt�metro DC.
 * X = 2: Volt�metro AC.
 * X = 3: Amper�metro DC.
 * X = 1: Amper�metro AC.
 * X = 1: Ohmetro DC.
 * Luego de configurar el instrumento se inicia el timer de solicitud de datos.
*******************************************************************************/

void Multimetro::config_instrumento(int instrumento){
     switch (instrumento) {
            case volt_ac:
                 Encapsular('K','q','1','2',0x00,0x00);
                 Transmision();
                 if (bhardware)
                 Fl::add_timeout(0.05, cb_timer_mult, this);
                 break;
            case volt_dc:
                 Encapsular('K','q','1','1',0x00,0x00);
                 Transmision();
                 if (bhardware)
                 Fl::add_timeout(0.05, cb_timer_mult, this);
                 break;
            case amp_ac:
                 Encapsular('K','q','1','4',0x00,0x00);
                 Transmision();
                 if (bhardware)
                 Fl::add_timeout(0.05, cb_timer_mult, this);
                 break;
            case amp_dc:
                 Encapsular('K','q','1','3',0x00,0x00);
                 Transmision();
                 if (bhardware)
                 Fl::add_timeout(0.05, cb_timer_mult, this); 
                 break;
            case ohm:
                 Encapsular('K','q','1','5',0x00,0x00);
                 Transmision();
                 if (bhardware)
                 Fl::add_timeout(0.05, cb_timer_mult, this); 
                 break;
    }
}


/*******************************************************************************
 * Multimetro::escalar_valor: Calcula el valor de la medici�n en el rango de 
 *                            escala en que se encuentre.
 * escala: Dato de escala enviada desde el hardware en la que se encuentra el
 *         valor de la medici�n.
 * Para calcular el resultado de la medici�n se realiza la siguiente formula:
 * (valor_medici�n-256)*Factor.
 * Por cada escala hay un Factor por el que se debe multiplicar para obtener el 
 * valor de la medici�n.  
*******************************************************************************/
void Multimetro::escalar_valor(int escala){
     ivalor_conversion = atoi(buf_mult);
     switch (escala) {
            case 1:
                 if (instrument==volt_ac){
                    fvalor_escalado = (ivalor_conversion-256)*0.78;
                 }
                 else if (instrument==volt_dc){
                    fvalor_escalado = (ivalor_conversion-256)*0.78;
                 }
                 else if (instrument==amp_ac){
                    fvalor_escalado = (ivalor_conversion-256)*0.78;
                 }
                 else if (instrument==amp_dc){
                    fvalor_escalado = (ivalor_conversion-256)*0.78;
                 }
                 else if (instrument==ohm){
                    fvalor_escalado = (ivalor_conversion-256)*0.08;
                 }
                 break; 
            case 2:
                 if (instrument==volt_ac){
                    fvalor_escalado = (ivalor_conversion-256)*0.01;
                 }
                 else if (instrument==volt_dc){
                    fvalor_escalado = (ivalor_conversion-256)*0.01;
                 }
                 else if (instrument==amp_ac){
                    fvalor_escalado = (ivalor_conversion-256)*0.01;
                 }
                 else if (instrument==amp_dc){
                    fvalor_escalado = (ivalor_conversion-256)*0.01;
                 }
                 else if (instrument==ohm){
                    fvalor_escalado = (ivalor_conversion-256)*0.78;
                 }
                 break;
            case 3:
                 if (instrument==volt_ac){
                    fvalor_escalado = (ivalor_conversion-256)*0.08;
                 }
                 else if (instrument==volt_dc){
                    fvalor_escalado = (ivalor_conversion-256)*0.08;
                 }
                 else if (instrument==amp_ac){
                    fvalor_escalado = (ivalor_conversion-256)*0.08;
                 }
                 else if (instrument==amp_dc){
                    fvalor_escalado = (ivalor_conversion-256)*0.08;
                 }
                 else if (instrument==ohm){
                    fvalor_escalado = (ivalor_conversion-256)*7.81;
                 }
                 break;
            case 4:
                 if (instrument==volt_ac){
                    fvalor_escalado = (ivalor_conversion-256)*0.78;
                 }
                 else if (instrument==volt_dc){
                    fvalor_escalado = (ivalor_conversion-256)*0.78;
                 }
                 else if (instrument==amp_ac){
                    fvalor_escalado = (ivalor_conversion-256)*0.78;
                 }
                 else if (instrument==amp_dc){
                    fvalor_escalado = (ivalor_conversion-256)*0.78;
                 }
                 else if (instrument==ohm){
                    fvalor_escalado = (ivalor_conversion-256)*7812.5;
                 }
                 break;
            case 5:
                 if (instrument==volt_dc){
                    fvalor_escalado = (ivalor_conversion-256)*7.81;
                 }
                 else if (instrument==amp_dc){
                    fvalor_escalado = (ivalor_conversion-256)*0.08;
                 }
                 break;
            case 6:
                 if (instrument==volt_dc){
                    fvalor_escalado = (ivalor_conversion-256)*0.78;
                 }
                 else if (instrument==amp_dc){
                    fvalor_escalado = (ivalor_conversion-256)*0.78;
                 }
                 break;
            case 7:
                 if (instrument==volt_dc){
                    fvalor_escalado = (ivalor_conversion-256)*0.01;
                 }
                 else if (instrument==amp_dc){
                    fvalor_escalado = (ivalor_conversion-256)*0.01;
                 }
                 break;
            case 8:
                 if (instrument==volt_dc){
                    fvalor_escalado = (ivalor_conversion-256)*0.08;
                 }
                 else if (instrument==amp_dc){
                    fvalor_escalado = (ivalor_conversion-256)*0.08;
                 }
                 break;
            case 9:
                 if (instrument==volt_dc){
                    fvalor_escalado = (ivalor_conversion-256)*0.78;
                 }
                 else if (instrument==amp_dc){
                    fvalor_escalado = (ivalor_conversion-256)*0.78;
                 }
                 break; 
     }
     sprintf(cvalor,"%.3g",fvalor_escalado);
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
        //fl_message("escala es: %d",imult_escala);
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
        Beep(1000,1000);
     }
     else{
          ocontinuidad->box(FL_UP_BOX);
          ocontinuidad->clear();
     }
}


/**
 * 
*/
void Multimetro::cb_help(Fl_Widget* pboton, void *any){
     Multimetro* pmult=(Multimetro*)any;
     pmult->cb_help_in();
}

/**
 * 
*/
void Multimetro::cb_help_in(){

      Manual->show();
}
