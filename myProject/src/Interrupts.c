//=========================================================
// Lorsqu'il y a un overflow, le systeme appele l'interruption
// 1. Interruption du Timer 0
// 2. Interruption du timer 2
//=========================================================

// includes

#include <SI_C8051F930_Register_Enums.h>
#include "InitDevice.h"
#include "variables_globales.h"
#include "moteur.h"
#include "moteur_port.h"

INTERRUPT (TIMER2_ISR, TIMER2_IRQn){

	TMR2CN_TF2H = 0;               // flag overflow du timer 2
    changePhase();               // pour changer d’état de la phase.
}

INTERRUPT (TIMER0_ISR, TIMER0_IRQn){ // une base de temps de 250 cycles = 150us

	TCON_TF0 = 0;                   // etteint le flage d'interruption du timer0
	new_task = 1;                   // activer le scheduler et lancer une tache
}

INTERRUPT (UART0_ISR, UART0_IRQn) {

	static bit pass_R=0;
	if(SCON0_TI ==1){   // fin de transmission
      SCON0_TI =0;
	}
	else if(SCON0_RI ==1){  // si il y un message qui vient de Terminal
		                    // il attend la fin de reception, le flag monter automatiquement a 1
	   SCON0_RI = 0;        // remttre valeur de RI0 = 1=>RI0 = 0
	   if(pass_R==0){       // si le flag == 0, il est pret a recois encore des information
	   	      val = SBUF0;  // la variable Val (un octet) prend valeur de SBUF0
	   	      pass_R =1;    // Apres de commencer a recevoir l'information,il prend de temps pour finis la reception
	   }
	   else {               // Le PC tourne au programme pricipal pour faire un autre chose, en attendant cette reception finit
	   	   	  pass_R=0;     // quand, il y a une autre interruption, il va verifier si la lecture est finis
	   }
	}
}
