#include "analizador.h"
#include "generador.h"
#include "osciloscopio.h"
#include "multimetro.h"
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Box.H>

#include <pthread.h>

#include <windows.h> 


//Multimetro *mult =0;
Osciloscopio *osc = 0;
//Analizador *ana = 0;
//Generador *gene = 0;
pthread_t thread1;//, thread1, thread2, thread3;

int status, status2, status3;

/*void *runhilo(void *threadid)
{
   mult = new Multimetro();
}*/


void *runhilo2(void *threadid){
   //osc = new Osciloscopio(5,5,725,360,"",150);
  osc = new Osciloscopio();
}


/*void *runhilo3(void *threadid)
{
   ana = new Analizador();
}

void *runhilo4(void *threadid)
{
   gene = new Generador();
}*/



int main (int argc, char ** argv)
{
  Fl_Double_Window *window, *windowMult;
  Analizador *ana;
  Generador *gene;
  //Osciloscopio *osc;
  Multimetro *mult;
  
  Fl_Box *box_mult;
  Fl_Box *box_osc;
  
  
  int t =0;
  int u =0;
  int y =0;
  int f =0;
  int rc, rc2, rc3, rc4;
  
  window = new Fl_Double_Window (0,0,1024, 708);
  ana = new Analizador();
  gene = new Generador();
  mult = new Multimetro();

  /*rc=pthread_create(&thread, NULL, runhilo, (void *)t);
        if (rc){
           fl_message("ERROR; return code from pthread_create() is %d\n", rc);
           exit(-1);
  }*/
        
  rc2=pthread_create(&thread1, NULL, runhilo2, (void *)u);
        if (rc2){
           fl_message("ERROR; return code from pthread_create() is %d\n", rc2);
           exit(-1);
  }
  
 /* rc3=pthread_create(&thread2, NULL, runhilo3, (void *)y);
        if (rc3){
           fl_message("ERROR; return code from pthread_create() is %d\n", rc3);
           exit(-1);
  }       
 
 
  rc4=pthread_create(&thread3, NULL, runhilo4, (void *)f);
        if (rc4){
           fl_message("ERROR; return code from pthread_create() is %d\n", rc4);
           exit(-1);
  }*/
  
   
   
   
  /*rc = pthread_join(thread, NULL);
      if (rc){
         printf("ERROR; return code from pthread_join() is %d\n", rc);
         exit(-1);
      } 
    */  
  rc2 = pthread_join(thread1, NULL);
      if (rc2){
         printf("ERROR; return code from pthread_join() is %d\n", rc2);
         exit(-1);
      }
      
 /* rc3= pthread_join(thread2, NULL);
      if (rc3){
         printf("ERROR; return code from pthread_join() is %d\n", rc3);
         exit(-1);
      }      
   
  rc4= pthread_join(thread3, NULL);
      if (rc4){
         printf("ERROR; return code from pthread_join() is %d\n", rc4);
         exit(-1);
      } */
  
  box_mult = new Fl_Box(735,12,285,360,"");
  box_osc = new Fl_Box(7,12,725,360,"");
  
  fl_register_images();
  Fl_PNG_Image jpg("mult.png");      // Cargar la mascara en RAM
  Fl_PNG_Image jpgosc("osc.png");
  box_mult->image(jpg);
  box_osc->image(jpgosc);
 
  
  
  window->end ();
  
  window->show (argc, argv);
 
  
  return(Fl::run());
  
}
