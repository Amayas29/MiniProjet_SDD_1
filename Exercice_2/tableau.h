#ifndef __TABLEAU_H__
#define __TABLEAU_H__

int *alloue_tableau(int taille);
void desalloue_tableau(int *tableau);
void remplir_tableau(int *tableau, int taille, int valeur);
void afficher_tableau(int *tableau, int taille);

#endif