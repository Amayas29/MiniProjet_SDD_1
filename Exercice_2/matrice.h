#ifndef __MATRICE_H__
#define __MATRICE_H__

int **alloue_matrice(int n, int m);
void desaloue_matrice(int **matrice, int n);
void remplir_matrice(int **matrice, int n, int m, int valeur);
void afficher_matrice(int **matrice, int n, int m);
void remplir_matrice_sup(int **matrice, int n, int m, int valeur);
void remplir_matrice_inf(int **matrice, int n, int m, int valeur);

#endif