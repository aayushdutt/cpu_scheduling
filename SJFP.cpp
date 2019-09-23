#include<bits/stdc++.h>
using namespace std;

struct Proc {
    int at; // arrival time
    int bt; // burst time
    
    int ft; // finish time
    int tat; // turn around time
    int wt; // waiting time
};

void display(Proc p[], int n) {
    cout<<"AT\tBT\tTAT\tWT\n";
    for(int i=0; i<n; i++) {
        cout<<p[i].at<<'\t'<<p[i].bt<<'\t'<<p[i].tat<<'\t'<<p[i].wt<<'\t'<<endl;
    }
    cout<<endl;
}

float avgTAT(Proc p[], int n) {
    float sum = 0;
    for(int i=0; i<n; i++) {
        sum+=p[i].tat;
    }
    return sum/n;
}

float avgWT(Proc p[], int n) {
    float sum = 0;
    for(int i=0; i<n; i++) {
        sum+=p[i].wt;
    }
    return sum/n;
}

int main() {
    cout<<"Number of processes: ";
    int n; cin>>n; // number of processes
    Proc p[n];
    for(int i=0; i<n; i++) {
        cin>>p[i].at>>p[i].bt;
    }

    int rt[n];
    for(int i=0; i<n; i++) rt[i] = p[i].bt;
    int complete = 0;
    int minm = INT_MAX, shortest = 0;
    int t=0;
    bool check = false;

    while(complete != n) {
        for(int j=0; j<n; j++) {
            if(p[j].at <=t && rt[j]<minm && rt[j]>0) {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }

        if(check == false) {
            t++;
            continue;
        }

        rt[shortest]--;
        minm = rt[shortest];
        if(minm == 0) minm = INT_MAX;

        if(rt[shortest] == 0) {
            check = false;
            complete++;
            p[shortest].ft = t+1;
            p[shortest].tat = p[shortest].ft - p[shortest].at;
            p[shortest].wt = p[shortest].tat - p[shortest].bt;
        }
        t++;
    }

    display(p, n);
    cout<<"Average TAT: "<<avgTAT(p, n)<<endl;
    cout<<"Average TAT: "<<avgWT(p, n)<<endl;
}

/*
1 6
1 8
2 7
3 3
*/