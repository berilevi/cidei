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
    Fl_Tooltip::enable();
    fvalorEscalado = 0.0;
    strcpy(cvalor,"0.000");                                                     //Inicializaci�n del valor mostrado en el dsiplay
    strcpy(cnombre,"mult.txt"); 
    
    //imultimetro = new Fl_PNG_Image("mult.png");
    ogroup_mult = new Fl_Group (735,5,285,360,"");                              //Inicio del grupo de los elementos del mult�metro
    ogroup_mult->box(FL_ENGRAVED_FRAME);
    ogroup_mult->box(FL_UP_BOX);
    ogroup_mult->deactivate();
    boxgroup = new Fl_Box(735,12,285,360,"");
    /*odispMult  = new Fl_7Seg (738,42,230,99);                                   //Display del mult�metro
    odispMult->color(FL_BLACK);
    odispMult->thickness(5);
    odispMult->dot_len(7);
    odispMult->align_text(FL_ALIGN_RIGHT);
    odispMult->segment_gap(2);
    odispMult->value("00.0");*/
    
      
    
    odispMult  = new Fl_Box (738,42,230,99,"0.00");
    odispMult->box(FL_FLAT_BOX);
    odispMult->color(FL_BLACK);
    odispMult->labelcolor(FL_WHITE);
    odispMult->labelsize(80);
    
    ounidades = new Fl_Box (968,42,50,99,"VAC");                                //Display de las unidades de medida
    ounidades->labelsize(20);
    ounidades->labelcolor(FL_WHITE);
    ounidades->box(FL_FLAT_BOX);
    ounidades->color(FL_BLACK);
    
   // ohelpMult  = new Fl_Button (935,23,40,16,"Help");                           //Bot�n que inicia la ventana de ayuda de uso del instrumento.
   // ohelpMult->labelsize(9);
    //ohelpMult->box(FL_NO_BOX);
   // ohelpMult->tooltip("Inicia la ayuda de usuario para el uso del mult�metro");
    
    oayudaMult = new Fl_Check_Button(985,20,20,20,"");
    
    
    
    
    ovoltAc = new Fl_Button(762,169,80,25,"");                              //Bot�n que activa el instrumento volt�metro AC.   
    //ovoltAc->clear();   
   // multVac = new Fl_PNG_Image("vacg.png");
    //ovoltAc->image(multVac);
    ovoltAc->box(FL_UP_BOX);
    ovoltDc = new Fl_Button(913,169,80,25,"");                              //Bot�n que activa el instrumento volt�metro DC.
    ovoltDc->box(FL_UP_BOX);
    oampAc = new Fl_Button(762,229,80,25,"");                               //Bot�n que activa el instrumento Amper�metro AC.
    oampAc->box(FL_UP_BOX);
    oampDc = new Fl_Button(913,229,80,25,"");                               //Bot�n que activa el instrumento Amper�metro DC.
    oampDc->box(FL_UP_BOX);
    oohm = new Fl_Button(762,323,80,25,"");                                    //Bot�n que activa el instrumento Ohmetro.
    oohm->box(FL_UP_BOX);
    ocontinuidad = new Fl_Button(913,325,80,25,"");                         //Bot�n que activa el instrumento Medidor de continuidad.
    ocontinuidad->box(FL_UP_BOX);
    
    oboxOnMult = new Fl_Box(942,17,33,27,"");
    boxVac = new Fl_Box(762,177,80,25,"");
    boxVdc = new Fl_Box(913,177,80,25,"");
    boxAac = new Fl_Box(762,237,80,25,"");
    boxAdc = new Fl_Box(913,237,80,25,"");
    boxOhm = new Fl_Box(762,331,80,25,"");
    boxCont = new Fl_Box(913,332,80,24,"");
    
    //manualMult = new Fl_Help_Dialog;
    //manualMult->load("help_multimetro.html");                                 //Ventana de ayuda de uso del mult�metro
    
    
    ionMult = new Fl_PNG_Image("onmult.png"); 
    oboxOnMult->image(ionMult);
    
    imultimetro = new Fl_PNG_Image("mult.png");
    boxgroup->image(imultimetro); 
    
    iVoltAc = new Fl_PNG_Image("vacy.png");
    boxVac->image(iVoltAc);
    
    iVoltDc = new Fl_PNG_Image("vdc.png");
    boxVdc->image(iVoltDc);
    
    iAmpAc = new Fl_PNG_Image("aac.png");
    boxAac->image(iAmpAc);
    
    iAmpDc = new Fl_PNG_Image("adc.png");
    boxAdc->image(iAmpDc);
    
    iOhm = new Fl_PNG_Image("ohm.png");
    boxOhm->image(iOhm);
    
    iCont = new Fl_PNG_Image("cont.png");
    boxCont->image(iCont);
    
    ogroup_mult-> end();                                                        //Fin del grupo de elementos del mult�metro
      
     
    //omultOn = new Fl_Light_Button(942,10,33,27,"");                          //Bot�n que enciende/apaga el instrumento
    omultOn = new Fl_Button(942,10,33,27,"");
    omultOn->type(FL_TOGGLE_BUTTON);
    omultOn->box(FL_ENGRAVED_FRAME);
    //omultOn->labelsize(9); 
    
    
    
    // Callbacks de los diferentes botones del instrumento
    omultOn->callback(cbMultOn, this);
    ovoltAc->callback(cbVoltAc, this);
    ovoltDc->callback(cbVoltDc, this);
    oampAc->callback(cbAmpAc, this);
    oampDc->callback(cbAmpDc, this);
    oohm->callback(cbOhm, this);
    ocontinuidad->callback(cbCont, this);
   // ohelpMult->callback(cbHelpMult,this);
    oayudaMult->callback(cbAyudaMult,this);
    
}

