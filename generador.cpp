// Class automatically generated by Dev-C++- New Class wizard

#include "generador.h" // class's header file
//#include <math.h>


char cfrecuencia [9];                        // Cadena de caracteres con el valor de frecuencia que se visualizar� en el display

/******************************************************************************
 * Generador::Generador: Constructor de la clase Generador.
 * Se inicializan las variables y se realizan las instancias de los objetos que
 * hacen parte del instrumento y sus callbacks:
 * - Control de amplitud.
 * - Control de nivel de offset.
 * - Selectores de tipo de se�al.
 * - Displays de frecuencia, amplitud y nivel de offset.
*******************************************************************************/
Generador::Generador(){

    igen = new Fl_PNG_Image("generador.png");                   
	ogroupGenerador = new Fl_Group (515,370,505,330,"");                       //Inicio de grupo de objetos que hacen parte del generador
	ogroupGenerador->box(FL_UP_BOX);
	ogroupGenerador->deactivate();
	boxgroupgen = new Fl_Box(515,377,505,330,"");
	/*odispGen = new Fl_7Seg(520,410,320,100,"");                              //Display 7 segmentos donde se visualiza la frecuencia configurada 
    odispGen->box(FL_EMBOSSED_FRAME);
    odispGen->color(FL_BLACK);
    odispGen->thickness(5);
    odispGen->dot_len(5);
    odispGen->align_text(FL_ALIGN_RIGHT);*/
    //odispGen->value("000.0");
    odisplayGen = new Fl_Box(522,408,320,100,"0.000");
    odisplayGen->labelsize(80);
    odisplayGen->labelcolor(FL_WHITE);
    odisplayGen->box(FL_FLAT_BOX);
    odisplayGen->color(FL_BLACK);
    omHz = new Fl_Box(861,416,25,13,"");                                     //Indicador de escala de miliHertz
    omHz->labelsize(10);
    omHz->box(FL_ENGRAVED_BOX);
    omHz->align(FL_ALIGN_RIGHT);
    oHz = new Fl_Box(861,449,25,13,"");                                       //Indicador de escala de Hertz
    oHz->labelsize(10);
    oHz->box(FL_ENGRAVED_BOX);
    oHz->align(FL_ALIGN_RIGHT);
    oMeHz = new Fl_Box(861,481,25,13,"");                                    //Indicador de escala de MegaHertz
    oMeHz->labelsize(10);
    oMeHz->box(FL_ENGRAVED_BOX);
    oMeHz->align(FL_ALIGN_RIGHT);
    //ohelpGen  = new Fl_Button (520,375,412,28,"");                          //Bot�n que inicia la ayuda de uso del instrumento
    //ohelpGen->labelsize(10);
    
    ogroupSenal = new Fl_Group (778,512,122,180,"");                           //Inicio del grupo de botones de selecci�n de tipo de se�al
    //ogroupSenal->box(FL_ENGRAVED_FRAME);
	ogroupSenal->box(FL_NO_BOX);
    ogroupSenal->deactivate();
    oseno = new Fl_Button(798,540,78,25,"Seno");                                //Bot�n de selecci�n de se�al seno.
    oseno->labelsize(12);
    ocuadrada = new Fl_Button(798,598,78,25,"Cuadrada");                        //Bot�n de selecci�n de se�al cuadrada.
    ocuadrada->labelsize(12);
    otriangulo = new Fl_Button(798,656,78,25,"Triangulo");                      //Bot�n de selecci�n de se�al tri�ngulo.
    otriangulo->labelsize(12);
    ogroupSenal->end();                                                        //Fin del grupo de botones selctores de tipo de se�al.
    
    ogroupFrecuencia = new Fl_Group (905,406,110,286,"");                      //Inicio del grupo de botones de configuraci�n de frecuencia.
    //ogroupFrecuencia->box(FL_ENGRAVED_FRAME);
    ogroupFrecuencia->box(FL_NO_BOX);
	ogroupFrecuencia->deactivate();
    //ofrecGen = new Fl_Knob (900,440,100,100,"Frecuencia");                     //Ajuste grueso de frecuencia.
    ofrecGen = new Fl_Dial (958,502,42,42,"");
    //ofrecGen->color(147);
    ofrecGen->box(FL_NO_BOX);
    ofrecGen->type(8);
    //ofrecGen->scaleticks(0);
    ofrecGen->labelsize(9);
    ofrecGen->step(0.1);
    ofrecGen->range(0,1);
    
    //ofrecGen2 = new Fl_Knob (915,565,70,70,"Ajuste Fino");                     //Ajuste fino de frecuencia.
    ofrecGen2 = new Fl_Dial (958,600,42,42,"");
    ofrecGen2->color(147);
    ofrecGen2->box(FL_NO_BOX);
    ofrecGen2->type(8);
    //ofrecGen2->scaleticks(0);
    ofrecGen2->labelsize(9);
    ofrecGen2->step(0.01);
    ofrecGen2->range(0,1);
    
    oescalaFrecuencia = new Fl_Choice(920,430,80,20,"");                 //Men� de escalas de frecuencia
    oescalaFrecuencia->labelsize(13);
    oescalaFrecuencia->align(FL_ALIGN_TOP);
    oescalaFrecuencia->add("1 Hz",0,(Fl_Callback *)cbFrec1,this);             
    oescalaFrecuencia->add("100 Hz",0,(Fl_Callback *)cbFrec100,this);
    oescalaFrecuencia->add("500 Hz",0,(Fl_Callback *)cbFrec500,this);
    oescalaFrecuencia->add("1 KHz",0,(Fl_Callback *)cbFrec1k,this);
    oescalaFrecuencia->add("100 KHz",0,(Fl_Callback *)cbFrec100k,this);
    oescalaFrecuencia->add("500 KHz",0,(Fl_Callback *)cbFrec500k,this);
    oescalaFrecuencia->add("1 MHz",0,(Fl_Callback *)cbFrec1m,this);
       
    ovalorFrec = new Fl_Value_Input(920,655,90,20,"");                        //Caja de texto para configurar por teclado el valor de frecuencia
    ovalorFrec->type(FL_FLOAT_INPUT);
    ogroupFrecuencia->end();                                                   //Fin del grupo de controles de frecuencia
    
    ogroupAmplitud = new Fl_Group (521,513,123,180,"");                        //Inicio del grupo de controles de amplitud
    //ogroupAmplitud->box(FL_ENGRAVED_FRAME);
    ogroupAmplitud->box(FL_NO_BOX);
	ogroupAmplitud->deactivate();
    //oamplitud = new Fl_Knob (540,556,62,62,"Amplitud");                         //Bot�n de ajuste de la amplitud de la se�al
    oamplitud = new Fl_Dial (552,556,62,62,"");
    oamplitud->color(180);
    oamplitud->box(FL_NO_BOX);
    oamplitud->type(8); 
    //oamplitud->scaleticks(0);
    oamplitud->labelsize(11);
    oamplitud->range(0,5);
    odispAmplitud = new Fl_Output(545,650,70,20,"");                           //Display del valor de la amplitud.
    ogroupAmplitud->end();                                                     //Fin del grupo de controles de amplitud
    
    ogroupOffset = new Fl_Group (650,513,124,180,"");                          //Inicio del grupo de controles de nivel de offset
    //ogroupOffset->box(FL_ENGRAVED_FRAME);
    ogroupOffset->box(FL_NO_BOX);
	ogroupOffset->deactivate();
    //ooffset = new Fl_Knob (655,550,80,80,"Offset");                             //Perilla de ajuste de nivel de offset.
    ooffset = new Fl_Dial (682,556,62,62,"");
    ooffset->color(180);
    ooffset->box(FL_NO_BOX);
    ooffset->type(8);
    //ooffset->scaleticks(0); 
    ooffset->labelsize(11);
    ooffset->range(-5,5);
    odispOffset = new Fl_Output(660,650,70,20,"");                             //Display de nivel de offset
    ogroupOffset->end();                                                       //Fin del grupo de controles de nivel de offset
    
    boxgroupgen->image(igen);
    
 	ogroupGenerador-> end();                                                   //Fin del grupo de controles del generador
	
	/*oboxNombre = new Fl_Box(520,375,254,30,"");            
    oboxNombre->box(FL_ENGRAVED_FRAME);
    oboxNombre->labelfont(FL_HELVETICA_BOLD);
    oboxNombre->labelsize(19);*/
	
	ogenOn = new Fl_Light_Button(938,375,35,28,"ON");                          //Bot�n para prender/apagar el generador  
    ogenOn->labelsize(9);     
    
    // Callbacks de los botones del generador de se�ales
    
    ogenOn->callback(cbGeneradorOn, this);
    oseno->callback(cbSeno,this);
    ocuadrada->callback(cbCuadrada,this);
    otriangulo->callback(cbTriangulo,this);
    ofrecGen->callback(cbFrecGen, this);
    ofrecGen2->callback(cbFrecgen2, this);
    oamplitud->callback(cbAmplitud, this);
    ooffset->callback(cbOffset, this);

}


