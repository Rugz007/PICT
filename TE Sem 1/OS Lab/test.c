#include<stdio.h>

int main()
{
    int arr_time[10],burst_time[10],temp[10];
    int n,smallest,count,time,i;
    double wait_time=0,turn_around_time=0,end;
    float avg_wt ,avg_tat;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the details:");
    for(i = 0;i<n; i++)
    {
        printf("Enter arrival time:");
        scanf("%d",&arr_time[i]);
        printf("Enter burst time:");
        scanf("%d",&burst_time[i]);
        temp[i] = burst_time[i];
    }
    burst_time[9] = 9999;
    for(time = 0;count != n;time++)
    {
        smallest = 9;
        for(i = 0;i<n;i++)
        {
            if(burst_time[i] < burst_time[smallest] && burst_time[i] > 0 && arr_time[i] <= time)
            {
                smallest = i;
            }
        }
        burst_time[smallest]--;
        if(burst_time[smallest] == 0)
        {
            count++;
            end = time + 1;
        }
    }
}