#include <stdio.h>
#include <stdlib.h>

struct Process{
    int priority;
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt; // Remaining time not Response Time
};


void premptivePriority(struct Process p[] , int n){
    int completed = 0;
    int time = 0;

    int minIdx = -1 ; int minPriority = 1e9;

    for(int i = 0 ; i<n ;i++){
        p[i].rt = p[i].bt;
    }

    while(completed<n){
        minIdx = -1;
        minPriority = 1e9;

        for(int i = 0 ; i < n ;i++){
            if(p[i].rt>0 && p[i].at<=time && p[i].priority<minPriority){
                minIdx = i;
                minPriority = p[i].priority;
            }

            if(minIdx==-1){
                time++;
            }

            else{
                p[minIdx].rt--;
                
             
                if(p[minIdx].rt==0){
                    p[minIdx].ct = time+1;
                    p[minIdx].tat = p[minIdx].ct - p[minIdx].at;
                    p[minIdx].wt = p[minIdx].tat - p[minIdx].bt;
                    completed++;


                }
                time++;
            }
        }
    }
}
