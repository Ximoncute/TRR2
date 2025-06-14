#include <bits/stdc++.h>
using namespace std;

const int INF = 10000;

void solve() {
    ifstream in("DT.INP");
    ofstream out("DT.OUT");

    int t;
    in >> t;

    int n, m;
    in >> n >> m;

    vector<vector<int>> adj(n + 1, vector<int>(n + 1, INF));
    vector<int> degree(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        adj[i][i] = 0;
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        in >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
        degree[u]++;
        degree[v]++;
    }

    if (t == 1) {
        for (int i = 1; i <= n; ++i) {
            out << degree[i] << " ";
        }
        out << "\n";
    } else if (t == 2) {
        out << n << "\n";
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                out << adj[i][j] << " ";
            }
            out << "\n";
        }
    }

    in.close();
    out.close();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}