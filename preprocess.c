#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char name[3];
    int arr_time;
    int work_time;
    int ret_time;
    int waiting_time;
    int pri_index;
    Node *next;



}Node;

typedef struct {
    char name[5];
    int start_time;
    int end_time;
    int pri_index;
    struct gantt *next;
    
}gantt;



int main(){
    gantt *head = NULL;

}

void add(gantt **head,char name[5], int arr_time, int work_time,int pri_index){
  gantt *new_gantt =  (gantt*)malloc(sizeof(gantt));
  new_gantt->start_time = arr_time;
  new_gantt->end_time = work_time;
  new_gantt->pri_index = pri_index;
  new_gantt->next = *head;
  *head = new_gantt;
while(new_gantt->next == NULL){
    if (new_gantt->pri_index > (*head)->pri_index){
        *head = new_gantt;
    }
    else{
        (*head)->next = new_gantt; //gantt 정렬
    }
}




    
    

}

