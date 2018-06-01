/*
 -----------------------------------------------------------------------------------
 Laboratoire : No 6
 Fichier     : main.c
 Auteur(s)   : Rafael Da Cunha Garcia, Florian Shaufelberger,
                Jorge-Andre Fulgencio Esteves
 Date        : 01.06.2018

 But         : Tester la generation de bateau, l'affichage des caracteristique de
                ceux-ci, l'affichage de la somme et la moyennne des taxes annuelles
                dues par types de bateau

 Remarque(s) :

 Compilateur : MinGW-gcc 7.1.0
 -----------------------------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>
#include "bateau.h"
#include "affichage.h"
#include "taxe.h"

int main(void) {
    Bateau port[] = {initBateauVoilier("BlackPearl", 15),
                     initBateauPeche("Hollandais Volant", 25, 15),
                     initBateauPlaisance("Blue Mary", 13, "Barbe Violette")};

    printf("%*c\n", 20, '-');
    affichagePort(port, 3);


    return EXIT_SUCCESS;
}