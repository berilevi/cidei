#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Window.H>
#include <Fl/fl_Light_Button.h>
#include <FL/Fl_Ask.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Box.H>
#include "osciloscopio.h"
#include "multimetro.h"
#include "analizador.h"
#include "generador.h"
#include <string>
#include <pthread.h>

Multimetro *mult =0;
Osciloscopio *osc = 0;
Analizador *ana = 0;
Generador *gene = 0;
pthread_t thread, thread1, thread2;

int status, status2, status3;

void *runhilo(void *threadid)
{
   mult = new Multimetro();
}

void *runhilo3(void *threadid)
{
   ana = new Analizador();
}

void *runhilo2(void *threadid)
{
   osc = new Osciloscopio(8,8,380,304,"",150);
}

int main (int argc, char ** argv)
{
  Fl_Double_Window *window;
  Fl_Window *window2;
 
  
  //Fl_Light_Button *omult_on;

  int t =0;
  int u =0;
  int y =0;
  int rc, rc2, rc3;
  
  window = new Fl_Double_Window (1024, 708);
  //window2 = new Fl_Window (104, 108, 200,200,"hola");
  ana = new Analizador();
  gene = new Generador();
  
  
  rc=pthread_create(&thread, NULL, runhilo, (void *)t);
        if (rc){
           fl_message("ERROR; return code from pthread_create() is %d\n", rc);
           exit(-1);
  }
        
  rc2=pthread_create(&thread1, NULL, runhilo2, (void *)u);
        if (rc2){
           fl_message("ERROR; return code from pthread_create() is %d\n", rc2);
           exit(-1);
  }
  
 /* rc3=pthread_create(&thread2, NULL, runhilo3, (void *)y);
        if (rc3){
           fl_message("ERROR; return code from pthread_create() is %d\n", rc3);
           exit(-1);
  }*/       
 
   
  rc = pthread_join(thread, NULL);
      if (rc)
      {
         printf("ERROR; return code from pthread_join() is %d\n", rc);
         exit(-1);
      } 
      
  rc2 = pthread_join(thread1, NULL);
      if (rc2)
      {
         printf("ERROR; return code from pthread_join() is %d\n", rc2);
         exit(-1);
      }
      
/*  rc3= pthread_join(thread2, NULL);
      if (rc3)
      {
         printf("ERROR; return code from pthread_join() is %d\n", rc3);
         exit(-1);
      }      
  */ 
  
  
  
  window->end ();
  window->show (argc, argv);
  
//  window2->end ();
//  window2->show (argc, argv);
  
  return(Fl::run());
  
}
