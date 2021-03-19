#include <stdio.h>
#include <stdlib.h>

const static int len = 10;

int main(void) {
    int *tab;
    int i;

    tab = (int *)malloc(sizeof(int) * len);

    for (i = len - 1; i >= 0; i--) {
        tab[i] = i;
    }

    free(tab);
    return 0;
}