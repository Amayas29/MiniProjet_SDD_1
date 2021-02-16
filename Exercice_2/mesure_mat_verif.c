#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "algo.h"
#include "matrice.h"
#include "tableau.h"
#include "commun.h"

int main() {

    int maxValeur = 100;
    int *check = alloue_tableau(maxValeur);
    int n = 50;

    char *file_name = "sortie_vitesse_mat_verif.txt";
    FILE *file = fopen(file_name, "w");

    int **mat = NULL;

    clock_t temps_initial;
    clock_t temps_final;
    double temps_cpu_algo1;
    double temps_cpu_algo2;

    srand(time(NULL));

    for(int i = 0; i < NUMBER_ITERATION; i++) {
        mat = alloue_matrice(n);
        remplir_matrice(mat, n ,maxValeur);

        temps_initial = clock();
        verfie_matrice_1(mat, n);
        temps_final = clock();
        temps_cpu_algo1 = ((double) (temps_final - temps_initial)) / CLOCKS_PER_SEC;

        temps_initial = clock();
        verfie_matrice_2(mat, n, check, maxValeur);
        temps_final = clock();
        temps_cpu_algo2 = ((double) (temps_final - temps_initial)) / CLOCKS_PER_SEC;

        fprintf(file, "%d %f %f\n", n*n, temps_cpu_algo1, temps_cpu_algo2);

        desalloue_matrice(mat, n);
        n++;
        
    }

    desalloue_tableau(check);
    fclose(file);
    return 0;
}