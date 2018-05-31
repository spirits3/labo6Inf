#include <stdio.h>

#include "bateau.h"
#include "affichage.c"

void affichageBateau(const Bateau bateau) {

	printf("%s%s\n" ,"nom du bateau: ", bateau.nom );
	
	printf("%s", "type du bateau: ");
	if(bateau.typeA == VOILIER) {
		printf("%s\n", "voilier");
		printf("%s%s%s\n", "La surface de la voilure est de: ", bateau.Voilier.surfaceVoilure, "[m2]");
	}

	else if(bateau.typeA = BATEAUAMOTEUR){
		printf("%s\n", "moteur");
		printf("%s%s%s\n", "puissance: ", bateau.BateauAMoteur.puissance, "[CV]");
		printf("%s", "Utilisation du bateau: ");
        if(bateau.BateauAMoteur.typeB == PECHE) {
        	printf("%s", "peche");
        	printf("%s%s%s\n", "Le bateau peut pecher ", bateau.BateauPeche.tonnes, " tonnes maximum.");
        }
        else if(bateau.BateauAMoteur.typeB == PLAISANCE) {
        	printf("%s\n", "plaisance");
        	printf("%s%s\n", "nom du proprietaire: ", bateau.BateauAMoteur.BateauPlaisance.nomPropriétaire);
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

}

void affichageTaxe()
