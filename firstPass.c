/*The algorithem
*The function receives a file with its name,
*Checking that it is not an empty song or a comment line
*And begins to read line by line.
*Once a line is scanned, we begin to read word for word separately and try to identify its context
*Each word has its own uniqueness, so you can basically sort them by values and send them to the correct functions/*

/*use free() function*/


#include "Assembler.h"
#include "Assembler.cpp"
																			
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

#define ONE_ BYTE 8
#define TWO_ BYTE 16
#define THREE_BYTES 24
#define FOUR_ BYTE 32
#define errorFlag 0;



#define BUFZIZE 81 /*max 80 chars on a line + 1 for \0*/
#define FLOOR floor(log10(abs(x)))+1 /*lengthe of integer*/





int firstPass( char *filename){
	

extern char nonSymbols[]={"!","@","#","$","%","^","&","*","<",">"};
extern char commands[] = {"add", "sub", "and", "or" ,"nor", "move", "movehi", "movelo", "addi", "subi", "andi", "ori", "nori", "bne", "beq", "blt", "bgt", "lb", "sb", "lw", "sw", "lh", "sh", "jump", "la", "call", "stop"};
extern char dataNames[] = {".dh", ".db", ".dw", ".asciz", ".enrty" , ".extern"};
extern int IC = 100;/*represent the line reading*/
extern int DC = 0; /*represent the amount of data read*/


char *buff; /*represent the current line*/
char *word;
long *number;
int loc = 0;
temp = (char*)malloc (BUFSIZE*(sizeof(char)));
//char word [BUFSIZE];
char rg1,rg2,rg3,imm_val;
int symbolFlag =0, dataFlag =0;


FILE*  fp = fopen(filename, "r");
      if(fp == NULL) {
          perror("\nERROR - Unable to open file!");
          exit(1);
      }
      
	 /*allocating memory to pointers for variables*/  
    buff = (char*)malloc (BUFSIZE*(sizeof(char)));
				if(buff == NULL)
					printf(stderr,"\nERROR - not enough space for buff"); 
	
	temp = (char*)malloc (BUFSIZE*(sizeof(char)));
				if(temp == NULL)
					printf(stderr,"\nERROR - not enough space for temp"); 
	
	number = (long*)malloc ((sizeof(long)));
				if(temp == NULL)
					printf(stderr,"\nERROR - not enough space for temp"); 
	
	
	/*allocating memory to pointers for linked list structtures*/
	TypeR *head1;
        head1 =(TypeR*)malloc(sizeof(TypeR));
        if(head1 ==NULL)
        {
                printf(stderr,"\nERROR - Out of Memory Space:");
                exit(0);
        }
							
	TypeI *head2;
        head2 =(TypeI*)malloc(sizeof(TypeI));
        if(head2 ==NULL)
        {
                printf(stderr,"\nERROR - Out of Memory Space:");
                exit(0);
        }
							
	TypeJ *head3;
        head1 =(TypeJ*)malloc(sizeof(TypeJ);
        if(head3 ==NULL)
        {
                printf(stderr,"\nERROR - Out of Memory Space:");
                exit(0);
        }
    
	/*allocating memory to pointers for symbol list structture*/
	symboList head4;;
        head4 =(TypeJ*)malloc(sizeof(TypeJ);
        if(head4 ==NULL)
        {
                printf(stderr,"\nERROR - Out of Memory Space:");
                exit(0);
        }		    
		
		
																
	 
	 /*reading a line from the file*/
        while(fgets(buf, sizeof(buf), fp)) != NULL) {
        	IC++;
        
		/*Reading the line, word for word*/	
			while (!feof(buff)) {
				
		if(buff + loc > 80)
			printf(stderr,"ERROR - the line is too lng- line %d", DC);
		loc += skip_spaces(loc);
	
		/*end of line*/
		if (*(buff + loc) == '\n') {
			IC++;
		}
		/*the function takes all the line and start reading it word by word*/
		if (sscanf(buff, "%s", word)) {
			if (word[0] == ';' || line[0] == '\n' || line[0] == '\0' || line[loc] == '\0')
				loc++;
	
		/*it is a simbol*/		
			if (word[strlen(word) - 1] == ':'){
				/*verifing its a Symbol and its not using forbidden name*/
				symbolFlag = isItSymbol(word);
					if(symbolFlag == 1){
					char sym[70];
					strcpy(sym, word);
					/*1 represent regurlar data*/
					addSymbol(sym,IC, 1);
					loc = loc + strlen(word-1));
					sscanf(buff + loc, "%s", word));
					
					}
			printf(stderr,"\nERROR - this is not legal name for symbol - line %d", IC);	
			errorFlag = 1;	
			}
			/*check if the data is db/dh/dw or asciz or entry/extern*/
			if (word[0] == '.') {
				/*check if the data exist*/
				dataFlag = isItdata(word);
				/*check the data by its first letters*/
					if(dataFlag == 1){
						if (word[1] == 'd'){
							/*word[2] == 'b'*/
							if (word[2] == 'b')
							/*there is 3 differnnt function here*/
								while(buff[loc] != BUFSIZE && !buff ){
									loc = loc + strlen(word-1));
									sscanf(buff + loc, "%s", word));
								/*dbDATA function*/
									dbDATA(word, line, 4);
									DC++;
								}
									/*word[2] == 'w'*/		
							else if (word[2] == 'w'){
								while(buff[loc] != BUFSIZE && !buff){
									loc = loc + strlen(word-1));
									sscanf(buff + loc, "%s", word));
								/*dwDATA function*/
									dwDATA(word, line, 4);
									DC++;
								}
							}
								
							else{ /*word[2] == 'h'*/	
								while(buff[loc] != BUFSIZE && !buff){
									loc = loc + strlen(word-1));
									sscanf(buff + loc, "%s", word));
								/*dhDATA function*/	
									dhDATA(word, line, 4);
									DC++;
								}
							}
						}
							/*entry or extern data line, When it detects a ent/ext prompt, 
							it scans the following icon and puts it in the icon table, with the suitable ent/ext value*/
							else if(word[1] == 'e'){
								/*entery data line*/
								if (word[2] == 'n'){
									sscanf(buff + loc, "%s", word));
									symbolflag = isItSymbol(word);
									if(symbolFlag ==1)
									/*2 represent entry data*/
									addSymbol(word, , IC, 2);
									
								}
								/*extern data line*/	
								else if (word[2] == 'x'){
									sscanf(buff + loc, "%d", woed));
									extData(symbol);
									isItSymbol(word);
									if(symbolFlag ==1)
									/*3 represent extern data*/
									addSymbol(word, IC, 3);
								}
								else
								
							}
						
							/*this is asciz, the last option left*/
							else{
								loc = loc + strlen(word-1));
								sscanf(buff + loc, "%s", word));
								ascizData(word, IC);
								/*do not forget the \0*/
								DC = DC + strlen(word-1);	
							} 
						}
					}
						else{
							printf(stderr,"\nERROR - this is not data - wrong input - line %d", DC);
							errorFlag = 1;
						}
								
