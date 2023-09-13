/************************************************************************************************
* Author Name           : Khaled Abdeldayem

* Author Email          : kh.dayem@gmail.com

* Author github         : https://github.com/khaleddayem

* Problem Description   : You are given  triangles, specifically, their sides ,
			  Print them in the same style 
			  but sorted by their areas from the smallest one to the largest one. 

* Problem Link          : https://www.hackerrank.com/challenges/small-triangles-large-triangles

************************************************************************************************/
/* INCLUDE SECTION */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Struct Declaration */
struct triangle
{
	int a;
	int b;
	int c;
};

/* Making type triangle of struct triangle */
typedef struct triangle triangle;

/* Sort an array a of the length n */
void sort_by_area(triangle* tr, int n) {

    /* Used to iterate through the loops */
    int i,j;
	
    /* S is an array to store the AREAS */
    /* You can find the math formulas in the problem page */
    double *s,p=0;
	
    /* Using calloc to make a dynamic array of zeros */
    s=(double*)calloc(n, sizeof(double));
	
    /* Used for swapping */
    triangle temp;
	
    /* Loop to calculate the areas of the given triangles in the S array */
    for(i=0;i<n;i++)
    {
        p=(tr[i].a+tr[i].b+tr[i].c)/2.0;
        s[i]=sqrt(p*(p-tr[i].a)*(p-tr[i].b)*(p-tr[i].c));
    }
	
    /* Simple Bubble sort */
    for(i = 0; i < n ; ++i)
    {
        for(j = i+1; j < n; ++j)
        {
            if(s[i] > s[j] )
            {
                temp = *(tr + i);
                *(tr + i) = *(tr + j);
                *(tr + j) = temp;
                
            }
        }
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
