#include <bits/stdc++.h>
using namespace std;

int n, adj[101][101];
bool visited[101];
vector<vector<int>> components;

void OpenFile() {
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
}

void ReadData() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> adj[i][j];
}

void DFS(int u, vector<int>& comp) {
    visited[u] = true;
    comp.push_back(u);
    for (int v = 1; v <= n; ++v) {
        if (adj[u][v] && !visited[v]) {
            DFS(v, comp);
        }
    }
}

void FindConnectedComponents() {
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            vector<int> comp;
            DFS(i, comp);
            sort(comp.begin(), comp.end());
            components.push_back(comp);
        }
    }

    cout << components.size() << '\n';
    for (const auto& comp : components) {
        for (int v : comp)
            cout << v << ' ';
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OpenFile();
    ReadData();
    FindConnectedComponents();
    return 0;
}
