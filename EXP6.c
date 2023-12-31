#include<stdio.h>
typedef struct{
    int processid;
    int bursttime;
    int priority;
}process;
void fcfs(process processes[],int n){
    int waitingtime=0;
    float totalwaitingtime=0;
    float averagewaitingtime;
    printf("\n fcfs scheduling algorithm\n");
    for(int i=0;i<n;i++){
        printf("process %d is runnning \n",processes[i].processid);
        waitingtime+=processes[i].bursttime;
        printf("process %d is finished.waiting time:%d\n",processes[i].processid,waitingtime);
        totalwaitingtime+=waitingtime;
    }
    averagewaitingtime=totalwaitingtime/n;
    printf("average waiting time:%.2f\n",averagewaitingtime);
}
void sjn(process processes[],int n){
    int totaltime=0;
    int waitingtime=0;
    float totalwaitingtime=0;
    float averagewaitingtime;
    printf("\n SJN scheduling algorithm\n");
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(processes[j].bursttime>processes[j+1].bursttime){
                process temp=processes[j];
                processes[j]=processes[j+1];
                processes[j+1]=temp;
            }
        }
}
 for(int i=0;i<n;i++){
        printf("process %d is runnning \n",processes[i].processid);
        waitingtime+=totaltime;
        totaltime+=processes[i].bursttime;
        printf("process %d is finished.waiting time:%d\n",processes[i].processid,waitingtime);
        totalwaitingtime+=waitingtime;
    }
    averagewaitingtime=totalwaitingtime/n;
    printf("average waiting time:%.2f\n",averagewaitingtime);
}
void priorityscheduling(process processes[],int n){
    int waitingtime=0;
    float totalwaitingtime=0;
    float averagewaitingtime;
     printf("\n priority scheduling algorithm\n");
      for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(processes[j].priority>processes[j+1].priority){
                process temp=processes[j];
                processes[j]=processes[j+1];
                processes[j+1]=temp;
            }
        }
}
for(int i=0;i<n;i++){
        printf("process %d is runnning \n",processes[i].processid);
        waitingtime+=processes[i].bursttime;
        printf("process %d is finished.waiting time:%d\n",processes[i].processid,waitingtime);
        totalwaitingtime+=waitingtime;
    }
    averagewaitingtime=totalwaitingtime/n;
    printf("average waiting time:%.2f\n",averagewaitingtime);
}
int main(){
    int n;
    printf("enter the number of processor");
    scanf("%d",&n);
    process processes[n];
    for(int i=0;i<n;i++){
        printf("\n enter details for process%d\n",i+1);
        processes[i].processid=i+1;
        printf("enter burst time :");
        scanf("%d",&processes[i].bursttime);
        printf("enter priority");
        scanf("%d",&processes[i].priority);
    }
    fcfs(processes,n);
    sjn(processes,n);
    priorityscheduling(processes,n);
    return 0;
} 
