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

#define ALIGNEMENT_MAXIMAL_GAUCHE 25
#define ALIGNEMENT_MAXIMAL_CENTRE 20
#define ALIGNEMENT_MAXIMAL_DROITE 6
#define NOMBRE_CELLULE_PLUS_1	  7
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
#define NUMERO_BATEAU       "Bateau No"


#define AFFICHER_LIGNE_TABLEAU(TAILLE) for(int i = 0; i < (TAILLE); ++i) { printf("-"); }

#define AFFICHER_LIGNE_2_ELEM(STRING1, STRING2) \
    printf("| %-*s| %-*s| %*s|\n", ALIGNEMENT_MAXIMAL_GAUCHE, (STRING1), \
            ALIGNEMENT_MAXIMAL_CENTRE, (STRING2), ALIGNEMENT_MAXIMAL_DROITE,"")

#define AFFICHER_LIGNE_3_ELEM(STRING1, VALEUR_INT, STRING2)  \
    printf("| %-*s| %-*d| %-*s|\n",ALIGNEMENT_MAXIMAL_GAUCHE, STRING1, \
            ALIGNEMENT_MAXIMAL_CENTRE, VALEUR_INT, ALIGNEMENT_MAXIMAL_DROITE, STRING2)

#define AFFICHER_TYPE_BATEAU(STRING) \
    printf("| %-*s| %-*s|\n", ALIGNEMENT_MAXIMAL_CENTRE, (STRING), \
            ALIGNEMENT_MAXIMAL_DROITE, "")

#define AFFICHER_DEBUT_PHRASE(STRING) \
    printf("| %-*s", ALIGNEMENT_MAXIMAL_GAUCHE, (STRING))



#define AFFICHER_LIGNE_TAXE \
    for (size_t i = 0; i < 62; ++i)printf("-");printf("\n") 
#define AFFICHAGE_MENU(a,b,c,d) \
    printf("%14s | %14s | %14s | %9s |\n", a, b, c, d)
#define AFFICHAGE_TAXE_TYPE(a,b,c) \
    printf("%14s | %14.2f | %14.2f | %9s |\n", a, b, c, MONNAIE); 


void affichageBateau(const Bateau* bateau);
void affichageTaxe();
void affichagePort(const Bateau port[], size_t nbBateau);
#endif /* AFFICHAGE_H */
