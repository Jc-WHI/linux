#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

typedef struct Process {
    int id;
    int priority;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
    struct Process* next;
} Process;

Process* createProcess(int id, int priority, int burstTime) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->id = id;
    process->priority = priority;
    process->burstTime = burstTime;
    process->waitingTime = 0;
    process->turnaroundTime = 0;
    process->next = NULL;
    return process;
}

void enqueue(Process** head, Process* newProcess) {
    if (*head == NULL || (*head)->priority > newProcess->priority) {
        newProcess->next = *head;
        *head = newProcess;
    } else {
        Process* current = *head;
        while (current->next != NULL && current->next->priority <= newProcess->priority) {
            current = current->next;
        }
        newProcess->next = current->next;
        current->next = newProcess;
    }
}

void calculateTimes(Process* head) {
    int currentTime = 0;
    Process* current = head;

    while (current != NULL) {
        current->waitingTime = currentTime;
        current->turnaroundTime = currentTime + current->burstTime;
        currentTime += current->burstTime;
        current = current->next;
    }
}

void printGanttChart(Process* head) {
    Process* current = head;
    int currentTime = 0;

    while (current != NULL) {
        printf("P%d (%d-%d)\n", current->id, currentTime, currentTime + current->burstTime);
        currentTime += current->burstTime;
        current = current->next;
    }
}

void printTimes(Process* head) {
    Process* current = head;
    int totalWaitingTime = 0, totalTurnaroundTime = 0;
    int processCount = 0;

    while (current != NULL) {
        printf("P%d: Waiting Time = %d, Turnaround Time = %d\n", current->id, current->waitingTime, current->turnaroundTime);
        totalWaitingTime += current->waitingTime;
        totalTurnaroundTime += current->turnaroundTime;
        processCount++;
        current = current->next;
    }

    printf("Average Waiting Time = %.2f\n", (double)totalWaitingTime / processCount);
    printf("Average Turnaround Time = %.2f\n", (double)totalTurnaroundTime / processCount);
}

void runProcess(int id, int burstTime) {
    for (int i = 0; i < burstTime; i++) {
        printf("P%d: %d\n", id, i + 1);
        sleep(1);
    }
}

void scheduleProcesses(Process* head) {
    Process* current = head;

    while (current != NULL) {
        pid_t pid = fork();

        if (pid == 0) {
            runProcess(current->id, current->burstTime);
            exit(0);
        } else {
            wait(NULL);
        }

        current = current->next;
    }
}

int main() {
    Process* head = NULL;

    enqueue(&head, createProcess(1, 1, 10));
    enqueue(&head, createProcess(3, 3, 6));
    enqueue(&head, createProcess(2, 2, 28));
    enqueue(&head, createProcess(5, 5, 14));
    enqueue(&head, createProcess(4, 4, 4));

    calculateTimes(head);

    printf("Gantt Chart:\n");
    printGanttChart(head);

    printf("\nProcess Times:\n");
    printTimes(head);

    scheduleProcesses(head);

    return 0;
}
