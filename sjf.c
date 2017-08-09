#include<stdio.h>
#define MAX 100

int main(){
    int bt[MAX],tat[MAX],wt[MAX],p[MAX],n,temp,pos,total=0,i,j;
    float average_wt,average_tat;
    printf("Enter no of Processes");
    scanf("%d",&n);
    printf("Enter no of Burst time : \n");
    for( i = 0 ; i < n ; i++){
        printf("P%d : ",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }
    for( i = 0 ; i < n ; i++){
        pos=i;
        for( j = i+1 ; j < n ; j++){
            if(bt[j]<bt[pos]){
                pos=j;
            }
        }
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    wt[0]=0;
    for(i = 0 ; i < n ; i++){
        wt[i]=0;
        for(j = 0 ; j < i ; j++){
            wt[i]+=bt[j];
        }
        total += wt[i];
    }
    average_wt=(float)total/n;
    total=0;
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for( i = 0; i < n ; i++){
        tat[i]=wt[i]+bt[i];
        total+=tat[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
    average_tat=(float)total/n;
    printf("\n%f\n",average_wt);
    printf("\n%f\n",average_tat);
}

