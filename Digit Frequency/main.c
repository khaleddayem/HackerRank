/************************************************************************************************
* Author Name           : Khaled Abdeldayem

* Author Email          : kh.dayem@gmail.com

* Author github         : https://github.com/khaleddayem

* Problem Description   : Given a string,consisting of alphabets and digits, 
                          find the frequency of each digit in the given string.

* Problem Link          : https://www.hackerrank.com/challenges/frequency-of-digits-1/problem?isFullScreen=true

************************************************************************************************/

/* INCLUDE SECTION */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/* MACRO SECTION */

#define MAX_DIGIT 10
#define ASCII_OF_0 48

/* MAIN BODY */

int main(){
    char* str;
    int iter=0;                             /* Used for printing the Freq array LOOP */
	int freq[MAX_DIGIT]={0};                       /* Creating an Array of 0's for the freq */
	
    str=malloc(1024 * sizeof(char));        /* Allocating memory for the string */
    scanf("%s",str);					    /* Scanning the string from the user */
    str=realloc(str, strlen(str) + 1);      /* Reallocating the memory to free Unused memory */
    while(*str!='\0')                       /* Looping through the string till the null char */
    {
        
        freq[*str-ASCII_OF_0]++;			/* Converting the numbers of Char to int by subtracting the ascii of zero (48) */
        str++;								/* incrementing the value in the corresponding index to the number in string */
    }
    for(iter=0;iter<MAX_DIGIT;iter++)       /* looping to print the array */
    {
        printf("%d ",freq[i]);
    }
    return 0;
}
