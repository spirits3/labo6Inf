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
/*
 -----------------------------------------------------------------------------------
 Laboratoire : No 6
 Fichier     : affichage.c
 Auteur(s)   : Rafael Da Cunha Garcia, Florian Shaufelberger,
                Jorge-Andre Fulgencio Esteves
 Date        : 01.06.2018

 But         : Definir les constantes pour l'affichage ainsi que les phrases 
 			   utilisées pour l'affichage.

 Remarque(s) :

 Compilateur : MinGW-gcc 7.1.0
 -----------------------------------------------------------------------------------
*/
#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "bateau.h"
#include <stdio.h>

#define ALIGNEMENT_MAXIMAL_GAUCHE 35
#define ALIGNEMENT_MAXIMAL_CENTRE 20
#define ALIGNEMENT_MAXIMAL_DROITE 6
#define NOMBRE_CELLULE_PLUS_1	  4
#define NOM_DU_BATEAU 		"Nom du bateau: "
#define TYPE_DU_BATEAU 		"Type du bateau: "
#define TYPE_VOILIER 		"voilier"
#define SURFACE_VOILURE 	"Surface voilure: "
#define M2					"[m2]"
#define TYPE_MOTEUR			"moteur"
#define PUISSANCE_MOTEUR	"Puissance du moteur: "
#define CV					"[CV]"
#define UTILISATION_BATEAU	"Utilisation du bateau: "
#define TYPE_PECHE			"peche"
#define BATEAU_PEUT_PECHER	"Le bateau peut pecher"
#define TONNES				"tonnes"
#define TYPE_PLAISANCE		"plaisance"
#define NOM_PROPRIETAIRE	"Nom du proprietaire: "

void affichageBateau(const Bateau* bateau);
void affichageTaxe();
void affichagePort(const Bateau port[], size_t nbBateau);
#endif /* AFFICHAGE_H */