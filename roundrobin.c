#include <stdio.h>
#include <stdlib.h>
struct Process{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt; // Remaining time not Response Time
};

void sortBYat(struct Process p[],int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < n-i-1 ; j++){
            if(p[j].at > p[j+1].at){
                struct Process r = p[j];
                p[j]= p[j+1];
                p[j+1] = r;


            }

        }
    }
}

void roundrobin(struct Process p[] , int n  , int quantum){
    int done  = 0;
    int time = 0;

    sortBYat(p,n);

    for(int i = 0 ; i < n ; i++){
        p[i].bt = p[i].rt;

    }
    while(done < n){
    for(int i = 0 ; i < n ;i++){
        if(p[i].rt > 0 && p[i].at<time){
            if(quantum < p[i].rt){
                p[i].rt -= quantum;
                time+=quantum;
            }
            else{
                time+= p[i].rt;
                p[i].rt = 0;
                p[i].ct = time;
                p[i].tat = p[i].ct - p[i].at;
                p[i].wt = p[i].tat - p[i].bt;
                done++;

            }
        }
    }




}

