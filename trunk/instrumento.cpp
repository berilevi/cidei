// Class automatically generated by Dev-C++ New Class wizard

#include "instrumento.h"  // Archivo de cabecera de clase
#include <stdio.h>
#include <FL/Fl_Ask.H>

// Constructor de la clase
Instrumento::Instrumento()
{

    strcpy(vid_pid, "vid_04d8&pid_000a");       // Product & Vendor ID
    strcpy(out_pipe, "\\MCHP_EP3");             // End Point de salida 
    strcpy(in_pipe, "\\MCHP_EP3");              // End Point de salida
    trama_control[0] = 0x01;                    // Valor de inicio de trama
    trama_control[5] = 0x04;                    // Final de trama del protocolo
    trama_control[6] = 0x00;                    // Fin de cadena que se va a transmitir
    strcpy(buf_mult,"0000");                    // Inicializar el bufer del multimetro.
    ch1_muestreado = 0;                         // Inicializar el estado del muestreo del canal 1 del osciloscopio
    ch2_muestreado = 0;                         // Inicializar el estado del muestreo del canal 2 del osciloscopio
    idato_osc_ch1 =0;                           // Dato muestreado uno a uno por el canal 1 del osciloscopio
    idato_osc_ch2 =0;                           // Dato muestreado uno a uno por el canal 2 del osciloscopio
    inum_datos = 0;                             // inicializado el numero de datos almacenados
}

// Destructor de clase
Instrumento::~Instrumento()
{
	// insert your code here
}

// Activar el instrumento
void Instrumento::activar(bool bx)
{
	bestado = bx;
}

// Verificacion del estado de conexi�n con el hardware
void Instrumento::Sethardware(bool x)
{
	bhardware = x;
}

// Activar el almacenamiento de datos en archivoa planos
void Instrumento::Setarchivo(bool x)
{
	barchivo = x;
}


/*
 * Esta funci�n genera un archivo plano con los datos 
 * enviados por el hardware del instrumento.
 */
void Instrumento::archivar()
{
     FILE * log;
     log = fopen(cnombre,"w+");                           // Nombre y permisos de acceso al archivo de texto
     if (log != NULL) {
        fwrite(idatos,sizeof(int),inum_datos,log);        // Escritura de los datos en el archivo de texto
     }
     else {
          fl_alert("No se pudo abrir el archivo");        // Error de apertura del archivo 
     }          
}

/**
 * La funci�n Transmision realiza la comunicacion con el hardware a traves de USB
 * haciendo uso del framework que proporciona Microchip.
*/

void Instrumento::Transmision(){
   
   if (bestado){                     // Se ejecuta si el instrumento esta activo

      DWORD selection;               // Pipe para la transmision 
      fflush(stdin);                 // Limpiar Buffers
      selection = 0;                 // El pipe para la comunicacion va a ser siempre el cero

      myOutPipe = MPUSBOpen(selection,vid_pid,out_pipe,MP_WRITE,0);                   //Abrir el pipe de salida para escritura
      myInPipe = MPUSBOpen(selection,vid_pid,out_pipe,MP_READ,0);                     //Abrir el pipe de entrada para lectura
      if(myOutPipe == INVALID_HANDLE_VALUE || myInPipe == INVALID_HANDLE_VALUE)       //Verificar que se abrieron correctamente los pipes
      {
        fl_message("Failed to open data pipes.");         
        return;
      }

      DWORD RecvLength=190;                                                           //Longitud maxima del buffer que recibe los datos de transmision        
      DWORD SentDataLength;                                                           
      
      //fl_message("envio al hw es: %s", trama_control);
    
      MPUSBWrite(myOutPipe,trama_control,10,&SentDataLength,100);                     //Transmitir la trama al hardware
      fflush(stdin);                                                                  //Limpiar el buffer de salida
      
      MPUSBRead(myInPipe,receive_buf,190,&RecvLength,100);                            //Recibir lo que transmite el hardware
      MPUSBRead(myInPipe,receive_buf,190,&RecvLength,100);
  
      Desencapsular(receive_buf);                                                     //Desencapsular la trama enviada desde el hardware
             
      MPUSBClose(myOutPipe);                                                          //Cerrar los pipes al terminar cada comunicacion 
      MPUSBClose(myInPipe);
      myOutPipe = myInPipe = INVALID_HANDLE_VALUE;                                    
    
   }
   else {
        MPUSBClose(myOutPipe);                                                        //Cerrar los pipes al terminar cada comunicacion 
        MPUSBClose(myInPipe);
        myOutPipe = myInPipe = INVALID_HANDLE_VALUE;    
   }
}

/*
 * La funci�n Encapsular organiza la trama que se env�a al hardware a traves de USB.
*/
void Instrumento::Encapsular(char cnom, char coper, char clong, char cdato, char cfin, char cfin2)
{
     trama_control[1] = cnom;           //Dispositivo de hardware 
     trama_control[2] = coper;          //Operacion que se va a realizar 
     trama_control[3] = clong;          //Longitud de datos que se van a enviar
     trama_control[4] = cdato;          //Dato que se va a configurar en el hardware
     trama_control[7] = cfin;           //Dato que se va a configurar en el hardware
     trama_control[8] = cfin2;          //Dato que se va a configurar en el hardware
}