/*******************************************************************************
 * Generador::cbGeneradorOn: Callback del bot�n que prende/apaga el generador 
 *                             de se�ales.
 * Al prender el instrumento se inicializa con las siguientes configuraciones 
 * por defecto:
 * Se�al tipo: Seno.
 * Frecuencia de la se�al: xxxxx Hz.
 * Amplitud: 5 V pico a pico.
 * Nivel de offset: 0 Voltios. 
*******************************************************************************/
void Generador::cbGeneradorOn(Fl_Widget* pboton, void *any){
     Generador* pgener=(Generador*)any;
     pgener->cbGeneradorOnIn();
}

void Generador::cbGeneradorOnIn(){
     if (ogenOn->value()== 1){
        activar(1);
        Encapsular('I','a','1','0',0x00,0x00);
        Transmision();
        if (bhardware==1){
           ogroupGenerador->activate();
           ogroupFrecuencia->activate();
           ogroupOffset->activate();
           oescalaFrecuencia->value(0);
           ogroupSenal->activate();
           ogroupAmplitud->activate();
           oseno->value(1);
        }
        else {
             fl_message("Error de hardware");
        }
     }
     if (ogenOn->value()== 0){
        ocuadrada->box(FL_UP_BOX);                      
        ocuadrada->value(0);
        otriangulo->box(FL_UP_BOX);                      
        otriangulo->value(0);
        activar(0);
        oseno->box(FL_UP_BOX);                      
        oseno->value(0);
        ogroupGenerador->deactivate(); 
     } 
}



