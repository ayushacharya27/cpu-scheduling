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

void non_premptivePriority(struct Process p[] , int n){
    int completed = 0 ;
    int time = 0;

    sortBYat(p,n);

    while(completed<n){
        int minId = -1 ; int minPriority = 1e9;

        for(int i = 0 ; i < n ;i++){
            if(!p[i].done_flag && p[i].priority< minPriority){
                minId = i;
                minPriority = p[i].priority;
            }

            if(minId==-1){
                time++;
            }
            else{
                p[minId].ct = time + p[minId].bt;
                p[minId].tat = p[minId].ct  - p[minId].at;
                p[minId].wt = p[minId].tat - p[minId].bt;
                p[minId].done_flag = 1;
                time+=p[minId].ct;
                completed++;
                


            }

        }
    }
}

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