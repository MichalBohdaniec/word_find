#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "scantext.h"


int checkword(char *findA, char *findB){

	int lenA = strlen(findA); 			//int length of A ie. string we are looking for
	int lenB = strlen(findB);			 //int length of B ie. the array we are searching for
	int posA = 0; 			 //current position in A
	int posB = 0; 			 //current position in B
	int foundcount = 0;			 //current position in the complete word

	while(posB <= lenB){

		if(findA[posA]==findB[posB]){  //check if current position in word is equal
			posA++;					   //to position in the string A
			posB++;
			foundcount++;			   //move "pointers" accordingly
			}
		else {
			posA=0 ;				   //if the combination of strings != the combo
			foundcount=0 ;			   //break the accummulation in A and foundcount and continue
			posB++ ;				   //looking ie. B++
		}

		if(foundcount == lenA){						//we do that until size of count is the size of A
			return 1;
			foundcount=0;
			posA++;
			posB++;
			getchar();


		}
	}
	return 0;
}

vid scantext (char *importA, char *importB, char *out, int wcmd){

	int txtpos = 0;
	int wordpos = 0;
	char wordbuffer [1000];

	while(txtpos <= strlen(importB)){

		if(importB[txtpos] != ' ' && importB[txtpos] != '\0' && importB[txtpos] != '\n' && importB[txtpos] != '\n'){
			wordbuffer[wordpos] = importB[txtpos];
			wordpos++;
		}

		else {
			wordbuffer[wordpos] = importB[txtpos];

			if (checkword(importA,wordbuffer)==1){
				if(wcmd == 0){
					FILE *output;
					output=fopen(out,"a");
					fputs(wordbuffer,output);
					fputc('\n',output);
					fclose(output);
				}
				else printf("%s\n",wordbuffer);
			}

			wordpos=0;
			memset(wordbuffer,0,1000);

		}
		txtpos++;
	}
}
