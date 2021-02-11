#ifndef __ALGO_H__
#define __ALGO_H__

int somme_1(int *tableau, int taille);
int somme_2(int *tableau, int taille);
int verfie_matrice_1(int **matrice, int n, int m);
int verfie_matrice_2(int **matrice, int n, int m, int *check, int maxValeur);
int **produit_mat_1(int **mat1, int **mat2, int m, int n, int p);
int **produit_triang(int **sup, int **inf, int m, int n, int p);

#endif