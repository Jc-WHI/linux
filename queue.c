#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct {
    int items[SIZE];
    int front, rear;
} CircularQueue;

void initQueue(CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(CircularQueue* q) {
    return q->front == -1;
}

int isFull(CircularQueue* q) {
    return (q->rear + 1) % SIZE == q->front;
}

void enqueue(CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % SIZE;
    q->items[q->rear] = value;
}

int dequeue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % SIZE;
    }
    return value;
}

void printQueue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    int i = q->front;
    while (i != q->rear) {
        printf("%d -> ", q->items[i]);
        i = (i + 1) % SIZE;
    }
    printf("%d\n", q->items[i]);
}

int main(){
    CircularQueue queue;
    initQueue(&queue);
    enqueue(&queue,5);
    printQueue(&queue);

}