// class destructor
Multimetro::~Multimetro(){
}


/*******************************************************************************
 * Multimetro::cbMultOn: Callback del bot�n que activa/desactiva el mult�metro
 * El Callaback consta de la funci�n static e inline cbMultOn y cbMultOnIn.
 * Al encender el instrumento se inicia el instrumento volt�metro AC por defecto 
*******************************************************************************/
void Multimetro::cbMultOn(Fl_Widget* pboton, void *any){
     Multimetro* pmult=(Multimetro*)any;
     pmult->cbMultOnIn();
}

void Multimetro::cbMultOnIn(){
     if (omultOn->value()== 1){                                                //Encender Mult�metro
        activar(1);
        Encapsular('K','a','1','0',0x00,0x00);                                  //Trama de inicio de mult�metro
        Transmision();
        if (bhardware==1){
           ogroup_mult->activate();
           cbVoltAcIn();                                                     //Inicio por defecto de volt�metro AC
           ounidades->label("VAC");
           ounidades->redraw();
        }
        else {
             fl_message("Error de hardware");
             omultOn->value(0);
        }
     }
     if (omultOn->value()== 0){                                                //Apagar el Mult�metro
        Fl::remove_timeout(cbTimerMult, this);
        activar(0);
        ovoltAc->box(FL_UP_BOX);
        ovoltAc->clear();
        ovoltDc->box(FL_UP_BOX);
        ovoltDc->clear();
        oampAc->box(FL_UP_BOX);
        oampAc->clear();
        oampDc->box(FL_UP_BOX);
        oampDc->clear();
        oohm->box(FL_UP_BOX);
        oohm->clear();
        ocontinuidad->box(FL_UP_BOX);
        ocontinuidad->clear(); 
        ogroup_mult->deactivate();
        Fl_Tooltip::disable(); 
     } 
}

/*******************************************************************************
* Multimetro::setDispMult: M�todo para colocar el valor de la medici�n en el 
*                            display del mult�metro.
* svalor : Cadena de caracteres con el valor de la medici�n realizada
*******************************************************************************/
void Multimetro::setDispMult(char svalor [4]){
    // odispMult->value((svalor));
    odispMult->label((svalor));       
}

/*******************************************************************************
 * Multimetro::cbTimerMult: Callback del timer para realizar la solicitud 
 *                            de datos del mult�metro.  
 * El Callaback consta de la funci�n static e inline cbTimerMult y 
 * cbTimerMultIn.
 * Se env�a una trama de solicitud de datos de mult�metro al hardware Mu04.
 * escalarValor(x): Funci�n que se encarga de escalar el valor de la medida en 
 *                   la escala adecuada.
 *                   El param�tro es el valor de la escala que env�a el hardware.
 * setDispMult(): Se env�a el dato escalado para mostrarlo en el display.
 * Se repite el timer de solicitud de datos cada medio segundo. 
*******************************************************************************/

