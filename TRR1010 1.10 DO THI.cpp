#include <bits/stdc++.h>
using namespace std;

const int INF = 10000;
int t, n, c[105][105];

void ReadData() {
    cin >> t >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> c[i][j];
}

void CalcDeg() {
    for (int i = 1; i <= n; ++i) {
        int deg = 0;
        for (int j = 1; j <= n; ++j)
            if (i != j && c[i][j] != INF && c[i][j] != 0)
                deg++;
        cout << deg << " ";
    }
    cout << "\n";
}

void EdgeList() {
    vector<tuple<int, int, int>> edges;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (c[i][j] != INF && c[i][j] != 0) {
                edges.push_back({i, j, c[i][j]});
            }
        }
    }
    cout << n << " " << edges.size() << "\n";
    sort(edges.begin(), edges.end());
    for (auto edge : edges) {
        int u = get<0>(edge);
        int v = get<1>(edge);
        int w = get<2>(edge);
        cout << u << " " << v << " " << w << "\n";
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    ReadData();
    if (t == 1)
        CalcDeg();
    else
        EdgeList();

    return 0;
}
