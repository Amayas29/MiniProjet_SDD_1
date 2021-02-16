#ifndef __COMMUN_H__
#define __COMMUN_H__
#include <stdio.h>

#define NUMBER_ITERATION 10

#define print_probleme(msg) fprintf(stderr, "%s dans la fonction %s a la ligne %d\n", msg, __PRETTY_FUNCTION__, __LINE__) 

#endif