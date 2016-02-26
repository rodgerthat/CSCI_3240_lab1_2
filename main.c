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

int n;                      // user input variable for total number of bits
int binArray[32] = {0};     // array of intergers for decimal / binary conversion

// initialize variables
int UMin = 0;       // probably always.
int UMax = 1;
int TMin = 0;
int NegOne = -1;    // always.
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
void printFloatingPointResults();
void intToBinArray(int dec, int *binArray);

int main() {
	
	// get user input
	printf("%s", "Please enter total number of bits:\n");
	scanf("%i", &n);

	// input validation, tyty CSCI_1170
	 while (n < 2 || n > 32) {
		printf("%s", "Input must be a number between 2 and 32\n\n");
		printf("%s", "Please enter total number of bits:");
		scanf("%i", &n);
	 }

    // calculate conversions for data
    //calcUMin  // lol nope.
    calcUMin_strHex(UMin_strHex);
    calcUMin_strBin(UMin_strBin);
    UMax = calcUMax(n);
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
    printFloatingPointResults();

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
    if (n <= 8) { bitDepthMimic = 2;
    } else if (n <= 16) { bitDepthMimic = 4;
    } else if (n <= 32) { bitDepthMimic = 8;
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
    for ( i=0; i < n; i++ ) {
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
    for ( i=0; i < n; i++ ) {
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
    for ( i=0; i < n; i++ ) {
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
    for ( i=0; i < n; i++ ) {
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
    for ( i=0; i < n; i++ ) {
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

    printf("totalNumBits : %i\n ", n);

    //printf("sizeof(unsigned int) : %lu \n", sizeof(unsigned int) );

    printf("For %i bits:\n", n);
    printf("Number\tDecimal\tHex\tBinary\n");
    printf("UMin\t%i\t0x%s\t%s\n", UMin, UMin_strHex, UMin_strBin );
    printf("UMax\t%i\t0x%s\t%s\n", UMax, UMax_strHex, UMax_strBin);
    printf("TMin\t%i\t0x%s\t%s\n", TMin, TMin_strHex, TMin_strBin);
    printf("-1\t%i\t0x%s\t%s\n", NegOne, UMax_strHex, NegOne_strBin);
    printf("TMax\t%i\t0x%s\t%s\n", TMax, TMax_strHex, TMax_strBin);

}

/**
 * calcBias
 * Bias = (2^(k-1)) - 1
 * k = total number of exponent bits
 */
int calcBias(int totNumExpBits) {

    int bias = ( 1 << (totNumExpBits - 1) ) - 1;     // left shift by the total number of bits,
    return bias;
}

/**
 * intToBinArray
 * convert a dec int into binary int array
 */
void intToBinArray(int dec, int *binArray) {

    int q = dec;  // quotient
    int r=0;
    int i=0;

    // init array
    for (i=0; i<sizeof(binArray); i++) binArray[i] = 0;

    // calc bin int rep of dec int
    // divide dec / 2, get modulus and assign to array
    // continue to divide quotient by 2 until 0 is reached.
    i = 0;
    while ( q != 0 ) {
        r = q % 2;
        binArray[i] = r;
        q = q / 2;
        i++;
    }

    // tried getting schifty. didn't go so well.
    //int i;
    //for (i=0; i<sizeof(dec); i++) {

    //    dec = dec >> 1;
    //    if ( dec & 1 ) str[i] = '1';
    //    else str[i] = '0';
    //}

}

/**
 * printBinArray
 * loop through the binary array and print out each integer
 * restricted with number of bits
 */
void printBinArray(int *binArray, int numBits) {

    int i;

    // loop through array, printf each int,
    for (i=numBits-1; i>=0; i--) {
        printf("%i", binArray[i]);   // print binary string
    }
    printf(" ");
}


/**
 *
 */
void printFloatingPointResults() {
    // V = (-1)^s * m * 2^E

    int j;      // number of fraction bits
    int k;      // number of exponent bits
    int b;      // the bias
    int e;      // value of exp
    int f;      // value of frac
    int E;      // E
    float fV;   // fV
    float M;    // M
    float V;    // the Value

    printf("%s", "Please enter the number of exponent bits:\n");
    scanf("%i", &k);

    // calc num frac bits
    j = (n - k) - 1;     // -1 for the Signed Bit

    printf("Positive floating point values for %i Exp bits and %i Frac bits:\n", k, j);
    printf("%s", "S Exp Frac Value\n");
    int eMax = (1 << k) - 1;
    int fMax = (1 << j) - 1;

    // loop thru exp bits
    for ( e=0; e<=eMax; e++) {

        // loop thru frac bits
        for (f=0; f<=fMax; f++) {

            printf("%s", "0 ");     // signed bit.

            intToBinArray(e, binArray);
            printBinArray(binArray, k);
            //printf("%i ", e );

            intToBinArray(f, binArray);
            printBinArray(binArray, j);
            //printf("%i ", f );

            // check special cases

            if ( e == eMax && f == 0 ) {
                //if ( e == 0 && frac == 0 )
                // V = inf;
                printf("inf");
            } else if ( e == eMax ) {
                //if ( e == (2^k)
                // V == NaN
                printf("NaN");
            } else if ( e != 0 && e != eMax) {
                // if ( e != 0 && e != 2^k )
                //NORMALIZED
                // calc bias    (2^(k-1))-1
                b = ( 1 << (k - 1) ) - 1;     // left shift by the total number of bits,
                // calc E       e - bias
                E = e - b;
                // calc fV      f / 2^j
                //fV = f / ( 1<<j );
                fV = (float)f / ( 1<<j );
                // calc M
                M = 1.00 + fV;
                printf("%f", M);
                // calc V
                V = (float)(1<<E) * M;
                //printf("%f", V);
            } else {
                // well, by now it must be denormalized then
                // DENORMALIZED
                // calc bias    (2^(k-1))-1
                // calc E       1 - bias
                // calc V

                // calc V
                //printf("%f", V);
                printf("DENORMALIZED");
            }

            printf("\n");
        }


    }

}


