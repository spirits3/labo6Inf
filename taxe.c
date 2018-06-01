#include "taxe.h"

double taxeBase (const Bateau* bateau) {
    return bateau->typeA ? TAXE_BASE_VOILIER : TAXE_BASE_MOTEUR;
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

void taxeTotalPort(Bateau port[], double *taxeParType,uint8_t nombreDeBateau) {
	for(size_t i = 0; i < nombreDeBateau; ++i) {
	    if (port[i].typeA == VOILIER) 
		taxeParType[0] += taxeParBateau(&port[i]);
	    else if (port[i].bateauMoteur.typeB == PECHE) 
		taxeParType[1] += taxeParBateau(&port[i]);
	    else if (port[i].bateauMoteur.typeB == PLAISANCE) 
		taxeParType[2] += taxeParBateau(&port[i]);
	}
}
