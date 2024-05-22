#include<stdio.h>
#include<stdlib.h>

//1. 단순 링크드 리스트 구현

typedef struct Node{
    int data;
    struct Node *next;
}Node;

void insert(Node **head, int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode; // newNode가 첫번째 노드가 됨.
}

void printlist(Node *head){
    Node *curruent = head;
    while(curruent !=NULL){
        printf("%d",curruent->data);
        curruent = curruent->next;
    }
    printf("end");
}


int main() {
    Node *head = NULL;
    insert(&head,1);
    insert(&head,5);
    printlist(head);
}