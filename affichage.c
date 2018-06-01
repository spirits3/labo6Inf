#include <stdio.h>
#include "affichage.h"

void affichageBateau(const Bateau* bateau) {

	printf("Nom du bateau: %s\n", bateau->nom );
	
	printf("Type du bateau: ");
	if(bateau->typeA == VOILIER) {
		printf("%s\n", "voilier");
		printf("La surface de la voilure est de: %d[m2]\n", bateau->voilier.surfaceVoilure);
	}

	else if(bateau->typeA == BATEAU_A_MOTEUR){
		printf("moteur\npuissance: %d[CV]\n", bateau->bateauMoteur.puissance);
		printf("Utilisation du bateau: ");
        if(bateau->bateauMoteur.typeB == PECHE) {
        	printf("peche\nLe bateau peut pecher %d tonnes maximum.\n", bateau->bateauMoteur.bateauPeche.tonnePoisson);
        }
        else if(bateau->bateauMoteur.typeB == PLAISANCE) {
        	printf("plaisance\nnom du proprietaire: %s\n", bateau->bateauMoteur.bateauPlaisance.nomProprietaire);
        }
        else {
        	printf("pas de type de bateau a moteur\n");
        	return;
        }
    }
    else {
	   	printf("pas de type");
    	return;
    }
    printf("\n");

}

void affichageTaxe();


void affichagePort(const Bateau port[], size_t nbBateau) {
    for (size_t i = 0; i < nbBateau; ++i) {
        affichageBateau(&port[i]);
    }
}