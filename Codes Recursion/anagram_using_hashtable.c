#include<stdio.h>
#include<string.h>

int main(){

    char *a="decimal";
    char *b="medicel";
    int hash[26]={0},i;
    for ( i = 0; i < a[i]!='\0'; i++)
    {
        hash[a[i]-97]++;
    }
    for ( i = 0; b[i]!='\0'; i++)
    {
        hash[b[i]-97]--;
        if(hash[b[i]-97]-- <0){
            printf("Not Anagram");
            break;
        }
    }
    if(b[i]=='\0')
    printf("Anagram");
    
    



    return 0;
}