/*we got to the command*/					
			 		else if(isalpha(word[0])){
			 			int commandFlag = isItCommand(word);
			 			/*this is R command*/
			 				if(commandFlag == 1){
			 					loc = loc + strlen(word-1));
			 					loc += skip_spaces(loc);
			 					sscanf(buff + loc, "%s", word));
								 rg1 = word[1];
			 					loc += skip_spaces(loc);
			 					sscanf(buff + loc, "%s", word));
			 					rg2 = word[1];
			 					loc += skip_spaces(loc);
			 					sscanf(buff + loc, "%s", word));
			 					rg3 = word[1];
			 					R_opcode(IC, rg1, rg2 , rg3);
							}
			 			/*this is I command*/	
			 				else if(commandFlag == 2){
			 						loc = loc + strlen(word-1));
			 					loc += skip_spaces(loc);
			 					sscanf(buff + loc, "%s", word));
								 rg1 = word[1];
			 					loc += skip_spaces(loc);
			 					sscanf(buff + loc, "%s", word));
			 					strcpy(imm_val, word);
			 					loc += skip_spaces(loc);
			 					sscanf(buff + loc, "%s", word));
			 					strcpy(rg3, word);
			 					I_opcode(IC, rg1, imm_val, rg2);
							}
			 			/*this is J command*/	
			 				else if(commandFlag == 3){
			 						loc = loc + strlen(word-1));
			 					loc += skip_spaces(loc);
			 					sscanf(buff + loc, "%s", word));
								J_opcode(IC, word);
			 				}
			 				/*this is not a coomand*/
			 				else{
			 				printf(stderr,"\nERROR - this is not data - wrong input - line %d", DC);
			 				errorFlag = 1;	
							 }
			 		}
		 		
		
			}/*end of sscanf*/
			else{
				printf(stderr,"\nERROR - line is null - line %d")
				errorFlag = 1;
				
			}
			IC++;
			free(tmp);
		}/*end of feof state*/
		DC += 4;
		IC += 4;
		symbolFlag =0;
		dataFlag= 0;
		
		}
		
	}/*enf of fgets*/
	if(errorFlag ==1){
		printf(stderr,"there were a errors in the input file, can't build the output files");
		return 0;
}
			return 1;	
			
}/*end of function*/


