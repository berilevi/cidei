// Class automatically generated by Dev-C++ New Class wizard

#include "analizador.h" // class's header file

int isec_numdatos = 0;
int iespera_trigger = 0;
char  cbyte_anterior[] = "00000000";
bool bconf_trigger = 0;

// class constructor
Analizador::Analizador() {                 
    
    idatapos = 0;
    inum_muestras = TAM_ALMACENADO;
    idatos_graficados = 40;
    btimer_trigger = 0;
    btrigger = 0;
    bmuestreando = 0;
     
    ogroup_ana = new Fl_Group(5,370,505,330,"");
    ogroup_ana->box(FL_ENGRAVED_FRAME);
    ogroup_ana->box(FL_UP_BOX);
    ogroup_ana->deactivate(); 
     
    apantalla_ch1 = new Fl_Scope(20,410,400,34,"");  // Instancia de canal 1
    apantalla_ch2 = new Fl_Scope(20,442,400,34,"");  // Instancia de canal 2
    apantalla_ch3 = new Fl_Scope(20,474,400,34,"");  // Instancia de canal 3
    apantalla_ch4 = new Fl_Scope(20,506,400,34,"");  // Instancia de canal 4
    apantalla_ch5 = new Fl_Scope(20,538,400,34,"");  // Instancia de canal 5
    apantalla_ch6 = new Fl_Scope(20,570,400,34,"");  // Instancia de canal 6
    apantalla_ch7 = new Fl_Scope(20,602,400,34,"");  // Instancia de canal 7
    apantalla_ch8 = new Fl_Scope(20,634,400,34,"");  // Instancia de canal 8
    
    oscroll = new Fl_Scrollbar(12,670,415,10,"");
    oscroll->type(FL_HORIZONTAL);
    oscroll->range(0,40);
    oscroll->linesize(2);
    oscroll->step(1);
    oscroll->deactivate();
      
    olog_ana = new Fl_Button(290,382,40,16,"Log");
    olog_ana->labelsize(10);
    
    ohelp_ana = new Fl_Button(340,382,40,16,"Help");
    ohelp_ana->labelsize(10);
    
    oayuda_ana = new Fl_Check_Button(385,382,20,16,"?");
    oayuda_ana->labelsize(12);
    
    apantalla_ch1->TraceColour(FL_RED);
    apantalla_ch1->tracetype(FL_SCOPE_TRACE_LOOP);
    apantalla_ch1->redrawmode(FL_SCOPE_REDRAW_ALWAYS);
    apantalla_ch1->linetype(FL_SCOPE_LINE);
    apantalla_ch2->TraceColour(FL_RED);
    apantalla_ch2->tracetype(FL_SCOPE_TRACE_LOOP);
    apantalla_ch2->redrawmode(FL_SCOPE_REDRAW_ALWAYS);
    apantalla_ch2->linetype(FL_SCOPE_LINE);
    apantalla_ch3->TraceColour(FL_RED);
    apantalla_ch3->tracetype(FL_SCOPE_TRACE_LOOP);
    apantalla_ch3->redrawmode(FL_SCOPE_REDRAW_ALWAYS);
    apantalla_ch3->linetype(FL_SCOPE_LINE);
    apantalla_ch4->TraceColour(FL_RED);
    apantalla_ch4->tracetype(FL_SCOPE_TRACE_LOOP);
    apantalla_ch4->redrawmode(FL_SCOPE_REDRAW_ALWAYS);
    apantalla_ch4->linetype(FL_SCOPE_LINE);
    apantalla_ch5->TraceColour(FL_RED);
    apantalla_ch5->tracetype(FL_SCOPE_TRACE_LOOP);
    apantalla_ch5->redrawmode(FL_SCOPE_REDRAW_ALWAYS);
    apantalla_ch5->linetype(FL_SCOPE_LINE);
    apantalla_ch6->TraceColour(FL_RED);
    apantalla_ch6->tracetype(FL_SCOPE_TRACE_LOOP);
    apantalla_ch6->redrawmode(FL_SCOPE_REDRAW_ALWAYS);
    apantalla_ch6->linetype(FL_SCOPE_LINE);
    apantalla_ch7->TraceColour(FL_RED);
    apantalla_ch7->tracetype(FL_SCOPE_TRACE_LOOP);
    apantalla_ch7->redrawmode(FL_SCOPE_REDRAW_ALWAYS);
    apantalla_ch7->linetype(FL_SCOPE_LINE);
    apantalla_ch8->TraceColour(FL_RED);
    apantalla_ch8->tracetype(FL_SCOPE_TRACE_LOOP);
    apantalla_ch8->redrawmode(FL_SCOPE_REDRAW_ALWAYS);
    apantalla_ch8->linetype(FL_SCOPE_LINE);
    
            
    ogroup_ana_botones = new Fl_Group(425,375,80,175,"");          // Agrupa los elementos del analizador
    ogroup_ana_botones->box(FL_ENGRAVED_FRAME); 
    ogroup_ana_botones->deactivate();
           
    omuestreo = new Fl_Value_Slider(430,390,30,150,"");
    omuestreo->range(1,10);
    omuestreo->step(1);
    omuestreo->round(1); 
    
    ogroup_ana_botones->end();
    
    omuestrear_on = new Fl_Light_Button(430,560,70,30,"Capturar");
    omuestrear_on->labelsize(13);
    
    orep_dato = new Fl_Choice(430,620,70,20,"");
    orep_dato->add("Decimal");
    orep_dato->add("Binario");
    orep_dato->add("Hexadecimal");
    
    odato1 = new Fl_Output(430,645,70,20,"");
    odato1->textsize(9);
    
    otrigger_on = new Fl_Light_Button(430,595,70,20,"Trigger"); 
    otrigger_on->labelsize(12);
          
    ogroup_ana->end();
    
    obox_trigger = new Fl_Box(415,520,92,70,"");
    obox_trigger->box(FL_UP_BOX);
    obox_trigger->hide();
    
    ogroup_trigger = new Fl_Group(415,520,92,70,"");
    ogroup_trigger->hide();
    oflancosubida = new Fl_Button(420,530,20,20,"s");
    oflancobajada = new Fl_Button(445,530,20,20,"b");  
    oselector = new Fl_Spinner(470,530,30,20,""); 
    oselector->range(1,8);
    ocerrar_trigger = new Fl_Button(460,565,40,16,"Cerrar");
    ocerrar_trigger->labelsize(9);
    
    ogroup_trigger->end();
    
    
    obox_nombre = new Fl_Box(12,375,223,30,"ANALIZADOR L�GICO");
    obox_nombre->box(FL_ENGRAVED_FRAME);
    obox_nombre->labelfont(FL_HELVETICA_BOLD);
    obox_nombre->labelsize(20);
    
    oana_on = new Fl_Light_Button(240,375,38,30,"ON");
    oana_on->labelsize(9);
    
    ocursor = new Cursores(20,410,400,668);
    
    oana_on->callback(cb_ana_on, this);
    omuestrear_on->callback(cb_muestrear,this);
    oscroll->callback(cb_mas_datos, this);
    otrigger_on->callback(cb_trigger_on,this);
    ocerrar_trigger->callback(cb_cerrar_trigger,this);
    oflancosubida->callback(cb_subida,this);
    oflancobajada->callback(cb_bajada,this);
}