/*******************************************************************************
 * Generador::cbSeno: Callback del bot�n que selecciona la se�al tipo seno.
 * Se le env�a al hardware una trama con la configuraci�n de tipo de se�al seno
 * y los otros botones de selecci�n de tipo de se�al se desactivan.
*******************************************************************************/
void Generador::cbSeno(Fl_Widget* pboton, void *any){
     Generador* pgener=(Generador*)any;
     pgener->cbSenoIn();
}

void Generador::cbSenoIn(){
     if (oseno->value()== 0){
        ocuadrada->box(FL_UP_BOX);                      
        ocuadrada->value(0);
        otriangulo->box(FL_UP_BOX);                      
        otriangulo->value(0);
        Encapsular('I','i','1','1',0x00,0x00);                                  //Trama tipo de se�al seno
        Transmision();
        if (bhardware==1){                                                         //Si la respuesta fue ack.
           otriangulo->value(0);
           oseno->value(1);
           oseno->box(FL_DOWN_BOX);
        }
        else {
             fl_message("Error de hardware");
        }
     }
}


/*******************************************************************************
 * Generador::cbCuadrada: Callback del bot�n que selecciona la se�al tipo 
 *                         cuadrada.
 * Se le env�a al hardware una trama con la configuraci�n de tipo de se�al 
 * cuadrada y los otros botones de selecci�n de tipo de se�al se desactivan.
*******************************************************************************/
void Generador::cbCuadrada(Fl_Widget* pboton, void *any){
     Generador* pgener=(Generador*)any;
     pgener->cbCuadradaIn();
}

void Generador::cbCuadradaIn(){
     if (ocuadrada->value()== 0){
        oseno->box(FL_UP_BOX);                      
        oseno->value(0);
        otriangulo->box(FL_UP_BOX);                      
        otriangulo->value(0);
        Encapsular('I','i','1','3',0x00,0x00);                                  //Trama tipo de se�al cuadrada
        Transmision();
        if (bhardware==1){                   
           ocuadrada->value(1);
           ocuadrada->box(FL_DOWN_BOX);
        }
        else {
             fl_message("Error de hardware");
        }
     }
}

