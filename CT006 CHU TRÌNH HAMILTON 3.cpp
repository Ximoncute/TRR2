#include <bits/stdc++.h>
using namespace std;
int a[505][505];
int n, st;
set<int> se[1005];
int x[1005];
bool used[1005];
vector<int> tmp;
int sum = 1e9;
void hamliton(int u)
{
    for (int y : se[x[u - 1]])
    {
        if (u == n + 1 && y == st)
        {
            int tong = 0;
            for (int i = 1; i < n; i++)
            {
                tong += a[x[i]][x[i + 1]];
            }
            tong += a[x[n]][x[1]];
            if (tong < sum)
            {
                tmp.clear();
                sum = tong;
                tmp.push_back(st);
                for (int i = 1; i <= n; i++)
                {
                    tmp.push_back(x[i]);
                }
                tmp.push_back(st);
            }
        }
        else if (!used[y])
        {
            x[u] = y;
            used[y] = true;
            hamliton(u + 1);
            used[y] = false;
        }
    }
}
int main()
{
    // freopen("CT.INP", "r", stdin);
    // freopen("CT.OUT", "W", stdout);
    cin >> n >> st;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] != 0 && a[i][j] != 10000)
            {
                se[i].insert(j);
                se[j].insert(i);
            }
        }
    }
    x[1] = st;
    used[x[1]] = true;
    hamliton(2);
    if (tmp.size() != 0)
    {
        cout << sum << endl;
        for (int i = 1; i < tmp.size(); i++)
        {
            cout << tmp[i] << " ";
        }
    }
    else
    {
        cout << 0;
    }
}