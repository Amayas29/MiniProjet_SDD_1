#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "algo.h"
#include "tableau.h"
#include "commun.h"

int main(void) {

    char *file_name = "sortie_vitesse_tab.txt";
    FILE *file = fopen(file_name, "w");

    int n = 1;
    int *t = NULL;
    int valeur = 100;

    clock_t temps_initial;
    clock_t temps_final;
    double temps_cpu_algo1;
    double temps_cpu_algo2;

    srand(time(NULL));

    for(int i = 0; i < NUMBER_ITERATION; i++) {

        t = alloue_tableau(n);
        remplir_tableau(t, n, valeur);

        temps_initial = clock();
        somme_1(t, n);
        temps_final = clock();
        temps_cpu_algo1 = ((double) (temps_final - temps_initial)) / CLOCKS_PER_SEC;

        temps_initial = clock();
        somme_2(t, n);
        temps_final = clock();
        temps_cpu_algo2 = ((double) (temps_final - temps_initial)) / CLOCKS_PER_SEC;

        fprintf(file, "%d %f %f\n", n, temps_cpu_algo1, temps_cpu_algo2);

        desalloue_tableau(t);
        n++;
    }

    fclose(file);
    return 0;
}