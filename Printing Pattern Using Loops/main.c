#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
    /* if we draw the pattern we can see the number of cloumns and rows is equal to 2*n-1 */
    int rows=2*n-1;
    /* THE IDEA THAT WE HAVE 4 CONDITIONS */
    /* 1- SUBTRACTING COLUMN INDEX FROM THE NUMBER (n - j) */
    /* 2- SUBTRACTING COLUMN INDEX FROM THE RIGHT SIDE FROM THE NUMBER (n - 1 - j) */
    /* 3- SUBTRACTING ROW    INDEX FROM THE NUMBER (n - i) */
    /* 4- SUBTRACTING ROW    INDEX FROM THE RIGHT SIDE FROM THE NUMBER (n - 1 - i) */
    /* WE USE THE SMALLEST VALUE OF THEM */
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<rows; j++){
            int min;
            /* return the smaller value between col and index value */
            min =i<j? i:j;

            /* check if row index from the opposite side is smaller than normal index */
            min = rows-1-i < min? rows-1-i:min;

            /* check if col index from the opposite side is smaller than normal index */
            min = rows-1-j <min ? rows-1-j:min;

            /* print the number - the samllest value of them */
            printf("%d ",n-min); /* we can use ====printf("%c",'a'+min);==== to print with alphabet */
        }printf("\n");
    }
return 0;}
