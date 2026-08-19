#include<stdio.h>
int main()
{
    int n, i, j, temp;
    int bt[20], pr[20], wt[20], tat[20];
    float avg_wt=0, avg_tat=0;

    printf("Enter Number of Processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nEnter Burst Time for P%d: ",i+1);
        scanf("%d",&bt[i]);
        printf("Enter Priority for P%d: ",i+1);
        scanf("%d",&pr[i]);
    }

    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(pr[i] > pr[j])
            {
                temp=pr[i]; pr[i]=pr[j]; pr[j]=temp;
                temp=bt[i]; bt[i]=bt[j]; bt[j]=temp;
            }

    wt[0] = 0;
    for(i=1;i<n;i++)
        wt[i] = wt[i-1] + bt[i-1];

    printf("\nProcess\tPriority\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++)
    {
        tat[i] = wt[i] + bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
        printf("P%d\t%d\t\t%d\t%d\t%d\n",i+1,pr[i],bt[i],wt[i],tat[i]);
    }

    avg_wt /= n;
    avg_tat /= n;
    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);
    return 0;
}
