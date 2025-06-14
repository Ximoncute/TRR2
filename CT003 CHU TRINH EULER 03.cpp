#include <bits/stdc++.h>
using namespace std;

int t, n, u;
vector<vector<int>> adj;
vector<vector<int>> temp_adj;

void readInput() {
    ifstream fin("CT.INP");
    fin >> t;
    if (t == 1) {
        fin >> n;
    } else {
        fin >> n >> u;
    }
    adj.assign(n + 1, vector<int>());
    for (int i = 1; i <= n; ++i) {
        int k, v;
        fin >> k;
        for (int j = 0; j < k; ++j) {
            fin >> v;
            adj[i].push_back(v);
        }
    }
    fin.close();
}

// Hàm kiểm tra đồ thị Euler hay nửa Euler
int checkEulerType() {
    vector<int> inDeg(n + 1, 0), outDeg(n + 1, 0);

    for (int u = 1; u <= n; ++u) {
        for (int v : adj[u]) {
            outDeg[u]++;
            inDeg[v]++;
        }
    }

    int startNodes = 0, endNodes = 0;
    for (int i = 1; i <= n; ++i) {
        if (inDeg[i] != outDeg[i]) {
            if (outDeg[i] - inDeg[i] == 1) {
                startNodes++;
            } else if (inDeg[i] - outDeg[i] == 1) {
                endNodes++;
            } else {
                return 0; // Không phải Euler cũng không phải nửa Euler
            }
        }
    }

    if (startNodes == 0 && endNodes == 0) return 1; // Euler
    if (startNodes == 1 && endNodes == 1) return 2; // Nửa Euler
    return 0;
}

// Hàm tìm chu trình Euler bằng thuật toán Hierholzer
vector<int> findEulerCycle(int start) {
    vector<int> result;
    stack<int> stk;
    temp_adj = adj;

    stk.push(start);
    while (!stk.empty()) {
        int v = stk.top();
        if (!temp_adj[v].empty()) {
            int u = temp_adj[v].back();
            temp_adj[v].pop_back();
            stk.push(u);
        } else {
            result.push_back(v);
            stk.pop();
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

void writeOutput() {
    ofstream fout("CT.OUT");
    if (t == 1) {
        fout << checkEulerType();
    } else {
        vector<int> cycle = findEulerCycle(u);
        for (int v : cycle) {
            fout << v << " ";
        }
    }
    fout.close();
}

int main() {
    readInput();
    writeOutput();
    return 0;
}
