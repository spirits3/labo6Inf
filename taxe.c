/*
 -----------------------------------------------------------------------------------
 Laboratoire : No 6
 Fichier     : taxe.c
 Auteur(s)   : Rafael Da Cunha Garcia, Florian Shaufelberger,
                Jorge-Andre Fulgencio Esteves
 Date        : 01.06.2018

 But         : Definir les methodes de calcul de taxes de base, taxes annuelles
 				et taxes moyennes

 Remarque(s) :

 Compilateur : MinGW-gcc 7.1.0
 -----------------------------------------------------------------------------------
*/

#include "taxe.h"

double taxeBase (const Bateau* bateau) {
    return bateau->typeA ? TAXE_BASE_MOTEUR : TAXE_BASE_VOILIER;
}

double taxeSpecifique(const Bateau* bateau) {
	
	if (bateau->typeA == VOILIER) {
		return bateau->voilier.surfaceVoilure < SURFACE_VOILE_MAX_AVANT_TAXE ? TAXE_SPECIFIQUE_PETITE_VOILE : TAXE_SPECIFIQUE_GRANDE_VOILE;
	}

	if (bateau->bateauMoteur.typeB == PECHE) {
		return bateau->bateauMoteur.bateauPeche.tonnePoisson < TONNAGE_MAX_AVANT_TAXE ? TAXE_SPECIFIQUE_PETIT_TONNAGE : TAXE_SPECIFIQUE_GRAND_TONNAGE;
	}

	if (bateau->bateauMoteur.typeB == PLAISANCE) {
		return bateau->bateauMoteur.puissance < PUISSANCE_MAX_AVANT_TAXE ? TAXE_SPECIFIQUE_PETIT_MOTEUR : TAXE_SPECIFIQUE_GRAND_MOTEUR;
	}
	return 0;
}

double taxeParBateau(const Bateau* bateau) {
    return taxeBase(bateau) + taxeSpecifique(bateau);
}

void taxeTotalPort(Bateau port[], double taxeParType[],const uint8_t NB_BATEAU) {
	for(size_t i = 0; i < NB_BATEAU; ++i) {
            if (port[i].typeA == VOILIER) 
                taxeParType[0] += taxeParBateau(&port[i]);
            else if (port[i].bateauMoteur.typeB == PECHE) 
                taxeParType[1] += taxeParBateau(&port[i]);
            else if (port[i].bateauMoteur.typeB == PLAISANCE) 
                taxeParType[2] += taxeParBateau(&port[i]);
	}
}

void taxeMoyennePort(Bateau port[], double taxeMoyenneType[], const uint8_t NB_BATEAU) {
    
    uint8_t *nombre_bateau_type = (uint8_t*)calloc(NB_BATEAU, sizeof(uint8_t));

    for(size_t i = 0; i < NB_BATEAU; ++i) {
        if (port[i].typeA == VOILIER) 
            nombre_bateau_type[0]++;
        else if (port[i].bateauMoteur.typeB == PECHE) 
            nombre_bateau_type[1]++;
        else if (port[i].bateauMoteur.typeB == PLAISANCE) 
            nombre_bateau_type[2]++;
    }
    
    taxeTotalPort(port, taxeMoyenneType, NB_BATEAU);
    
    for(size_t i = 0; i < NB_BATEAU; ++i) 
        taxeMoyenneType[i] /= nombre_bateau_type[i];   


}