// class destructor
Analizador::~Analizador() {
                                          
}


/**
 * Iniciar el analizador l�gico
*/
void Analizador::cb_ana_on(Fl_Widget* pboton, void *pany) {
     Analizador* pana=(Analizador*)pany;
     pana->cb_ana_on_in();
}

/** 
 * Iniciar el analizador l�gico
*/
void Analizador::cb_ana_on_in() {
      if(oana_on->value()== 1) {
        activar(1);
        Encapsular('C','a','1','0',0x00,0x00);
        Transmision();
        if (bhardware){
           ogroup_ana->activate();
           ogroup_ana_botones->activate();
           isec_numdatos = 0;
           //oflancosubida->value(1);
           //oflancosubida->box(FL_DOWN_BOX);
           oselector->value(1);
           //Fl::add_timeout(0.1, cb_timer_ana, this);
        }
        else {
             fl_message("Error de hardware");
        }
     }
     if(oana_on->value()== 0) {
        Fl::remove_timeout(cb_timer_ana, this);
        activar(0);
        ogroup_ana->deactivate();
        ogroup_ana_botones->deactivate();
        oflancosubida->value(0);
        oflancosubida->box(FL_UP_BOX); 
        oflancobajada->value(0);
        oflancobajada->box(FL_UP_BOX);
     }
}


