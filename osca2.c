#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct process {
    int pid;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int remaining_time;
} process_t;
int main() {
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    process_t* processes = malloc(num_processes * sizeof(process_t));
    for (int i = 0; i < num_processes; i++) {
        printf("Enter the burst time and arrival time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].burst_time, &processes[i].arrival_time);
        processes[i].pid = i + 1;
        processes[i].waiting_time = 0;
        processes[i].remaining_time = processes[i].burst_time;
    }
    int current_time = 0;
    int completed_processes = 0;
    while (completed_processes < num_processes) {
        int highest_priority_process_index = -1;
        float highest_priority = -1;
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                float priority = 1 + (float) processes[i].waiting_time / processes[i].remaining_time;
                if (priority > highest_priority) {
                    highest_priority = priority;
                    highest_priority_process_index = i;
                }
            }
        }

        if (highest_priority_process_index == -1) {
            current_time++;
            continue;
        }

        printf("Current time: %d, Process %d is running\n", current_time, processes[highest_priority_process_index].pid);
        processes[highest_priority_process_index].remaining_time--;
        for (int i = 0; i < num_processes; i++) {
            if (i != highest_priority_process_index && processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                processes[i].waiting_time++;
            }
        }

        if (processes[highest_priority_process_index].remaining_time == 0) {
            printf("Process %d has completed\n", processes[highest_priority_process_index].pid);
            completed_processes++;
            processes[highest_priority_process_index].waiting_time = current_time - processes[highest_priority_process_index].arrival_time - processes[highest_priority_process_index].burst_time;
        }

        current_time++;
    }
    printf("\nGantt chart:\n ");
    for (int i = 0; i < current_time; i++) {
        printf("--");
    }
    printf("\n|");
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < processes[i].burst_time; j++) {
            printf(" ");
        }
        printf("|");
    }
    printf("\n ");
    for (int i = 0; i < current_time; i++) {
        printf("--");
    }
    printf("\n");
   int total_waiting_time = 0;
    for (int i = 0; i < num_processes; i++) {
        total_waiting_time += processes[i].waiting_time;
    }
}
