#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"
#include "commun.h"
#include "tableau.h"

int **alloue_matrice(int n, int m) {

    int **matrice = malloc(sizeof(int *) * n);

    if(!matrice) {
        print_probleme("Erreur d'allocation");
        return NULL;
    }

    for(int i = 0; i < n ; i++)
        matrice[ i ] = alloue_tableau(m);

    return matrice;
}

void desaloue_matrice(int **matrice, int n) {
    for(int i = 0; i < n; i++)
        desalloue_tableau(matrice[ i ]);
    
    free(matrice);
}

void remplir_matrice(int **matrice, int n, int m, int valeur) {
    for(int i = 0; i < n; i++)
        remplir_tableau(matrice[ i ], m, valeur);
}

void afficher_matrice(int **matrice, int n, int m) {
    for(int i = 0; i < n; i++)
        afficher_tableau(matrice[ i ], m);
}

void remplir_matrice_sup(int **matrice, int n, int m, int valeur) {
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {

            if(i > j)
                matrice[ i ][ j ] = 0;
            else
                matrice[ i ][ j ] = rand() % valeur;
        }
    }
}

void remplir_matrice_inf(int **matrice, int n, int m, int valeur) {
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {

            if(i < j)
                matrice[ i ][ j ] = 0;
            else
                matrice[ i ][ j ] = rand() % valeur;
        }
    }
}