/**
 * Callback para seleccionar la configuraci�n del sistema de trigger del
 * analizador l�gico.
*/
void Analizador::cb_trigger_on(Fl_Widget* pboton, void *pany) {
     Analizador* pana=(Analizador*)pany;
     pana->cb_trigger_on_in();
}

/**
 * Mostrar el panel de configuraci�n del sistema de trigger del instrumento
*/
void Analizador::cb_trigger_on_in() {
     if(otrigger_on->value()== 1) {
        obox_trigger->show();
        ogroup_trigger->show();
        bconf_trigger = 1;
        oflancosubida->value(1);
        oflancosubida->box(FL_DOWN_BOX);
     }
     else{
         bconf_trigger = 0; 
     }
}


/**
 * CallbackBot�n para cerrar el panel de configuraci�n del sistema de trigger
*/
void Analizador::cb_cerrar_trigger(Fl_Widget* pboton, void *pany) {
     Analizador* pana=(Analizador*)pany;
     pana->cb_cerrar_trigger_in();
}

/**
 *  Cerrar el panel de configuraci�n del sistema de trigger
*/
void Analizador::cb_cerrar_trigger_in() {
     obox_trigger->hide();
     ogroup_trigger->hide();
}



/**
 * Callback del boton que habilita el muestreo en el analizador
*/
void Analizador::cb_muestrear(Fl_Widget* pboton, void *pany) {
     Analizador* pana=(Analizador*)pany;
     pana->cb_muestrear_in();
}

/**
 * Callback del boton que habilita el muestreo en el analizador
*/
void Analizador::cb_muestrear_in() {
     if(omuestrear_on->value()== 1) {
       Fl::add_timeout(0.001, cb_timer_ana, this);
       omuestrear_on->value(0);
       omuestrear_on->box(FL_DOWN_BOX);
     }  
}


/**
 *
*/
void Analizador::cb_subida(Fl_Widget* pboton, void *pany) {
     Analizador* pana=(Analizador*)pany;
     pana->cb_subida_in();
}

/**
 * 
*/
void Analizador::cb_subida_in() {
      if (oflancosubida->value()== 0){
         oflancobajada->box(FL_UP_BOX);                      
         oflancobajada->value(0);
         oflancosubida->value(1);
         oflancosubida->box(FL_DOWN_BOX);
      }
      else {
         oflancosubida->value(0);
         oflancosubida->box(FL_UP_BOX);
      }
}

/**
 *
*/
void Analizador::cb_bajada(Fl_Widget* pboton, void *pany) {
     Analizador* pana=(Analizador*)pany;
     pana->cb_bajada_in();
}

/**
 * 
*/
void Analizador::cb_bajada_in() {
     if (oflancobajada->value()== 0){
         oflancosubida->box(FL_UP_BOX);                      
         oflancosubida->value(0);
         oflancobajada->value(1);
         oflancobajada->box(FL_DOWN_BOX);
      }
      else {
         oflancobajada->value(0);
         oflancobajada->box(FL_UP_BOX);
      }
}


/**
 * 
*/
void Analizador::cb_mas_datos(Fl_Widget* pboton, void *pany) {
     Analizador* pana=(Analizador*)pany;
     pana->cb_mas_datos_in();
}

/**
 * 
*/
void Analizador::cb_mas_datos_in() {
    //idatos= 40 - oscroll->value();  
    ocursor->iposx = oscroll->value()*10;
   // ocursor->redraw();  
}


/**
 * Este m�todo es el callback del timer para realizar la solicitud 
 * de datos del analizador al hardware.  
*/
void Analizador::cb_timer_ana(void *pany) {
     Analizador* pana=(Analizador*)pany;
     pana->cb_timer_ana_in();
}

