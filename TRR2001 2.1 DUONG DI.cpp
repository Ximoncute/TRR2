#include <bits/stdc++.h>
using namespace std;

int t, n, u, v;
int adj[101][101];

void OpenFile() {
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
}

void ReadData() {
    cin >> t >> n >> u >> v;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> adj[i][j];
}


void CountLength2Paths() {
    int cnt = 0;
    for (int k = 1; k <= n; ++k) {
        if (adj[u][k] && adj[k][v]) {
            cnt++;
        }
    }
    cout << cnt << '\n';
}


bool visited[101];
vector<int> path;
bool DFS(int curr, int target) {
    visited[curr] = true;
    path.push_back(curr);
    if (curr == target) return true;
    for (int i = 1; i <= n; ++i) {
        if (adj[curr][i] && !visited[i]) {
            if (DFS(i, target)) return true;
        }
    }
    path.pop_back();
    return false;
}

void FindDFSPath() {
    memset(visited, 0, sizeof(visited));
    path.clear();
    if (DFS(u, v)) {
        for (int x : path) cout << x << " ";
        cout << '\n';
    } else {
        cout << 0 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OpenFile();
    ReadData();
    if (t == 1) CountLength2Paths();
    else FindDFSPath();
    return 0;
}
