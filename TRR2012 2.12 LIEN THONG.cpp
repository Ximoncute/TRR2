#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 105;
int n;
int a[MAX][MAX];       // Ma trận kề
bool visited[MAX];     // Mảng đánh dấu đỉnh đã thăm

void bfs(int start, vector<int>& component) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        component.push_back(u);

        for (int v = 1; v <= n; ++v) {
            if (a[u][v] && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    ifstream fin("TK.INP");
    ofstream fout("TK.OUT");

    fin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            fin >> a[i][j];

    vector<vector<int>> components;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            vector<int> comp;
            bfs(i, comp);
            sort(comp.begin(), comp.end());
            components.push_back(comp);
        }
    }

    fout << components.size() << endl;
    for (const auto& comp : components) {
        for (int v : comp)
            fout << v << " ";
        fout << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
