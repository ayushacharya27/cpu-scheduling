#include <stdio.h>
#include <stdlib.h>
struct Process{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    // No Response time Fucker
    int done_flag;
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

void sjf(struct Process p[], int n ){
    int time = 0 ;
    int completed = 0;

    sortBYat(p,n);
    
    while(completed<n){
        int minId = -1 ; int minBt = 1e9;
        for(int i = 0 ; i < n ;i++){
            if(!p[i].done_flag && p[i].at<=time && p[i].bt < minBt){
                minId=i; minBt = p[i].bt;
            }

        }

        if(minId==-1){
            time++; 
        }
        else{
            p[minId].ct = time+p[minId].bt;
            p[minId].tat = p[minId].ct - p[minId].at;
            p[minId].bt = p[minId].tat - p[minId].bt;
            time+=p[minId].bt;
            p[minId].done_flag = 1;
            
            completed++;

        }
    }


        
    
}