#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100;
int n;
int adj[MAX][MAX];
bool visited[MAX];
int disc[MAX];      // Thời gian khám phá đỉnh
int low[MAX];       // low[u] là thời gian khám phá nhỏ nhất có thể đạt được từ cây con gốc u
int parent[MAX];    // parent[u] là cha của u trong cây DFS
bool isArticulation[MAX]; // Kiểm tra đỉnh có phải là đỉnh trụ không
int timeCount;       // Biến đếm thời gian trong DFS

void dfs(int u) {
    visited[u] = true;
    disc[u] = low[u] = ++timeCount;
    int children = 0; // Số lượng con của u trong cây DFS

    for (int v = 0; v < n; ++v) {
        if (adj[u][v]) {
            if (!visited[v]) {
                children++;
                parent[v] = u;
                dfs(v);

                // Cập nhật giá trị low cho u
                low[u] = min(low[u], low[v]);

                // Kiểm tra xem u có phải là đỉnh trụ không
                // Trường hợp 1: u là gốc của cây DFS và có ít nhất 2 con
                if (parent[u] == -1 && children > 1) {
                    isArticulation[u] = true;
                }
                // Trường hợp 2: u không phải là gốc và low[v] >= disc[u]
                if (parent[u] != -1 && low[v] >= disc[u]) {
                    isArticulation[u] = true;
                }
            } else if (v != parent[u]) {
                // Cập nhật low[u] nếu có cạnh ngược từ u đến tổ tiên v
                low[u] = min(low[u], disc[v]);
            }
        }
    }
}

void findArticulationPoints() {
    timeCount = 0;
    fill(visited, visited + n, false);
    fill(parent, parent + n, -1);
    fill(isArticulation, isArticulation + n, false);

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Đếm số lượng đỉnh trụ và lưu lại
    int count = 0;
    vector<int> articulationPoints;
    for (int i = 0; i < n; ++i) {
        if (isArticulation[i]) {
            count++;
            articulationPoints.push_back(i + 1); // Đỉnh được đánh số từ 1
        }
    }

    // Ghi kết quả ra file
    ofstream outFile("TK.OUT");
    outFile << count << endl;
    if (count > 0) {
        sort(articulationPoints.begin(), articulationPoints.end());
        for (int i = 0; i < articulationPoints.size(); ++i) {
            outFile << articulationPoints[i] << " ";
        }
    }
    outFile.close();
}

int main() {
    ifstream inFile("TK.INP");
    inFile >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inFile >> adj[i][j];
        }
    }
    inFile.close();

    findArticulationPoints();

    return 0;
}