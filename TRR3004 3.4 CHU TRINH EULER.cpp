#include <bits/stdc++.h>
using namespace std;

const int MAX = 105;
int a[MAX][MAX];
int inDeg[MAX], outDeg[MAX];
bool visited[MAX];
vector<int> adj[MAX], revAdj[MAX];  // Đồ thị và đồ thị ngược
int n, u;

void OpenFile() {
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
}

// DFS cho kiểm tra liên thông yếu
void dfs(int v, vector<int> graph[]) {
    visited[v] = true;
    for (int neighbor : graph[v]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph);
        }
    }
}

bool isWeaklyConnected() {
    // Xây dựng đồ thị liên thông yếu bằng cách bỏ hướng
    memset(visited, false, sizeof(visited));
    int start = -1;
    for (int i = 1; i <= n; i++) {
        if (outDeg[i] > 0 || inDeg[i] > 0) {
            start = i;
            break;
        }
    }
    if (start == -1) return true;

    // Đồ thị không hướng (gộp cả adj và revAdj)
    vector<int> undirected[MAX];
    for (int i = 1; i <= n; i++) {
        for (int j : adj[i]) {
            undirected[i].push_back(j);
            undirected[j].push_back(i);
        }
    }

    dfs(start, undirected);
    for (int i = 1; i <= n; i++) {
        if ((outDeg[i] > 0 || inDeg[i] > 0) && !visited[i]) return false;
    }
    return true;
}

// Kiểm tra loại đồ thị Euler có hướng
int checkEuler() {
    if (!isWeaklyConnected()) return 0;

    int start = 0, end = 0;
    for (int i = 1; i <= n; i++) {
        if (outDeg[i] == inDeg[i]) continue;
        else if (outDeg[i] == inDeg[i] + 1) start++;
        else if (inDeg[i] == outDeg[i] + 1) end++;
        else return 0;
    }

    if (start == 0 && end == 0) return 1;         // Euler
    if (start == 1 && end == 1) return 2;         // Nửa Euler
    return 0;
}

// Tìm chu trình Euler với Hierholzer (đồ thị có hướng)
void findEulerPath(int start) {
    stack<int> st;
    vector<int> path;
    st.push(start);

    vector<stack<int>> graph(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int v : adj[i]) {
            graph[i].push(v);
        }
    }

    while (!st.empty()) {
        int v = st.top();
        if (!graph[v].empty()) {
            int u = graph[v].top();
            graph[v].pop();
            st.push(u);
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
            inDeg[i] = outDeg[i] = 0;
            adj[i].clear();
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
                if (a[i][j]) {
                    outDeg[i]++;
                    inDeg[j]++;
                    adj[i].push_back(j);
                }
            }
        }

        cout << checkEuler();
    } else {
        cin >> n >> u;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
                if (a[i][j]) {
                    adj[i].push_back(j);
                }
            }
        }

        findEulerPath(u);
    }

    return 0;
}