void dbData(char number1[20], int line){
	
	/*The function gets a number, converts it to INT, converts it to binary encoding and prints it as a binary string,
	In addition it checks that the encoding does not contain more than 8 characters*/ 		
		temp = &number1;	
		number = atoi(number1);
		temp = decimalToBin(number)
		if(strlen(temp) > 8) ){
			printf(stderr,"\n ERROR - number too long");
			errorFlag = 1;
		}
		addSymbol(&temp, line, 4);
		free(temp);
	}
	
	/*The function gets a number, converts it to INT, converts it to binary encoding and prints it as a binary string
	In addition it checks that the encoding does not contain more than 16 characters*/
void dwData(char number1[20], int line){	
		
		temp = &number1;	
		number = atoi(number1);
		temp = decimalToBin(number)
		if(strlen(temp) > 16) ){
			printf("\n ERROR - number too long");
			errorFlag = 1;
		}
		addSymbol(&temp, line, 4);
		free(temp);
	}
	
/*The function gets a number, converts it to INT, converts it to binary encoding and prints it as a binary string
	In addition it checks that the encoding does not contain more than 16 characters*/
	void dhData(char number1[20], int line){					
	
		temp = &number1;	
		number = atoi(number1);
		temp = decimalToBin(number)
		if(strlen(temp) > 32) ){
			printf(stderr,"\n ERROR - number too long");
			errorFlag = 1;
	}
		addSymbol(&temp, line, 4);
		free(temp);
}

/*The function gets a string, converts it to INT and then changes the number to a binary base.
In addition it checks that the number does not contain more than 8 binary digits*/	
void ascizData(char word1[BUFSIZE -5 ], int line){					
	
			char c;
			temp = (char*)malloc(BUFSIZE*sizeof(char));
			/*start at 1 and finished length-2 to avoid "" in te edges */
			for (int i=1 ; i< strlen(word1-2) ; i++)){
				c = atoi(wor1[i]);
				temp = decimalToBin(c);
				if(strlen(temp) > 8) ){
						printf(stderr,"\n ERROR - number too long");
						errorFlag = 1;
		}
			/*00000000 in the end*/	
				
		}
		addSymbol(&temp, line, 4);
		free(temp);
	}
					
/*A function designed for the R commands, It puts the appropriate values ??in place, in the known fields the function already encodes the numbers to a binary base*/
void R_opcode(int line, int code, int rg1, int rg2, int rg3){
	
	
	/*Converts the regisers to a binary string that Representing the address*/
	char bin_reg1[ONE_ BYTE] = decimalToBin(rg1); 
	char bin_reg2[ONE_ BYTE] = decimalToBin(rg2);
	char bin_reg3[ONE_ BYTE] = decimalToBin(rg3);
	TypeR *temp,*ptrR;
	char add1 = "add", sub1 = "sub", and1 = "and", or1= "or", nor1 = "nor", move1= "move", moveh= "movehi", movel = "movelo";
	
        temp = (TypeR*)malloc(sizeof(TypeR));
        if(temp==NULL)
                printf(stderr,"\nERROR - nOut of Memory Space:ntemp line %d", line);
        ptr = (TypeR*)malloc(sizeof(TypeR));
        if(ptr==NULL)
                printf(stderr,"\nERROR - nOut of Memory Space:nptr line %d", line);        
      
	           
	/*Each R operation is in a different home according to the appropriate encoding*/	        
		if(strcmp(code, add1 )== 0){
			temp->IC_line = line;
			temp->opCode  = "000000";
			temp->rg1_ = bin_reg1;
			temp->rg2_ = bin_reg2;
			temp->rg3_ = bin_reg3;	
			temp->func= "00001";
	
		} 
		else if(strcmp(code, sub1)== 0){
			temp->IC_line_ = line;
			temp->opCode_  = "000000";
			temp->rg1_ = bin_reg1;
			temp->rg2_ = bin_reg2;
			temp->rg3_ = bin_reg3;	
			temp->func= "00010";
			
		}
		else if(strcmp(code, and1) == 0){
			temp->IC_line_ = line;
			temp->opCode_  = "000000";
			temp->rg1_ = bin_reg1;
			temp->rg2_ = bin_reg2;
			temp->rg3_ = bin_reg3;	
			temp->func_= "00011";
			
		}
		else if(strcmp(code, or1 )== 0){
			temp->IC_line_ = line;
			temp->opCode_  = "000000";
			temp->rg1_ = bin_reg1;
			temp->rg2_ = bin_reg2;
			temp->rg3_ = bin_reg3;	
			temp->func_= "00100";
			
		}
		
		else if(strcmp(code, nor1 )== 0){
			temp->IC_line = line;
			temp->opCode_  = "000000";
			temp->rg1 = bin_reg1;
			temp->rg2 = bin_reg2;
			temp->rg3 = bin_reg3;	
			temp->func= "00101";
			
		}
				
		else if(strcmp(code, move1)== 0){
			temp->IC_line = line;
			temp->opCode_  = "000001";
			temp->rg1_ = bin_reg1;
			temp->rg2_ = "00000";
			temp->rg3_ = bin_reg3;	
			temp->func_= "00001";
		
		}
		else if(strcmp(code, moveh)== 0){
			temp->IC_line = line;
			temp->opCode_  = "000001";
			temp->rg1_ = bin_reg1;
			temp->rg2_ = "00000";
			temp->rg3_ = bin_reg3;	
			temp->func_= "00010";
		
		}  
		else if(strcmp(code, movel )== 0){
			temp->IC_line = line;
			temp->opCode_  = "000001";
			temp->rg1_ = bin_reg1;
			temp->rg2_ = "00000";
			temp->rg3_ = bin_reg3;	
			temp->func_= "00011";
		
		}	 
		else{
		printf(stderr,"\nERROR -NO OTHER OPTIONS LEFT");
		errorFlag = 1;
		}
	ptrR = &temp
	ptrR = ptrR->next;
	addNode(ptrR, head1);
		free(temp);
}

