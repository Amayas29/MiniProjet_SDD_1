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

MatriceTriangulaire *alloue_matrice_triangulaire(int taille,int orientation){
    
    MatriceTriangulaire *matrice = (MatriceTriangulaire *) malloc(sizeof(MatriceTriangulaire));
    if(!matrice){
        print_probleme("alloucation de matrice triangulaire echouer");
        return NULL;
    }

    if(orientation != 0 && orientation != 1)
        orientation = 1;
    matrice->orientation = orientation;
    matrice->taille = taille;

    matrice->matrice = (int **) malloc(sizeof(int *) * taille);
    
    if(!matrice){
        print_probleme("alloucation de la matrice triangulaire echouer");
        return NULL;
    }
    for(int i  = 0; i < taille; i++){
        matrice->matrice[i] = (int) malloc(sizeof(int) * (orientation * (taille-i)+ (1 - orientation) * ( i+1 )));
        if(!matrice->matrice[i]){
            
        }
    }
}