#include <stdio.h>
#include "bateau.h"

void affichageBateau(const Bateau bateau) {

	printf("%s%s\n" ,"nom du bateau: ", bateau.nom );
	
	printf("%s", "type du bateau: ");
	if(bateau.typeA == VOILIER) {
		printf("%s\n", "voilier");
		printf("%s%d%s\n", "La surface de la voilure est de: ", bateau.voilier.surfaceVoilure, "[m2]");
	}

	else if(bateau.typeA == MOTEUR){
		printf("%s\n", "moteur");
		printf("%s%d%s\n", "puissance: ", bateau.bateauMoteur.puissance, "[CV]");
		printf("%s", "Utilisation du bateau: ");
        if(bateau.bateauMoteur.typeB == PECHE) {
        	printf("%s\n", "peche");
        	printf("%s%d%s\n", "Le bateau peut pecher ", bateau.bateauMoteur.bateauPeche.tonnePoisson, " tonnes maximum.");
        }
        else if(bateau.bateauMoteur.typeB == PLAISANCE) {
        	printf("%s\n", "plaisance");
        	printf("%s%s\n", "nom du proprietaire: ", bateau.bateauMoteur.bateauPlaisance.nomProprietaire);
        }
        else {
        	printf("%s\n", "pas de type de bateau a moteur");
        	return;
        }
    }
    else {
	   	printf("%s", "pas de type");
    	return;
    }
    printf("\n");

}