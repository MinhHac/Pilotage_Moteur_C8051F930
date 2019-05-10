#include <SI_C8051F930_Register_Enums.h>
#include "moteur_port.h"
#include "variables_globales.h"

void InitMoteur(void){                  // initialisation du moteur

   CKCON &= ~0x30;         // T2ML = 0 et T2MH=0, la fréquence d'incrémentation
                           //dépend de T2XCLK
   TMR2RLL = 0x18;         // valeur init: FC18 (H)
   TMR2RLH = 0xFC;
   TMR2L = 0x18;               // valeur init: FC18 (H)
   TMR2H = 0xFC;

   TMR2CN = 0x04;          // 16bits auto-reload et f =fsys/12 avec T2XCLK = 00
                           // Lancer timer2 = moteur tourne au démarrage du microcontrôleur
   IE_ET2 = 1;             // Timer 2 Interrupt Enable
}

void changePhase(void){             // change le phase chaque une base de temps du Timer 2

	switch(etat_phase) {
	     case 0: {
            Phase1;    // sortie phase 1
            break;}
	     case 1: {
            Phase2;	   // sortie phase 2
		    break;}
	     case 2: {
            Phase3;    // sortie phase 3
		    break;}

	     case 3: {
           Phase4;     // sortie phase 4
		   break;}
	}
    etat_phase++;                           // basculement vers une autre phase
    if(etat_phase==4)  etat_phase=0;        // après la phase 4, il retourne la phase 1
}

void demarage_arret_Moteur(void){// Pour arrêt et démarrage du moteur
	TMR2CN_TR2 = !TMR2CN_TR2;    // basculement d’état du TMR2CN_TR2
                                 // => stopper ou lancer le timer2
}

void InitMoteur_Base100us(void){  // configurer le timer 2

          CKCON &= ~0x30;     // T2ML = 0 et T2MH=0, la fréquence d'incrémentation
                                                 //dépend de T2XCLK

          TMR2RLL = 0x59;         // valeur init: FFEF (H)
          TMR2RLH = 0xFF;
          TMR2L = 0x59;               // valeur init: FFEF (H)
          TMR2H = 0xFF;

          TMR2CN = 0x04;   // 16bits auto-reload et f =fsys/12 avec T2XCLK = 00
	                              // Lancer timer2 = moteur tourne au démarrage du microcontrôleur
          IE_ET2 = 1;            // Timer 2 Interrupt Enable
}

void ChangePhase2(void){
	if(etat_phase==0){            // Au debut
		Phase1;                   // sortir la phase 1
	}
	else if(etat_phase==val){     // Apres val fois d'interruption, le compteur etat_phase = la valeur recu par UART0
		Phase2;                   // sortir la phase 2, la duree correspond a 100*val
	}
	else if(etat_phase==2*val){   // Apres une duree de 100*val
		Phase3;                   // sortir la phase 3
	}
	else if(etat_phase==3*val){
		Phase4;
	}
    etat_phase++;                 // le compteur va monter chaque l'interruption
	if(etat_phase==4*val) etat_phase =0;  // Apres 4*val*100us = une periode, le compteur retoune a 0
}
