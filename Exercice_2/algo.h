#ifndef __ALGO_H__
#define __ALGO_H__
#include "matrice.h"

int somme_1(int *tableau, int taille);
int somme_2(int *tableau, int taille);
int verfie_matrice_1(int **matrice, int n);
int verfie_matrice_2(int **matrice, int n, int *check, int maxValeur);
int **produit_mat_1(int **mat1, int **mat2, int m);
int **produit_triang(MatriceTriangulaire *sup, MatriceTriangulaire *inf);

#endif