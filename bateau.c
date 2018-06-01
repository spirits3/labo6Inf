#include "bateau.h"


Bateau initBateauVoilier(const char* nom, uint16_t surfaceVoilure) {
    return (Bateau) {.nom = nom, .typeA = VOILIER, .voilier = (Voilier) {surfaceVoilure}};
}

Bateau initBateauPeche(const char* nom, uint16_t puissance, uint16_t tonnePoisson) {
    return (Bateau) {.nom = nom, .typeA = BATEAU_A_MOTEUR,
                     .bateauMoteur = (BateauAMoteur) {.puissance = puissance, .typeB = PECHE,
                                      .bateauPeche = (BateauPeche) {tonnePoisson}}};
}

Bateau initBateauPlaisance(const char* nom, uint16_t puissance, const char* nomProprietaire) {
    return (Bateau) {.nom = nom, .typeA = BATEAU_A_MOTEUR,
                     .bateauMoteur = (BateauAMoteur) {.puissance = puissance, .typeB = PLAISANCE,
                                      .bateauPlaisance = (BateauPlaisance) {nomProprietaire}}};
}