/*******************************************************************************
 * Generador::cbTriangulo: Callback del bot�n que selecciona la se�al tipo
 *                          triangulo.
 * Se le env�a al hardware una trama con la configuraci�n de tipo de se�al 
 * triangulo y los otros botones de selecci�n de tipo de se�al se desactivan.
*******************************************************************************/
void Generador::cbTriangulo(Fl_Widget* pboton, void *any){
     Generador* pgener=(Generador*)any;
     pgener->cbTrianguloIn();
}

void Generador::cbTrianguloIn(){
     if (otriangulo->value()== 0){
        oseno->box(FL_UP_BOX);                      
        oseno->value(0);
        ocuadrada->box(FL_UP_BOX);                      
        ocuadrada->value(0);
        Encapsular('I','i','1','2',0x00,0x00);                                  //Trama de tipo de se�al tri�ngulo
        Transmision();
        if (bhardware==1){                   
           otriangulo->value(1);
           otriangulo->box(FL_DOWN_BOX);
        }
        else {
             fl_message("Error de hardware");
        }
     }
}


/*******************************************************************************
 * Generador::cbFrecGen: Callback del bot�n para seleccionar la frecuencia de 
 *                         la se�al generada.
 * FACTOR: Constante por la que se multiplica el valor del bot�n de configurar
 *         la frecuencia, para escalarlo al valor del chip generador de se�ales.
 * ifrechardware: Variable entera que contiene el valor que se debe enviar al 
 *                hardware para configurar la frecuencia de la se�al.
 * frecHexa: Cadena de caracteres donde se almacena el valor ifrechardware
 *            convertido en caracteres hexadecimales que se envi�n en la trama
 *            de configuraci�n de fracuencia de se�al.
 * Para encapsular el valor de frecuencia configurado, se recorre el arreglo de 
 * car�cteres en forma inversa es decir desde el ultimo caracter hasta el primero
 * mediante un ciclo for() y se va adicionando car�cter a car�cter a la trama que
 * se env�a al hardware: "trama_control[]". 
 * Para configurar la frecuencia, se env�a en "trama_control[]" en 8 car�cteres
 * hexadecimales, si el valor se representa en menos de 8 car�cteres hexadecima-
 * les, el resto se rrellena con '0's.  
*******************************************************************************/
void Generador::cbFrecGen(Fl_Widget* pboton, void *any){
     Generador* pgener=(Generador*)any;
     pgener->cbFrecGenIn();
}

void Generador::cbFrecGenIn(){
    
     int ifrechardware;
     int ilong;
     char pruebafrec[10];
     ovalorFrec->value(ofrecGen->value()*5.3687);
     ifrechardware = int(FACTOR*(ofrecGen->value()+ofrecGen2->value()));
     itoa(ofrecGen->value(),cfrecuencia,10);                                  
     //odispGen->value(cfrecuencia);
     sprintf(pruebafrec, "%.6g", ofrecGen->value()); //Valor de la frecuencia guardado en formato de 6 decimales.                         
     //odispGen->value(pruebafrec);
     odisplayGen->label(pruebafrec);
     itoa(ifrechardware,frecHexa,16);                //Conversi�n del valor entero en una cadena de caracteres con el valor hexadecimal.    
     ilong = strlen(frecHexa);
     for (int icont = 8; icont > 0; icont --){        //Ciclo para encapsular el valor de frecuencia configurado en la trama para enviar la hardware.
         if(ilong > 0){
            if (frecHexa[ilong-1]>60){                                                        
               frecHexa[ilong-1]=frecHexa[ilong-1]-32;  
               trama_control[icont-1]=frecHexa[ilong-1];                                                          
            }
            else{
                 trama_control[icont-1]= frecHexa[ilong-1];
            }
         }
         else{
             trama_control[icont-1] = '0'; 
         }
         ilong--;
     }
     trama_control[0] = 0x05;
     trama_control[8] = 0x00;
     Transmision();
}


/*******************************************************************************
 * Generador::cbFrecgen2: Callback del bot�n que realiza el ajuste fino de la
 *                         frecuencia de la se�al generada.
 * Bot�n de ajuste fino para configurar el valor de la frecuencia de las se�ales
 * generadas. Ajusta el valor en un decimo del valor de la escala en la que se 
 * encuentra.
*******************************************************************************/

void Generador::cbFrecgen2(Fl_Widget* pboton, void *any){
     Generador* pgener=(Generador*)any;
     pgener->cbFrecgen2In();
}

