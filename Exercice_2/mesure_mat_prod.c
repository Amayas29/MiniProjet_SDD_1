#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "algo.h"
#include "matrice.h"
#include "tableau.h"
#include "commun.h"

int main() {

    int maxValeur = 100;
    int n = 50;

    char *file_name = "sortie_vitesse_mat_prod.txt";
    FILE *file = fopen(file_name, "w");

    int **mat1;
    int **mat2;

    MatriceTriangulaire *matTriangulaireSup;
    MatriceTriangulaire *matTriangulaireInf;
   
    clock_t temps_initial;
    clock_t temps_final;
    double temps_cpu_algo1;
    double temps_cpu_algo2;

    srand(time(NULL));

    int **p = NULL;
    for(int i = 0; i < NUMBER_ITERATION; i++) {
       

        temps_initial = clock();
        p = produit_mat_1(mat1, mat2, n);
        temps_final = clock();
        temps_cpu_algo1 = ((double) (temps_final - temps_initial)) / CLOCKS_PER_SEC;

        desalloue_matrice(p, n);
        matTriangulaireSup = alloue_matrice_triangulaire(n,1);
        matTriangulaireInf = alloue_matrice_triangulaire(n,0);
        temps_initial = clock();
        p = produit_triang(matTriangulaireSup, matTriangulaireInf);
        temps_final = clock();
        temps_cpu_algo2 = ((double) (temps_final - temps_initial)) / CLOCKS_PER_SEC;

        desalloue_matrice(p, n);

        fprintf(file, "%d %f %f\n", n*n, temps_cpu_algo1, temps_cpu_algo2);

        desalloue_matrice_triangulaire(matTriangulaireInf);

        desalloue_matrice_triangulaire(matTriangulaireSup);
        n++;
    }

    fclose(file);
    return 0;
}