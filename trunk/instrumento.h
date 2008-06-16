// Class automatically generated by Dev-C++ New Class wizard
		
#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <FL/Fl_Ask.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Tooltip.H>
#include <FL/Fl_Help_Dialog.h>

using namespace std;

#pragma hdrstop
#include <stdio.h>
#include <windows.h>
#include "_mpusbapi.h"         // Archivo de cabecera para el enlace con la DLL 
                               // que provee Microchip para la comunicacion USB          
//#pragma argsused*/

#define SIZE_DATA 150          // Maximo tama�o del vector recibido desde el hardawre 
#define SIZE_OSC 512           // Maximo tama�o del vector recibido desde el hardawre 


/*******************************************************************************
*La clase Instrumento es la clase base para los cuatro instrumentos: Osciloscopio,
*Mult�metro, Analizador L�gico y Generador de Se�ales, que conforman el LIV y 
*representa las caracteristicas generales que poseen. 
*******************************************************************************/

class Instrumento {
      
	public:
		// Constructor de Clase
		Instrumento();
		// Destructor de clase
		~Instrumento();
		//Almacena los identificadores de producto y vendedor del dispositivo USB
		char vid_pid[18];
		// Cadena con el n�mero del endpoint de salida para la comunicaci�n USB.
		char out_pipe[11];
	    //Cadena con el n�mero del endpoint de entrada para la comunicaci�n USB
        char in_pipe[11];
		//Apuntador al handle del endpoint pipe de salida para la comunicaci�n USB
        HANDLE myOutPipe;
		//Apuntador al handle del endpoint pipe de entrada para la comunicaci�n USB
        HANDLE myInPipe;
		//Buffer donde se encapsula los comandos enviados al hardware para la comunicaci�n USB
        BYTE trama_control[9];
		//Buffer donde se almacena la informaci�n enviada desde el hardware
	    BYTE receive_buf[SIZE_DATA];
		//Variable que indica si el hardware ya completo de muestrear la se�al del canal 1 del osciloscopio.
	    bool ch1_muestreado;
		//Variable que indica si el hardware ya completo de muestrear la se�al del canal 2 del osciloscopio.
	    bool ch2_muestreado;
		//Buffer donde se almacenan los datos enviados por el hardware del canal 1 del osciloscopio.
	    int buf_osc_ch1[572];
		//int buf_osc_ch1[SIZE_OSC];
        //Variable donde se almacena el dato muestreado uno a uno por el hardware del canal 1 del osciloscopio. 
	    int idato_osc_ch1;
		//Variable donde se almacena el dato muestreado uno a uno por el hardware del canal 2 del osciloscopio. 
	    int idato_osc_ch2;
		//Buffer donde se almacenan los datos enviados por el hardware del canal 2 del osciloscopio.
	    int buf_osc_ch2[572];
	    //int buf_osc_ch2[SIZE_OSC];
		//Buffer donde se almacena la informaci�n desencapsulada enviada por el hardware del Mult�metro.
	    char buf_mult[4];
		//Buffer donde se almacena la informaci�n desencapsulada enviada por el hardware del Analizador L�gico.
	    char buf_analizador[3];
		//Valor de escala de la medicion realizada con el Mult�metro. 
		int imult_escala;
		//Arreglo con los datos de las se�ales digitalizados por el hardware.
		/* TODO (JuanP#1#): Revizar por que al quitarla se da�a el muestreo del 
                            analizador. */
		int idatos[572];                                
		//Variable que representa el estado activo o inactivo de los instrumentos.
		bool bestado;
		//La funci�n archivar genera un archivo plano con los datos enviados por el hardware.
		void archivar(); 
        //La funci�n Sethardware asigna el valor de la variable bhardware que indica el estado del hardware.
        void Sethardware(bool x); 
        //La funci�n activar asigna el valor de la variable estado que indica si el instrumento est� o no activo.
		void activar(bool bx); 
		//La funci�n Transmision realiza la comunicaci�n con el hardware a trav�s de USB.
		void Transmision();
		//La funci�n Encapsular organiza la trama que se env�a al hardware a trav�s de USB.
		void Encapsular(char, char, char, char, char,char);
		//La funci�n Desencapsular organiza los datos enviados desde el hardware a los instrumentos de software a trav�s de USB.
		void Desencapsular(BYTE []);		
		//Esta variable representa el estado funcional del hardware del instrumento.
		bool bhardware;
		//Esta variable contiene el nombre del archivo de texto donde se almacenan los datos del instrumento.
		char cnombre [12];
		//Pantalla de manuales de uso de los instrumentos
		//Fl_Help_Dialog *manuales;
};

#endif // INSTRUMENTO_H