/**
 * Esta funci�n acompa�a la funci�n cb_timer_ana
 * para realizar los llamados de callback del timer 
*/
void Analizador::cb_timer_ana_in() {
     Encapsular('C','p','1','0',0x00,0x00);
     Transmision();
     separar_canales();
     Fl::repeat_timeout(0.001, cb_timer_ana, this);
}


/**
 * Esta funcion separa los datos enviados desde el hardware para cada
 * canal del analizador logico.
*/
void Analizador::separar_canales() {
     
     int ilong;
     int ipos_msb;
     int ipos_lsb;
     char cdato_1[9];
     
     // Convertir los car�cteres a datos hexadecimales
     
     if (buf_analizador[0] > 64){
        ipos_msb = int(buf_analizador[0]-55);
     }
     else{
         ipos_msb = int(buf_analizador[0]-48); 
     }
     if (buf_analizador[1] > 64){
        ipos_lsb = int(buf_analizador[1]-55);
     }
     else{
         ipos_lsb = int(buf_analizador[1]-48); 
     }
     //itoa(atoi(buf_analizador),cdato_1,10);                  //convertir el dato a caracter para colocarlo en el cuadro de la rep del dato
     // odato1->value(cdato_1);
     
     // Guardar el n�mero hexadecimal m�s significativo convertido a binario en caracteres   
     itoa(ipos_msb,recibido_msb,2);
     ilong = strlen(recibido_msb);
     
     for (int i= 4; i > 0; i-- ){
         if (ilong > 0){
            recibido_msb2[i-1] = recibido_msb[ilong-1];
         }
         else {
              recibido_msb2[i-1] = '0';
         }
         ilong --;
     }
     itoa(ipos_lsb,recibido_lsb,2);
     ilong = strlen(recibido_lsb);
     for (int i= 4; i > 0; i-- ){
         if (ilong > 0){
            recibido_lsb2[i-1] = recibido_lsb[ilong-1]; 
         }
         else {
              recibido_lsb2[i-1] = '0';
         }
         ilong --;
     }
     cbyte_actual[0]= recibido_msb2[0];
     cbyte_actual[1]= recibido_msb2[1];
     cbyte_actual[2]= recibido_msb2[2];
     cbyte_actual[3]= recibido_msb2[3];
     cbyte_actual[4]= recibido_lsb2[0];
     cbyte_actual[5]= recibido_lsb2[1];
     cbyte_actual[6]= recibido_lsb2[2];
     cbyte_actual[7]= recibido_lsb2[3];  
     
     if (bmuestreando == 0){
         if (bconf_trigger == 1){
             btrigger = trigger();
             if (btrigger == 0){
                Fl::add_timeout(1, cb_timer_trigger, this);
                if (iespera_trigger == 10 ){
                   
                }
             } 
         }             
         
              

     }
     
     if (btrigger == 1){
        Fl::remove_timeout(cb_timer_trigger, this);
        bmuestreando = 1;
        almacenar();
     } 
     else{
          Fl::add_timeout(1, cb_timer_trigger, this); 
          if (iespera_trigger == 10 && btrigger == 0){
             Fl::remove_timeout(cb_timer_trigger, this);
             btimer_trigger = 1;
             bmuestreando = 1;
             almacenar();
          }
     } 
     strcpy(cbyte_anterior,cbyte_actual);                              //convertir la cadena actual a la anterior 

}


/**
 * Funci�n para determinar si ocurrio el evento que dispara el muestreo
*/
bool Analizador::trigger(int i, char cactual, char canterior) {
    if (oselector->value()== i+1){
       if (oflancosubida->value()== 1){
          if (cactual > canterior){
             btrigger = 1;
             btimer_trigger = 0;
             Fl::remove_timeout(cb_timer_trigger, this);
            // Fl::remove_timeout(cb_timer_ana, this);
          }
       }
       else{
           if (cactual < canterior){
              btrigger = 1;
              btimer_trigger = 0;
              Fl::remove_timeout(cb_timer_trigger, this);
           }
       }
    }
    else {
         btrigger = 0;
    }
    return btrigger; 
}


