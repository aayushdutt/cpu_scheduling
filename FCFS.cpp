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
        cout<<p[i].at<<'\t'<<p[i].bt<<'\t'<<p[i].tat<<'\t'<<p[i].wt<<endl;
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

    int t=0;
    for(int i=0; i<n; i++) {
        t = max(p[i].at, t);
        p[i].ft = t + p[i].bt;
        p[i].tat = p[i].ft - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        t+=p[i].bt;
    }

    display(p, n);
    cout<<"Average TAT: "<<avgTAT(p, n)<<endl;
    cout<<"Average TAT: "<<avgWT(p, n)<<endl;
}