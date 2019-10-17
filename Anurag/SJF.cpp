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
    priority_queue<process, vector<process>, cmpBt> pq;
    int time = a[0].arr;
    float tat[n];
    float wt[n];
    memset(tat, 0, sizeof(tat));
    memset(wt, 0, sizeof(wt));
    pq.push(a[0]);
    a[0].finished = true;
    float TAT = 0, WT = 0;
    int num = 1;
    while (!pq.empty() and num < n)
    {

        if (!pq.empty())
        {
            time += pq.top().bt;
            int i = pq.top().id - 1;
            tat[i] = time - pq.top().arr;
            wt[i] = tat[i] - pq.top().bt;
            cout << i << " " << tat[i] << " " << wt[i] << endl;
            TAT += tat[i];
            WT += wt[i];
            pq.pop();
        }
        else
        {
            time++;
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
    cout << "Tat: " << TAT / n << endl
         << "Wt: " << WT / n << endl;
    return 0;
}