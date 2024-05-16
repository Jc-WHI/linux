#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

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
    return 0;



}