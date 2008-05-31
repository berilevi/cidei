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
//Fl_Help_Dialog *manuales;




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
  //window->color(Fl_Color());
  //window->cursor(FL_CURSOR_HAND);
  osc = new Osciloscopio();
 //ana = new Analizador();
  mult = new Multimetro();
 // gene = new Generador();
 // osc = new Osciloscopio();
  //manuales = new Fl_Help_Dialog;
  


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

  
/*  box_mult = new Fl_Box(735,12,285,360,"");
  boxVacMult = new Fl_Box(762,178,80,25,"");
  box_osc = new Fl_Box(6,12,725,360,"");
  boxNomOsc = new Fl_Box(29,20,195,22,"");
  boxOscOn = new Fl_Box(255,16,30,30,"");
  box_analizador = new Fl_Box(6,376,505,330,"");
  box_generador = new Fl_Box(517,375,505,330,"");*/
  
  //boxNomOsc->callback(cb_help);
  
 // fl_register_images();
 // Fl_PNG_Image jpg("mult.png");      // Cargar la mascara en RAM
 // Fl_PNG_Image jpgvacg("vacg.png");
 // Fl_PNG_Image jpgosc("osc.png");
 // Fl_PNG_Image jpgnomosc("oscNom.png");
  //Fl_PNG_Image jpgoscon("oscon.png");
 // Fl_PNG_Image jpgan("analizador.png");
  //Fl_PNG_Image jpggen("generador.png");
  
 // box_mult->image(jpg);
  //boxVacMult->image(jpgvacg);
 // box_osc->image(jpgosc);
// boxNomOsc->image(jpgnomosc);
  //boxOscOn->image(jpgoscon);
 // box_analizador->image(jpgan);
  //box_generador->image(jpggen);
 
  
  
  window->end ();
  
  window->show (argc, argv);
 
  
  return(Fl::run());
  
}
