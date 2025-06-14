#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int MAX = 100;
int n, u;
int adj[MAX][MAX];
vector<int> path;
vector<vector<int>> hamiltonCycles;
bool visited[MAX];

void findHamiltonCycles(int current, int count) {
    if (count == n) {
        if (adj[current][u - 1]) { // Kiểm tra có cạnh từ current về u không
            path.push_back(u);
            hamiltonCycles.push_back(path);
            path.pop_back();
        }
        return;
    }

    for (int next = 0; next < n; ++next) {
        if (adj[current][next] && !visited[next]) {
            visited[next] = true;
            path.push_back(next + 1); // Đỉnh được đánh số từ 1 đến n
            findHamiltonCycles(next, count + 1);
            path.pop_back();
            visited[next] = false;
        }
    }
}

int main() {
    ifstream in("CT.INP");
    ofstream out("CT.OUT");

    in >> n >> u;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            in >> adj[i][j];
        }
    }

    // Khởi tạo
    path.push_back(u);
    visited[u - 1] = true; // Đỉnh u được đánh số từ 1 đến n, trong mảng từ 0 đến n-1
    findHamiltonCycles(u - 1, 1);

    if (hamiltonCycles.empty()) {
        out << 0 << endl;
    } else {
        for (const auto &cycle : hamiltonCycles) {
            for (int v : cycle) {
                out << v << " ";
            }
            out << endl;
        }
        out << hamiltonCycles.size() << endl;
    }

    in.close();
    out.close();
    return 0;
}