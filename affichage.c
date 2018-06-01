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

#define AFFICHER_LIGNE(TAILLE) for(int i = 0; i < (TAILLE); ++i) { printf("-"); } 

void affichageBateau(const Bateau* bateau) {

    const int TAILLE_TABLEAU = ALIGNEMENT_MAXIMAL_GAUCHE + ALIGNEMENT_MAXIMAL_CENTRE + ALIGNEMENT_MAXIMAL_DROITE + NOMBRE_CELLULE_PLUS_1;

    AFFICHER_LIGNE(TAILLE_TABLEAU); 

	printf("\n|%-*s|%-*s|%*s|\n", ALIGNEMENT_MAXIMAL_GAUCHE, NOM_DU_BATEAU, ALIGNEMENT_MAXIMAL_CENTRE, bateau->nom, ALIGNEMENT_MAXIMAL_DROITE, "");

    printf("|%-*s", ALIGNEMENT_MAXIMAL_GAUCHE, TYPE_DU_BATEAU);
	
	if(bateau->typeA == VOILIER) {
		printf("|%-*s|%-*s|\n", ALIGNEMENT_MAXIMAL_CENTRE, TYPE_VOILIER,ALIGNEMENT_MAXIMAL_DROITE, "");
		printf("|%-*s|%-*d|%-*s|\n", ALIGNEMENT_MAXIMAL_GAUCHE, SURFACE_VOILURE, ALIGNEMENT_MAXIMAL_CENTRE, bateau->voilier.surfaceVoilure, ALIGNEMENT_MAXIMAL_DROITE, M2);
	}

	else if(bateau->typeA == BATEAU_A_MOTEUR){
        printf("|%-*s|%-*s|\n", ALIGNEMENT_MAXIMAL_CENTRE, TYPE_MOTEUR, ALIGNEMENT_MAXIMAL_DROITE, "");
		printf("|%-*s|%-*d|%-*s|\n",ALIGNEMENT_MAXIMAL_GAUCHE, PUISSANCE_MOTEUR, ALIGNEMENT_MAXIMAL_CENTRE, bateau->bateauMoteur.puissance, ALIGNEMENT_MAXIMAL_DROITE, CV);
		printf("|%-*s", ALIGNEMENT_MAXIMAL_GAUCHE, UTILISATION_BATEAU);
        if(bateau->bateauMoteur.typeB == PECHE) {
        	printf("|%-*s|%-*s|\n", ALIGNEMENT_MAXIMAL_CENTRE, TYPE_PECHE, ALIGNEMENT_MAXIMAL_DROITE, "");
            printf("|%-*s|%-*d|%-*s|\n", ALIGNEMENT_MAXIMAL_GAUCHE, BATEAU_PEUT_PECHER, ALIGNEMENT_MAXIMAL_CENTRE, bateau->bateauMoteur.bateauPeche.tonnePoisson, ALIGNEMENT_MAXIMAL_DROITE, TONNES);
        }
        else if(bateau->bateauMoteur.typeB == PLAISANCE) {
        	printf("|%-*s|%-*s|\n",ALIGNEMENT_MAXIMAL_CENTRE, TYPE_PLAISANCE, ALIGNEMENT_MAXIMAL_DROITE, "");
            printf("|%-*s|%-*s|%-*s|\n", ALIGNEMENT_MAXIMAL_GAUCHE, NOM_PROPRIETAIRE, ALIGNEMENT_MAXIMAL_CENTRE, bateau->bateauMoteur.bateauPlaisance.nomProprietaire, ALIGNEMENT_MAXIMAL_DROITE, "");
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
    AFFICHER_LIGNE(TAILLE_TABLEAU);
    printf("\n");

}

void affichageTaxe(const Bateau port[], size_t nbBateau) {


}


void affichagePort(const Bateau port[], size_t nbBateau) {
    for (size_t i = 0; i < nbBateau; ++i) {
        affichageBateau(&port[i]);
    }
}