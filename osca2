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
}
