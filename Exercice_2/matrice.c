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
        print_probleme("allocation de matrice triangulaire echouer");
        return NULL;
    }

    if(orientation != 0 && orientation != 1)
        orientation = 1;

    matrice->orientation = orientation;
    matrice->taille = taille;

    matrice->matrice = (int **) malloc(sizeof(int *) * taille);
    
    if(!matrice){
        print_probleme("allocation de la matrice triangulaire echouer");
        return NULL;
    }
    for(int i  = 0; i < taille; i++){
        matrice->matrice[i] = alloue_tableau((orientation * (taille-i)+ (1 - orientation) * ( i+1 )));
        if(!matrice->matrice[i]){

            print_probleme("allocation du tableau echouer");

            for(int j = 0;j<i;i++)
                free(matrice->matrice[j]);
            
            return NULL;
        }
    }
    return matrice;
}

void remplir_matrice_triangulaire(MatriceTriangulaire *matrice, int valeur){
    if(!matrice){
        print_probleme("matrice non allouer");
        return ;
    }
    int fin = 0;

    for(int i = 0; i<matrice->taille ;i++) 
        remplir_tableau(matrice->matrice[i], matrice->orientation * (matrice->taille-i)+ (1 - matrice->orientation) * ( i+1 ), valeur);
    
       
}

void desalloue_matrice_triangulaire(MatriceTriangulaire *matrice) {
    
    if(!matrice){
        print_probleme("matric non allouer");
        return;
    }

    for(int i = 0; i<matrice->taille; i++)
        desalloue_tableau(matrice->matrice[i]);
    
    free(matrice->matrice);
    free(matrice);
}

void afficher_matrice_triangulaire(MatriceTriangulaire *matrice){

    if(!matrice){
        print_probleme("matric non allouer");
        return;
    }

    for (int i = 0; i < matrice->taille; i++) {   
        for (int j = 0; matrice->orientation && j < i; j++)
            printf("0 ");
        

        for (int j = 0; j <  matrice->orientation * (matrice->taille-i)+ (1 - matrice->orientation) * ( i+1 ); j++) {
            printf("%d ",matrice->matrice[i][j]);
        }

        
        for (int j = 0; !matrice->orientation && j < i; j++)
            printf("0 ");
        
        printf("\n");
    }
    
}

