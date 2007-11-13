// Class automatically generated by Dev-C++ New Class wizard

#include "instrumento.h" // class's header file
#include <stdio.h>
#include <FL/Fl_Ask.H>

// class constructor
Instrumento::Instrumento()
{
    int icont;
    inum_datos=0;
    strcpy(vid_pid, "vid_04d8&pid_000a");       // Product & Vendor ID
    strcpy(out_pipe, "\\MCHP_EP3");             // End Point de salida 
    strcpy(in_pipe, "\\MCHP_EP3");              // End Point de salida
    trama_control[0] = 0x01;                    // Valor de inicio de trama
    trama_control[5] = 0x04;                    // Final de trama del protocolo
    trama_control[6] = 0x00;                    // Fin de cadena que se va a transmitir
    
    strcpy(buf_mult,"0000");
}

// class destructor
Instrumento::~Instrumento()
{
	// insert your code here
}


// sets the value of estado
void Instrumento::activar(bool bx)
{
	bestado = bx;
}

// sets the value of hardware
void Instrumento::Sethardware(bool x)
{
	bhardware = x;
}

// sets the value of archivo
void Instrumento::Setarchivo(bool x)
{
	barchivo = x;
}

// sets the value of num_datos
void Instrumento::Setnum_datos(int x)
{
	inum_datos = x;
}

/*
 * Esta funci�n almacena los datos enviados por el hardware
 * del instrumento en el arreglo datos.
 */
void Instrumento::almacenar(int itamano, char cdato [])
{
     int ii;
     if (inum_datos >= 379) {              // Almacenar datos para pantalla y media del osciloscopio
        inum_datos = 0;
     }
     for (ii=0;ii < itamano-1; ii++){   
         idatos[ii+inum_datos] = int(cdato[ii]);
         //itiempo[ii+inum_datos]=ii+inum_datos;
      }   
      inum_datos = inum_datos+(itamano-1);  
}

/*
 * Esta funci�n genera un archivo plano con los datos 
 * enviados por el hardware del instrumento.
 */
void Instrumento::archivar()
{
     FILE * log;
     log = fopen(cnombre,"w+");
     if (log != NULL) {
             //fwrite(idatos,sizeof(int),inum_datos,log);
             //fwrite(receive_buf_osc,sizeof(char),50,log);
     }
     else {
          fl_alert("No se pudo abrir el archivo");     
     }          
}

/**
 * La funci�n Transmision realiza la comunicaci�n
 * con el hardware a trav�s de USB.
*/

void Instrumento::Transmision(){
   
   int icont;
   
   if (bestado){

    DWORD selection;
    fflush(stdin);
    selection = 0;

    myOutPipe = MPUSBOpen(selection,vid_pid,out_pipe,MP_WRITE,0);
    myInPipe = MPUSBOpen(selection,vid_pid,out_pipe,MP_READ,0);
    if(myOutPipe == INVALID_HANDLE_VALUE || myInPipe == INVALID_HANDLE_VALUE)
    {
        fl_message("Failed to open data pipes.");
        return;
    }

    DWORD RecvLength=100;
    DWORD SentDataLength;
    
     
    MPUSBWrite(myOutPipe,trama_control,10,&SentDataLength,10);
      
    MPUSBRead(myInPipe,receive_buf,110,&RecvLength,10);
    
    Desencapsular(receive_buf);
    
    itamano_trama = int(receive_buf [4]);

    if (receive_buf[2]== 'D'){
      //strcpy(receive_buf_mult,"0000");
       for (icont=5;icont<(itamano_trama+5);icont++){
            // receive_buf_mult[icont-5]=receive_buf[icont];
         }
         if (itamano_trama < 4){
         //   receive_buf_mult[itamano_trama] = 0x00;
         }
    }
    else if (receive_buf[2]== 'A'){
         for (icont=5;icont<(itamano_trama+4);icont++){
             receive_buf_osc[icont-5]=receive_buf[icont]; 
         }
    }
    
    //fl_message("dato es: %d", atoi(receive_buf_mult));
               
    MPUSBClose(myOutPipe);
    MPUSBClose(myInPipe);
    myOutPipe = myInPipe = INVALID_HANDLE_VALUE;    
    
    }
    else {
    MPUSBClose(myOutPipe);
    MPUSBClose(myInPipe);
    myOutPipe = myInPipe = INVALID_HANDLE_VALUE;    
}
}

/*
 * La funci�n Encapsular organiza la trama que se env�a
 * al hardware a trav�s de USB.
*/
void Instrumento::Encapsular(char cnom, char coper, char clong, char cdato)
{
     trama_control[1] = cnom;
     trama_control[2] = coper;
     trama_control[3] = clong;
     trama_control[4] = cdato;
}

/**
 * La funci�n Desencapsular organiza los datos enviados desde el hardware
 * a los instrumentos de software a trav�s de USB.
*/
void Instrumento::Desencapsular(char recibida [])
{
     int icont;
     int itamano;
     char sanalizador1 [8];
     char sanalizador2 [5];
     int imsb;
     int ilsb;
     itamano = int (recibida [3]);
     switch (recibida [1]){
            case 'A':
                 switch (recibida [2]){
                        case '1':
                             for (icont = 4; icont < (itamano+4); icont++){
                                 buf_osc_ch1[icont-4]=recibida[icont];
                             }
                        case '2':
                             for (icont = 4; icont < (itamano+4); icont++){
                                 buf_osc_ch1[(icont-4)+143]=recibida[icont];
                             }
                        case '3':
                             for (icont = 4; icont < (itamano+4); icont++){
                                 buf_osc_ch1[(icont-4)+286]=recibida[icont];
                             }
                        case '4':
                             for (icont = 4; icont < (itamano+4); icont++){
                                 buf_osc_ch1[(icont-4)+429]=recibida[icont];
                             }                    
                 }
            case 'B':
                 switch (recibida [2]){
                        case '1':
                             for (icont = 4; icont < (itamano+4); icont++){
                                 buf_osc_ch2[icont-4]=recibida[icont];
                             }
                        case '2':
                             for (icont = 4; icont < (itamano+4); icont++){
                                 buf_osc_ch2[(icont-4)+143]=recibida[icont];
                             }
                        case '3':
                             for (icont = 4; icont < (itamano+4); icont++){
                                 buf_osc_ch2[(icont-4)+286]=recibida[icont];
                             }
                        case '4':
                             for (icont = 4; icont < (itamano+4); icont++){
                                 buf_osc_ch2[(icont-4)+429]=recibida[icont];
                             }                    
                 }
            case 'C':
                 imsb = int(recibida [4]);
                 ilsb = int(recibida [5]);
                 itoa (imsb, sanalizador1, 2);
                 itoa (imsb, sanalizador2, 2);
                 strcat (sanalizador1, sanalizador2);
                 /* TODO (JPP#1#): revizar lo que hizo ricardo para el analizador */
            case 'D':
                 strcpy(buf_mult,"0000");
                 for (icont=4;icont<(itamano+4);icont++){
                     buf_mult[icont-4]=receive_buf[icont];
                 }
                 if (itamano < 4){
                    buf_mult[itamano] = 0x00;
                 }
            case 'E':
                 
            case 'F':
                 
            case 'G':
                 
            case 'H':
            
            case 'I':
            
            case 'J':
                 
            case 'K':
                 
            case 'L':
                 
     ;}
}


