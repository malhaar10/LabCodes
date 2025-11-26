#include <stdio.h>

int main() {
    int n, i, j, temp, total_wt = 0, total_tat = 0;
    float avg_wt, avg_tat;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n], pid[n];

    // Input Burst Time and assign Process IDs
    printf("Enter Burst Times:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
        pid[i] = i + 1;  // Process ID
    }

    // Sort processes by Burst Time using Selection Sort
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (bt[j] < bt[i]) {
                // Swap Burst Time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap Process ID
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    // Calculate Waiting Time
    wt[0] = 0;  // First process has 0 waiting time
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        total_wt += wt[i];
    }

    // Calculate Turnaround Time and total TAT
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total_tat += tat[i];
    }

    // Calculate Average WT and TAT
    avg_wt = (float)total_wt / n;
    avg_tat = (float)total_tat / n;

    // Display the results
    printf("P\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", pid[i], bt[i], wt[i], tat[i]);
    }

    printf("Average Waiting Time= %.2f\n", avg_wt);
    printf("Average Turnaround Time= %.2f\n", avg_tat);

    return 0;
}
