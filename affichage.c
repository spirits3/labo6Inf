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
#include "taxe.h"


const int TAILLE_TABLEAU = ALIGNEMENT_MAXIMAL_GAUCHE + ALIGNEMENT_MAXIMAL_CENTRE
                           + ALIGNEMENT_MAXIMAL_DROITE + NOMBRE_CELLULE_BATEAU;
void affichageBateau(const Bateau* bateau) {

    AFFICHER_LIGNE_TABLEAU(TAILLE_TABLEAU);
  
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
            AFFICHER_LIGNE_3_ELEM(BATEAU_PEUT_PECHER,
                                  bateau->bateauMoteur.bateauPeche.tonnePoisson, TONNES);
        }
        else if(bateau->bateauMoteur.typeB == PLAISANCE) {
        	AFFICHER_TYPE_BATEAU(TYPE_PLAISANCE);
            AFFICHER_LIGNE_2_ELEM(NOM_PROPRIETAIRE,
                                  bateau->bateauMoteur.bateauPlaisance.nomProprietaire);
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


void affichageTaxeAnnuelle(double taxeAnnuelleType[]) {

    AFFICHER_LIGNE_TABLEAU(TAILLE_TABLEAU);
    AFFICHAGE_MENU("Type de bateau", "Taxe annuelle", "Monnaie");
    AFFICHER_LIGNE_TABLEAU(TAILLE_TABLEAU);
    AFFICHER_LIGNE_2_ELEM_MONNAIE("Voilier",taxeAnnuelleType[0]);
    AFFICHER_LIGNE_2_ELEM_MONNAIE("Peche",taxeAnnuelleType[1]);
    AFFICHER_LIGNE_2_ELEM_MONNAIE("Plaisance",taxeAnnuelleType[2]);
    AFFICHER_LIGNE_TABLEAU(TAILLE_TABLEAU);
    printf("\n");
}

void affichageTaxeMoyenne(double taxeMoyenneType[]) {
                                
    AFFICHER_LIGNE_TABLEAU(TAILLE_TABLEAU);
    AFFICHAGE_MENU("Type de bateau", "Taxe moyenne", "Monnaie");
    AFFICHER_LIGNE_TABLEAU(TAILLE_TABLEAU);
    AFFICHER_LIGNE_2_ELEM_MONNAIE("Voilier", taxeMoyenneType[0]);
    AFFICHER_LIGNE_2_ELEM_MONNAIE("Peche", taxeMoyenneType[1]);
    AFFICHER_LIGNE_2_ELEM_MONNAIE("Plaisance", taxeMoyenneType[2]);
    AFFICHER_LIGNE_TABLEAU(TAILLE_TABLEAU);
    printf("\n");
}

void affichagePort(const Bateau port[], size_t nbBateau) {
    for (size_t i = 0; i < nbBateau; ++i) {
        printf("%s %lu :\n", NUMERO_BATEAU, (long unsigned) (i + 1));
        affichageBateau(&port[i]);
    }
}
