/*
 -----------------------------------------------------------------------------------
 Laboratoire : No 6
 Fichier     : bateau.h
 Auteur(s)   : Rafael Da Cunha Garcia, Florian Shaufelberger,
                Jorge-Andre Fulgencio Esteves
 Date        : 01.06.2018

 But         : Definir les structures contenant les caracteristique de chaque type 
				de bateau,


 Remarque(s) :

 Compilateur : MinGW-gcc 7.1.0
 -----------------------------------------------------------------------------------
*/

#ifndef BATEAU_H
#define BATEAU_H

#include <stdint.h>

typedef enum {VOILIER, BATEAU_A_MOTEUR} TypeBateau;
typedef enum {PECHE, PLAISANCE} TypeBateauAMoteur;

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
    TypeBateauAMoteur typeB;
    union {
        BateauPeche bateauPeche;
        BateauPlaisance bateauPlaisance;
    };
} BateauAMoteur;

typedef struct {
    const char* nom;
    TypeBateau typeA;
    union {
        Voilier voilier;
        BateauAMoteur bateauMoteur;
    };
} Bateau;


Bateau initBateauVoilier(const char* nom, uint16_t surfaceVoilure);
Bateau initBateauPeche(const char* nom, uint16_t puissance, uint16_t tonnePoisson);
Bateau initBateauPlaisance(const char* nom, uint16_t puissance,
							const char* nomProprietaire);

#endif /* BATEAU_H */