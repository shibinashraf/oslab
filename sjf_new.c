#include<stdio.h>
int n,i,j,p[30], bt[30] ,tat[30], wt[30], tot_tat = 0, tot_wt = 0;
int sort()
{
int t,i,j;
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(bt[i]>bt[j])
{
swap(&bt[j],&bt[i]);
swap(&p[j],&p[i]);
}
}
}
}
void swap(int *a, int *b)
{
int t;
t = *a;
*a = *b;
*b = t;
}
    
void main(){
    
    float avg_tat, avg_wt;
    printf("Enter the no. of processes :");
    scanf("%d",&n);
    printf("Enter burst time for each process : ");
    for(i = 0 ; i < n ; i++){
    scanf("%d",&bt[i]);
    p[i] = i;
    }
sort();
    for(i = 0; i< n;i ++){
        if( i == 0){
            tat[i] = bt[i];
        }
        else{
        tat[i] = tat[i-1] + bt[i];
    }
        tot_tat += tat[i];
    }
    for(i = 0 ; i < n ; i++){
        if( i == 0 ){
            wt[i] == 0;
        }
        else{
            wt[i] = tat[i] - bt[i];
        }
        tot_wt += wt[i];
    }
     avg_tat = tot_tat/(float)n;
     avg_wt = tot_wt/(float)n;
    printf("PROCESS  \t\t BURST TIME \t\t TAT \t\t WT");
    for(i = 0 ; i < n ; i++){
        printf("\n Process[%d] \t\t %d  \t\t %d \t\t %d ",p[i], bt[i], tat[i], wt[i]);
    }
    printf("\n Total TURN AROUND TIME = %d", tot_tat);
    printf("\n Average TURN AROUND TIME = %f", avg_tat);
    printf("\n Total WAITING TIME = %d", tot_wt);
    printf("\n Average WAITING TIME = %f", avg_wt);
}
