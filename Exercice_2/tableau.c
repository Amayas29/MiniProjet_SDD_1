#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tableau.h"
#include "matrice.h"
#include "commun.h"

// Permet d'allouer un tableau d'une taille donnee
int *alloue_tableau(int taille) {

    int *tableau = malloc(sizeof(int) * taille);

    if(tableau == NULL)
        print_probleme("Erreur d'allocation");

    return tableau;
}

// Permet de liberer un tableau
void desalloue_tableau(int *tableau) {
    free(tableau);
}

// Permet de remplire un tableau random
void remplir_tableau(int *tableau, int taille, int valeur) {
    if(!tableau) return;

    for(int i = 0; i < taille; i++)
        tableau[ i ] = rand() % valeur; 
}

// Permet d'afficher un tableau
void afficher_tableau(int *tableau, int taille) {
    if(!tableau) return;

    for(int i = 0; i < taille; i++)
        printf("%-5d ", tableau[ i ]);
    
    printf("\n");
}
