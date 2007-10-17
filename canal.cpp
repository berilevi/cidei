// Class automatically generated by Dev-C++ New Class wizard

#include "canal.h" // class's header file
int isec_acople;

 
// class destructor
Canal::~Canal()
{
	// insert your code here
}


// sets the value of nv_div
void Canal::Setnv_div(int x)
{
	nv_div = x;
}


// sets the value of npos_y
void Canal::Setnpos_y(int x)
{
	npos_y = x;
}


// sets the value of bgnd
void Canal::Setbgnd(bool x)
{
	bgnd = x;
}


// sets the value of bac
void Canal::Setbac(bool x)
{
	bac = x;
}


// sets the value of bdc
void Canal::Setbdc(bool x)
{
	bdc = x;
}

/*
 * M�todo para realizar la gr�fica de la se�al adquirida por
 * el canal del osciloscopio
 */
void Canal::draw(){ }

/*
 * M�todo para calcular el valor pico a pico de la se�al
 * adquirida por el canal del osciloscopio
 */
float Canal::vpp()
{
      int icont;
      int imayor = 0;         // Inicializar el valor mayor
      int imenor = 500;       // Inicializar el valor menor
      
      for (icont=0; icont<inum_datos; icont++){
          if (idatos[icont]>imayor){
              imayor = idatos[icont];               
          }
          if (idatos[icont]< imenor){
             imenor = idatos[icont];
          }                                
      }  
      dvolt_pp = imayor - imenor; 
      return dvolt_pp;                  
}

/*
 * M�todo para calcular la frecuencia de la se�al (periodica) 
 * adquirida por el canal del osciloscopio
 */
float Canal::frecuencia()
{
	/* TODO (#1#): Implement Canal::frecuencia() */
}

/**
 * Este m�todo es el callback del boton selector de acople
 * del canal del osciloscopio debe ir acompa�ada de una funci�n 
 * inline para poder realizar los callbacks. 
*/
void Canal::cb_acople(Fl_Widget* pboton, void *pany)
{
     Canal* pcanal=(Canal*)pany;       
     pcanal->cb_acople_in();
}

/**
 * Esta funci�n acompa�a la funci�n  cb_acople  
 * para realizar los llamados de callback del selector de acople
 * del canal en el osciloscopio 
*/
void Canal::cb_acople_in(){
  if (isec_acople==0){
     oacop_gnd->value(0);
     oacop_ac->value(1);
     }
     if (isec_acople==1){
     oacop_ac->value(0);
     oacop_dc->value(1);
     }
     if (isec_acople==2){
     oacop_dc->value(0);
     oacop_gnd->value(1);
     isec_acople=-1;
     }
     isec_acople++;  
}

/**
 * Este m�todo es el callback del selector de la escala de volt/div
 * del canal del osciloscopio debe ir acompa�ada de una funci�n 
 * inline para poder realizar los callbacks. 
*/
void Canal::cb_volt_div(Fl_Widget* psel, void *pany)
{
     Fl_Knob *pselector = (Fl_Knob *)psel;
     Canal* pcanal=(Canal*)pany;           
     pcanal->cb_volt_div_in(pselector);
}

/**
 * Esta funci�n acompa�a la funci�n  cb_volt_div  
 * para realizar los llamados de callback del selector de la escala
 * de volt/div del canal en el osciloscopio 
*/
void Canal::cb_volt_div_in(Fl_Widget* psel){
     Fl_Knob *pselector = (Fl_Knob *)psel;
     pselector->value(floor(pselector->value()));
     omenu_v_div->value(pselector->value());
}

/**
 * Este m�todo es el callback del selector de posici�n de la se�al
 * del canal del osciloscopio debe ir acompa�ada de una funci�n 
 * inline para poder realizar los callbacks. 
*/
void Canal::cb_posx(Fl_Widget* psel, void *pany)
{
     Fl_Knob *pselector = (Fl_Knob *)psel;
     Canal* pcanal=(Canal*)pany;       
     pcanal->cb_posx_in(pselector);
}

/**
 * Esta funci�n acompa�a la funci�n  cb_posx  
 * para realizar los llamados de callback del selector de posicion
 * de la se�al del canal en el osciloscopio 
*/
void Canal::cb_posx_in(Fl_Widget* psel){
     Fl_Knob *pselector = (Fl_Knob *)psel;
     ov_posy->value(pselector->value());
     Setnpos_y(10000*(pselector->value()));
}


/**
 * La funci�n recorrer_datos recorre el arreglo idatos y envia punto 
 * por punto los datos para graficar.
*/
void Canal::recorrer_datos()
{
     int icont;
     for (icont=0; icont < inum_datos-1; icont++){
        idato_graf= idatos[icont];
        if (idato_graf==0) {
           opantalla->Add(560+npos_y);
        } 
        else{
             opantalla->Add(npos_y+(560*(idato_graf)));
        }
     }
}
