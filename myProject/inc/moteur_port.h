//=========================================================
// Déclaration et macro de configuration des I/Os
// (code dépendant du matériel)
//=========================================================
#ifndef MOTEUR_PORT_H_
#define MOTEUR_PORT_H_

// Signaux sorties
sbit  S1 = P1^0;         // signal sorti sur le broche P1.0
sbit  S2 = P1^1;         // signal sorti sur le broche P1.1
sbit  S3 = P1^2;        // signal sorti sur le broche P1.2
sbit  S4 = P1^3;        // signal sorti sur le broche P1.3

//les 4 bits poids faible de P1 sont en PUSH PULL
#define P1MDOUT |= 0x0F;

// Bouton poussoir
sbit BUTTON = P0^2;

//le bit 3 de P0 est en OPEN DRAIN
#define P0MDOUT &= ~0x04;

// Définition des phases

#define	Phase1;		S1 =0;S2 =0;S3 =1;S4 =1;     // la phase 1 est 0011
#define	Phase2;		S1 =1;S2 =0;S3 =0;S4 =1;     // la phase 2 est 1001
#define	Phase3;		S1 =1;S2 =1;S3 =0;S4 =0;     // la phase 3 est 1100
#define	Phase4;		S1 =0;S2 =1;S3 =1;S4 =0;     // la phase 4 est 0110

#endif /* MOTEUR_PORT_H_ */
