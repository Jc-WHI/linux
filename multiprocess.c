#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
typedef struct Node {
    int data;
    struct Node* next;
}Node;


int main(){
    int i, ret,status;
    pid_t pid;
    for (i = 0; i < 5; i++){
        pid = fork();
        if (pid<0){
            printf("fork error");
            exit(1);
        }
        else if (pid == 0){
            printf("forked\n");
            
            return 0;

        }
    }
    for (i = 0; i<5; i++){
        pid = wait(&status);

        if (pid == -1){
            perror("wait failed");
        }
        if (WIFEXITED(status)){
            printf("%d,%d\n",pid,WEXITSTATUS(status));

        }

    }


    

    struct Node *head = malloc(sizeof(struct Node));
    struct Node *tail;
    head->data = 1;
    tail->data = NULL;
    tail->next = NULL;
    head->next = tail;
    
    add(head,10);

    printf("%d",head->data);
    return 0;
    
}



struct Node {
    int data;
    struct Node* next;
};

void add(struct Node* node, int n) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = n;
    newNode->next = node->next;
    node->next = newNode;
}