void Multimetro::cbTimerMult(void *pany){
     Multimetro* pmult=(Multimetro*)pany;
     pmult->cbTimerMultIn();
}

void Multimetro::cbTimerMultIn(){
     Encapsular('K','p','1','0',0x00,0x00);
     Transmision();
     escalarValor(imult_escala);
     setDispMult(cvalor);
     ounidades->redraw();
     Fl::repeat_timeout(0.5, cbTimerMult, this);
}


/*******************************************************************************
 * Multimetro::configInstrumento: Envia la trama de selecci�n de instrumento al 
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

void Multimetro::configInstrumento(int instrumento){
     switch (instrumento) {
            case volt_ac:
                 Encapsular('K','q','1','2',0x00,0x00);
                 Transmision();
                 if (bhardware==1)
                 Fl::add_timeout(0.05, cbTimerMult, this);
                 break;
            case volt_dc:
                 Encapsular('K','q','1','1',0x00,0x00);
                 Transmision();
                 if (bhardware==1)
                 Fl::add_timeout(0.05, cbTimerMult, this);
                 break;
            case amp_ac:
                 Encapsular('K','q','1','4',0x00,0x00);
                 Transmision();
                 if (bhardware==1)
                 Fl::add_timeout(0.05, cbTimerMult, this);
                 break;
            case amp_dc:
                 Encapsular('K','q','1','3',0x00,0x00);
                 Transmision();
                 if (bhardware==1)
                 Fl::add_timeout(0.05, cbTimerMult, this); 
                 break;
            case ohm:
                 Encapsular('K','q','1','5',0x00,0x00);
                 Transmision();
                 if (bhardware==1)
                 Fl::add_timeout(0.05, cbTimerMult, this); 
                 break;
    }
}


/*******************************************************************************
 * Multimetro::escalarValor: Calcula el valor de la medici�n en el rango de 
 *                            escala en que se encuentre.
 * escala: Dato de escala enviada desde el hardware en la que se encuentra el
 *         valor de la medici�n.
 * Para calcular el resultado de la medici�n se realiza la siguiente formula:
 * (valor_medici�n-256)*Factor.
 * Por cada escala hay un Factor por el que se debe multiplicar para obtener el 
 * valor de la medici�n.  
*******************************************************************************/
void Multimetro::escalarValor(int escala){
     ivalorConversion = atoi(buf_mult);
     switch (escala) {
            case 1:
                 if (instrument==volt_ac){
                    fvalorEscalado = (ivalorConversion-256)*0.78;
                 }
                 else if (instrument==volt_dc){
                    fvalorEscalado = (ivalorConversion-256)*0.78;
                 }
                 else if (instrument==amp_ac){
                    fvalorEscalado = (ivalorConversion-256)*0.78;
                 }
                 else if (instrument==amp_dc){
                    fvalorEscalado = (ivalorConversion-256)*0.78;
                 }
                 else if (instrument==ohm){
                    fvalorEscalado = (ivalorConversion-256)*0.08;
                 }
                 else if (instrument==continuidad){
                    fvalorEscalado = (ivalorConversion-256)*0.078;
                    /*if (fvalorEscalado < 1)
                       Beep(1000,1000);*/
                 }
                 break; 
            case 2:
                 if (instrument==volt_ac){
                    fvalorEscalado = (ivalorConversion-256)*0.01;
                 }
                 else if (instrument==volt_dc){
                    fvalorEscalado = (ivalorConversion-256)*0.01;
                 }
                 else if (instrument==amp_ac){
                    fvalorEscalado = (ivalorConversion-256)*0.01;
                 }
                 else if (instrument==amp_dc){
                    fvalorEscalado = (ivalorConversion-256)*0.01;
                 }
                 else if (instrument==ohm){
                    fvalorEscalado = (ivalorConversion-256)*0.78;
                 }
                 break;
            case 3:
                 if (instrument==volt_ac){
                    fvalorEscalado = (ivalorConversion-256)*0.08;
                 }
                 else if (instrument==volt_dc){
                    fvalorEscalado = (ivalorConversion-256)*0.08;
                 }
                 else if (instrument==amp_ac){
                    fvalorEscalado = (ivalorConversion-256)*0.08;
                 }
                 else if (instrument==amp_dc){
                    fvalorEscalado = (ivalorConversion-256)*0.08;
                 }
                 else if (instrument==ohm){
                    fvalorEscalado = (ivalorConversion-256)*7.81;
                 }
                 break;
            case 4:
                 if (instrument==volt_ac){
                    fvalorEscalado = (ivalorConversion-256)*0.78;
                 }
                 else if (instrument==volt_dc){
                    fvalorEscalado = (ivalorConversion-256)*0.78;
                 }
                 else if (instrument==amp_ac){
                    fvalorEscalado = (ivalorConversion-256)*0.78;
                 }
                 else if (instrument==amp_dc){
                    fvalorEscalado = (ivalorConversion-256)*0.78;
                 }
                 else if (instrument==ohm){
                    fvalorEscalado = (ivalorConversion-256)*7812.5;
                 }
                 break;
            case 5:
                 if (instrument==volt_dc){
                    fvalorEscalado = (ivalorConversion-256)*7.81;
                 }
                 else if (instrument==amp_dc){
                    fvalorEscalado = (ivalorConversion-256)*0.08;
                 }
                 break;
            case 6:
                 if (instrument==volt_dc){
                    fvalorEscalado = (ivalorConversion-256)*0.78;
                 }
                 else if (instrument==amp_dc){
                    fvalorEscalado = (ivalorConversion-256)*0.78;
                 }
                 break;
            case 7:
                 if (instrument==volt_dc){
                    fvalorEscalado = (ivalorConversion-256)*0.01;
                 }
                 else if (instrument==amp_dc){
                    fvalorEscalado = (ivalorConversion-256)*0.01;
                 }
                 break;
            case 8:
                 if (instrument==volt_dc){
                    fvalorEscalado = (ivalorConversion-256)*0.08;
                 }
                 else if (instrument==amp_dc){
                    fvalorEscalado = (ivalorConversion-256)*0.08;
                 }
                 break;
            case 9:
                 if (instrument==volt_dc){
                    fvalorEscalado = (ivalorConversion-256)*0.78;
                 }
                 else if (instrument==amp_dc){
                    fvalorEscalado = (ivalorConversion-256)*0.78;
                 }
                 break; 
     }
     sprintf(cvalor,"%.3g",fvalorEscalado);
}


