#include <stdlib.h>
#include <stdio.h>
#include "bateau.h"
#include "affichage.h"
#include "taxe.h"

int main(void) {
    Bateau port[] = {initBateauVoilier("BlackPearl", 15),
                     initBateauPeche("Hollandais Volant", 25, 15),
                     initBateauPlaisance("Blue Mary", 13, "Barbe Violette")};

    affichagePort(port, 3);


    return EXIT_SUCCESS;
}