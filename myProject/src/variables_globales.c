//=========================================================
// Declaration les variables globales
//
//=========================================================

// les variables pour l'ordonnanceur
xdata unsigned int  scheduler_ct;
bit new_task=0;

// la variable pour garder l'etat des phases de sortie
xdata unsigned int  etat_phase ;

// la variable contient valeur recu de UART0
xdata unsigned char val=6;
