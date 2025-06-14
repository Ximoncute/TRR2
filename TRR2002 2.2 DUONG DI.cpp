#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Hàm đọc dữ liệu từ file
void readInput(int &t, int &n, int &u, int &v, vector<vector<int>> &adjMatrix, ifstream &inp) {
    inp >> t;
    inp >> n >> u >> v;
    adjMatrix.resize(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inp >> adjMatrix[i][j];
        }
    }
}

// Hàm giải quyết yêu cầu 1: Đếm số đường đi độ dài 2 từ u đến v
int countPathsOfLength2(int n, int u, int v, const vector<vector<int>> &adjMatrix) {
    int count = 0;
    for (int k = 0; k < n; ++k) {
        if (adjMatrix[u-1][k] && adjMatrix[k][v-1]) {
            count++;
        }
    }
    return count;
}

// Hàm giải quyết yêu cầu 2: Tìm đường đi từ u đến v bằng BFS
vector<int> bfsPath(int n, int u, int v, const vector<vector<int>> &adjMatrix) {
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    queue<int> q;
    
    q.push(u-1);
    visited[u-1] = true;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        if (current == v-1) {
            break;
        }
        
        for (int neighbor = 0; neighbor < n; ++neighbor) {
            if (adjMatrix[current][neighbor] && !visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;
                q.push(neighbor);
            }
        }
    }
    
    // Reconstruct path
    vector<int> path;
    if (parent[v-1] == -1 && u != v) {
        return path; // empty path means no path found
    }
    
    int current = v-1;
    while (current != -1) {
        path.push_back(current + 1);
        current = parent[current];
    }
    reverse(path.begin(), path.end());
    
    return path;
}

int main() {
    ifstream inp("TK.INP");
    ofstream out("TK.OUT");
    
    int t, n, u, v;
    vector<vector<int>> adjMatrix;
    
    readInput(t, n, u, v, adjMatrix, inp);
    
    if (t == 1) {
        int result = countPathsOfLength2(n, u, v, adjMatrix);
        out << result;
    } else if (t == 2) {
        vector<int> path = bfsPath(n, u, v, adjMatrix);
        if (path.empty() || path.front() != u || path.back() != v) {
            out << 0;
        } else {
            for (size_t i = 0; i < path.size(); ++i) {
                if (i > 0) out << " ";
                out << path[i];
            }
        }
    }
    
    inp.close();
    out.close();
    return 0;
}