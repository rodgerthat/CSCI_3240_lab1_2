/********************************************************************
*
* File : main.c
* Author : Norris, Joel R. 
* Date : 
* 
********************************************************************/
#include <stdio.h>
#include <stdlib.h>

int totalNumBits;

int int1 = 00;
int int2 = 000000;

int UMin = 0;       // probably always.
int UMax = 1;
int TMin = 0;
int NegOne = -1;
int TMax = 0;

char UMax_strHex[8];
char UMax_strBin[8];
char UMin_strHex[8];
char UMin_strBin[8];
char NegOne_strHex[8];
char NegOne_strBin[8];
char TMin_strHex[8];
char TMax_strBin[8];
char TMax_strHex[8];
char TMax_strBin[8];


void decToHex(int dec, char *str);
void calcUMin_strHex(char *str);
void calcUMin_strBin(char *str);
void calcUMax_strHex(char *str);
void calcUMax_strBin(char *str);
void printResults();

int main() {
	
	// get user input
	printf("%s", "Please enter total number of bits:");
	scanf("%i", &totalNumBits);

	// input validation
	 while ( totalNumBits < 2 || totalNumBits > 32) {
		printf("%s", "Input must be a number between 2 and 32\n\n");
		printf("%s", "Please enter total number of bits:");
		scanf("%i", &totalNumBits);
	 }

    calcUMax(totalNumBits);

    printf("UMax: %d\n", UMax);

	decToHex(UMax, UMax_strHex);
    calcUMin_strHex(UMin_strHex);
    calcUMin_strBin(UMin_strBin);
    calcUMax_strBin(UMax_strBin);
    calcTMin_strHex(TMin_strHex);

    printf("str_hex : 0x%s\n", UMax_strHex);

    printResults();

	/**
	Please enter the total number of bits: 

	For 5 bits:
	Number	Decimal	Hex	Binary
	UMin	0	0x00	00000
	UMax	31	0x1F	11111
	TMin	-16	0x10	10000
	-1	    -1	0x1F	11111
	TMax	15	0x0F	01111

	Please enter the number of exponent bits: 
	...
	**/




	/**
	Please enter the total number of bits: 

	For 32 bits:
	Number	Decimal	Hex	Binary
	UMin	0	0x00000000	00000000000000000000000000000000
	UMax	0	0x00000000	00000000000000000000000000000000
	TMin	-2147483648	0x80000000	10000000000000000000000000000000
	-1	-1	0xFFFFFFFF	11111111111111111111111111111111
	TMax	2147483647	0x7FFFFFFF	01111111111111111111111111111111

	Please enter the number of exponent bits: 
	...
	**/

	return 0;

}

/**
 *
 */
int calcUMax(int totalNumBits) {

    // calc UMax, ( 2 to the power of n ) - 1
    int umax;
    int i;
    for ( i=1; i <= totalNumBits; i++ ) { umax *= 2; }
    umax--;

    return umax;
}

/**
 *
 */
void calcUMin_strHex(char *str) {

}

/**
 *
 */
void calcUMin_strBin(char *str) {
    //
    int i;
    for ( i=0; i<totalNumBits; i++ ) {
        str[i] = '0';
    }
}

void calcUMax_strBin(char *str) {
    //
    int i;
    for ( i=0; i<totalNumBits; i++ ) {
        str[i] = '1';
    }
}

/**
 *
 */
void calcTMin_strHex(char *str) {
    //UMax / 2, * -1

}

/**
 *
 */
void calcTMin_strBin(char *str) {
    //
    int i;
    for ( i=0; i<totalNumBits; i++ ) {
        if (i==0) str[i] = '1';
        else str[i] = '0';
    }
}

/**
 *
 */
void decToHex(int dec, char *str) { sprintf( str, "%X", dec); }

/**
 *
 */
void printResults() {

    printf("totalNumBits : %i\n ", totalNumBits );

    //printf("sizeof(unsigned int) : %lu \n", sizeof(unsigned int) );

    printf("For %i bits:\n", totalNumBits);
    printf("Number\tDecimal\tHex\tBinary\n");
    printf("UMin\t%i\t0x%s\t%s\n", UMin, UMin_strHex, UMin_strBin );
    printf("UMax\t%i\t0x%s\t%s\n", UMax, UMax_strHex, UMax_strBin);
    printf("TMin\t%i\t0x%s\t%s\n", TMin, TMin_strHex, TMax_strBin);
    printf("-1\t%i\t0x%s\t%s\n", NegOne, NegOne_strHex, NegOne_strBin);
    printf("TMax\t%i\t0x%s\t%s\n", TMax, TMax_strHex, TMax_strBin);

}

