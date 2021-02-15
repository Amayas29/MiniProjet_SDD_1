#include <stdlib.h>
#include "algo.h"
#include "tableau.h"
#include "matrice.h"
#include "commun.h"

int somme_1(int *tableau, int taille) {
    int somme = 0;

    if(tableau) {
        for(int i = 0; i < taille; i++)
            for (int j = 0; j < taille; j++)
                somme += (tableau[ i ] - tableau[ j ]) * (tableau[ i ] - tableau[ j ]);
    }

    return somme;
}

int somme_2(int *tableau, int taille) {
    int sommeX = 0;
    int sommeXCarre = 0;

    for(int i = 0; i < taille; i++) {
        sommeX += tableau[ i ];
        sommeXCarre += tableau[ i ] * tableau[ i ];
    }

    return 2 * taille * sommeXCarre - 2 * sommeX * sommeX;
}

int verfie_matrice_1(int **matrice, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < n; k++) {
                for(int l = 0; l < m; l++) {
                    if(i != k && j != l && matrice[i][j] == matrice[k][l])
                        return 0;
                }
            }
        }
    }
    return 1;
}

int verfie_matrice_2(int **matrice, int n, int m, int *check, int maxValeur) {

    for(int i = 0; i < maxValeur; i++)
        check[ i ] = 0;
    

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(check[matrice[i][j]] != 0) 
                return 0;
            
            check[matrice[i][j]] = 1;
        }
    }

    return 1;
}

int **produit_mat_1(int **mat1, int **mat2, int m) {
    
    int **prod = alloue_matrice(m);
    if(!prod) return NULL;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            prod[i][j] = 0;
            for(int k = 0; k < m; k++)
                prod[i][j] += mat1[i][k] * mat2[k][j];
        }
    }

    return prod;
}

int **produit_triang(MatriceTriangulaire *sup, MatriceTriangulaire *inf) {

    if(sup->taille != inf->taille) {
        print_probleme("les matrice ne sont pas de la meme taille");
        return NULL;
    }

    if(sup->orientation && !inf->orientation){
        print_probleme("prbleme d'incompatibilité");
        return NULL;
    }

    int **prod = alloue_matrice(sup->taille);
    if(!prod){ 
        print_probleme("erreur d'allocation de la matrice");
        return NULL;
    }
    int l = 0;
    for(int i = 0; i < sup->taille; i++) {
        l = 0;
     for(int j = 0; j < sup->taille; j++) {  
        prod[i][j] = 0;
        for (int k = 0; k < sup->taille - j; j++) {   
            prod[i][j] += sup->matrice[i][l] * inf->matrice[k][j];
            l++;
            if(l >= sup->taille -i)
                break;
        }
        
     } 
  }
    return prod;
}
