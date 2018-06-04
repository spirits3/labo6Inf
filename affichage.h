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

#include <stdio.h>
#include <inttypes.h>

#include "bateau.h"

//Tous les espaces pour faire que notre tableau soit coherent
#define ALIGNEMENT_MAXIMAL_GAUCHE 	25
#define ALIGNEMENT_MAXIMAL_CENTRE 	20
#define ALIGNEMENT_MAXIMAL_DROITE 	6
#define ALIGNEMENT_TAXE_MOYENNE		12
#define NOMBRE_CELLULE_BATEAU	  	7

//Toutes les phrases que l'on va utiliser pour le tableau
#define NOM_DU_BATEAU 		"Nom du bateau "
#define TYPE_DU_BATEAU 		"Type du bateau "
#define TYPE_VOILIER 		"Voilier"
#define SURFACE_VOILURE 	"Surface voilure: "
#define M2					"[m2]"
#define TYPE_MOTEUR			"Moteur"
#define PUISSANCE_MOTEUR	"Puissance du moteur "
#define CV					"[CV]"
#define UTILISATION_BATEAU	"Utilisation du bateau "
#define TYPE_PECHE			"Peche"
#define BATEAU_PEUT_PECHER	"Le bateau peut pecher"
#define TONNES				"tonnes"
#define TYPE_PLAISANCE		"Plaisance"
#define NOM_PROPRIETAIRE	"Nom du proprietaire "
#define NUMERO_BATEAU       "Bateau No"
#define MENU_TAXE_MOYENNE   "Taxe moyenne"
#define MENU_TAXE_ANNUELLE  "Taxe annuelle"
#define MENU_MONNAIE        "Monnaie"

//Permet d'afficher la bordure du haut et bas du tableau
#define AFFICHER_LIGNE_TABLEAU(TAILLE) for(int i = 0; i < (TAILLE); ++i) { printf("-"); } printf("\n");

//Permet d'afficher string/string au format du tableau bateau
#define AFFICHER_LIGNE_2_ELEM(STRING1, STRING2) \
    printf("| %-*s| %-*s| %*s|\n", ALIGNEMENT_MAXIMAL_GAUCHE, (STRING1), \
            ALIGNEMENT_MAXIMAL_CENTRE, (STRING2), ALIGNEMENT_MAXIMAL_DROITE,"")

//Permet d'afficher string/int/string au format du tableau bateau
#define AFFICHER_LIGNE_3_ELEM(STRING1, VALEUR_INT, STRING2)  \
    printf("| %-*s| %-*"PRIu16"| %-*s|\n",ALIGNEMENT_MAXIMAL_GAUCHE, STRING1, \
            ALIGNEMENT_MAXIMAL_CENTRE, VALEUR_INT, ALIGNEMENT_MAXIMAL_DROITE, STRING2)

//Permet d'afficher string/double/double/monnaie au format du tableau taxe
#define AFFICHER_LIGNE_2_ELEM_MONNAIE(STRING1, DOUBLE1) \
    printf("| %-*s| %-*.2f| %-*s|\n",ALIGNEMENT_MAXIMAL_GAUCHE, STRING1, \
            ALIGNEMENT_MAXIMAL_CENTRE, DOUBLE1, ALIGNEMENT_MAXIMAL_DROITE, MONNAIE)

//Permet d'afficher le debut du type des bateau au format du tableau bateau
#define AFFICHER_TYPE_BATEAU(STRING) \
    printf("| %-*s| %-*s|\n", ALIGNEMENT_MAXIMAL_CENTRE, (STRING), \
            ALIGNEMENT_MAXIMAL_DROITE, "")

//Permet d'afficher un debut de phrase au format du tableau bateau
#define AFFICHER_DEBUT_PHRASE(STRING) \
    printf("| %-*s", ALIGNEMENT_MAXIMAL_GAUCHE, (STRING))

//Permet d'afficher le menu au format du tableau taxe
#define AFFICHAGE_MENU(a,b,c) \
    printf("| %-*s| %-*s|%-*s|\n", ALIGNEMENT_MAXIMAL_GAUCHE, a,\
    		ALIGNEMENT_MAXIMAL_CENTRE, b, ALIGNEMENT_MAXIMAL_DROITE, c)

void affichageBateau(const Bateau* bateau);
void affichageTaxeAnnuelle( Bateau port[], const uint8_t NB_BATEAU);
void affichageTaxeMoyenne( Bateau port[], const uint8_t NB_BATEAU);
void affichagePort(const Bateau port[], size_t nbBateau);
void afficheEnTeteTableauTaxe();
#endif /* AFFICHAGE_H */
