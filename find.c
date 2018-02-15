#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readtxt.h"
#include "scantext.h"

int main (int argc, char **argv){
	
	int rcmd = 0;
	int wcmd = 0;
	int flag = 0;
	int c = 0;
	char string[100]; 
	char input [100];
	char output[100];
	
	//Read command arguments
	for(int i=2;i<=argc-1;i++){
		if(argc > 7) exit(0);
		if(strcmp(argv[i],"-i") == 0) flag=1;	
		if(strcmp(argv[i],"-o") == 0) flag=2;			
		if(strcmp(argv[i],"-c") == 0) flag=3;	
		if(strcmp(argv[i],"-c") == 1 && strcmp(argv[i],"-o") == 1 && strcmp(argv[i],"-i") == 1)	
			flag =4;
		
		switch(flag){
			case 1:
				if(strcmp(argv[i+1],"-c") == 0){
					printf("ERROR ABDK0039 : -o not specified\n");
					exit(0);
				}
				if(strcmp(argv[i+1],"-o") == 1 && strcmp(argv[i+1],"-i") == 1 && strcmp(argv[i+1],"-c") == 1){
						strcpy(input,argv[i+1]);
						break;
				}
					else {
					rcmd++;
					break;
					}
			case 2:
				if (i == argc-1){
					wcmd=1;
					break;
				}
				if(strcmp(argv[i+1],"-c") == 0){
					wcmd=1;
					c=1;
					break;
				}
				else{
					strcpy(output,argv[i+1]);
					break;
				}
			case 3:
				if(i==argc-1){
					c=1;
					break;
				}
				else {
					printf("ERROR ABDK0069 : arguments after -c found\n");
					exit(0);
				}
			case 4:
				if(strcmp(argv[i-1],"-i") == 0){
					strcpy(input,argv[i]);
					break;
				}
				if(strcmp(argv[i-1],"-o") == 0){
					strcpy(output,argv[i]);
					break;
				}
					
					
			default:
				printf("%s",argv[i]);
				break;
				
		}
		
		
	}
	
	//Work with the string
	strcpy(string,argv[1]);
	if(c) cs(string);
	
	//Scan document
	scantext(string,readtxt(input,rcmd,c),output,wcmd);
	
	return 0;
}