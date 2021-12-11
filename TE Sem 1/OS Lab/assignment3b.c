#include <stdio.h>
int main()
{
    int i, n, total = 0, x, quant;
    int wait_time = 0, turnaround_time = 0, arr_time[10], burst_time[10], temp[10];
    float average_wait_time, average_turnaround_time;
    printf("Enter Total Number of Processes:\t");
    scanf("%d", &n);
    x = n;
    for (i = 0; i < n; i++)
    {
        printf("\nEnter Details of Process %d \n", i + 1);
        printf("Arrival Time :\t");
        scanf("%d", &arr_time[i]);
        printf("Burst Time :\t");
        scanf("%d", &burst_time[i]);
        temp[i] = burst_time[i];
    }
    printf("\nEnter Time Quantum:\t");
    scanf("%d", &quant);
    for (total = 0, i = 0; x != 0;)
    {
        if (temp[i] <= quant && temp[i] > 0)
        {
            total = total + temp[i];
            temp[i] = 0;
            x--;
            wait_time = wait_time + total - arr_time[i] - burst_time[i];
            turnaround_time = turnaround_time + total - arr_time[i];
        }
        else if (temp[i] > 0)
        {
            temp[i] = temp[i] - quant;
            total = total + quant;
        }

        if (i == n - 1)
        {
            i = 0;
        }
        else if (arr_time[i + 1] <= total)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }
    average_wait_time = wait_time * 1.0 / n;
    average_turnaround_time = turnaround_time * 1.0 / n;
    printf("\n\nAvg Waiting Time:\t%f", average_wait_time);
    printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time);
    return 0;
}