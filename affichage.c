/*
 -----------------------------------------------------------------------------------
 Laboratoire : No 6
 Fichier     : affichage.c
 Auteur(s)   : Rafael Da Cunha Garcia, Florian Shaufelberger,
                Jorge-Andre Fulgencio Esteves
 Date        : 01.06.2018

 But         : Contient les definitions des methodes d'affichage de taxes,
                bateau et port

 Remarque(s) :

 Compilateur : MinGW-gcc 7.1.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include "affichage.h"

#define AFFICHER_LIGNE_TABLEAU(TAILLE) for(int i = 0; i < (TAILLE); ++i) { printf("-"); } 
#define AFFICHER_LIGNE_2_ELEM(STRING1, STRING2)             printf("|%-*s|%-*s|%*s|\n", ALIGNEMENT_MAXIMAL_GAUCHE, (STRING1), ALIGNEMENT_MAXIMAL_CENTRE, (STRING2), ALIGNEMENT_MAXIMAL_DROITE,"")
#define AFFICHER_LIGNE_3_ELEM(STRING1, VALEUR_INT, STRING2) printf("|%-*s|%-*d|%-*s|\n",ALIGNEMENT_MAXIMAL_GAUCHE, STRING1, ALIGNEMENT_MAXIMAL_CENTRE, VALEUR_INT, ALIGNEMENT_MAXIMAL_DROITE, STRING2)
#define AFFICHER_TYPE_BATEAU(STRING)                        printf("|%-*s|%-*s|\n", ALIGNEMENT_MAXIMAL_CENTRE, (STRING),ALIGNEMENT_MAXIMAL_DROITE, "")
#define AFFICHER_DEBUT_PHRASE(STRING)                       printf("|%-*s", ALIGNEMENT_MAXIMAL_GAUCHE, (STRING))


void affichageBateau(const Bateau* bateau) {

    const int TAILLE_TABLEAU = ALIGNEMENT_MAXIMAL_GAUCHE + ALIGNEMENT_MAXIMAL_CENTRE + ALIGNEMENT_MAXIMAL_DROITE + NOMBRE_CELLULE_PLUS_1;

    AFFICHER_LIGNE_TABLEAU(TAILLE_TABLEAU); 

    printf("\n");
  
    AFFICHER_LIGNE_2_ELEM(NOM_DU_BATEAU, bateau->nom);
    AFFICHER_DEBUT_PHRASE(TYPE_DU_BATEAU);
	
	if(bateau->typeA == VOILIER) {
		AFFICHER_TYPE_BATEAU(TYPE_VOILIER);
		AFFICHER_LIGNE_3_ELEM(SURFACE_VOILURE,bateau->voilier.surfaceVoilure, M2);
	}

	else if(bateau->typeA == BATEAU_A_MOTEUR){
        AFFICHER_TYPE_BATEAU(TYPE_MOTEUR);
        AFFICHER_LIGNE_3_ELEM(PUISSANCE_MOTEUR, bateau->bateauMoteur.puissance, CV);
		AFFICHER_DEBUT_PHRASE(UTILISATION_BATEAU);
        if(bateau->bateauMoteur.typeB == PECHE) {
        	AFFICHER_TYPE_BATEAU(TYPE_PECHE);
            AFFICHER_LIGNE_3_ELEM(BATEAU_PEUT_PECHER, bateau->bateauMoteur.bateauPeche.tonnePoisson, TONNES);
        }
        else if(bateau->bateauMoteur.typeB == PLAISANCE) {
        	AFFICHER_TYPE_BATEAU(TYPE_PLAISANCE);
            AFFICHER_LIGNE_2_ELEM(NOM_PROPRIETAIRE, bateau->bateauMoteur.bateauPlaisance.nomProprietaire);
        }
        else {
        	printf("pas de type de bateau a moteur");
        	return;
        }
    }
    else {
	   	printf("pas de type");
    	return;
    }
    AFFICHER_LIGNE_TABLEAU(TAILLE_TABLEAU);
    printf("\n");

}

void affichageTaxe(const Bateau port[], size_t nbBateau) {


}


void affichagePort(const Bateau port[], size_t nbBateau) {
    for (size_t i = 0; i < nbBateau; ++i) {
        affichageBateau(&port[i]);
    }
}