#include<bits/stdc++.h>
using namespace std;

struct Proc {
    int at; // arrival time
    int bt; // burst time
    
    int ft; // finish time
    int tat; // turn around time
    int wt; // waiting time
    int rt; // remaining time
};

void display(Proc p[], int n) {
    cout<<"AT\tBT\tTAT\tWT\n";
    for(int i=0; i<n; i++) {
        cout<<p[i].at<<'\t'<<p[i].bt<<'\t'<<p[i].tat<<'\t'<<p[i].wt<<'\t'<<p[i].ft<<endl;
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
        p[i].rt = p[i].bt;
    }
    int quantum;
    cin>>quantum;

    bool vis[n] = {0};
    int t=p[0].at;
    queue<int> q;
    q.push(0);
    vis[0] = true;
    
    while(!q.empty()) {
        int front = q.front();
        q.pop();

        int minm = min(p[front].rt, quantum);
        p[front].rt -= minm;
        t += minm;

        for(int i=0; i<n; i++) {
            if(p[i].at <= t && vis[i] == 0) {
                q.push(i);
                vis[i] = true;
            }
        }

        if(p[front].rt != 0) q.push(front);
        else {
            p[front].ft = t;
            p[front].tat = p[front].ft - p[front].at;
            p[front].wt = p[front].tat - p[front].bt;
        }
    }

    display(p, n);
    cout<<"Average TAT: "<<avgTAT(p, n)<<endl;
    cout<<"Average TAT: "<<avgWT(p, n)<<endl;
}

/*
5
0 5
1 3
2 1
3 2
4 3
2
*/