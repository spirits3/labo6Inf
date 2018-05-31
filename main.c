#include <stdlib.h>
#include <stdio.h>
#include "bateau.h"

int main(void) {
    Bateau port[] = {initBateauVoilier("BlackPearl", 15),
                     initBateauPeche("Hollandais Volant", 25, 15),
                     initBateauPlaisance("Blue Mary", 13, "Barbe Violette")};

    printf("%s %d\n",port[0].nom, port[0].voilier.surfaceVoilure);
    printf("%s %d %d\n", port[1].nom, port[1].bateauMoteur.puissance, port[1].bateauMoteur.bateauPeche.tonnePoisson);
    printf("%s %d %s\n", port[2].nom, port[2].bateauMoteur.puissance, port[2].bateauMoteur.bateauPlaisance.nomProprietaire);
    return EXIT_SUCCESS;
}