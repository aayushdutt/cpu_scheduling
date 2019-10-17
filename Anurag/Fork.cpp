#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int pid = fork();
    cout << pid << endl;
    if (pid)
    {
        cout << "parent" << endl;
        wait(NULL);
        cout << getpid() << endl;
        cout << getppid() << endl;
    }
    else
    {
        cout << "child" << endl;
        cout << getpid() << endl;
        cout << getppid() << endl;
    }
    return 0;
}