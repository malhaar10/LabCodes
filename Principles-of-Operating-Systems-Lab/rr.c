#include<stdio.h>

int main()
{
    int m, tq, wt = 0, tat = 0, sum = 0, i, count = 0;
    printf("Enter time quantum: ");
    scanf("%d", &tq);
    printf("Enter the number of processes: ");
    scanf("%d", &m);
    int x = m;
    int at[m], bt[m];
    printf("Enter arrival times for each process: ");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &at[i]);
    }
    int temp [m];
    printf("Enter burst times for each process: ");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }
    for (sum = 0, i = 0; x != 0;){
        if (temp[i] <= tq && temp[i] > 0){
            sum = sum + temp[i];
            temp[i] = 0;
            count = 1;
        }
        else if (temp[i] > 1){
            temp[i] = temp[i] - tq;
            sum = sum + tq;
        }
        if (temp[i] == 0 && count == 1){
            x--;
            wt = wt + sum - at[i] - bt[i];
            tat = tat + sum - at[i]; 
            count = 0;
        }
        if(i == m-1){
            i = 0;
        }
        else if(at[i+1] <= sum){
            i++;
        }
        else{
            i = 0;
        }
    }
    float avg_wt = (float) wt / (float) m;
    float avg_tat = (float) tat / (float) m;
    printf("Average waiting time: %f\nAverage turn around time: %f\n", avg_wt, avg_tat);
    return 0;
}