/*A function designed for the I commands, It puts the appropriate values ??in place, in the known fields the function already encodes the numbers to a binary base*/
void I_opcode(int line, int rg1, int immed, int rg2){
	
	/*Converts the regisers to a binary string that Representing the address*/
	char bin_reg1[ONE_ BYTE] = decimalToBin(rg1); 
	char bin_reg2[ONE_ BYTE] = decimalToBin(rg2);
	char imm_val[THREE_BYTES] = decimalToBin(rg1);
	
	TypeI *temp,*ptrI;
	char addi1 = "addi", subi1 = "subi", andi1 = "andi", ori1= "ori", nori1 = "nori", bne1 ="bne" , beq1 = "beq" , blt1 = "blt", bgt1 ="bgt", lb1= "lb", sb1 = "sb", lw1 = "lw", sw1= "sw", lh1 = "lh", sh1 = "sh";
	
	temp = (TypeI*)malloc(sizeof(TypeI));
        if(temp==NULL)
                printf(stderr,"\nERROR - Out of Memory Space:ntemp line %d", line);
        ptr = (TypeI*)malloc(sizeof(TypeI));
        if(ptr==NULL)
                printf(stderr,"\nERROR - Out of Memory Space:nptr line %d", line);
       /*get to the end of the node list*/
	    insert_end();   
	
/*Each I operation is in a different home according to the appropriate encoding*/	
	if(strcmp(code, addi1 )== 0){
		temp->IC_line_ = line ;
		temp->opCode_ = "001010";
		temp->rg1_ = bin_reg1;
		temp->rg2_  = bin_reg2;
		temp->immVal_ = imm_val;
	
	}
	else if(strcmp(code, subi1 )== 0){
        	temp->IC_line_ = line ;
		temp->opCode_ = "001011";
		temp->rg1_ = bin_reg1;
		temp->rg2_  =bin_reg2;
		temp->immVal_ = imm_val;
		
	}
	else if(strcmp(code, andi1 )== 0){
        	temp->IC_line_ = line ;
		temp->opCode_ = "001100";
		temp->rg1_ = bin_reg1;
		temp->rg2_  =bin_reg2;
		temp->immVal_ =imm_val;
		
	}
	else if(strcmp(code, ori1 )== 0){
        	temp->IC_line_ = line ;
		temp->opCode_ = "001101";
		temp->rg1_ = bin_reg1;
		temp->rg2_ = bin_reg2;
		temp->immVal_= imm_val;
		
	}
	else if(strcmp(code, nori1 )== 0){
        	temp->IC_line_ = line ;
		temp->opCode_ = "001110";
		temp->rg1_ = bin_reg1;
		temp->rg2_  = bin_reg2;
		temp->immVal_ = imm_val;
		
	}
/*can be also a symbol in imm*/	
	else if(strcmp(code, bne1 )== 0){
        	temp->IC_line_ = line ;
		temp->opCode_ = "001111";
		temp->rg1_ = bin_reg1;
		temp->rg2_ = bin_reg2;
		temp->immVal_ = imm_val;
		
	}
	else if(strcmp(code, beq1 )== 0){
        	temp->IC_line_ = line ;
		temp->opCode_ = "010000";
		temp->rg1_ = bin_reg1;
		temp->rg2_  = bin_reg2;
		temp->immVal_ = imm_val;
		
	}  
	else if(strcmp(code, blt1 )== 0){
        	temp->IC_line_ = line ;
		temp->opCode_ = "010001";
		temp->rg1_ = bin_reg1;
		temp->rg2_ = bin_reg2;
		temp->immVal_ =imm_val;
	
	}
	else if(strcmp(code, bgt1 )== 0){
        	temp->IC_line_ = line ;
		temp->opCode_ = "010010";
		temp->rg1_  = bin_reg1;
		temp->rg2_ = bin_reg2;
		temp->immVal_ = imm_val;
	
	}
	else if(strcmp(code, lb1 )== 0){
        	temp->IC_line_ = line ;
		temp->opCode_ = "010011";
		temp->rg1_ = bin_reg1;
		temp->rg2_ = bin_reg2;
		temp->immVal_ =imm_val;
		
	}
	else if(strcmp(code, sb1 )== 0){
        	temp->IC_line_ = line ;
		temp->opCode_ = "010100";
		temp->rg1_ = bin_reg1;
		temp->rg2_  = bin_reg2;
		temp->immVal_ =imm_val;
		
	}
	else if(strcmp(code, lw1 )== 0){
        	temp->IC_line_ = line ;
		temp->opCode_ = "010101";
		temp->rg1_ = bin_reg1;
		temp->rg2_ = bin_reg2;
		temp->immVal_ = imm_val;
	
	}
	else if(strcmp(code, sw1 )== 0){
        	temp->IC_line_ = line ;
		temp->opCode_ = "010110";
		temp->rg1_  = bin_reg1;
		temp->rg2_ = bin_reg2;
		temp->immVal_ =imm_val;
	
	}
	else if(strcmp(code, lh1 )== 0){
        	temp->IC_line_ = line ;
		temp->opCode_ = "010111";
		temp->rg1_ = bin_reg1;
		temp->rg2_ = bin_reg2;
		temp->immVal_ =imm_val;
		
	}
	else if(strcmp(code, sh1 )== 0){
        	temp->IC_line_ = line ;
		temp->opCode_ = "011000";
		temp->rg1_ = bin_reg1;
		temp->rg2_ = bin_reg2;
		temp->immVal_ =imm_val;
	
	}
	else{
		printf(stderr,"\nERROR -NO OTHER OPTIONS LEFT");
		errorFlag = 1;
	}
	
	ptrI = &temp
	ptrI = ptrI->next;
	addNode(ptrI, head2);
		free(temp);
	}
		
