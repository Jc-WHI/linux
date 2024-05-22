#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(){
    char str[100001];
    scanf("%100000s",str);
    for (int i = 0; i < strlen(str); i++){
        struct str *new_string = (*str)malloc(sizeof(str));
    }

    

}


typedef struct {
    char ch;
    struct str *prev;
    struct str *next;

}str;


