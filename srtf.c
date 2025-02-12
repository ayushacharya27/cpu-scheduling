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

void srtf(struct Process p[] , int n){
    int completed = 0;
    int time = 0;

    int min_Id = -1;
    int min_Bt = 1e9;

    for(int i = 0 ; i  < n ; i++){
        p[i].rt = p[i].bt;
    }

    while(completed<n){
        int min_Id = -1;
        int min_Bt = 1e9;

        for(int i = 0 ; i< n ;i++){
            if(p[i].at<=time && p[i].rt> 0 && p[i].rt < min_Bt ){
                min_Id = i ;
                min_Bt = p[i].rt;

            }
        }
        if(min_Id==-1){
            time++;
        }
        else{
            p[min_Id].rt--;
            
            if(p[min_Id].rt == 0){
                completed++;
                p[min_Id].ct = time+1;
                // Write on your own
            }
            time++;
        }
        
        
    }


}