/*A function designed for the R commands, It puts the appropriate values ??in place, in the known fields the function already encodes the numbers to a binary base*/
void J_opcode(int line, int rg1){
	
	TypeJ *temp,*ptrJ;
	char jmp1 = "jmp", la1 = "la", call1 = "call", stop1= "stop";
	
	temp = (TypeJ*)malloc(sizeof(TypeJ));
        if(temp==NULL)
                printf(stderr,"\nERROR - Out of Memory Space:ntemp line %d", line);
        ptr = (TypeJ*)malloc(sizeof(TypeJ));
        if(ptr==NULL)
                printf(stderr,"\nERROR - Out of Memory Space:nptr line %d", line);
       /*get to the end of the node list*/
	    insert_end();   
	 
	/*Each J operation is in a different home according to the appropriate encoding*/	    
	if(strcmp(code, jmp1 )){    
		temp->IC_line_ = line;
		temp->opCode_ ="011110";
		temp->rg1_ = rg1;
		
	}
	else if(strcmp(code, la1 )== 0){    
		temp->IC_line_ = line;
		temp->opCode_ ="011111";
		temp->rg1_  = 0;
		
	}
	else if(strcmp(code, call1 )== 0){    
		temp->IC_line_ = line;
		temp->opCode_= "100000";
		temp->rg1_   = 0 ;
		
	}
	else if(strcmp(code, stop1 )== 0){    
		temp->IC_line_ = line;
		temp->opCode_ = "111111";
		temp->rg1_ = 0 ;
	}
	else{
		printf(stderr,"\nERROR -NO OTHER OPTIONS LEFT");
		errorFlag = 1;
	}
	
	
	ptrJ = &temp
	ptrJ = ptrJ->next;
	addNode(ptrJ, head3);
		free(temp);
}					
					
						
					
					
											
				
			
			
			
			





	
	

