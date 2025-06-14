#include <bits/stdc++.h>
using namespace std;

const int MAX = 105;
int a[MAX][MAX];       // Ma trận kề
int deg[MAX];          // Bậc của đỉnh
bool visited[MAX];     // Dùng cho DFS
set<int> adj[MAX];     // Danh sách kề dạng set
int n, u;

void OpenFile() {
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
}

// DFS để kiểm tra liên thông
void DFS(int v) {
    visited[v] = true;
    for (int i = 1; i <= n; i++) {
        if (a[v][i] && !visited[i]) {
            DFS(i);
        }
    }
}

// Kiểm tra liên thông các đỉnh có bậc > 0
bool isConnected() {
    memset(visited, false, sizeof(visited));
    int start = -1;
    for (int i = 1; i <= n; i++) {
        if (deg[i] > 0) {
            start = i;
            break;
        }
    }
    if (start == -1) return true; // Đồ thị rỗng

    DFS(start);
    for (int i = 1; i <= n; i++) {
        if (deg[i] > 0 && !visited[i]) return false;
    }
    return true;
}

// Kiểm tra loại đồ thị Euler
int checkEuler() {
    if (!isConnected()) return 0;

    int odd = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i] % 2 != 0) odd++;
    }
    if (odd == 0) return 1;       // Euler
    else if (odd == 2) return 2;  // Nửa Euler
    else return 0;                // Không phải
}

// Tìm chu trình Euler từ đỉnh u
void findEulerCycle(int start) {
    stack<int> st;
    vector<int> path;
    st.push(start);

    while (!st.empty()) {
        int v = st.top();
        if (!adj[v].empty()) {
            int u = *adj[v].begin();
            st.push(u);
            adj[v].erase(u);
            adj[u].erase(v);
        } else {
            path.push_back(v);
            st.pop();
        }
    }

    reverse(path.begin(), path.end());
    for (int v : path) {
        cout << v << " ";
    }
    cout << endl;
}

int main() {
    OpenFile();
    int t;
    cin >> t;

    if (t == 1) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            deg[i] = 0;
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
                if (a[i][j]) deg[i]++;
            }
        }
        cout << checkEuler();
    } else {
        cin >> n >> u;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
                if (a[i][j]) {
                    adj[i].insert(j);
                }
            }
        }
        findEulerCycle(u);
    }

    return 0;
}