/*******************************************************************************
 * Multimetro::cbVoltAc: Callback del bot�n que activa el medidor de voltaje 
 *                         en AC.
 * El Callaback consta de la funci�n static e inline cbVoltAc y cbVoltAcIn.
 * Los botones de selecci�n de instrumento son excluyentes, es decir que cuando
 * se activa uno, los demas se desactivan.
 * Se realiza un llamado al m�todo configInstrumento(), con el parametro
 * volt_ac.
*******************************************************************************/
void Multimetro::cbVoltAc(Fl_Widget* pboton, void *any){
     Multimetro* pmult=(Multimetro*)any;
     pmult->cbVoltAcIn();
}

void Multimetro::cbVoltAcIn(){
     if (ovoltAc->value()== 0){
        Fl::remove_timeout(cbTimerMult, this);
        ovoltDc->box(FL_UP_BOX);
        ovoltDc->clear();
        oampAc->box(FL_UP_BOX);
        oampAc->clear();
        oampDc->box(FL_UP_BOX);
        oampDc->clear();
        oohm->box(FL_UP_BOX);
        oohm->clear();
        ocontinuidad->box(FL_UP_BOX);
        ocontinuidad->clear();        
        ovoltAc->box(FL_DOWN_BOX);
        ovoltAc->set();
        instrument = volt_ac;
        ounidades->label("VAC");
        configInstrumento(volt_ac);
     }
     else{
          ovoltAc->box(FL_UP_BOX);
          ovoltAc->clear();
     }
}


/*******************************************************************************
 * Multimetro::cbVoltDc: Callback del bot�n que activa el medidor de voltaje 
 *                         en DC.
 * El Callaback consta de la funci�n static e inline cbVoltDc y cbVoltDcIn.
 * Los botones de selecci�n de instrumento son excluyentes, es decir que cuando
 * se activa uno, los demas se desactivan.
 * Se realiza un llamado al m�todo configInstrumento(), con el parametro
 * volt_dc.
*******************************************************************************/

