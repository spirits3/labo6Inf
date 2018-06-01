/*
 -----------------------------------------------------------------------------------
 Laboratoire : No 6
 Fichier     : affichage.h
 Auteur(s)   : Rafael Da Cunha Garcia, Florian Shaufelberger,
                Jorge-Andre Fulgencio Esteves
 Date        : 01.06.2018

 But         : Definitions des prototypes des methodes d'afichage de bateau,
                port et taxes ainsi que les definitions de la bibliotheque d'affichage

 Remarque(s) :

 Compilateur : MinGW-gcc 7.1.0
 -----------------------------------------------------------------------------------
*/

#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "bateau.h"

void affichageBateau(const Bateau* bateau);
void affichageTaxe();
void affichagePort(const Bateau port[], size_t nbBateau);
#endif /* AFFICHAGE_H */