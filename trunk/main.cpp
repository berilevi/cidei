#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <Fl/fl_Light_Button.h>
#include <FL/Fl_Ask.H>
#include "osciloscopio.h"
#include "multimetro.h"
#include <string>
#include <pthread.h>

Multimetro *mult =0;
Osciloscopio *osc;
pthread_t thread;
int hilo, a;

void *runhilo(void *threadid)
{
   int tid;
   tid = (int)threadid;
   mult   = new Multimetro();
   mult->activar(1);
   mult->ogroup_mult->activate();
   pthread_exit(NULL);
}


void cb_onmult(Fl_Widget * pbot){
     Fl_Button* ponmult = (Fl_Button *)pbot;
     if (ponmult->value()== 1){
        mult->activar(1);
        mult->ogroup_mult->activate(); 
     }
     if (ponmult->value()== 0){
        mult->activar(0);
        pthread_exit(NULL);
        strcpy(mult->receive_buf_mult,"0.00");
        mult->ogroup_mult->deactivate(); 
     }
}


void cb_onosc(Fl_Widget * pbot){
     Fl_Button* ponosc = (Fl_Button *)pbot;
     if (ponosc->value()== 1){
        osc->activar(1);
        osc->ogroup_osc->activate(); 
        osc->ogroup_tdiv->activate();
     }
     if (ponosc->value()== 0){
        osc->activar(0);
        osc->ogroup_osc->deactivate(); 
        osc->ogroup_tdiv->deactivate();
     }
}


int main (int argc, char ** argv)
{
  Fl_Double_Window *window;
 
  Fl_Light_Button *omult_on;
  Fl_Light_Button *oosc_on;
  
  int t =0;
  int rc;
  int status;
  
  window = new Fl_Double_Window (1024, 708);
  osc    = new Osciloscopio(8,8,380,304,"",150); 
 
  
  omult_on = new Fl_Light_Button(960,280,30,20,"ON");
  oosc_on = new Fl_Light_Button(650,340,30,20,"ON");
  oosc_on->labelsize(9);
  omult_on->labelsize(9);
  
  rc=pthread_create(&thread, NULL, runhilo, (void *)t);
        if (rc){
           fl_message("ERROR; return code from pthread_create() is %d\n", rc);
           exit(-1);
        }
 
  omult_on->callback(cb_onmult);
  oosc_on->callback(cb_onosc);
   
  window->end ();
  window->show (argc, argv);
  
  rc = pthread_join(thread, (void **)&status);
      if (rc)
      {
         printf("ERROR; return code from pthread_join() is %d\n", rc);
         exit(-1);
      }
  
  return(Fl::run());
  
}
