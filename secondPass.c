#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>


/*algorithem*/
	
/*	go the symbol table, 
	for every symbol that appear '?'put inside its place the number that apper in the symbol list
	
	if all the regs translate to binary, 
	translate it to hexa and import it to files
	
	*/
	
	


void SecondPass(char filename[30]);



/*add the symbols and make the comlete tables*/



void SecondPass(char filename[30], int ICF,int DCF){


/*opening 3 files for output*/
char obj_file_name[LINE_LEN], ent_file_name[LINE_LEN], ext_file_name[LINE_LEN];
	FILE *obj_file, *ent_file, *ext_file;

 	/*open the object file*/
	strcpy(obj_file_name, file_name);
	strcat(obj_file_name, ".obj");
	obj_file_name[strlen(file_name) + 4] = '\0';
	obj_file = fopen(obj_file_name, "w");
	if(obj_file == NULL) {
          perror("\nERROR - Unable to open obj file!");
          exit(1);
      }

	/*open the entry file*/
	strcpy(ent_file_name, file_name);
	strcat(ent_file_name, ".ent");
	ent_file_name[strlen(file_name) + 4] = '\0';
	ent_file = fopen(ent_file_name, "w");
	if(ent_file == NULL) {
          perror("\nERROR - Unable to open ent file!");
          exit(1);
      }

	/*open the extern file*/
	strcpy(ext_file_name, file_name);
	strcat(ext_file_name, ".ext");
	ext_file_name[strlen(file_name) + 4] = '\0';
	ext_file = fopen(ext_file_name, "w");
	if(ext_file == NULL) {
          perror("\nERROR - Unable to open ext file!");
          exit(1);
      }
      
	int IC = 100;
	
	
	/*represent the symbol the program will serach for in this function*/
	char *symbuff = (char*)malloc(70*sizeof(char));
	if (!symbuff)
        printf(stderr,"\nERROR - Dynamic allocatio error");
    
	/*represent the IC line the shown next to the symboll*/    
    int *ICbuff = (int*)malloc(sizeof(int));
	if (!ICbuff)
        printf(stderr,"\nERROR - Dynamic allocatio error");  
        
    TypeR *current;    
    for(IC =100; IC < ICF ; IC++){
	
	
		/*reading line by line again and gets in any line the last word using strtok */    	
 		while(fgets(buf, sizeof(buff), fp)) != NULL) { 	
    
    
		    /*findin the last word in the sentence and verifing its a symbol*/
			char *last_tok = NULL;
		        char *tok = strtok(buff, " \t\n");
		        while (tok) {
		            last_tok = tok;
		            tok = strtok(NULL, " \t\n");
		        }
		        if (last_tok)
		            printf("%s\n", last_tok);
		    /*a second STRTOK is used to make sure it does not stick to the comma or other character*/ 
				char symbolWithoutComma[70] ;
		 			strcpy(symbolWithoutComma,last_tok);
		         
				*last_tok = NULL;
		        tok = strtok(symbolWithoutComma, ",");
		        while (tok) {
		            last_tok = tok;
		            tok = strtok(NULL, ",");
		        }
		        if (last_tok)
		            printf("%s\n", last_tok);
		            
		            
		        /*Checks whether it is a label according to the criteria we have already performed in the first pass*/
		        if (isItSymbol(last_tok) == 1){
		        	
		        	
		        	/*Goes through the symbol table and when it identifies an icon identical to the current one, enters its row number (value) in the current symbol*/
		        	/*head4 representing symboList list head*/
					for(temp = **head4; teamp != NUll ;temp = temp->next){
								
						if(searchSymbolValue(head4, symbolName) == 1);{
							/*The assembler goes over the file again by line, and the current line is the validable value we found, so the given value is the current IC*/	
							temp->value = IC;					
						}
					}
				}
				/*IC promoted in a row, move on to the next row*/
				IC+4;
		   }/*finish rewriting the symbol table*/
	
	
	/*writing the complete Command table Which is converted from a binary base to a hexadecimal base,
	When the rows are arranged in the order of the row*/
		while(head1->next != NULL || head2->next != NULL  || head3->next != NULL){
			for(int i= 100 ; i < ICF ; 1++){
				/*HEAD1 represents the linked list of R commands*/
				if(head1->value == i){
					binaryToHex(head1->opCode_[7], 7
					char opCode_[7];
						char rg1_[6] ;
						char rg2_ [6];
						char rg3_ [6];	
						int func_;
					fprintf(obj_file, "%4d\t %1s%1s\t %1s%1s \t%1s" , head1-> value , binaryToHex(head1->opCode_[7], 7), binaryToHex(head1->rg1_[6], 7),binaryToHex(head1->rg2_[7], 7),binaryToHex(head1->rg3_[7], 7),binaryToHex(head1->func, 5));	
				}
				/*HEAD2 represents the linked list of I commands*/
				if(head2->value == i){
					binaryToHex(head3->opCode_[7], 7
					char opCode_[7];
						char rg1_[6] ;
						char rg2_ [6];
						char imm_val[17];	
						int func_;
					fprintf(obj_file, "%4d\t %1s%1s\t %1s%1s  ", head1-> value , binaryToHex(head1->opCode_[7], 7), binaryToHex(head1->rg1_[6], 7),binaryToHex(head1->rg2_[7], 7),binaryToHex(head1->rg3_[7], 7));
				}
					/*HEAD3 represents the linked list of J commands*/
				if(head3->value == i){
					binaryToHex(head3->opCode_[7], 7
					char opCode_[7];
						char rg1_[2] ;
						
						int func_;
					fprintf(obj_file, "%4d\t %1s%1s\t %1s" , head1-> value , binaryToHex(head1->opCode_[7], 7), binaryToHex(head1->rg1_[6], 7) ,binaryToHex(head1->func, 5));
				}
			}
/*The program does not unify the 3 data structures because I have not found a good way to do so, 
but it searches for the given value in each of the data structures and complements it.
In the final print, the table is presented as a structure arranged by value*/
		}
	
	
	
	
		/*Writes the symbols to the entry and the external files*/
		while(symboList->next != NULL )
	        {
	        	/*the value given to represent ENT is 2*/
	        	if(symboList->attributes == 2){
					fprintf(ent_file, "\n %4d \t %s \t %s\n", symboList->value , symboList->value, "entry");
					fprintf(ent_file, "\n");
		            node = node->next;
	        	}
	        	/*the value given to represent ENT is 3*/
	        	if(symboList->attributes == 3){
					fprintf(ext_file, "\n %4d \t %s \t %s\n", symboList->value , symboList->value, "external");
					fprintf(ext_file, "\n");
		            node = node->next;
	        	}
		}
    	
	/*Closes the files, and finishes the program*/
	free(temp);
	cleanLists();
	close(obj_file);
	close(ent_file);
	close(ext_file);

}
