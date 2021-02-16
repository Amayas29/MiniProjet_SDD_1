#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "algo.h"
#include "matrice.h"
#include "tableau.h"
#include "commun.h"

int main() {

    int maxValeur = 100;
    int n = 1000;

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

    int **prod = NULL;

    for(int i = 0; i < NUMBER_ITERATION; i++) {
        
        // On alloue les matrices
        mat1 = alloue_matrice(n);
        remplir_matrice(mat1, n ,maxValeur);

        mat2 = alloue_matrice(n);
        remplir_matrice(mat1, n ,maxValeur);

        matTriangulaireSup = alloue_matrice_triangulaire(n, 1);
        remplir_matrice_triangulaire(matTriangulaireSup, maxValeur);

        matTriangulaireInf = alloue_matrice_triangulaire(n, 0);
        remplir_matrice_triangulaire(matTriangulaireInf, maxValeur);

        // calcule du temps pour le premier algorithme (produit matrice non triangulaire)
        temps_initial = clock();
        prod = produit_mat_1(mat1, mat2, n);
        temps_final = clock();
        temps_cpu_algo1 = ((double) (temps_final - temps_initial)) / CLOCKS_PER_SEC;
        desalloue_matrice(prod, n);

        // calcule du temps pour le premier algorithme (produit matrice non triangulaire)
        temps_initial = clock();
        prod = produit_triang(matTriangulaireSup, matTriangulaireInf);
        temps_final = clock();
        temps_cpu_algo2 = ((double) (temps_final - temps_initial)) / CLOCKS_PER_SEC;
        desalloue_matrice(prod, n);
        
        fprintf(file, "%d %f %f\n", n, temps_cpu_algo1, temps_cpu_algo2);

        // On libere l'espace memoires alloue
        desalloue_matrice_triangulaire(matTriangulaireInf);
        desalloue_matrice_triangulaire(matTriangulaireSup);
        desalloue_matrice(mat1, n);
        desalloue_matrice(mat2, n);

        n++;
    }

    fclose(file);
    return 0;
}