/**
 * Funci�n para almacenar las muestras
*/
void Analizador::almacenar() {
     if (idatapos > inum_muestras-1) {
           graficar_datos();
           idatapos = 0;
           bmuestreando = 0;
           btrigger = 0;
           btimer_trigger = 0;
           Fl::remove_timeout(cb_timer_ana, this);
           omuestrear_on->value(0);
     }
     
     strcpy(pdata_analizador [idatapos], cbyte_actual);
     idatapos++;
     iespera_trigger = 0;
     ocursor->redraw();
}


/**
 * 
*/
void Analizador::cb_timer_trigger(void *pany) {
     Analizador* pana=(Analizador*)pany;
     pana->cb_timer_trigger_in();
}

/**
 * 
*/
void Analizador::cb_timer_trigger_in() {
     iespera_trigger++;
}



/**
 * Funcion para recorrer los buffers y graficar la informacion
*/
void Analizador::graficar_datos() {
     
     for (int i=0; i<inum_muestras; i++) {
         
         //Canal 1
         if (pdata_analizador[i][0]=='1'){
            for (int i=0; i<idatos_graficados;i++){                   
                apantalla_ch1->Add(50000);
            }
         }
         else if (pdata_analizador[i][0]=='0'){
              for (int i=0; i<idatos_graficados;i++){                   
                  apantalla_ch1->Add(10000);
              }
         }
         //Canal 2
         if (pdata_analizador[i][1]=='1'){
            for (int i=0; i<idatos_graficados;i++){                   
                apantalla_ch2->Add(50000);
            }
         }
         else if (pdata_analizador[i][1]=='0'){
              for (int i=0; i<idatos_graficados;i++){                   
                  apantalla_ch2->Add(10000);
              }
         }
         //Canal 3
         if (pdata_analizador[i][2]=='1'){
            for (int i=0; i<idatos_graficados;i++){                   
                apantalla_ch3->Add(50000);
            }
         }
         else if (pdata_analizador[i][2]=='0'){
              for (int i=0; i<idatos_graficados;i++){                   
                  apantalla_ch3->Add(10000);
              }
         }
         //Canal 4
         if (pdata_analizador[i][3]=='1'){
            for (int i=0; i<idatos_graficados;i++){                   
                apantalla_ch4->Add(50000);
            }
         }
         else if (pdata_analizador[i][3]=='0'){
              for (int i=0; i<idatos_graficados;i++){                   
                  apantalla_ch4->Add(10000);
              }
         }
         //Canal 5
         if (pdata_analizador[i][4]=='1'){
            for (int i=0; i<idatos_graficados;i++){                   
                apantalla_ch5->Add(50000);
            }
         }
         else if (pdata_analizador[i][4]=='0'){
              for (int i=0; i<idatos_graficados;i++){                   
                  apantalla_ch5->Add(10000);
              }
         }
         //Canal 6
         if (pdata_analizador[i][5]=='1'){
            for (int i=0; i<idatos_graficados;i++){                   
                apantalla_ch6->Add(50000);
            }
         }
         else if (pdata_analizador[i][5]=='0'){
              for (int i=0; i<idatos_graficados;i++){                   
                  apantalla_ch6->Add(10000);
              }
         }
         //Canal 7
         if (pdata_analizador[i][6]=='1'){
            for (int i=0; i<idatos_graficados;i++){                   
                apantalla_ch7->Add(50000);
            }
         }
         else if (pdata_analizador[i][6]=='0'){
              for (int i=0; i<idatos_graficados;i++){                   
                  apantalla_ch7->Add(10000);
              }
         }
         //Canal 8
         if (pdata_analizador[i][7]=='1'){
            for (int i=0; i<idatos_graficados;i++){                   
                apantalla_ch8->Add(50000);
            }
         }
         else if (pdata_analizador[i][7]=='0'){
              for (int i=0; i<idatos_graficados;i++){                   
                  apantalla_ch8->Add(10000);
              }
         }
         ocursor->redraw();
     }

}
