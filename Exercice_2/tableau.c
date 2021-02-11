#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tableau.h"
#include "matrice.h"
#include "commun.h"

int *alloue_tableau(int taille) {

    int *tableau = malloc(sizeof(int) * taille);

    if(tableau == NULL)
        print_probleme("Erreur d'allocation");

    return tableau;
}

void desalloue_tableau(int *tableau) {
    free(tableau);
}

void remplir_tableau(int *tableau, int taille, int valeur) {
    if(!tableau) return;

    for(int i = 0; i < taille; i++)
        tableau[ i ] = rand() % valeur; 
}

void afficher_tableau(int *tableau, int taille) {
    if(!tableau) return;

    for(int i = 0; i < taille; i++)
        printf("%d ", tableau[ i ]);
    
    printf("\n");
}
