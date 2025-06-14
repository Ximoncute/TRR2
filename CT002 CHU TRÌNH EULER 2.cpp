#include <bits/stdc++.h>
using namespace std;
set<int> ke[10005];
int bac[10005];
int n, m, u;
bool visited[10005];
int a[505][505];
void DFS(int u)
{
    visited[u] = true;
    for (int x : ke[u])
    {
        if (!visited[x])
        {
            DFS(x);
        }
    }
}
void EC(int u)
{
    stack<int> st;
    st.push(u);
    vector<int> ans;
    while (!st.empty())
    {
        int x = st.top();
        if (ke[x].size() != 0)
        {
            int y = *ke[x].begin();
            st.push(y);
            ke[x].erase(y);
            ke[y].erase(x);
        }
        else
        {
            st.pop();
            ans.push_back(x);
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
int check1()
{
    for (int i = 1; i <= n; i++)
    {
        if (bac[i] % 2 != 0)
            return 0;
    }
    return 1;
}
int check2()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (bac[i] % 2 != 0)
            cnt++;
    }
    if (cnt == 0 || cnt == 2)
        return 1;
    else
        return 0;
}
int tplt()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cnt++;
            DFS(i);
        }
    }
    return cnt;
}
int main()
{
    int t;
    cin >> t;
    if (t == 1)
    {
        cin >> n;
        for (int x = 1; x <= n; x++)
        {
            for (int y = 1; y <= n; y++)
            {
                cin >> a[x][y];
                if (a[x][y])
                {
                    bac[x]++;
                    // bac[y]++;
                }
            }
        }
        if (check1())
        {
            cout << 1;
        }
        else if (check2())
        {
            cout << 2;
        }
        else
        {
            cout << 0;
        }
    }
    else
    {
        cin >> n >> u;
        for (int x = 1; x <= n; x++)
        {
            for (int y = 1; y <= n; y++)
            {
                cin >> a[x][y];
                if (a[x][y])
                {
                    ke[x].insert(y);
                    ke[y].insert(x);
                }
            }
        }
        EC(u);
    }
}