//=========================================================
// Prototype des fonctions
//=========================================================
#ifndef __INIT_DEVICE_H__                // s'il a deja declare,
#define __INIT_DEVICE_H__                // on a pas besion de faire encore

extern void initDevice(void);            // pour appeler tous les fonctions initiales.
extern void configuration_timer0(void);  // configuration du timer 0
extern void configuration_timer1(void);  // configuration du timer 1
extern  void permetion_interrupt(void);  // permissions des interruptions

#endif

