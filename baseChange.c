#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>
#include <stddef.h>






/*Converts the number from a binary base to a decimal base*/
int binToDecimal(char *bin){
    int i;
    int num=0;

    for (i=9;i>-1;i--){
        num+=pow(2,9-i)*(bin[i]-'0');
    }
    if(bin[0]=='1')
        return 0-(pow(2,10)-num);
    return num;
}

/*Converts the number from a decimal base to a binary base*/
char * decimalToBin(int num){
    unsigned int i=0,abs = num;
    int j;
    char temp;
    char * bin = (char *)malloc(11* sizeof(char));
    if (!bin)
        printf(stderr,"\nERROR - Dynamic allocatio error");
    while(i<10){
        bin[i]= abs%2+'0';
        abs=abs/2;
        i++;
    }
    for (j=0;j<5;j++){
        temp = bin[9 - j];
        bin[9 - j] = bin[j];
        bin[j] = temp;
    }    
    bin[10] = '\0';
    return bin;
    

/*Converts the number from a binary base to a hexadecimal base*/    
     char *binaryToHex(char *binary, int length)
    {
        int i;
        char *hex;
        char *paddedBinary = padBinary(binary, length);
        int hexLength = strlen(paddedBinary) / 4; /* We need one hex symbol for every 4 binary symbols */
        hexLength = hexLength + hexLength/2 + 1; /* Make place for a space after every two symbols + the null terminater*/
        hex = (char *)malloc(hexLength);
        if(hex == NULL)
            exit(1);
        for(i = 0; i < length; i += 8)
        {
            char halfByte[5];
/* copy the 4 binary digits and decode them to one hex digit */
            memcpy(halfByte, paddedBinary, 4);
            halfByte[4] = '\0';
            *hex++ = valueOf(halfByte);
            paddedBinary += 4;

            memcpy(halfByte, paddedBinary, 4);
            halfByte[4] = '\0';
            *hex++ = valueOf(halfByte);
            paddedBinary += 4;

            *hex++ = ' ';
        }
        *hex = '\0';
        hex -= hexLength - 1;
        return hex;
    }













