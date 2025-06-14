#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100;
int n;
int adj[MAX][MAX];
bool visited[MAX];
int disc[MAX], low[MAX], parent[MAX];
vector<pair<int, int>> bridges;

void dfs(int u, int time) {
    visited[u] = true;
    disc[u] = low[u] = ++time;

    for (int v = 0; v < n; ++v) {
        if (adj[u][v]) {
            if (!visited[v]) {
                parent[v] = u;
                dfs(v, time);
                low[u] = min(low[u], low[v]);

                if (low[v] > disc[u]) {
                    if (u < v) {
                        bridges.push_back({u, v});
                    } else {
                        bridges.push_back({v, u});
                    }
                }
            } else if (v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }
}

void findBridges() {
    for (int i = 0; i < n; ++i) {
        visited[i] = false;
        parent[i] = -1;
        disc[i] = 0;
        low[i] = 0;
    }

    int time = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, time);
        }
    }
}

int main() {
    ifstream in("TK.INP");
    ofstream out("TK.OUT");

    in >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            in >> adj[i][j];
        }
    }

    findBridges();

    // Sort bridges in lexicographical order
    sort(bridges.begin(), bridges.end());

    out << bridges.size() << endl;
    for (auto bridge : bridges) {
        out << bridge.first + 1 << " " << bridge.second + 1 << endl;
    }

    in.close();
    out.close();
    return 0;
}