#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<time.h>

void main()
{
    int alg_no, n,bt[5],wt[5],tat[5],avg_wt,avg_tat,i,j,p[5],pr[5],total,pos,temp;
    printf("Select an algorithm to use: \n");
    printf("1. Shortest job first\n");
    printf("2. Priority Scheduling\n");
    printf("3. First in First Out\n");
    scanf("%d",&alg_no);

    switch (alg_no)
    {
        case 1:   //shortest job first case
        total=0;
        printf("Enter number of process:");
        scanf("%d",&n);
 
        printf("\nEnter Burst Time:\n");
        for(i=0;i<n;i++)
        {
            printf("p%d:",i+1);
            scanf("%d",&bt[i]);
            p[i]=i+1;           //contains process number
        }
 
        //sorting burst time in ascending order using selection sort
        for(i=0;i<n;i++)
        {
            pos=i;
            for(j=i+1;j<n;j++)
            {   
                if(bt[j]<bt[pos])
                pos=j;
            }
 
            temp=bt[i];
            bt[i]=bt[pos];
            bt[pos]=temp;
            temp=p[i];
            p[i]=p[pos];
            p[pos]=temp;
        }
 
        wt[0]=0;            //waiting time for first process will be zero
 
        //calculate waiting time
        for(i=1;i<n;i++)
        {
            wt[i]=0;
            for(j=0;j<i;j++)
            {  
                 wt[i]+=bt[j];
            }   
            total+=wt[i];
        }
        avg_wt=(float)total/n;      //average waiting time
        total=0;
 
        printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
        for(i=0;i<n;i++)
        {
            tat[i]=bt[i]+wt[i];     //calculate turnaround time
            total+=tat[i];
            printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
        }
 
        avg_tat=(float)total/n;     //average turnaround time
        printf("\n\nAverage Waiting Time=%d",avg_wt);
        printf("\nAverage Turnaround Time=%d\n",avg_tat);

        break;

        case 2:
        total=0;
        printf("Enter Total Number of Process:");
        scanf("%d",&n);
 
        printf("\nEnter Burst Time and Priority\n");
        for(i=0;i<n;i++)
        {
            printf("\nP[%d]\n",i+1);
            printf("Burst Time:");
            scanf("%d",&bt[i]);
            printf("Priority:");
            scanf("%d",&pr[i]);
            p[i]=i+1;           //contains process number
        }
 
        //sorting burst time, priority and process number in ascending order using selection sort
        for(i=0;i<n;i++)
        {
            pos=i;
            for(j=i+1;j<n;j++)
            {
                if(pr[j]<pr[pos])
                pos=j;
            }
 
            temp=pr[i];
            pr[i]=pr[pos];
            pr[pos]=temp;
 
            temp=bt[i];
            bt[i]=bt[pos];
            bt[pos]=temp;
 
            temp=p[i];
            p[i]=p[pos];
            p[pos]=temp;
        }
 
        wt[0]=0;	//waiting time for first process is zero
 
        //calculate waiting time
        for(i=1;i<n;i++)
        {
            wt[i]=0;
            for(j=0;j<i;j++)
            wt[i]+=bt[j];
            total+=wt[i];
        }
 
        avg_wt=total/n;      //average waiting time
        total=0;
 
        printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
        for(i=0;i<n;i++)
        {
            tat[i]=bt[i]+wt[i];     //calculate turnaround time
            total+=tat[i];
            printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
        }
 
        avg_tat=total/n;     //average turnaround time
        printf("\n\nAverage Waiting Time=%d",avg_wt);
        printf("\nAverage Turnaround Time=%d\n",avg_tat);
        break;

        case 3:
        avg_wt=0;
        avg_tat=0;
        printf("Enter total number of processes(maximum 5):");
        scanf("%d",&n);
 
        printf("\nEnter Process Burst Time\n");
        for(i=0;i<n;i++)
        {
            printf("P[%d]:",i+1);
            scanf("%d",&bt[i]);
        }
 
        wt[0]=0;    //waiting time for first process is 0
 
        //calculating waiting time
        for(i=1;i<n;i++)
        {
            wt[i]=0;
            for(j=0;j<i;j++)
            wt[i]+=bt[j];
        }
 
        printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
 
        //calculating turnaround time
        for(i=0;i<n;i++)
        {
            tat[i]=bt[i]+wt[i];
            avg_wt+=wt[i];
            avg_tat+=tat[i];
            printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
        }
 
        avg_wt/=i;
        avg_tat/=i;
        printf("\n\nAverage Waiting Time:%d",avg_wt);
        printf("\nAverage Turnaround Time:%d",avg_tat);
        break;
        default:
            break;
    }
}