void Multimetro::cbVoltDc(Fl_Widget* pboton, void *any){
     Multimetro* pmult=(Multimetro*)any;
     pmult->cbVoltDcIn();
}

void Multimetro::cbVoltDcIn(){
     if (ovoltDc->value()== 0){
        Fl::remove_timeout(cbTimerMult, this);
        ovoltAc->box(FL_UP_BOX);
        ovoltAc->clear();
        oampAc->box(FL_UP_BOX);
        oampAc->clear();
        oampDc->box(FL_UP_BOX);
        oampDc->clear();
        oohm->box(FL_UP_BOX);
        oohm->clear();
        ocontinuidad->box(FL_UP_BOX);
        ocontinuidad->clear();                     
        ovoltDc->box(FL_DOWN_BOX);
        ovoltDc->set();
        instrument = volt_dc;
        ounidades->label("VDC");
        configInstrumento(volt_dc);
     }
     else{
          ovoltDc->box(FL_UP_BOX);
          ovoltDc->clear();
     }
}


/*******************************************************************************
 * Multimetro::cbAmpAc: Callback del bot�n que activa el medidor de corriente 
 *                         en AC.
 * El Callaback consta de la funci�n static e inline cbAmpAc y cbAmpAcIn.
 * Los botones de selecci�n de instrumento son excluyentes, es decir que cuando
 * se activa uno, los demas se desactivan.
 * Se realiza un llamado al m�todo configInstrumento(), con el parametro
 * amp_ac.
*******************************************************************************/

void Multimetro::cbAmpAc(Fl_Widget* pboton, void *any){
     Multimetro* pmult=(Multimetro*)any;
     pmult->cbAmpAcIn();
}

void Multimetro::cbAmpAcIn(){
    if (oampAc->value()== 0){
        Fl::remove_timeout(cbTimerMult, this);
        //fl_alert("Verifique las puntas de prueba");
        ovoltAc->box(FL_UP_BOX);
        ovoltAc->clear();
        ovoltDc->box(FL_UP_BOX);
        ovoltDc->clear();
        oampDc->box(FL_UP_BOX);
        oampDc->clear();
        oohm->box(FL_UP_BOX);
        oohm->clear();
        ocontinuidad->box(FL_UP_BOX);
        ocontinuidad->clear();                     
        oampAc->box(FL_DOWN_BOX);
        oampAc->set();
        instrument = amp_ac;
        ounidades->label("AAC");
        configInstrumento(amp_ac);
     }
     else{
          oampAc->box(FL_UP_BOX);
          oampAc->clear();
     } 
}


/*******************************************************************************
 * Multimetro::cbAmpDc: Callback del bot�n que activa el medidor de corriente 
 *                         en DC.
 * El Callaback consta de la funci�n static e inline cbAmpDc y cbAmpDcIn.
 * Los botones de selecci�n de instrumento son excluyentes, es decir que cuando
 * se activa uno, los demas se desactivan.
 * Se realiza un llamado al m�todo configInstrumento(), con el parametro
 * amp_dc.
*******************************************************************************/

void Multimetro::cbAmpDc(Fl_Widget* pboton, void *any){
     Multimetro* pmult=(Multimetro*)any;
     pmult->cbAmpDcIn();
}

void Multimetro::cbAmpDcIn(){
    if (oampDc->value()== 0){
        Fl::remove_timeout(cbTimerMult, this);
        fl_alert("Verifique las puntas de prueba");
        ovoltAc->box(FL_UP_BOX);
        ovoltAc->clear();
        ovoltDc->box(FL_UP_BOX);
        ovoltDc->clear();
        oampAc->box(FL_UP_BOX);
        oampAc->clear();
        oohm->box(FL_UP_BOX);
        oohm->clear();
        ocontinuidad->box(FL_UP_BOX);
        ocontinuidad->clear();                     
        oampDc->box(FL_DOWN_BOX);
        oampDc->set();
        instrument = amp_dc;
        ounidades->label("ADC");
        configInstrumento(amp_dc);
     }
     else{
          oampDc->box(FL_UP_BOX);
          oampDc->clear();
     } 
}


