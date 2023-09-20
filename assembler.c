/*
*		C project - mmn 14
*
*		@author Binyamin 
*		
*
* The algorithm is presented later in the program
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

#include "assembler.h"


int main(int argc, char **argv) {
	
	char *fullFileName;	
	
	printf("HELLO, welcome to my program, \n ");
	int i;
	
		if (argc <= 1) {
		printf(stderr,"ERROR - No File where typed.\n");
		exit(1);
	}
	for (i = 1; i < argc; i++) {
		/*changing the ending of file to .as*/
		fullFileName = NULL;
		fullFileName = concat(argv[i],".as\0");
		
		/*start with the first pass*/
		if(firstPass(&argv[i], char fileName) == 1){
		
			printf("Success with first pass, keeping up for second pass");
			/*if there no errors, starting with the second pass*/
			SecondPass(argv[i]);
			
		}
		else{					
					fclose(file);
					free(fullFileName);
					cleanLists();
					continue;
		}
}
	
	
	