/**
 * La funci�n Desencapsular organiza los datos enviados desde el hardware
 * a los instrumentos de software a traves de USB.
*/
void Instrumento::Desencapsular(BYTE recibida [])
{
      //fl_message("trama recibida %s", recibida);
     int icont = 0;                                                      //Contador auxiliar para los ciclos
     int itamano;
     itamano = int (recibida [3]);                                       //Tamano de la informacion enviada
     switch (recibida [1]){
            case 'A':                                                    //Informacion para Osciloscopio canal 1
                 if (recibida [2] == '1'){                               //Primer vector de datos para canal 1
                   for (icont = 4; icont < 147; icont++){
                        buf_osc_ch1[icont-4]=int(recibida[icont]);
                    }
                 }
                 else if (recibida [2] == '2'){                          //Segundo vector de datos para el canal 1
                      for (icont = 4; icont < 147; icont++){
                          buf_osc_ch1[(icont-4)+143]=int(recibida[icont]);
                      }
                 }
                 else if (recibida [2] == '3'){                           //Tercer vector de datos para el canal 1
                      for (icont = 4; icont < 147; icont++){
                          buf_osc_ch1[(icont-4)+286]=int(recibida[icont]);
                      }
                 }
                 else if (recibida [2] == '4'){                           //Cuarto vector de datos para el canal 1
                      for (icont = 4; icont < 147; icont++){
                          buf_osc_ch1[(icont-4)+429]=int(recibida[icont]);
                      }
                 }
                 break;
            case 'B':                                                     //Informacion para Osciloscopio canal 2
                 if (recibida [2] == '1'){                                //Primer vector de datos para canal 2
                    for (icont = 4; icont < 147; icont++){
                        buf_osc_ch2[icont-4]=int(recibida[icont]);
                    }
                 }
                 else if (recibida [2] == '2'){                           //Segundo vector de datos para canal 2
                      for (icont = 4; icont < 147; icont++){
                          buf_osc_ch2[(icont-4)+143]=int(recibida[icont]);
                      }
                 }
                 else if (recibida [2] == '3'){                           //Tercer vector de datos para canal 2
                      for (icont = 4; icont < 147; icont++){
                          buf_osc_ch2[(icont-4)+286]=int(recibida[icont]);
                      }
                 }
                 else if (recibida [2] == '4'){                           //Cuarto vector de datos para canal 2
                      for (icont = 4; icont < 147; icont++){
                          buf_osc_ch2[(icont-4)+429]=int(recibida[icont]);
                      }
                 } 
                 break;                  
            case 'C':                                                     //Informacion para Analizador l�gico
                 if (recibida [2] == 'p'){
                   buf_analizador[0] = recibida[4];
                   buf_analizador[1] = recibida[5];
                 }                                     
                 break;
            case 'D':                                                     //Informacion para Voltimetro AC
                 strcpy(buf_mult,"0000");
                 for (icont=4;icont<(itamano+4);icont++){
                     buf_mult[icont-4]=receive_buf[icont];
                 }
                 if (itamano < 4){
                    buf_mult[itamano] = 0x00;                              
                 }
                 imult_escala = recibida[2];
                 break;
            case 'E':                                                     //Informacion para Voltimetro DC
                 strcpy(buf_mult,"0000");
                 for (icont=4;icont<(itamano+4);icont++){
                     buf_mult[icont-4]=receive_buf[icont];
                 }
                 if (itamano < 4){
                    buf_mult[itamano] = 0x00;
                 }
                 imult_escala = recibida[2];
                 break;
            case 'F':                                                     //Informacion para Amperimetro AC
                 strcpy(buf_mult,"0000");
                 for (icont=4;icont<(itamano+4);icont++){
                     buf_mult[icont-4]=receive_buf[icont];
                 }
                 if (itamano < 4){
                    buf_mult[itamano] = 0x00;
                 }
                 imult_escala = recibida[2];
                 break;
            case 'G':                                                     //Informacion para Amperimetro DC
                 strcpy(buf_mult,"0000");
                 for (icont=4;icont<(itamano+4);icont++){
                     buf_mult[icont-4]=receive_buf[icont];
                 }
                 if (itamano < 4){
                    buf_mult[itamano] = 0x00;
                 }
                 imult_escala = recibida[2];
                 break;
            case 'H':                                                     //Informacion para Ohmetro
                 strcpy(buf_mult,"0000");
                 for (icont=4;icont<(itamano+4);icont++){
                     buf_mult[icont-4]=receive_buf[icont];
                 }
                 if (itamano < 4){
                    buf_mult[itamano] = 0x00;
                 }
                 break;
                 imult_escala = recibida[2];
            case 'I':                                                     //Informacion para Generador de se�ales
                 break;
            case 'J':                                                     //Pruebas de conectividad de LIV
                 if (recibida [2]== 0x06){                                //ACK
                    Sethardware(true);
                 }
                 else if (recibida [2] == 0x15){                          //NACK
                      fl_message("Error de Hardware nack");
                      Sethardware(0);
                 }
                 break;
            case 'K':                                                     //Informacion para el Multimetro
                 break;
            case 'L':                                                     //Informacion para el Osciloscopio
                 if (recibida [2] == 'p'){
                    if (recibida [4]== '1'){                              //Muestreo completo de se�al en canal 1 del osciloscopio
                       ch1_muestreado = 1;         
                    }
                    else if(recibida [4]== '2'){                          //Muestreo completo de se�al en canal 2 del osciloscopio
                        ch2_muestreado = 1; 
                    }
                 }
                 else if (recibida [2] == '1'){                           //Muestreo de la se�al dato por dato en canal 1
                      idato_osc_ch1=(recibida[4]-'0');
                 }
                 else if (recibida [2] == '2'){                           //Muestreo de la se�al dato por dato en canal 2
                      idato_osc_ch2=int(recibida[5]-'0');
                 }
                 else if (recibida [2] == '3'){
                 }
                 break;
     }
}


