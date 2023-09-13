/************************************************************************************************
* Author Name           : Khaled Abdeldayem

* Author Email          : kh.dayem@gmail.com

* Author github         : https://github.com/khaleddayem

* Problem Description   : handle requests which come in the following forms:
						  1 x y : Insert a book with  pages at the end of the  shelf.
						  2 x y : Print the number of pages in the  book on the  shelf.
						  3 x   : Print the number of books on the  shelf.

* Problem Link          : https://www.hackerrank.com/challenges/dynamic-array-in-c

************************************************************************************************/

/* INCLUDE SECTION */
#include <stdio.h>
#include <stdlib.h>

/* This stores the total number of books in each shelf. */
int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int** total_number_of_pages;

 /* MAIN BODY */
int main()
{
	int total_number_of_shelves;

	/* Scanning the number of Shelves */
    scanf("%d", &total_number_of_shelves);    
    
    int total_number_of_queries;
	
	/* Scanning the number of queries */
    scanf("%d", &total_number_of_queries);
    
	/* init an array for books */
    total_number_of_books=(int*)malloc(sizeof(int)*total_number_of_shelves);   
    
	/* allocate memory for a 2D array of shelves and books */
    total_number_of_pages=(int**)malloc(sizeof(int*)*total_number_of_shelves); 
    /* Loop to set the array of number of books to 0 && make the 2D dynamic array */
    for(int i=0; i<total_number_of_shelves; i++)  
	{
		/* Setting number of books on each shelf to 0 */
        total_number_of_books[i]=0;
		/* Making the 2D dynamic Array of books and shelves */
        total_number_of_pages[i]=(int*)malloc(sizeof(int));
    }
    
    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) 
		{
            int x, y;
			
			/* X is shelf number and Y is number of pages */
            scanf("%d %d", &x, &y);
			
			/* Increment the book count on the Xth shelf */
            *(total_number_of_books+x)+=1;
			
			/* Resizing the array of pages to dynamically allocate memory for the added book */
            *(total_number_of_pages+x)=realloc(*(total_number_of_pages+x), *(total_number_of_books+x)*sizeof(int));
			
			/* Putting the number of pages on the Xth shlef & the new book location */
            *(*(total_number_of_pages+x)+*(total_number_of_books+x)-1)=y;

        
        } else if (type_of_query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
    
    return 0;
}