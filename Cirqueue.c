#include<stdlib.h>
#include<stdio.h>
#define size 3

typedef struct {
    int front,rear;
    int item[3]
}cqueue;


void init(cqueue *c){
    c->front = -1;
    c->rear = -1;

}
int isEmpty(cqueue *c){
    return c->front==-1;
}

int isFull(cqueue *c){
    return (c->rear+1) % size == c->front;
}

int enqueue(cqueue *c, int var){
    if(isFull(c)){
        printf("Queue is Full\n");
        return;
    }
    if(isEmpty(c)){
        c->front = 0;
    }
    c->rear = (c->rear+1) % size;
    c->item[c->rear] = var;



}

int dequeue(cqueue *c){

}





int main(){

}