#include<stdlib.h>
#include<stdio.h>
struct Node{
    int *a;
    struct Node *next;

}*head,*next;
int main(){
    init();
    add(5);
    search();

}


void init(){
    //this is for *head and *next
    struct Node *head = (struct Node*)malloc(sizeof(*head));
    struct Node *next = (struct Node*)malloc(sizeof(*next));
    head->a = 0;
    head->next = next;
    next->next = next;

}
void add(int value){
    struct Node* newNode;
    if(head!=NULL){
    head -> a = value;
    head->next = newNode->next;
    newNode->next = next;
    next->next = next;
    }
}

void search(){
    struct Node *current;
    int cnt;
    current->a = head->a;
    current->next = head->next;
    while(next->next == next){
        current->a = next->a;
        current->next = next->next->next;
        printf("%d",current->a);
    cnt++;
    }
}

//result : Segmentation Fault

