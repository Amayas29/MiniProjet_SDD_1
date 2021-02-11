#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "algo.h"
#include "matrice.h"
#include "tableau.h"
#include "commun.h"

int main() {

    int maxValeur = 100;
    int n = 50, m = 50;

    char *file_name = "sortie_vitesse_mat_prod.txt";
    FILE *file = fopen(file_name, "w");

    int **mat1 = NULL;
    int **mat2 = NULL;

    clock_t temps_initial;
    clock_t temps_final;
    double temps_cpu_algo1;
    double temps_cpu_algo2;

    srand(time(NULL));

    int **p = NULL;
    for(int i = 0; i < NUMBER_ITERATION; i++) {
        mat1 = alloue_matrice(n, m);
        remplir_matrice_sup(mat1, n, m, maxValeur);

        mat2 = alloue_matrice(m, n);
        remplir_matrice_inf(mat2, m, n, maxValeur);

        temps_initial = clock();
        p = produit_mat_1(mat1, mat2, n, m, n);
        temps_final = clock();
        temps_cpu_algo1 = ((double) (temps_final - temps_initial)) / CLOCKS_PER_SEC;

        desaloue_matrice(p, n);

        temps_initial = clock();
        p = produit_triang(mat1, mat2, n, m, n);
        temps_final = clock();
        temps_cpu_algo2 = ((double) (temps_final - temps_initial)) / CLOCKS_PER_SEC;

        desaloue_matrice(p, n);

        fprintf(file, "%d %f %f\n", n*m, temps_cpu_algo1, temps_cpu_algo2);

        desaloue_matrice(mat1, n);
        desaloue_matrice(mat2, m);
        n++;
        m++;
    }

    fclose(file);
    return 0;
}