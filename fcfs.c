#include <stdio.h>
#include <stdlib.h>
struct Process{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
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

void fcfs(struct Process p[] , int n){
    sortBYat(p,n);
    int current_time = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(current_time<p[i].at){
            current_time = p[i].at;
        }
        p[i].ct = current_time + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        current_time = p[i].ct;
    }

}

void display(struct Process p[] , int n){
    for(int i = 0 ; i < n ;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t", p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }


}

int main(){
    return 0;
}