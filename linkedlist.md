#링크드리스트 C로 구현

1) 구조체를 통한 정의
typedef struct Node{
    int data; // for value
    Node *next; // 포인터 -> 다음 노드를 가르키는 포인터
};

2) 동적 리스트 : 여기다 덧붙여서 연결리스트를 구현함

---

문제는 1) 포인터와 2) 동적리스트 부분의 선언
그리고 기초 연산의 구현임.

#include <stdlib.h>
#include <stdio.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to add a new node after the given node
void add(struct Node* node, int n);

int main() {
    // Allocate memory for the head node and initialize it
    struct Node *head = malloc(sizeof(struct Node));
    if (head == NULL) {
        perror("malloc failed");
        return 1;
    }
    head->data = 1;
    head->next = NULL;

    // Allocate memory for the tail node and initialize it
    struct Node *tail = malloc(sizeof(struct Node));
    if (tail == NULL) {
        perror("malloc failed");
        free(head); // Free previously allocated memory before exiting
        return 1;
    }
    tail->data = 0;  // Assuming you want to initialize it with some value
    tail->next = NULL;
    head->next = tail;

    // Add a new node with data 10
    add(head, 10);

    // Print the linked list to verify the add function
    struct Node *current = head;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }

    // Free the allocated memory
    current = head;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

void add(struct Node* node, int n) {
    // Allocate memory for the new node and initialize it
    struct Node* newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("malloc failed");
        return;
    }
    newNode->data = n;
    newNode->next = node->next;
    node->next = newNode;
}

---

24-05-17 
링크드 리스트 구현  마지막

역으로 생각을 해본다 




