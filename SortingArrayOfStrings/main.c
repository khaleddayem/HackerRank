/************************************************************************************************
* Author Name           : Khaled Abdeldayem

* Author Email          : kh.dayem@gmail.com

* Author github         : https://github.com/khaleddayem

* Problem Description   : Given an array of strings, 
						  you need to implement a function which sorts the strings according to a comparison function,

* Problem Link          : https://www.hackerrank.com/challenges/sorting-array-of-strings/

************************************************************************************************/

/* INCLUDE SECTION */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* LEXICOGRAPHIC SORT IS DONE STRCMP FUNCTION IN STRING.H */
int lexicographic_sort(const char* a, const char* b) {
    return (strcmp(a,b));

}

/* WE REVERSE IT BY PASSING THE ARGUMENTS BACKWARDS */
int lexicographic_sort_reverse(const char* a, const char* b) {
    return (strcmp(b,a));
}

/* INSTEAD OF CALCULATIN THE NUMBER OF DISTINCT CHAR'S FOR EACH STRING */
/* IT'S EASIER TO MAKE A FUNCTION THAT COUNT THEM AND PASS THE STRINGS ONE BY ONE */
int characters_count(const char *s){
	/* N IS THE NUMBER OF DISTINCT CHARACHTERS */
    int n = 0;
	
	/* ARRAY OF ZEROS WILL WORK AS A FLAG FOR EACH CHARACHTERS */
    int count[128] = {0};
	
    while(*s != '\0'){
		/* IF THE CORRESPONDING INDEX WITH CHAR ASCII IS EQUAL TO 0 THAT MEAN THIS CHAR IS NEW */
		/* IF IT EQUAL TO 1 THAT MEAN THIS CHAR OCCURED BEFORE */
        if (!count[*s])
		{
			/* INCREMENT THE CORRESPONDING INDEX WITH CHAR ASCII */
            count[*s]++;
			
			/* INCREMENT DISTINCT CHAR NUMBER */
            n++;
        }
        s++;
    }
    return n;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b){
	/* CON IS THE DIFFERENCE IN DISTINCT CHAR NUMBER */
    int con = characters_count(a) - characters_count(b);
	
	/* IF EQUAL THAT MEAN THEY HAVE THE SAME DISTINCT CHAR NUMBER AND WE RETURN LEXICOGRAPHIC SORT */
    return (con ? con : lexicographic_sort(a, b));
}

/* FUNCTION TO SORT STRINGS BY THEIR LENGTH */
int sort_by_length(const char* a, const char* b) {
    int leen=strlen(a)-strlen(b);
if (strlen(a)!=strlen(b))
        return leen;
   else
        return strcmp(a,b)>0;
}

/* WE GIVE THIS FUNCTION 3 ARGUMENTS */
/* 1- AN ARRAY OF THE STRINGS WE WANT TO SORT (2D ARRAY) */
/* 2- THE LENGTH WHICH IS EQUAL TO NUMBER OF STRINGS WE WANT TO SORT */
/* 3- THE SORTING METHOD WHICH IS PASSED AS A CALL BACK FUNCTION */
void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
	/* SORTED FLAG TO BREAK THE LOOP WHEN SORTED */
	int sorted = 0;
    int top = len - 1;
    while (!sorted) 
	{
        sorted = 1;
		/* SIMPLE BUBBLE SORT LOOP */
        for (int i = 0; i < top; i++) 
		{
			/* CHECK IF THE 2 STRINGS ARE THE SAME WE SKIP SORTING THEM */
            if (cmp_func(arr[i], arr[i + 1]) > 0) 
			{
                char *tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                sorted = 0;
            }
        }
        top--;
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}