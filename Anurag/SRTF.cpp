#include <bits/stdc++.h>
using namespace std;
#define ms(x, t) memset(x, t, sizeof(x))
typedef long long int ll;
typedef unsigned long long int ull;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define pf push_front
#define endl "\n"
const int limit = 1e7 + 1;
const int inf = 1e7;
const int mod = 1e9 + 7;
struct process
{
    int id, arr, bt;
    bool finished = false;
};
struct cmpBt
{
    int operator()(const process &a,
                   const process &b)
    {
        return a.bt > b.bt;
    }
};
bool cmp(const process &a, process &b)
{
    if (a.arr == b.arr)
    {
        return a.bt < b.bt;
    }
    return a.arr < b.arr;
}
bool all(process a[], int n)
{
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (a[i].arr != -1)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    process a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].id >> a[i].arr >> a[i].bt;
    }
    sort(a, a + n, cmp);
    int time = a[0].arr;
    priority_queue<process, vector<process>, cmpBt> pq;
    float tat[n];
    float wt[n];
    memset(tat, 0, sizeof(tat));
    memset(wt, 0, sizeof(wt));
    pq.push(a[0]);
    a[0].finished = true;
    float TAT = 0, WT = 0;
    int num = 1;
    while (!pq.empty() and num <= n)
    {
        time++;
        if (!pq.empty())
        {
            process temp = pq.top();
            pq.pop();
            int id = temp.id - 1;

            cout << time << " " << id << endl;
            if (temp.bt == 1)
            {
                tat[id] = time - temp.arr;
                wt[id] = tat[id] - a[id].bt;
            }
            else
            {
                temp.bt--;
                pq.push(temp);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i].arr <= time && a[i].finished == false)
            {
                pq.push(a[i]);
                a[i].finished = true;
                num++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << tat[i] << " " << wt[i] << endl;
        TAT += tat[i];
        WT += wt[i];
    }
    cout<<TAT/n<<" "<<WT/n<<endl;

    return 0;
}