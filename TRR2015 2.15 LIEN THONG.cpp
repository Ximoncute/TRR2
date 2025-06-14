#include <bits/stdc++.h>
using namespace std;

const int MAX = 105;
int n;
int a[MAX][MAX];     // Ma trận kề
bool visited[MAX];

// Đọc dữ liệu
void ReadInput() {
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
}

// DFS cho đồ thị có hướng
void DFS(int u, int matrix[MAX][MAX]) {
    visited[u] = true;
    for (int v = 1; v <= n; ++v)
        if (matrix[u][v] && !visited[v])
            DFS(v, matrix);
}

// Kiểm tra liên thông mạnh
bool isStronglyConnected() {
    for (int start = 1; start <= n; ++start) {
        memset(visited, false, sizeof(visited));
        DFS(start, a);
        for (int i = 1; i <= n; ++i)
            if (!visited[i]) return false;
    }
    return true;
}

// Chuyển vị ma trận
void transpose(int src[MAX][MAX], int dest[MAX][MAX]) {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dest[j][i] = src[i][j];
}

// Kiểm tra liên thông yếu
bool isWeaklyConnected() {
    // Xây ma trận vô hướng từ ma trận có hướng
    int undirected[MAX][MAX] = {};
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (a[i][j] || a[j][i])
                undirected[i][j] = undirected[j][i] = 1;

    memset(visited, false, sizeof(visited));
    DFS(1, undirected);
    for (int i = 1; i <= n; ++i)
        if (!visited[i]) return false;
    return true;
}

int main() {
    ReadInput();
    if (isStronglyConnected()) {
        cout << 1;  // Liên thông mạnh
    } else if (isWeaklyConnected()) {
        cout << 2;  // Liên thông yếu
    } else {
        cout << 0;  // Không liên thông
    }
    return 0;
}
