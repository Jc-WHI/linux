#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define process_num 5

 struct Process  {
    int id;
    int priority;
    int burstTime;
    int waitingTime;
    int turnaroundTime;


}*process;
typedef struct Node {
    struct Process *process;
    struct Node* next;
}*Node;


int main(){
    int i, pid_num,status;
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


    

    
}

void addqueue(struct Node *Node,struct Process *process){
    Node->process = &process;
    int *a;
    a = malloc(sizeof(Node))
    


}










