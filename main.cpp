#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <Fl/fl_Light_Button.h>
#include <FL/Fl_Ask.H>
#include "osciloscopio.h"
#include "multimetro.h"
#include <string>
#include <pthread.h>

Multimetro *mult =0;
Osciloscopio *osc = 0;
pthread_t thread, thread1;
int status, status2;


void *runhilo(void *threadid)
{
   mult   = new Multimetro();
}


void *runhilo2(void *threadid)
{
   osc    = new Osciloscopio(8,8,380,304,"",150);
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


int main (int argc, char ** argv)
{
  Fl_Double_Window *window;
  Fl_Light_Button *omult_on;

  int t =0;
  int u =0;
  int rc, rc2;
  
  window = new Fl_Double_Window (1024, 708);
 
  omult_on = new Fl_Light_Button(960,280,30,20,"ON");
  omult_on->labelsize(9);
  
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
 
  omult_on->callback(cb_onmult);
   

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
   
  window->end ();
  window->show (argc, argv);
  
  
  
  return(Fl::run());
  
}
