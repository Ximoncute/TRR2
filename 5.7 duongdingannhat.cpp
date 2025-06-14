#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include <algorithm>

using namespace std;

const long long INF = 1e18; // Using a large value for infinity

int main() {
    ifstream fin("BN.INP");
    ofstream fout("BN.OUT");

    if (!fin.is_open()) {
        fout << "Error opening input file." << endl;
        return 1;
    }

    int n, s, t;
    fin >> n >> s >> t;

    // Adjust s and t to be 0-indexed
    s--;
    t--;

    vector<vector<int>> adj_matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fin >> adj_matrix[i][j];
        }
    }

    fin.close();

    vector<long long> dist(n, INF);
    vector<int> pred(n, -1);

    dist[s] = 0;

    // Bellman-Ford algorithm
    for (int i = 0; i < n - 1; ++i) {
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                if (adj_matrix[u][v] != 10000) { // Check if edge exists
                    if (dist[u] != INF && dist[u] + adj_matrix[u][v] < dist[v]) {
                        dist[v] = dist[u] + adj_matrix[u][v];
                        pred[v] = u;
                    }
                }
            }
        }
    }

    // Check for negative cycles
    bool has_negative_cycle = false;
    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            if (adj_matrix[u][v] != 10000) { // Check if edge exists
                if (dist[u] != INF && dist[u] + adj_matrix[u][v] < dist[v]) {
                    has_negative_cycle = true;
                    break;
                }
            }
        }
        if (has_negative_cycle) {
            break;
        }
    }

    if (has_negative_cycle) {
        fout << -1 << endl;
    } else {
        if (dist[t] == INF) {
            fout << 0 << endl;
        } else {
            fout << dist[t] << endl;

            vector<int> path;
            int curr = t;
            while (curr != -1) {
                path.push_back(curr);
                curr = pred[curr];
            }
            reverse(path.begin(), path.end());

            for (size_t i = 0; i < path.size(); ++i) {
                fout << path[i] + 1 << (i == path.size() - 1 ? "" : " ");
            }
            fout << endl;
        }
    }

    fout.close();

    return 0;
}
