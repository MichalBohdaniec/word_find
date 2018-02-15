#include <stdio.h>
#include <stdlib.h>
#include "readtxt.h"
#include "cs.h"


char* readtxt (char *in , int rcmd, int c)
{
	if(rcmd == 1){
	printf("Please enter input text :\n");
	char text[10000]; //Buffer
	fgets(text,(10000),stdin);
	if(c) cs(text);
	return text;
	}
	
	else{	
	FILE *rfile;
    rfile = fopen(in,"r");
	fseek(rfile,0,SEEK_END);
	int size = ftell(rfile);
	rewind(rfile);
	char* text = (char*) malloc(sizeof(int)*size); 
	fread(text, sizeof(int), size, rfile);
	if(c) cs(text);
	
	return text;
	free(text);
	fclose(rfile);
	}
}