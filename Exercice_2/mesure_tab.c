#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "algo.h"
#include "commun.h"
#include "tableau.h"

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

    for (int i = 0; i < NUMBER_ITERATION; i++) {
        //allocation et remplicage du tableau
        t = alloue_tableau(n);
        remplir_tableau(t, n, valeur);

        // calcule du temps pour la premiere fonction de O(n²)
        temps_initial = clock();
        somme_1(t, n);
        temps_final = clock();
        temps_cpu_algo1 = ((double)(temps_final - temps_initial)) / CLOCKS_PER_SEC;

        // calcule du temps pour la premiere fonction de O(n)
        temps_initial = clock();
        somme_2(t, n);
        temps_final = clock();
        temps_cpu_algo2 = ((double)(temps_final - temps_initial)) / CLOCKS_PER_SEC;

        //ecriture du resultat des temps dans un fichier
        fprintf(file, "%d %f %f\n", n, temps_cpu_algo1, temps_cpu_algo2);

        //desallocation du tableau
        desalloue_tableau(t);
        n++;
    }

    fclose(file);
    return 0;
}