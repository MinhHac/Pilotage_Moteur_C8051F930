
//=========================================================
// Declaration les variables globales
//
//=========================================================

#ifndef VARIABLES_GLOBALES_H_
#define VARIABLES_GLOBALES_H_

// les variables pour l'ordonnanceur
extern xdata unsigned int  scheduler_ct;
extern bit new_task;

// la variable pour garder l'etat des phases de sortie
extern xdata unsigned int  etat_phase ;

// la variables contient valeur recu de UART0
extern xdata unsigned char val;

#endif /* VARIABLES_GLOBALES_H_ */