void Generador::cbFrecgen2In(){

     ovalorFrec->value(ofrecGen->value()*5.3687+ofrecGen2->value());
}



/*******************************************************************************
 * Generador::cbAmplitud: Callback del bot�n que selecciona la amplitud de la 
 *                         se�al generada.
 * camplitud[]: Cadena de car�cteres que contiene la amplitud configurada para
 *              mostrarla en el diplay de amplitud.
 * El valor del bot�n de configurar la amplitud de la se�al se debe multiplicar 
 * por 51 para escalarlo a valores con el que se configura el hardware entre 0 y
 * FF hexadecimal y se almacena en una cadena de caracteres.
 * amplitudHexa[]: Cadena de caracteres que almacena el valor hexadecimal que
 *                  representa la amplitud configurada por el usuario.  
 * El dato de amplitud se encapsula en "trama_control[]" en la que se env�a al 
 * hardware la amplitud configurada por el usuario.
*******************************************************************************/
void Generador::cbAmplitud(Fl_Widget* pboton, void *any){
     Generador* pgener=(Generador*)any;
     pgener->cbAmplitudIn();
}

void Generador::cbAmplitudIn(){
     char camplitud [10];
     sprintf(camplitud, "%.3g", oamplitud->value());
     odispAmplitud->value(camplitud);
     int ilong;
     itoa(oamplitud->value()*51,amplitudHexa,16);
     ilong = strlen(amplitudHexa);
     if (amplitudHexa[0] > 60){                                     //Para dejar caracteres numericos hexadecimales.            
           amplitudHexa[0]= amplitudHexa[0]-32;
     }
     if (amplitudHexa[1] > 60){
           amplitudHexa[1]= amplitudHexa[1]-32;
     }
     if (ilong>1){
        trama_control[4]= amplitudHexa[0];
        trama_control[5]= amplitudHexa[1];
     }
     else{
        trama_control[4]= '0';
        trama_control[5]= amplitudHexa[1];
     }
     trama_control[0]= 0x01;
     trama_control[1]= 'I';
     trama_control[2]= 'm';
     trama_control[3]= '2';
     trama_control[6]= 0x04;
     trama_control[7]= 0x06;
   //  Transmision();
  /*   if ( ~bhardware){
        fl_message("Error de hardware amp es %d", bhardware);
     }*/
}



/*******************************************************************************
 * Generador::cbOffset: Callback del bot�n que selecciona el nivel de offset de 
 *                       la se�al generada.
 * coffset[]: Cadena de car�cteres que contiene el valor de nivel de offset  
 *            configurado por el usuario para ser visualizado en el display de
 *            valor de offset.
 * El valor de offset se puede configurar entre -5V y 5V en la IGU pero para el 
 * hardware se debe enviar un dato hexadecimal entre 0xOO y 0xFF, por lo que hay
 * que multiplicar el dato del bot�n por 25.6 y sumarle 128 para luego convertir 
 * ese valor en hexadecimal y guardarlo en una cadena de caracteres.
 * offsetHexa[]: Cadena de caracteres que almacena el valor que se va a enviar
 *                al hardware del nivel de offset configurado por el usuario.
 * La cadena de caracteres offsetHexa[], se encapsula en la trama de protocolo
 * trama_control[] para configurar nivel de offset.
*******************************************************************************/
void Generador::cbOffset(Fl_Widget* pboton, void *any)
{
     Generador* pgener=(Generador*)any;
     pgener->cbOffsetIn();
}

void Generador::cbOffsetIn(){
     char coffset [10];
     sprintf(coffset, "%.2g", ooffset->value());                      //Almacenar en formato de dos decimales el valor configurado de nivel de offset          
     odispOffset->value(coffset);
     int ilong;                                               
     itoa(int((ooffset->value()*25.6)+128),offsetHexa,16);           //Escalar el valor configurado de offset entre 0x00 y 0xFF.
     ilong = strlen(offsetHexa);
     if (offsetHexa[0] > 60){
           offsetHexa[0]= offsetHexa[0]-32;
     }
     if (offsetHexa[1] > 60){
           offsetHexa[1]= offsetHexa[1]-32;
     }
     if (ilong>1){
        trama_control[4]= offsetHexa[0];
        trama_control[5]= offsetHexa[1];
     }
     else{
        trama_control[4]= '0';
        trama_control[5]= offsetHexa[1];
     }
     trama_control[0]= 0x01;
     trama_control[1]= 'I';
     trama_control[2]= 'n';
     trama_control[3]= '2';
     trama_control[6]= 0x04;
     trama_control[7]= 0x00;
 //    Transmision();
//     if (~bhardware)
  //      fl_message("Error de hardware");
}



