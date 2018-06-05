/*
 -----------------------------------------------------------------------------------
 Laboratoire : No 6
 Fichier     : bateau.c
 Auteur(s)   : Rafael Da Cunha Garcia, Florian Shaufelberger,
                Jorge-Andre Fulgencio Esteves
 Date        : 01.06.2018

 But         : Contient la definition des methodes permettant d'initialiser divers
                bateaux. Une methode par type de bateau a generer.

 Remarque(s) :

 Compilateur : MinGW-gcc 7.1.0
 -----------------------------------------------------------------------------------
*/

#include "bateau.h"


Bateau initBateauVoilier(const char* nom, uint16_t surfaceVoilure) {
    return (Bateau) {.nom = nom, .typeA = VOILIER,
						.voilier = (Voilier) {surfaceVoilure}};
}

Bateau initBateauPeche(const char* nom, uint16_t puissance, uint16_t tonnePoisson) {
    return (Bateau) {.nom = nom, .typeA = BATEAU_A_MOTEUR,
                     .bateauMoteur = (BateauAMoteur) {.puissance = puissance,
									  .typeB = PECHE,
                                      .bateauPeche = (BateauPeche) {tonnePoisson}}};
}

Bateau initBateauPlaisance(const char* nom, uint16_t puissance,
							const char* nomProprietaire) {
    return (Bateau) {.nom = nom, .typeA = BATEAU_A_MOTEUR,
                     .bateauMoteur = (BateauAMoteur) {.puissance = puissance,
									  .typeB = PLAISANCE,
                                      .bateauPlaisance = (BateauPlaisance) 
															{nomProprietaire}}};
}
