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

char str_hex[8];

void decToHex(int dec, char *str);
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



    // calc UMax, ( 2 to the power of n ) - 1
    int i;
    for ( i=1; i <= totalNumBits; i++ ) { UMax *= 2; }
    UMax--;

    printf("UMax: %d\n", UMax);

	decToHex(UMax, str_hex);

    printf("str_hex : 0x%s\n", str_hex);

    printResults();

	/**
	Please enter the total number of bits: 

	For 5 bits:
	Number	Decimal	Hex	Binary
	UMin	0	0x00	00000
	UMax	31	0x1F	11111
	TMin	-16	0x10	10000
	-1	-1	0x1F	11111
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
void decToHex(int dec, char *str) { sprintf( str, "%X", dec); }

/**
 *
 */
void printResults() {

    printf("totalNumBits : %i\n ", totalNumBits );

    printf("sizeof(unsigned int) : %lu \n", sizeof(unsigned int) );

    printf("For %i bits:\n", totalNumBits);
    printf("Number\tDecimal\tHex\tBinary\n");
    printf("UMin\t0\t0x00\t000000\n");
    printf("UMax\t%i\t0x%s\t111111\n", UMax, str_hex);

}

