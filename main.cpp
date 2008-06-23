#include "analizador.h"
#include "generador.h"
#include "osciloscopio.h"
#include "multimetro.h"
#include <FL/Fl.H>
#include <FL/Fl_Help_Dialog.h>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Box.H>
#include <pthread.h>
#include <windows.h> 


Osciloscopio *osc = 0;
pthread_t thread1;

int status, status2, status3;


void *runhilo2(void *threadid){
  osc = new Osciloscopio();
}

int main (int argc, char ** argv)
{
  Fl_Double_Window *window, *windowMult;
  Analizador *ana;
  Generador *gene;
  Multimetro *mult;
  
  
  Fl_Box *box_mult;
  Fl_Box *boxVacMult;
  Fl_Box *box_osc;
  Fl_Box *boxNomOsc;
  Fl_Box *boxOscOn;
  Fl_Box *box_analizador;
  Fl_Box *box_generador;
  
  
  int t =0;
  int u =0;
  int y =0;
  int f =0;
  int rc, rc2, rc3, rc4;
  
  window = new Fl_Double_Window (0,0,1024,708);
  osc = new Osciloscopio();
  //ana = new Analizador();
  mult = new Multimetro();
  //gene = new Generador();
  // osc = new Osciloscopio();
  


 /* rc2=pthread_create(&thread1, NULL, runhilo2, (void *)u);
        if (rc2){
           fl_message("ERROR; return code from pthread_create() is %d\n", rc2);
           exit(-1);
  }
  

  rc2 = pthread_join(thread1, NULL);
      if (rc2){
         printf("ERROR; return code from pthread_join() is %d\n", rc2);
         exit(-1);
      }
      */

   
  
  window->end ();
  
  window->show (argc, argv);
 
  
  return(Fl::run());
  
}