/*******************************************************************************
 * Multimetro::cbOhm: Callback del bot�n que activa el medidor de resistencia 
 *  
 * El Callaback consta de la funci�n static e inline cbOhm y cbOhmIn.
 * Los botones de selecci�n de instrumento son excluyentes, es decir que cuando
 * se activa uno, los demas se desactivan.
 * Se realiza un llamado al m�todo configInstrumento(), con el parametro
 * ohm.
*******************************************************************************/

void Multimetro::cbOhm(Fl_Widget* pboton, void *any){
     Multimetro* pmult=(Multimetro*)any;
     pmult->cbOhmIn();
}

void Multimetro::cbOhmIn(){
     if (oohm->value()== 0){
        Fl::remove_timeout(cbTimerMult, this);
        ovoltAc->box(FL_UP_BOX);
        ovoltAc->clear();
        ovoltDc->box(FL_UP_BOX);
        ovoltDc->clear();
        oampDc->box(FL_UP_BOX);
        oampDc->clear();
        oampAc->box(FL_UP_BOX);
        oampAc->clear();
        ocontinuidad->box(FL_UP_BOX);
        ocontinuidad->clear();                     
        oohm->box(FL_DOWN_BOX);
        oohm->set();
        instrument = ohm;
        ounidades->label("R");
        configInstrumento(ohm);
     }
     else{
          oohm->box(FL_UP_BOX);
          oohm->clear();
     }
}


/*******************************************************************************
 * Multimetro::cbCont: Callback del bot�n que activa el medidor de continuidad 
 *  
 * El Callaback consta de la funci�n static e inline cbCont y cbContIn.
 * Los botones de selecci�n de instrumento son excluyentes, es decir que cuando
 * se activa uno, los demas se desactivan.
 * Se realiza un llamado al m�todo configInstrumento(), con el parametro
 * ohm.
 * La medici�n de continuidad se realiza con el ohmetro y se verifica si el 
 * valor de resistencia es menor que un (1) Ohmio entonces se activa un sonido 
 * indicador de continuidad.
*******************************************************************************/

void Multimetro::cbCont(Fl_Widget* pboton, void *any){
     Multimetro* pmult=(Multimetro*)any;
     pmult->cbContIn();
}

void Multimetro::cbContIn(){
     if (ocontinuidad->value()== 0){
        Fl::remove_timeout(cbTimerMult, this);
        ovoltAc->box(FL_UP_BOX);
        ovoltAc->clear();
        ovoltDc->box(FL_UP_BOX);
        ovoltDc->clear();
        oampDc->box(FL_UP_BOX);
        oampDc->clear();
        oampAc->box(FL_UP_BOX);
        oampAc->clear();
        oohm->box(FL_UP_BOX);
        oohm->clear();                     
        ocontinuidad->box(FL_DOWN_BOX);
        ocontinuidad->set();
        instrument = continuidad;
        ounidades->label("Cont");
        configInstrumento(ohm);
       // Beep(1000,1000);
     }
     else{
          ocontinuidad->box(FL_UP_BOX);
          ocontinuidad->clear();
     }
}


/*******************************************************************************
 * Multimetro::cbHelpMult: Callback del bot�n que lanza la ayuda del uso del
 *                      instrumento. 
 * El Callaback consta de la funci�n static e inline cbHelpMult y cbHelpMultIn.
 * Se despliega una ventana de ayuda con un archivo en html con la gu�a de
 * usuario del instrumento.
*******************************************************************************/

void Multimetro::cbHelpMult(Fl_Widget* pboton, void *any){
     Multimetro* pmult=(Multimetro*)any;
     pmult->cbHelpMultIn();
}

void Multimetro::cbHelpMultIn(){
      //manualMult->show();
}


/*******************************************************************************
 * Multimetro::cbAyudaMult: Callback del bot�n que activa los globos de ayuda
 *                       flotante para cada bot�n del mult�metro.
 * El Callaback consta de la funci�n static e inline cbAyudaMult y cbAyudaMultIn.
*******************************************************************************/
void Multimetro::cbAyudaMult(Fl_Widget* pboton, void *pany){
     Multimetro* pmult=(Multimetro*)pany;
     pmult->cbAyudaMultIn();
}

void Multimetro::cbAyudaMultIn(){
     if (oayudaMult->value() == 1){
        Fl_Tooltip::enable();
     }
     else{
         Fl_Tooltip::disable(); 
     }
}
