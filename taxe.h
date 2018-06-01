/*
 -----------------------------------------------------------------------------------
 Laboratoire : No 6
 Fichier     : taxe.h
 Auteur(s)   : Rafael Da Cunha Garcia, Florian Shaufelberger,
                Jorge-Andre Fulgencio Esteves
 Date        : 01.06.2018

 But         : Definir les constantes de taxation ainsi que les declarations des
                methodes de calcul de taxes de base, taxes annuelles et taxes moyennes

 Remarque(s) :

 Compilateur : MinGW-gcc 7.1.0
 -----------------------------------------------------------------------------------
*/

#ifndef TAXE_H
#define TAXE_H

#include <stdint.h>
#include <stdlib.h>
#include "bateau.h"

/*
	Toutes les taxes sont en [Euro]
	La surface maximal avant la taxation pour la voile est en [m2]
	Le Tonnage maximal avant la taxation pour le bateau a peche est en [tonnes]
	La puissance d'un moteur est en [CV]
*/
#define TAXE_BASE_VOILIER 	50
#define TAXE_BASE_MOTEUR	100

#define SURFACE_VOILE_MAX_AVANT_TAXE 200
#define TAXE_SPECIFIQUE_PETITE_VOILE 0
#define TAXE_SPECIFIQUE_GRANDE_VOILE 25

#define TONNAGE_MAX_AVANT_TAXE 20
#define TAXE_SPECIFIQUE_PETIT_TONNAGE 0
#define TAXE_SPECIFIQUE_GRAND_TONNAGE 100

#define PUISSANCE_MAX_AVANT_TAXE 100
#define TAXE_SPECIFIQUE_PETIT_MOTEUR 50
#define TAXE_SPECIFIQUE_GRAND_MOTEUR 100


double taxeBase (const Bateau* bateau);
double taxeSpecifique(const Bateau* bateau);
double taxeParBateau(const Bateau* bateau);
void taxeTotalPort(Bateau port[], double *taxeParType, uint8_t nombreDeBateau);

#endif /* TAXE_H */
