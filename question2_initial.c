#include<stdio.h>

typedef struct proc {
    int id;
    int burst_time;
    int wait_time;
    int turnaround_time;
} Process;

void findWaitingTime(Process proc[], int n) {
    proc[0].wait_time = 0;
    for (int i = 1; i < n ; i++ ) {
        proc[i].wait_time = proc[i-1].burst_time + proc[i-1].wait_time ;
    }
}

void findTurnAroundTime(Process proc[], int n) {
    for (int i = 0; i < n ; i++) {
        proc[i].turnaround_time = proc[i].burst_time + proc[i].wait_time;
    }
}

void findavgTime(Process proc[], int n) {
    int total_wt = 0, total_tat = 0;
    findWaitingTime(proc, n);
    findTurnAroundTime(proc, n);
    printf("Processes Burst Time Waiting Time Turnaround Time\n");
    for (int i=0; i<n; i++) {
        total_wt = total_wt + proc[i].wait_time;
        total_tat = total_tat + proc[i].turnaround_time;
        printf("%d\t\t%d\t\t%d\t\t%d\n",proc[i].id,proc[i].burst_time,proc[i].wait_time,proc[i].turnaround_time);
    }
    printf("Average waiting time : %f",(float)total_wt/n);
    printf("\nAverage turnaround time : %f",(float)total_tat/n);
}

int main() {
    Process proc[100];
    int n, i;
    printf("Enter the number of process: ");
    scanf("%d", &n);
    printf("Enter the burst time of the processes: \n");
    for(i=0; i<n; i++) {
        printf("Process[%d]: ", i+1);
        scanf("%d", &proc[i].burst_time);
        proc[i].id = i+1;
    }
    findavgTime(proc, n);
    return 0;
}