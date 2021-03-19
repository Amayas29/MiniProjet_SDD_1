#include "matrice.h"

#include <stdio.h>
#include <stdlib.h>

#include "commun.h"
#include "tableau.h"

// Permet d'allouer une matrice carre n*n
int **alloue_matrice(int n) {
    int **matrice = malloc(sizeof(int *) * n);

    if (!matrice) {
        print_probleme("Erreur d'allocation");
        return NULL;
    }

    // On alloue tous les tableaux
    for (int i = 0; i < n; i++)
        matrice[i] = alloue_tableau(n);

    return matrice;
}

// Permet de desalouer l'espace alloue a une matrice carre de taille n
void desalloue_matrice(int **matrice, int n) {
    // On desaloue tous les tableaux
    for (int i = 0; i < n; i++)
        desalloue_tableau(matrice[i]);

    free(matrice);
}

// Permet de remplir une matrice carre de taille n avec des valeurs entre 0 et valeur
void remplir_matrice(int **matrice, int n, int valeur) {
    // On remplie tous les tableaux
    for (int i = 0; i < n; i++)
        remplir_tableau(matrice[i], n, valeur);
}

// Permet d'afficher une matrice carre de taille n
void afficher_matrice(int **matrice, int n) {
    // Affiche tous les tableaux
    for (int i = 0; i < n; i++)
        afficher_tableau(matrice[i], n);
}

// Permet d'allouer une matrice triangulaire
MatriceTriangulaire *alloue_matrice_triangulaire(int taille, int orientation) {
    // On alloue la structure
    MatriceTriangulaire *matrice = (MatriceTriangulaire *)malloc(sizeof(MatriceTriangulaire));

    if (!matrice) {
        print_probleme("Erreur d'allocation");
        return NULL;
    }

    // Si c'est pas 0 ou 1 on mets par défaut à 1
    if (orientation != 0 && orientation != 1)
        orientation = 1;

    matrice->orientation = orientation;
    matrice->taille = taille;

    // On alloue le tableau de pointeurs
    matrice->matrice = (int **)malloc(sizeof(int *) * taille);

    if (!matrice) {
        print_probleme("Erreur d'allocation");
        free(matrice);
        return NULL;
    }

    // On parcours les lignes
    for (int i = 0; i < taille; i++) {
        /*
        * On alloue pour la ligne i le nombre de cases correspondantes
        * Avec la formule : (orientation * (taille-i) + (1 - orientation) * ( i+1 ))
        */
        matrice->matrice[i] = alloue_tableau((orientation * (taille - i) + (1 - orientation) * (i + 1)));

        if (!matrice->matrice[i]) {
            print_probleme("Erreur d'allocation");

            // On libere tous ce qu'on a déja allouer
            for (int j = 0; j < i; i++)
                free(matrice->matrice[j]);

            free(matrice->matrice);
            free(matrice);
            return NULL;
        }
    }

    return matrice;
}

// Permet de remplir une matrice traingulaire avec des valeurs entre 0 et valeur
void remplir_matrice_triangulaire(MatriceTriangulaire *matrice, int valeur) {
    if (!matrice) {
        print_probleme("Pointeur invalide");
        return;
    }

    // On parcours les lignes
    for (int i = 0; i < matrice->taille; i++)
        // On remplir les tableau de chaque ligne (la taille du tableau est donnée avec la meme formule lors de l'allocation)
        remplir_tableau(matrice->matrice[i], matrice->orientation * (matrice->taille - i) + (1 - matrice->orientation) * (i + 1), valeur);
}

// Permet de liberer l'espace allouer pour une matrice triangulaire
void desalloue_matrice_triangulaire(MatriceTriangulaire *matrice) {
    if (!matrice) {
        print_probleme("Pointeur invalide");
        return;
    }

    // On libere les tableaux dans chaque ligne
    for (int i = 0; i < matrice->taille; i++)
        desalloue_tableau(matrice->matrice[i]);

    free(matrice->matrice);
    free(matrice);
}

// Permet d'afficher une matrice triangulaire
void afficher_matrice_triangulaire(MatriceTriangulaire *matrice) {
    if (!matrice) {
        print_probleme("Pointeur invalide");
        return;
    }

    // On parcours les lignes
    for (int i = 0; i < matrice->taille; i++) {
        // Si superieure on affiche les i premieres 0
        for (int j = 0; matrice->orientation && j < i; j++)
            printf("%-5d ", 0);

        // On affiche les elements de la ligne
        for (int j = 0; j < matrice->orientation * (matrice->taille - i) + (1 - matrice->orientation) * (i + 1); j++)
            printf("%-5d ", matrice->matrice[i][j]);

        // Si inferieure on affiche les i derniers 0
        for (int j = 0; !matrice->orientation && j < matrice->taille - i - 1; j++)
            printf("%-5d ", 0);

        printf("\n");
    }
}