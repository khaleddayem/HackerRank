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
#include <stdlib.h>
#include <string.h>
#include <assert.h>
/* MACRO SECTION */
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
     return document[n-1][m-1][k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
    return document[m-1][k-1];

}

char*** kth_paragraph(char**** document, int k) {
    return document[k-1];

}
/* FUNCTION TO SPLIT A STRING WITH A DELIM KEY */
char** split_string(char* text, char Key) {
    char** result = malloc(1*sizeof(char*));
    int size = 1;

    /* strtok split the string using the delim given */
    char* temp = strtok(text, &Key);

    /* Store the word after splitting */ 
    *result = temp;
    
    /* While the String didnt end */
    while(temp != NULL) {
        size++;     /* Increase the size of the result array */
        result = realloc(result,size*sizeof(char*));  /* Resize it using the variable size */
        temp = strtok(NULL, &Key);                    /* Calling strtok again gives us the second word till delim key occur */
        result[size-1] = temp;                        /* Store the new word into the result array */
    }
    return result;
}


char**** get_document(char* text) {
    
    // split text by '\n' and count number of paragraphs
    char** paragraphs = split_string(text, '\n');
    int no_par = 0;
    while (paragraphs[no_par] != NULL) {
        no_par++;
    }
    char**** doc = malloc((no_par+1)*sizeof(char***));
    // set last position to NULL
    // to know when the array ends.
    doc[no_par] = NULL; 
    
    int i = 0;
    while (paragraphs[i] != NULL) {
        
        // split sentences of paragraph by '.' and count number of sentences
        char** sentences = split_string(paragraphs[i], '.');
        int no_sen = 0;
        while(sentences[no_sen] != NULL) {
            no_sen++;
        }
        
        doc[i] = malloc((no_sen+1)*sizeof(char**));
        // set last position to NULL
        // to know when the array ends.
        doc[i][no_sen] = NULL; 
        
        int j = 0;
        while (sentences[j] != NULL) {
            
            //doc[0][0] means: paragraph #0,sentence #0
            // split each sentence in each parahraph by " "
            // with the array of strings representing words
            doc[i][j] = split_string(sentences[j], ' ');
            j++;
        }
        i++;
    }
    
    return doc;

}


char* get_input_text() {    
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}