CC = gcc
CFLAGC = -Wall -g

PROGS = mesure_tab mesure_mat_verif mesure_mat_prod
all: $(PROGS)

%.o : %.c %.h
	$(CC) $(CFLAGC) -o $@ -c $<

mesure_tab : tableau.o matrice.o algo.o mesure_tab.o
	$(CC) $(CFLAGC) -o $@ $^

mesure_mat_verif : tableau.o matrice.o algo.o mesure_mat_verif.o
	$(CC) $(CFLAGC) -o $@ $^

mesure_mat_prod : tableau.o matrice.o algo.o mesure_mat_prod.o
	$(CC) $(CFLAGC) -o $@ $^

plot_tab :
	gnuplot -p < commande_tab.txt

plot_mat_verif :
	gnuplot -p < commande_mat_verif.txt

plot_mat_prod :
	gnuplot -p < commande_mat_prod.txt

clean :
	rm -rf $(PROGS) *.o *.ps sortie_vitesse_*.txt