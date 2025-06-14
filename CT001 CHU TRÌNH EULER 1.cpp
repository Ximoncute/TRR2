#include <bits/stdc++.h>
using namespace std;
set<int> ke[10005];
int bac[10005];
int n, m, u;
bool visited[10005];
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
    if (cnt == 2)
        return 1;
    else if (cnt == 1)
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
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            ke[x].insert(y);
            ke[y].insert(x);
            bac[x]++;
            bac[y]++;
        }
        if (tplt() > 1)
        {
            cout << 0;
        }
        else
        {
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
    }
    else
    {
        cin >> n >> m >> u;
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            ke[x].insert(y);
            ke[y].insert(x);
            bac[x]++;
            bac[y]++;
        }
        EC(u);
    }
}