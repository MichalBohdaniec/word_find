#include <stdio.h>
#include <stdlib.h>
#include "cs.h"

char* cs(char *c){
	for(int i = 0; i < strlen(c); i++)
		c[i] = tolower(c[i]);

	return c;
}