#include <bits/stdc++.h>
using namespace std;

const int INF = 10000;

void solve() {
    int t, n, m;
    cin >> t >> n >> m;
    
    vector<int> deg_in(n+1, 0), deg_out(n+1, 0);
    vector<vector<int>> adj_matrix(n+1, vector<int>(n+1, INF));
    
    for (int i = 1; i <= n; ++i)
        adj_matrix[i][i] = 0;
    
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        
        deg_out[u]++;
        deg_in[v]++;
        
        adj_matrix[u][v] = w;
    }
    
    if (t == 1) {
        for (int i = 1; i <= n; ++i)
            cout << deg_in[i] << " " << deg_out[i] << "\n";
    } else {
        cout << n << "\n";
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cout << adj_matrix[i][j];
                if (j < n) cout << " ";
            }
            cout << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    
    solve();
    
    return 0;
}