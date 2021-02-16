#include <stdlib.h>
#include "algo.h"
#include "tableau.h"
#include "matrice.h"
#include "commun.h"

// permet de faire la somme de la difference carre des case d'un tableau en O(n²)
int somme_1(int *tableau, int taille) {
    int somme = 0;

    if(tableau) {
        for(int i = 0; i < taille; i++)
            for (int j = 0; j < taille; j++)
                somme += (tableau[ i ] - tableau[ j ]) * (tableau[ i ] - tableau[ j ]);
    }

    return somme;
}

// permet de faire la somme de la difference carre des case d'un tableau en O(n)
int somme_2(int *tableau, int taille) {
    int sommeX = 0;
    int sommeXCarre = 0;

    for(int i = 0; i < taille; i++) {
        sommeX += tableau[ i ];
        sommeXCarre += tableau[ i ] * tableau[ i ];
    }

    return 2 * taille * sommeXCarre - 2 * sommeX * sommeX;
}

// permet de vericier si toutes les valeurs d'une matrice sont differentes en O(n⁴)
int verfie_matrice_1(int **matrice, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                for(int l = 0; l < n; l++) {
                    if(i != k && j != l && matrice[i][j] == matrice[k][l])
                        return 0;
                }
            }
        }
    }
    return 1;
}

// permet de vericier si toutes les valeurs d'une matrice sont differentes en O(n²)
int verfie_matrice_2(int **matrice, int n, int *check, int maxValeur) {

    //on utilise un tableau de maxValeur de valeurs comme tableau de booleen (0 si il n'existe pas 1 sinon)
    for(int i = 0; i < maxValeur; i++)
        check[ i ] = 0;
    

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(check[matrice[i][j]] != 0) 
                return 0;
            
            check[matrice[i][j]] = 1;
        }
    }

    return 1;
}

//permet de faire le produit matricielle
int **produit_mat_1(int **mat1, int **mat2, int m) {
    
    int **prod = alloue_matrice(m);
    if(!prod) return NULL;

    // c'est la somme du produit ligne * colonne
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            prod[i][j] = 0;
            for(int k = 0; k < m; k++)
                prod[i][j] += mat1[i][k] * mat2[k][j];
        }
    }

    return prod;
}

//permet de faire le produit matricielle entre deux matrice triangulaire sup * inf
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
    // c'est la somme du produit ligne * colonne
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
