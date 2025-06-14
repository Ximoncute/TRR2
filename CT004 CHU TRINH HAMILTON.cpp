#include <bits/stdc++.h>
using namespace std;
int a[505][505];
int n, st;
set<int> se[1005];
int x[1005];
bool used[1005];
vector<vector<int>> tmp;
void hamliton(int u)
{
    for (int y : se[x[u - 1]])
    {
        if (u == n + 1 && y == st)
        {
            vector<int> cnt(x + 1, x + n + 1);
            cnt.push_back(st);
            tmp.push_back(cnt);
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
    cin >> n >> st;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j])
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
        cout << tmp.size() << endl;
        for (auto it : tmp)
        {
            for (int x : it)
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << tmp.size();
    }
}