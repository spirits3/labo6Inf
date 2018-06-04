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
#include "taxe.h"
#include "affichage.h"

int main(void) {

	Bateau port[] = {initBateauVoilier("BlackPearl", 199),
    				 initBateauVoilier("Royal James", 200),
                     initBateauVoilier("Flying dragon", 50),
                     initBateauPeche("Hollandais Volant", 99, 19),
                     initBateauPeche("Fancy", 99, 20),
                     initBateauPeche("The Ranger", 100, 20),
                     initBateauPlaisance("Blue Mary", 99, "Wang Zhi"),
                 	 initBateauPlaisance("Titanic", 100, "Anne Dieu-le-veut"),
                 	 initBateauPlaisance("L'albatros", 300, "Barbe Rousse")};    


    const uint8_t NB_BATEAU = sizeof(port) / sizeof(Bateau);

    affichagePort(port, NB_BATEAU);        
    affichageTaxeAnnuelle(port, NB_BATEAU);
    affichageTaxeMoyenne(port, NB_BATEAU);

    return EXIT_SUCCESS;
}