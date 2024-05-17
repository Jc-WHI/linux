#include<stdio.h>
#include<stdlib.h>

typedef struct Node *node; 
struct Node{
    int data;
    node next;
}*head,*tail,*list;

void init(){

    head->data = 0;
    head->next = tail;
    tail-> data = NULL;
    tail->next = NULL;

    
}

void add(int a){
    if(head->data==NULL){
        head->data = 0;
        head->next = tail;
        tail->next = NULL;
    }
    head -> next = list;
    list->data = a;
    tail -> next = NULL;
    list->next = list;

}
int main(){
    node head;
    node tail;
    list = malloc(sizeof(node));
    void init();
    int num = 10;
    void add(num);



}



