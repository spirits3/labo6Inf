#ifndef BATEAU_H
#define BATEAU_H

enum typeBateau { VOILIER, MOTEUR };
enum typeBateauAMoteur {PECHE, PLAISANCE};

struct Bateau {
    const char* nom;
    typeBateau typeA;
    union {
        struct Voilier voilier;
        struct BateauAMoteur bateauMoteur;
    };
};

struct Voilier {
    uint16_t surfaceVoilure;
};

struct BateauAMoteur {
    uint16_t puissance;
    typeBateauAMoteur typeB;
    union {
        struct BateauPeche;
        struct BateauPlaisance;
    };
};

struct BateauPeche {
    uint16_t tonnePoisson;
};

struct BateauPlaisance {
    const char* nomProprietaire;
};
#endif