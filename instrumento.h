// Class automatically generated by Dev-C++ New Class wizard
		
#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H
#include <string.h>
#include <stdlib.h>
#include <FL/Fl_Ask.H>

#define SIZE_DATA 100

#pragma hdrstop
#include <stdio.h>
#include <windows.h>
#include "_mpusbapi.h"                  
#pragma argsused*/

/**
 * La clase Instrumento es la clase base para los cuatro instrumentos
 * que conforman el LIV y representa las caracteristicas generales que 
 * poseen. 
*/
class Instrumento	
{
	public:
		// class constructor
		Instrumento();
		// class destructor
		~Instrumento();
		/**
		 * La funci�n archivar genera un archivo plano con los datos 
		 * enviados por el hardware del intrumento.
		*/
		void archivar();
		/**
		 * La funci�n almacenar guarda los datos enviados por el hardware
		 * del instrumento en el arreglo datos [].
		*/
		void almacenar(int, char[]);
		/**
		 * La funci�n Setnum_datos asigna el valor de la variable
		 * num_datos
		*/
		void Setnum_datos(int x); 
        /**
		 * La funci�n Setarchivo asigna el valor de la variable
		 * archivo.
		*/		
		void Setarchivo(bool x); // sets the value of archivo
		/**
		 * La funci�n Sethardware asigna el valor de la variable
		 * hardware.
		*/
        void Sethardware(bool x); // sets the value of hardware
        /**
		 * La funci�n activar asigna el valor de la variable
		 * estado.
		*/
		void activar(bool bx); // sets the value of estado
		/**
		 * La funci�n Transmision realiza la comunicaci�n
		 * con el hardware a trav�s de USB.
		*/
		void Transmision();
		/**
		 * La funci�n Encapsular organiza la trama que se env�a
		 * al hardware a trav�s de USB.
		*/
		void Encapsular(char, char, char, char, char);
		/**
		 * Almacena los identificadores de producto y vendedor
        */
		char vid_pid[18];
		/**
		 * Cadena con el n�mero del endpoint de salida para
         * comunicaci�n USB.
	    */
		char out_pipe[11];
		/**
		 * Cadena con el n�mero del endpoint de entrada para
		 * comunicaci�n USB
	    */
        char in_pipe[11];
        /**
		 * Apunta al handle del endpoint pipe de salida para la
		 * comunicaci�n USB
	    */
        HANDLE myOutPipe;
        /**
		 * Apunta al handle del endpoint pipe de entrada para la
		 * comunicaci�n USB
	    */
        HANDLE myInPipe;
        /**
		 * Buffer donde se encapsula los comandos enviados al hardware
		 * para la comunicaci�n USB
	    */
        BYTE trama_control[SIZE_DATA];
        /**
		 * Buffer donde se almacena la informaci�n enviada desde el hardware
	    */
	    char receive_buf[SIZE_DATA];
	    /**
		 * Buffer donde se almacena la informaci�n desencapsulada 
         * enviada desde el hardware por el osciloscopio.
	    */
	    char receive_buf_osc[SIZE_DATA];
	    /**
		 * Buffer donde se almacena la informaci�n desencapsulada 
         * enviada desde el hardware por el multimetro.
	    */
	    char receive_buf_mult[5];
	    /**
		 * Esta variable contiene un arreglo con los datos de las se�ales
         * digitalizados por el hardware del instrumento.
		*/
		int idatos[380];
		/**
		 * Esta variable contiene un arreglo con los valores del tiempo
		 * en que se han adquirido los datos de las se�ales digitalizados 
         * por el hardware del instrumento.
	    */
		int itiempo[380];
		/**
		 * Esta variable representa el estado activo o inactivo del
		 * instrumento.
		*/
		bool bestado;
		/**
		 * Esta variable representa si se ha digitalizado datos para el
		 * instrumento.
		*/
		bool bmuestreado;
		/**
		 * Esta variable representa el numero de datos que se han
		 * almacenado provenientes del hardware del instrumento.
		*/
		int inum_datos;
		/**
		 * Esta variable representa el numero de datos que se han
		 * recibido provenientes del hardware del instrumento sin cabecera.
		*/
		int itamano_trama;
	    
	protected:
		
		/**
		 * Esta variable representa el estado funcional del hardware del instrumento.
		*/
		bool bhardware;
		/**
		 * Esta variable representa la habilitaci�n de la opci�n de guardar
		 * los datos adquiridos por los instrumentos en archivos planos. 
		*/
		bool barchivo;
		/**
		 * Esta variable contiene el nombre del instrumento
		*/
		char cnombre [12];	
};

#endif // INSTRUMENTO_H
