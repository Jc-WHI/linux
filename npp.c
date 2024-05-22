#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Process {
    char name[3];
    int arrivalTime;
    int burstTime;
    int priority;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
    struct Process *next;
} Process;

typedef struct GanttChart {
    char processName[3];
    int startTime;
    int endTime;
    struct GanttChart *next;
} GanttChart;

void insertProcess(Process **head, char name[], int arrivalTime, int burstTime, int priority) {
    Process *newProcess = (Process *)malloc(sizeof(Process));
    strcpy(newProcess->name, name);
    newProcess->arrivalTime = arrivalTime;
    newProcess->burstTime = burstTime;
    newProcess->priority = priority;
    newProcess->completionTime = 0;
    newProcess->waitingTime = 0;
    newProcess->turnaroundTime = 0;
    newProcess->next = NULL;

    if (*head == NULL || (*head)->priority < priority) {
        newProcess->next = *head;
        *head = newProcess;
    } else {
        Process *current = *head;
        while (current->next != NULL && current->next->priority >= priority) {
            current = current->next;
        }
        newProcess->next = current->next;
        current->next = newProcess;
    }
}

void nonPreemptivePriorityScheduling(Process *head, GanttChart **ganttHead) {
    int currentTime = 0;
    Process *current = head;
    GanttChart *ganttTail = NULL;

    while (current != NULL) {
        if (currentTime < current->arrivalTime) {
            currentTime = current->arrivalTime; // 프로세스 도착 시간을 고려
        }
        int startTime = currentTime;
        currentTime += current->burstTime;
        int endTime = currentTime;

        GanttChart *newGanttEntry = (GanttChart *)malloc(sizeof(GanttChart));
        strcpy(newGanttEntry->processName, current->name);
        newGanttEntry->startTime = startTime;
        newGanttEntry->endTime = endTime;
        newGanttEntry->next = NULL;

        if (*ganttHead == NULL) {
            *ganttHead = newGanttEntry;
        } else {
            ganttTail->next = newGanttEntry;
        }
        ganttTail = newGanttEntry;

        current->completionTime = endTime;
        current->turnaroundTime = current->completionTime - current->arrivalTime;
        current->waitingTime = current->turnaroundTime - current->burstTime;

        current = current->next;
    }
}

void printGanttChart(GanttChart *ganttHead) {
    GanttChart *current = ganttHead;
    while (current != NULL) {
        printf("%s (%d-%d)\n", current->processName, current->startTime, current->endTime);
        current = current->next;
    }
}

void printProcessDetails(Process *head) {
    Process *current = head;
    printf("Process\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    while (current != NULL) {
        printf("%s\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               current->name,
               current->arrivalTime,
               current->burstTime,
               current->priority,
               current->completionTime,
               current->turnaroundTime,
               current->waitingTime);
        current = current->next;
    }
}

int main() {
    Process *head = NULL;
    insertProcess(&head, "P1", 0, 10, 1);
    insertProcess(&head, "P2", 2, 28, 3);
    insertProcess(&head, "P3", 4, 6, 4);
    insertProcess(&head, "P4", 6, 4, 5);
    insertProcess(&head, "P5", 8, 14, 2);

    GanttChart *ganttHead = NULL;

    nonPreemptivePriorityScheduling(head, &ganttHead);
    printGanttChart(ganttHead);
    printProcessDetails(head);

    // 메모리 해제 (optional)
    Process *tempProcess;
    while (head != NULL) {
        tempProcess = head;
        head = head->next;
        free(tempProcess);
    }

    GanttChart *tempGantt;
    while (ganttHead != NULL) {
        tempGantt = ganttHead;
        ganttHead = ganttHead->next;
        free(tempGantt);
    }

    return 0;
}
