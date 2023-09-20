#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>
#include <stddef.h>








/*skip blanks or commas, and return the location of the location in the line*/
int skip_space(char loc) {
	
	int i = 0, c;
	while (isspace((c = loc[i]))|| loc[i] ==',') {
		i++;
			
	}
	return i;
	
	
	
/*decides whether its a symbol if does return 1, if not return 0*/
int isItSymbol(char sym) {
	
	char *symbolBuff = (char*) malloc(70 * sizeof(char));
	char str1;/*for strstr function*/
	
		/* if memory cannot be allocated */
  		if(symbolBuff == NULL) {
    	printf(stderr,"\nError! memory not allocated.");
    	}
    	
	symbolBuff = strcpy(symbolBuff, sym);
		/*check is there unlegal chars in the symbol*/
		for(int i =0 ; i < strlen(nonSymbols-1); i++)){
			str1 = strstr(symbolBuff, nonSymbol[i]);
			if(strcmp(str1, nonSymbol[i]) == 0 ){
				printf(stderr, "\nERROR - not a legal symbol char");
				return 0;
			}
		}
		
		/*compare symbol with commands name*/
		for(i =0 ; i < strlen(commands-1); i++)){
			if(strcmp(symbolBuff, commands[i]) == 0){
				printf(stderr, "\nERROR - not a legal symbol char");
					return 0;
			}
		}
		
		/*compare symbol with data names*/
		for(i =0 ; i < strlen(dataNames-1); i++)){
			if(strcmp(symbolBuff, commands[i]) == 0 ){
				printf(stderr, "\nERROR - not a legal symbol char");
					return 0;
			}
		}
		
		if(!isalpha(symbolBuff[0])){
			printf(stderr,"\nERROR - wrong symbol syntax");
			return 0;
		}	
		
			return 1;
	
	
}


/*check if this command is in the command table, 
return 1 if it R-command, 
return 2 if it I-command, 
return 3 if it J-command. 
else return 0*/
int isItCommand(char com){

	int i = NULL;
	for(i =0 ; i < strlen(commands-1); i++))
	{
		if(cmp(symbolBuff, commands[i]) == 0)
			break;
		}
	}
	if(i >= 0 || i<= 7)
		return 1;
	if(i >= 8 || i<= 22)
		return 2;
	if(i >= 23 || i<= 26)
	 	return 3;

	printf(stderr,"\nERROR - this is not a legal command name" );
		return 0;	
}

/*check if its legal data name*/
int isItData(char pro){
		for(i =0 ; i < strlen(dataNames-1); i++))
			if(cmp(symbolBuff, *(dataNames+i)) == 0)
				return 1;
		
		}else
			printf(stderr,"\nERROR - this is not a legal command name" );
		return 0;
	
	
}

/*Checks whether the register is a number, and whether it is in the appropriate range, if legal return 1, otherwise 0*/
int isItReg(int regis1){
	
	int reg1= regis1;
	
	if(!isdigit(reg1)){
		printf(stderr,"\nERROR - The memory register must be entered as a positive number");
		return 0;
	}
		
	if(reg1 < 0 || reg1 >31){
		printf("\nERROR - Invalid register range");
		return 0;
	}
	return 1;
	
	
	
/*Checks whether the number entered is integer based on decimal, if legal return 1, otherwise return 0*/
int isItLegalNumber(int num){
	
	int num1= num;
	if(!isdigit(num1))
		printf(stderr,"\nERROR - wrong input number");
		return 0;
	if(isxdigit(num1)){
		printf(stderr,"\nERROR - only decimal numbers permitted");
		return 0;
	}
	/*From the fact that the number is an int, then it is an integer and not a floating point*/
	return 1;
					
	
	
	
}



/*adding symbol to the symbol list with exception for entry extern or data file*/
int addSymbol(char sym[70], int line, int option ){
		
		if(option < 1 || option > 4)
			printf("\nERROR - no such option");
			
		while(!(Head->next= Null)){
			Head = Head->next;
		}
/*There are 4 options, if the received option is 
 1 - data line,
 2 - entry line, 
 3 - extern line
 4- code line*/
 	symboList Head = (symboList *)malloc(sizeof(symboList));
 		if(Head == NULL)
			printf(stderr,"\nERROR - not enough space for buff"); 
					
	Head->value = line;
	strcpy(Head->symbol, sym);	
	Head->attributes = option;
	Head->next= Null;
}


/*cleans all the nodes and tables*/
void cleanLists() {
	
		TypeR TypeR->next = NULL;
		free(TypeR);
		
		TypeI TypeI->next = NULL;
		free(TypeI);
		
		TypeJ TypeJ->next = NULL;
		free(TypeJ);
		
		
}










