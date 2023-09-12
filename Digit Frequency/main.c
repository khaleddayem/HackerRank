#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    char* str;
    int i=0;
    str=malloc(1024 * sizeof(char));
    scanf("%s",str);
    str=realloc(str, strlen(str) + 1);
    int freq[10]={0};
    while(*str!='\0')
    {
        
        freq[*str-48]++;
        str++;
    }
    for(i=0;i<10;i++)
    {
        printf("%d ",freq[i]);
    }
    return 0;
}
