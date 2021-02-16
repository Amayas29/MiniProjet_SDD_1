#ifndef __MATRICE_H__
#define __MATRICE_H__

typedef struct _matrice_triangulaire {
    int **matrice;
    int taille;
    // 1 pour superieure et 0 pour inferieure
    int orientation;
} MatriceTriangulaire;

int **alloue_matrice(int n);
void desalloue_matrice(int **matrice, int n);
void remplir_matrice(int **matrice, int n, int valeur);
void afficher_matrice(int **matrice, int n);

MatriceTriangulaire *alloue_matrice_triangulaire(int taille, int orientation);
void remplir_matrice_triangulaire(MatriceTriangulaire *matrice, int valeur);
void afficher_matrice_triangulaire(MatriceTriangulaire *matrce);
void desalloue_matrice_triangulaire(MatriceTriangulaire *matrice);

#endif