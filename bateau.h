#ifndef BATEAU_H
#define BATEAU_H

#include <stdint.h>

typedef enum {VOILIER, BATEAU_A_MOTEUR} typeBateau;
typedef enum {PECHE, PLAISANCE} typeBateauAMoteur;

typedef struct {
    uint16_t tonnePoisson;
} BateauPeche;

typedef struct {
    const char* nomProprietaire;
} BateauPlaisance;

typedef struct {
    uint16_t surfaceVoilure;
} Voilier;

typedef struct {
    uint16_t puissance;
    typeBateauAMoteur typeB;
    union {
        BateauPeche bateauPeche;
        BateauPlaisance bateauPlaisance;
    };
} BateauAMoteur;

typedef struct {
    const char* nom;
    typeBateau typeA;
    union {
        Voilier voilier;
        BateauAMoteur bateauMoteur;
    };
} Bateau;


Bateau initBateauVoilier(const char* nom, uint16_t surfaceVoilure);
Bateau initBateauPeche(const char* nom, uint16_t puissance, uint16_t tonnePoisson);
Bateau initBateauPlaisance(const char* nom, uint16_t puissance, const char* nomProprietaire);

#endif