#include<stdio.h>
#include<stdlib.h>

struct Node {
    int key;
    struct Node *next;
};
struct Node *head,*z,*t;


void init() {
    head = (struct Node*)malloc(sizeof(*head));
    z = (struct Node*)malloc(sizeof(*z));
    head->next = z;  // head 
    z->next = z;
    

}
void delete(struct Node *t){

    t->next = t->next->next;
}

void insert(int v, struct Node *t){
    struct Node *x;
    x = (struct Node*)malloc(sizeof(*x));
    x->key = v; x->next = t->next;
    t->next = x;
}
void printlist(struct Node *head){
    struct Node *current = head-> next;
    while(head->next != NULL){
        printf("%d",current->key);{
            current = current->next;
        }
    }
}

int main(){
    init();
    insert(5,head);
    free(head);
    printlist(head);
}

