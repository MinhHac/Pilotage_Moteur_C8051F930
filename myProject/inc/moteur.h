//=========================================================
// Prototype des fonctions
// (code d�pendant du mat�riel)
//=========================================================

#ifndef MOTEUR_H_
#define MOTEUR_H_

void InitMoteur(void);                  // initialisation du moteur
void changePhase(void);             // change le phase chaque une base de temps du Timer 2
void demarage_arret_Moteur(void);     // arr�t et d�marrage du moteur
void InitMoteur_Base100us(void);
void ChangePhase2(void);

#endif /* MOTEUR_H_ */