/*******************************************************************************
 * Generador::cbFrec1: Callbacks del men� de escalas de frecuencias de la se�al 
 *                      generada.  
 * El men� tiene 7 escalas de frecuencia que van desde 1Hz hasta 1 MHz.
 * Cuando se escoge alguna de las escalas, el bot�n de configurar frecuencia
 * se coloca en cero y se modifica el rango de dicho bot�n para la escala selec-
 * sionada en el men�. 
*******************************************************************************/

void Generador::cbFrec1(Fl_Widget* psel, void *pany){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     Generador* pgener=(Generador*)pany;
     pgener->cbFrec1In(pselector);
}

void Generador::cbFrec1In(Fl_Widget* psel){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     ofrecGen->range(0,1);
     ofrecGen->value(0);
     ofrecGen2->range(0,0.1);
     ofrecGen2->value(0);
     //odispGen->value("0.0");
}

void Generador::cbFrec100(Fl_Widget* psel, void *pany){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     Generador* pgener=(Generador*)pany;
     pgener->cbFrec100In(pselector);
}

void Generador::cbFrec100In(Fl_Widget* psel){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     ofrecGen->range(0,100);
     ofrecGen->value(0);
     ofrecGen2->range(0,10);
     ofrecGen2->step(0.1);
     ofrecGen2->value(0);
     //odispGen->value("0.0");
}


void Generador::cbFrec500(Fl_Widget* psel, void *pany){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     Generador* pgener=(Generador*)pany;
     pgener->cbFrec500In(pselector);
}

void Generador::cbFrec500In(Fl_Widget* psel){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     ofrecGen->range(0,500);
     ofrecGen->value(0);
     ofrecGen2->range(0,50);
     ofrecGen2->step(0.1);
     ofrecGen2->value(0);
     //odispGen->value("0.0");
}


void Generador::cbFrec1k(Fl_Widget* psel, void *pany){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     Generador* pgener=(Generador*)pany;
     pgener->cbFrec1kIn(pselector);
}

void Generador::cbFrec1kIn(Fl_Widget* psel){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     ofrecGen->range(0,1000);
     ofrecGen->value(0);
     ofrecGen2->range(0,100);
     ofrecGen2->step(0.1);
     ofrecGen2->value(0);
     //odispGen->value("0.0");
}

void Generador::cbFrec100k(Fl_Widget* psel, void *pany){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     Generador* pgener=(Generador*)pany;
     pgener->cbFrec100kIn(pselector);
}

void Generador::cbFrec100kIn(Fl_Widget* psel){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     ofrecGen->range(0,100000);
     ofrecGen->value(0);
     ofrecGen2->range(0,100);
     ofrecGen2->step(0.1);
     ofrecGen2->value(0);
     //odispGen->value("0.0");
}

void Generador::cbFrec500k(Fl_Widget* psel, void *pany){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     Generador* pgener=(Generador*)pany;
     pgener->cbFrec500kIn(pselector);
}

void Generador::cbFrec500kIn(Fl_Widget* psel){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     ofrecGen->range(0,500000);
     ofrecGen->value(0);
     ofrecGen2->range(0,500);
     ofrecGen2->step(0.1);
     ofrecGen2->value(0);
     //odispGen->value("0.0");
}

void Generador::cbFrec1m(Fl_Widget* psel, void *pany){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     Generador* pgener=(Generador*)pany;
     pgener->cbFrec1mIn(pselector);
}

void Generador::cbFrec1mIn(Fl_Widget* psel){
     Fl_Choice *pselector = (Fl_Choice *)psel;
     ofrecGen->range(0,1000000);
     ofrecGen->value(0);
     ofrecGen2->range(0,1000);
     ofrecGen2->step(0.1);
     ofrecGen2->value(0);
     //odispGen->value("0.0");
}



// class destructor
Generador::~Generador(){
	// insert your code here
}
