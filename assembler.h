#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>
#include <stddef.h>


#define SYMBOL_LEN 30
#define ONE_ BYTE 8
#define TWO_ BYTE 16
#define THREE_BYTES 24
#define FOUR_ BYTE 32


/*firstPass.c functions*/

int firstPass( char *filename);
void dbData(char number1[10], int line);
void dwData(char number1[20], int line);
void dhData(char number1[30], int line);
void ascizData(char word1[BUFSIZE -5 ], int line);
void R_opcode(int line, int code, int rg1, int rg2, int rg3);
void I_opcode(int line, int rg1, int rg2, int imm);
void J_opcode(int line, int rg1);


 /*functns.c function*/
 int skip_spaces(char line);
int isItSymbol(char sym);
int isItCommand(char com);
int isItData(char pro);
int isItReg(int regis1);
int isItLegalNumber(int num);
int addSymbol(char sym[70], int line, int option );
void cleanLists();

/*baseChange.c functions*/

int binToDecimal(char *bin);
char * decimalToBin(int num);
char *binaryToHex(char *binary, int length);

/*linkedList.c functions*/
void addNode(TypeR* newNode, TypeR** head);
void addNode(TypeI* newNode, TypeI** head);
void addNode(TypeJ* newNode, TypeJ** head);
int searchSymbolValue(symboList **head,char value[70]);
void addNode(TypeR* newNode, TypeR** head);
void addNode(TypeI* newNode, TypeI** head);
void addNode(TypeJ* newNode, TypeJ** head);


/*the SYMBOL LIST*/
/*This table accepts the symbols, it is divided so that in ATTRIBUTES,
 any number between 1 and 4 is a different database, and at the time of printing the number will become a string when:
1 - code line symbol
2 - entry line symbol
3 - extern line symbol
4 - data linesymbol*/ 
typedef struct symboList{
	
	int value;
	char symbol;
	int attributes{
	symboList *next;
}symboList;




/*node to define  R Data node*/
typedef struct TypeR{
	int IC_line_;
	char opCode_[7];
	char rg1_[6] ;
	char rg2_ [6];
	char rg3_ [6];	
	int func_;
	TypeR *next;
}TypeR;


/*node to define  I Data node*/
typedef struct TypeI{
	int IC_line_;
	char opCode_[7];
	char rg1_[6] ;
	char rg2_[6] ;
	char immVal_[THREE_BYTES];
	TypeI *next;
}TypeI;


/*node to define J Data node*/
typedef struct TypeJ{
	int IC_line_;
	char opCode_[7];
	char rg1_[2] ;
	TypeJ *next;
}TypeJ;









