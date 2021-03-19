#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "algo.h"
#include "commun.h"
#include "matrice.h"
#include "tableau.h"

int main() {
    int maxValeur = 100;

    int n = 1000;

    char *file_name = "sortie_vitesse_mat_verif.txt";
    FILE *file = fopen(file_name, "w");

    int **mat = NULL;

    clock_t temps_initial;
    clock_t temps_final;
    double temps_cpu_algo1;
    double temps_cpu_algo2;

    srand(time(NULL));

    for (int i = 0; i < NUMBER_ITERATION; i++) {
        // on alloue la matrice et on la remplie random
        mat = alloue_matrice(n);
        remplir_matrice(mat, n, maxValeur);

        // on calcule le temps que la fonction de verification O(n⁴) prend
        temps_initial = clock();
        verfie_matrice_1(mat, n);
        temps_final = clock();
        temps_cpu_algo1 = ((double)(temps_final - temps_initial)) / CLOCKS_PER_SEC;

        // on calcule le temps que la fonction de verification O(n) prend
        temps_initial = clock();
        verfie_matrice_2(mat, n, maxValeur);
        temps_final = clock();
        temps_cpu_algo2 = ((double)(temps_final - temps_initial)) / CLOCKS_PER_SEC;

        // on ecrit le resultat dans un fichier
        fprintf(file, "%d %f %f\n", n, temps_cpu_algo1, temps_cpu_algo2);

        // on desaloue la matrice allouer
        desalloue_matrice(mat, n);
        n++;
    }

    fclose(file);
    return 0;
}