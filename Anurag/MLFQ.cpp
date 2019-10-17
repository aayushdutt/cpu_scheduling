#include <bits/stdc++.h>

using namespace std;

struct process
{
    char id;
    int arr;
    int bur;
};

bool cust(process a, process b)
{
    return a.arr < b.arr;
}

int main()
{
    int n;
    cin >> n;
    vector<process> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].id >> a[i].arr >> a[i].bur;
    }
    int q1, q2;
    cin >> q1 >> q2;
    int time = 0;
    sort(a.begin(), a.end(), cust);
    int i = 0;
    queue<process> x, y, z;
    time = a[0].arr;
    while (i < n or x.size() or y.size() or z.size())
    {
        if (x.size())
        {
            process p = x.front();
            x.pop();
            time += min(q1, p.bur);
            p.bur -= min(q1, p.bur);
            if (p.bur != 0)
            {
                y.push(p);
            }
            cout << p.id << " ";
        }
        else if (y.size())
        {
            process p = y.front();
            y.pop();
            time += min(q2, p.bur);
            p.bur -= min(q2, p.bur);
            if (p.bur != 0)
            {
                z.push(p);
            }
            cout << p.id << " ";
        }
        else if (z.size())
        {
            process p = z.front();
            time += p.bur;
            z.pop();
            cout << p.id << " ";
        }

        for (; i < n; i++)
        {
            if (a[i].arr <= time)
                x.push(a[i]);
            else
                break;
        }
    }
    return 0;
}