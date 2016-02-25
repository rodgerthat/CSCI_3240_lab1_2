/********************************************************************
*
 * File : main.c
 * Author : Norris, Joel R.
 * Date : 2016_02_18
 * Class : CSCI_3240
* 
********************************************************************/

#include <stdio.h>
#include <stdlib.h>

int totalNumberOfBits;      // user input variable

// initialize variables
int UMin = 0;       // probably always.
int UMax = 1;
int TMin = 0;
int NegOne = -1;    // probably always.
int TMax = 0;

// char arrays for strings, in hex and binary
char UMax_strHex[32];
char UMax_strBin[32];
char UMin_strHex[32];
char UMin_strBin[32];
char TMin_strHex[32];
char TMin_strBin[32];
char NegOne_strHex[32];
char NegOne_strBin[32];
char TMax_strHex[32];
char TMax_strBin[32];

// function prototypes
void calcUMin_strHex(char *str);
void calcUMin_strBin(char *str);
int calcUMax(int totNumBits);
void calcUMax_strHex(int umax, char *str);
void calcUMax_strBin(char *str);
int calcTMin(int umax);
void calcTMin_strHex(int tmin, char *str);
void calcTMin_strBin(char *str);
void calcNegOne_strHex(char *str);
void calcNegOne_strBin(char *str);
int calcTMax(int umax);
void calcTMax_strHex(int tmax, char *str);
void calcTMax_strBin(char *str);
void decToHex(int dec, char *str);
void printResults();

int main() {
	
	// get user input
	printf("%s", "Please enter total number of bits:\n");
	scanf("%i", &totalNumberOfBits);

	// input validation, tyty CSCI_1170
	 while (totalNumberOfBits < 2 || totalNumberOfBits > 32) {
		printf("%s", "Input must be a number between 2 and 32\n\n");
		printf("%s", "Please enter total number of bits:");
		scanf("%i", &totalNumberOfBits);
	 }

    // calculate conversions for data
    //calcUMin  // lol nope.
    calcUMin_strHex(UMin_strHex);
    calcUMin_strBin(UMin_strBin);
    UMax = calcUMax(totalNumberOfBits);
    calcUMax_strHex(UMax, UMax_strHex);
    calcUMax_strBin(UMax_strBin);
    TMin = calcTMin(UMax);
    calcTMin_strHex(TMin, TMin_strHex);
    calcTMin_strBin(TMin_strBin);
    calcNegOne_strHex(NegOne_strHex);
    calcNegOne_strBin(NegOne_strBin);
    TMax = calcTMax(UMax);
    calcTMax_strHex(TMax, TMax_strHex);
    calcTMax_strBin(TMax_strBin);

    printResults();     // make it so.

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
 * calcUMin_strHex
 * create a string of characters that's a hexadecimal representation
 * of the unsigned minimum
 */
void calcUMin_strHex(char *str) {
    // moar shenanigans...
    int i;
    int bitDepthMimic = 0;
    if (totalNumberOfBits <= 8) { bitDepthMimic = 2;
    } else if (totalNumberOfBits <=16) { bitDepthMimic = 4;
    } else if (totalNumberOfBits <= 32) { bitDepthMimic = 8;
    } else {
        // do something
    }
    for( i=0; i<bitDepthMimic; i++){ str[i] = '0'; }
}

/**
 *  calcUMin_strBin
 *  create a string of characters that's a binary representation
 *  of the unsigned minimum
 */
void calcUMin_strBin(char *str) {
    //
    int i;
    for ( i=0; i < totalNumberOfBits; i++ ) {
        str[i] = '0';
    }
}

/**
 *  calcUMax
 *  calculate the Unsigned Maximum decimal integer
 *  that can be represented using a given number of bits
 *  uses bit shifting.
 */
int calcUMax(int totNumBits) {

    int umax = 1 << totNumBits;     // left shift by the total number of bits,
    umax--;                         // minus one, to account for 0
    return umax;
}

/**
 * calcUMax_strHex
 * convert UMax to hexadecimal string
 */
void calcUMax_strHex(int umax, char *str) {
    decToHex(umax, str);
}

/**
 *  calcUMax_strBin
 *  create string of characters to represent binary unsigned maximum
 */
void calcUMax_strBin(char *str) {
    //
    int i;
    for ( i=0; i < totalNumberOfBits; i++ ) {
        str[i] = '1';
    }
}

/**
 *  calcTMin
 *  calculate two's compliment minimum value
 */
int calcTMin(int umax) {
    int tmin = ( ( umax + 1 ) / 2 ) * -1;    // wonk.
    return tmin;
}


/**
 *  calcTMin_strHex
 *  create character array of hexadecimal representation of
 *  signed two's compliment minimum value
 */
void calcTMin_strHex(int tmin, char *str) {
    tmin *= -1;
    decToHex(tmin, str);    // nothing to see here, move along.
}

/**
 *  calcTMin_strBin
 *  create char array of binary representation
 *  of signed two's compliment minimum value
 */
void calcTMin_strBin(char *str) {
    // I'm only cheating myself :(
    int i;
    for ( i=0; i < totalNumberOfBits; i++ ) {
        if (i==0) str[i] = '1';
        else str[i] = '0';
    }
}

/**
 * calcNegOne_strHex
 * create ... wait a min. that's going to be the same all the time.
 * printf("%s", ftw");
 */
void calcNegOne_strHex(char *str) {

}

/**
 * calcNegOne_strBin
 * create char array of binary representation for -1
 */
void calcNegOne_strBin(char *str) {
    int i;
    for ( i=0; i < totalNumberOfBits; i++ ) {
        str[i] = '1';
    }
}

/**
 *  calcTMax
 *  signed maximum two's compliment, always half of unsigned maximum
 */
int calcTMax(int umax) {
    int tmax = umax / 2;
    return tmax;
}

/**
 *  calcTMax_strHex
 *  create hexadecimal string representation of two's compliment maximum
 */
void calcTMax_strHex(int tmax, char *str) {
    decToHex(tmax, str);
}

/**
 * calcTMax_strBin
 * create char array of binary representation of two's compliment maximum
 */
void calcTMax_strBin(char *str) {

    // I'm only cheating myself :(
    int i;
    for ( i=0; i < totalNumberOfBits; i++ ) {
        if (i==0) str[i] = '0';
        else str[i] = '1';
    }
}



/**
 *  decToHex
 *  where the magic happens.
 *  thx whoever wrote sprintf for handling signed integers.
 */
void decToHex(int dec, char *str) { sprintf( str, "%X", dec); }

/**
 * printResults()
 * prints out the results according to the spec
 */
void printResults() {

    printf("totalNumBits : %i\n ", totalNumberOfBits);

    //printf("sizeof(unsigned int) : %lu \n", sizeof(unsigned int) );

    printf("For %i bits:\n", totalNumberOfBits);
    printf("Number\tDecimal\tHex\tBinary\n");
    printf("UMin\t%i\t0x%s\t%s\n", UMin, UMin_strHex, UMin_strBin );
    printf("UMax\t%i\t0x%s\t%s\n", UMax, UMax_strHex, UMax_strBin);
    printf("TMin\t%i\t0x%s\t%s\n", TMin, TMin_strHex, TMin_strBin);
    printf("-1\t%i\t0x%s\t%s\n", NegOne, UMax_strHex, NegOne_strBin);
    printf("TMax\t%i\t0x%s\t%s\n", TMax, TMax_strHex, TMax_strBin);

}

