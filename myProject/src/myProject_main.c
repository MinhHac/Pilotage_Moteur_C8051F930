
//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_C8051F930_Register_Enums.h>
#include "InitDevice.h"
#include "variables_globales.h"
#include "moteur.h"
#include "moteur_port.h"

//-----------------------------------------------------------------------------
// procotype
//-----------------------------------------------------------------------------
void scheduler(void);

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
void main(){

	initDevice();                    // initialisations du microcontrôleur

	while (1){
		while(new_task==0);      // polling sur le flag de la base de temps
                                 // Attente activation du gestionnaire de tache
		new_task=0;              // Lorsque finir l’interruption, remettre le flag = 0
		scheduler();              // lancer la function scheduler()
	}

}


// chaque tache de scheduler prend une duree de temps de 60*150us = 9ms
void scheduler(void){                                // gestionnaire des taches

	static bit flag_init_moteur =0, etat_button=0;   // les flags en static

	switch(scheduler_ct) {                  // ordonnanceur comporte 4 taches
		case 0: {                           //tache 1 => faire quelque chose
			if(flag_init_moteur == 0){          // vérifier l’état du flag si le moteur n’initialise pas =>initialise le
			     flag_init_moteur = 1;   // Mettre le flag = 1 pour la prochaine fois, il ne le réinitialise pas
				 InitMoteur();                // Appel fonction initMoteur() pour initialiser le moteur
			}

		    if(BUTTON == 0 && etat_button != 0){       //  lorsque le bouton est lâché,
			     demarage_arret_Moteur();            //  appel cette fonction pour stopper ou démarrer le moteur
		    	 etat_button = 0;                             // remettre le flag = 0 après de lâcher
		    }
		    else if(BUTTON != 0){                                                     // si le bouton est appuyé
			     etat_button = 1;                                              // le flag = 1
		    }
			break;
		}
		case 60: {                          //tache 2=> faire quelque chose
			break;
		}
		case 120: {                         //tache 3=> faire quelque chose
			break;
		}
		case 180: {                         //tache 4=> faire quelque chose
			break;
		}
		default: break;
	}

	scheduler_ct++;                              // basculement d’une tache vert une autre
	if(scheduler_ct==240) scheduler_ct=0;        // après la tache 4, la tâche sera traité tache 0
}

