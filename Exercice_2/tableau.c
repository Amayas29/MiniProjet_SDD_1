#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tableau.h"
#include "matrice.h"
#include "commun.h"

// permet d'allouer un tableau d'une taille donnee
int *alloue_tableau(int taille) {

    int *tableau = malloc(sizeof(int) * taille);

    if(tableau == NULL)
        print_probleme("Erreur d'allocation");

    return tableau;
}

// permet de liberer un tableau
void desalloue_tableau(int *tableau) {
    free(tableau);
}

//permet de remplire un tableau random
void remplir_tableau(int *tableau, int taille, int valeur) {
    if(!tableau) return;

    for(int i = 0; i < taille; i++)
        tableau[ i ] = rand() % valeur; 
}

// permet d'afficher un tableau
void afficher_tableau(int *tableau, int taille) {
    if(!tableau) return;

    for(int i = 0; i < taille; i++)
        printf("%d ", tableau[ i ]);
    
    printf("\n");
}
