#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include <algorithm>

using namespace std;

const int INF = 10000; // Using the problem's definition of no edge

int main() {
    ifstream inputFile("DN.INP");
    ofstream outputFile("DN.OUT");

    if (!inputFile.is_open()) {
        cerr << "Error opening DN.INP" << endl;
        return 1;
    }

    int n, s, t;
    inputFile >> n >> s >> t;

    // Adjust s and t to be 0-indexed
    s--;
    t--;

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inputFile >> graph[i][j];
        }
    }

    inputFile.close();

    vector<int> dist(n, INF);
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);

    dist[s] = 0;

    // Use a priority queue to store pairs of (distance, vertex)
    // The priority queue will order by distance (smallest first)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, s});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) {
            continue;
        }

        visited[u] = true;

        // If we reached the target, we can stop early
        if (u == t) {
            break;
        }

        // Explore neighbors of u
        for (int v = 0; v < n; ++v) {
            // Check if there is an edge and if v is not visited
            if (graph[u][v] != INF && !visited[v]) {
                // Relaxation step
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    // Output results
    if (dist[t] == INF) {
        outputFile << 0 << endl;
    } else {
        outputFile << dist[t] << endl;

        vector<int> path;
        int current = t;
        while (current != -1) {
            path.push_back(current);
            current = parent[current];
        }
        reverse(path.begin(), path.end());

        for (size_t i = 0; i < path.size(); ++i) {
            outputFile << path[i] + 1 << (i == path.size() - 1 ? "" : " ");
        }
        outputFile << endl;
    }

    outputFile.close();

    return 0;
}
