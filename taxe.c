#include "taxe.h"

double taxeBase (const Bateau* bateau) {
	bateau.type ? return TAXE_BASE_VOILIER : return TAXE_BASE_MOTEUR;
}

double taxeSpecifique(const Bateau* bateau) {
	
	if (bateau.type == VOILIER) {
		bateau.plaisance.surface < SURFACE_VOILE_MAX_AVANT_TAXE ? return TAXE_SPECIFIQUE_PETITE_VOILE: return TAXE_SPECIFIQUE_GRANDE_VOILE;
	}

	if (bateau.moteur.type == PECHE) {
		bateau.moteur.tonnes < TONNAGE_MAX_AVANT_TAXE ? return TAXE_SPECIFIQUE_PETIT_TONNAGE: return TAXE_SPECIFIQUE_GRAND_TONNAGE;
	}

	if (bateau.moteur.type == PLAISANCE) {
		bateau.moteur.puissance < PUISSANCE_MAX_AVANT_TAXE ? return TAXE_SPECIFIQUE_PETIT_MOTEUR: return TAXE_SPECIFIQUE_GRAND_MOTEUR;
	}
	return 0;
}

double taxeParBateau(const Bateau* bateau) {
	return taxeBase(bateau) + taxeSpecifique(bateau);
}

void taxeTotalPort(const Bateau *port, double *taxeParType,const uint8_t nombreDeBateau) {
	for(size_t i = 0; i < nombreDeBateau; ++i) {
		if (port[i].type == VOILIER) {
			taxeParType[0] += taxeBase(port[i]);
			taxeParType[0] += taxeSpecifique(port[i]);
		} else if (port[i].moteur.type == PECHE) {
			taxeParType[1] += taxeBase(port[i]);
			taxeParType[1] += taxeSpecifique(port[i]);
		} else if (port[i].moteur.type == PLAISANCE) {
			taxeParType[2] += taxeBase(port[i]);
			taxeParType[2] += taxeSpecifique(port[i]);
		}
	}
}
