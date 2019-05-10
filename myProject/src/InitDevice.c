//=========================================================
// Declaration et Initialisation les parametres au demarage
// du Microcontroleur:
// 1. fonction appele les autres fonctions
// 2. fonction pour la configuration du timer 0
// 3. fonction pour la configuration du timer 1
//=========================================================

// includes
#include <SI_C8051F930_Register_Enums.h>
#include "InitDevice.h"

// foncitons
extern void initDevice(void){            // pour appeler tous les fonctions initiales.
	   permetion_interrupt();
	   configuration_timer0();
	   configuration_timer1();

}
extern void configuration_timer0(void){  // configuration du timer 0
	   CKCON &= ~0x0F;                   //  fsys/12 avec SCA1:SCA0 = 00

	   TMOD &= ~0x0F;  // mettre les bits poids faible du regitre TMOD timer0 a 0
	   TMOD |= 0x02;   // mode 2(8 bits auto reload comme un temporaseur)
	                   // => [10] pour les 1 et 0

	   TL0= 0x06;      // valeur init: 06(H) voir dans l’explication
	   TH0 = 0x06;     // il commence a 6 jusqu'a 255 pour remplir 8 bits

	   TCON_TR0 = 1;   // lancer timer 0
}
extern void configuration_timer1(void){  // configuration du timer 1
	   CKCON &= ~0x0F;              //  fsys/12 avec SCA1:SCA0 = 00 meme frequence avec Timer 0

	   TMOD &= ~0xF0;    // mettre les bits poids fort du registre TMOD a 0
	   TMOD |= 0x02;     // mode 2(8 auto-reload bits comme un temporisateur)
	                     // => [10] pour les bits 5 et 4
	   TH1 = 0xA9;       // voir la détaille du Timer 1 pour la vitesse de Baud(l’erreur de 0.22%)

	   SCON0_REN=1;                 // permission de la réception UART0
	   SCON0_TI =1;                 // prêt à transmission UART0

	   TCON_TR1 = 1;                 // lancer timer 0
}
extern  void permetion_interrupt(void){  // permissions des interruptions
		TCON_IT0 =1;                     // permission de l'interruption
		IE_ET0 =1;                       // du Timer0 est enable
		IE_ES0 =1;                       // du UART0 est enable
		IE_EA = 1;                       // EA =1 permission tous les interruptions
}


